//�ر���л 15�� ɳ��ɭ(sola) ������(Clovin) ��Խ(hangxingliu) �ļ���������֧��

// GitHub ��ַ 
//https://github.com/unlimitedsola
//https://github.com/Clovin
//https://github.com/hangxingliu

//����Ϸ����easyXͼ�ο�,��Ҫ��װ�ļ����ڵ�EasyX_2018���ְ�ſ�����
//VC6 Ĭ��ʹ�õ� MBCS ���룬�� VC2008 ���߰汾 VC Ĭ��ʹ�õ� Unicode ���롣������ϸ����������⣺
//�� char ��ʾ�ַ�ʱ��Ӣ��ռ��һ���ֽڣ�����ռ�������ֽڡ�
//������һ�����ص����⣺���������ֽڣ�����������Ӣ���ַ�������һ�������ַ���
//Ϊ�˽��������⣬Unicode ���뵮���ˡ�Unicode ���벻������Ӣ�Ķ��������ֽڱ�ʾ��
//���� MBCS ���룬�ַ������� char ���塣
//���� Unicode �����У��ַ������� wchar_t ���塣
//����Visual Sstudio �߰汾�п�ʹ��  _T("abc")  ��  ��Ŀ ��> ����  ��> �����ַ���  ��> Unicode ��> ���ַ��� ����
//��Ϊ���뱾��Դ�����ñ������İ汾�� Visual Studio 2017 ������ V141 �汾�Ĺ��߼� 
// ��Ҫ��VS12�����У��޸Ĺ��߼��汾����

#include<graphics.h>
#include<windows.h>
#include"Mydefine.h"
#include"Control.h"
#include"Role.h"
#include"Scene.h"
#include<time.h>
#include <mmsystem.h> //���ö�ý���ļ�����msciSendString��Ҫ���ô�ͷ�ļ�
#pragma comment(lib,"winmm.lib") //���ײ��� 

//ȫ�ֱ���
int life = LIFE;   //������life������
int world = 1;     //�����ǵ�world��

int main()
{
	initgraph(XSIZE, YSIZE); // ������ͼ�����²������ݵ�ʵ�־��ڻ�ͼ����

	control myCtrl;        //����һ����Ϸ����
	role myRole(world);    //�����ɫ
	scene myScene(world);  //������Ϸ����
	myCtrl.gameStart();//��Ϸ�Ŀ�ʼ����

					   //�����Ϸ����
	mciSendString("open res\\����.mp3 alias music_bg", NULL, 0, NULL);//�����ֲ���������������Ժ�����ֻ���ñ������� ��music_bg�� Ϊ���� 
	mciSendString("open res\\ʤ��.mp3 alias music_win", NULL, 0, NULL);//MegaloBox~
	mciSendString("open res\\����.mp3 alias music_passedAll", NULL, 0, NULL);//������.mp3��Ϊ���ļ�ԭ��
	mciSendString("open res\\GG.mp3 alias music_end", NULL, 0, NULL);
	mciSendString("play music_bg repeat", NULL, 0, NULL);



	while (true) //������ѭ����֤��Ϸ����������(���ظ��棩
	{
		//
		//���Ʋ�
		//
		int key = myCtrl.getKey(); //��ȡ��Ұ��µļ�                              
		if (key == VIR_RESTART)     //�����Ϸ������ѡ���ˡ����¿�ʼ��
		{
			myScene = scene(world); // �����ؿ�����
			mciSendString("play music_bg from 0", NULL, 0, NULL);
			myRole = role(world); //�����ؿ���ɫ
		}
		else if (key == VIR_HOME)   //�����Ϸ������ѡ���ˡ����˵���
		{
			mciSendString("stop music_bg", NULL, 0, NULL);
			life = LIFE; //��ʼ������ֵ
			world = 1; // ��ʼ���ؿ�
			myRole = role(world); //���´����ؿ����� 
			myScene = scene(world); // ���´����ؿ���ɫ
			myCtrl.gameStart(); //��ӡ��Ϸ��ʼ������
			mciSendString("play music_bg from 0", NULL, 0, NULL);
		}
		//
		//��ɫ��
		//
		myRole.action(key, &myScene);
		//
		//������
		//
		myScene.action(&myRole);

		if (myRole.isDied())     //�����������
		{
			mciSendString("stop music_bg", NULL, 0, NULL);
			BeginBatchDraw(); // ������ͼ������
			myScene.show();
			myRole.show();
			myCtrl.showScore(myRole.getScore());
			myCtrl.showLevel(world);
			EndBatchDraw();//������ͼ����������ӡ����ͼ�ν���
			Sleep(2500);
			life--;
			if (life == 0) //������ǵ���������
			{
				mciSendString("play music_end from 0", NULL, 0, NULL);
				myCtrl.showGameOver();
				life = LIFE; // ��ʼ������
				world = 1; // ��ʼ���ؿ�
				myCtrl.gameStart();
				myRole = role(world);
				myScene = scene(world);
				mciSendString("play music_bg from 0", NULL, 0, NULL);
			}
			else
			{
				myCtrl.showDied(life); // ����ͼ�ν�����ʾ�����м�����
				myRole = role(world); // ���ý�ɫ
				myScene = scene(world); //���ùؿ� ����Ϊ��ǰδͨ�عؿ�
				mciSendString("play music_bg from 0", NULL, 0, NULL);
			}
		}
		if (myRole.isPassed())   //������ǹ���
		{
			mciSendString("stop music_bg", NULL, 0, NULL);
			if (world == 3)//�������ͨ��
			{
				mciSendString("play music_win from 0", NULL, 0, NULL);
				Sleep(2500);
				mciSendString("play music_passedAll from 0", NULL, 0, NULL);
				myCtrl.showPassedAll(); //չ��������
				life = LIFE; //���³�ʼ����������
				world = 1; //��ʼ���ؿ�
				myRole = role(world);
				myScene = scene(world);
				myCtrl.gameStart();
				mciSendString("play music_bg from 0", NULL, 0, NULL);
			}
			else
			{
				mciSendString("play music_win from 0", NULL, 0, NULL);
				Sleep(2500);
				world++; //ͨ�أ�ȫ�ֱ����ؿ�+1
				myCtrl.showPassed(world); // չ�ֻ�ӵ�м�������
				myRole = role(world); // ������һ�صĽ�ɫ
				myScene = scene(world); //������һ�صĹؿ�
				mciSendString("play music_bg from 0", NULL, 0, NULL);
			}
		}


		//��ʾ����
		BeginBatchDraw(); //������ͼ���濪����
		myScene.show();
		myRole.show();
		myCtrl.showScore(myRole.getScore());
		myCtrl.showLevel(world);
		EndBatchDraw(); //������ͼ�������ڻ�ͼ���д�ӡ������ͼ

		//�ӳ� ���ڿ��������˶�(��ֹ�����˶�ʧ��)
		Sleep((int)(TIME * 800));
	}
	mciSendString("clase all", NULL, 0, NULL);//�ر����ж�ý�������ļ�
	closegraph(); // graphics��ͼ����,��initgraph�������׳���
	return 0;
}