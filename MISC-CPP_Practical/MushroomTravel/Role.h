#pragma once
#include<graphics.h>
#include "MyMap.h"
#include"Mydefine.h"
#include"Enemy.h"

const int ENEMY_TOTE = 30; //��������
const int BOMB_NUMBER = 5; 

class scene;

struct Hero
{
	int x;//���ǵĵ�ǰ���꣨����Ļ�ϵ����꣩
	int y;
	double xx;//���ǵ����꣨double�ͣ�
	double yy;
	double x0;//ԭ������
	double vX;//�ٶ�
	double vY;
	int turn;//�����˶��ķ���
	POINT direction; //��������ķ���
	bool isFly;//�����Ƿ��ڿ���
	bool died;//�����Ƿ�����
	bool ending;//�����Ƿ����Ͼ�Ҫ����
	bool passed;//�����Ƿ����
};

class role
{
private:
	int world;
	int KEY;
	scene *myScene; //������ͼ
	Hero myHero;//����һ������
	Enemy myEnemy[ENEMY_TOTE];//�������ɵ���
	POINT bombs[BOMB_NUMBER];//�������ɱ�ը��
	IMAGE img_hero; // ����ͼ�����
	IMAGE img_enemy;
	IMAGE img_showBomb;
	int hero_iframe;//���ڿ������ǡ����˺ͱ�ը�ļ���֡�����صڼ���ͼ����֡�����п�����ͼƬ��ˢ�´�ɶ�̬��ʾ��
	double enemy_iframe;
	double bomb_iframe[BOMB_NUMBER];
	int score;//����չʾ
	MyMap *touchMap(int x, int y, scene *myScene);//���ڱ�ʾ�����Ƿ�Ӵ���ͼ��Ե���ж��ƶ���������Ҫ����
	POINT *touchCoins(int x, int y, scene *myScene);//���ڱ�ʾ�����Ƿ�Ե����
	Enemy *touchEnemy(int x, int y, Enemy *emy);//���ڱ�ʾ�����Ƿ�Ӵ�����
	bool isTouch(POINT *p1, POINT *p2);//�����ж������Ƿ��ڵ�ͼ��(�����ж�����������������ж��йؼ�����
	void setBomb(int x, int y);//����չʾ��ըЧ��
public:
	role(int world);
	~role() {};
	Hero *getHero()  //����������Ϣ(ָ��󷨺�
	{ 
		return &myHero;
	}
	bool isDied()
	{ 
		return myHero.died;
	}
	bool isPassed() 
	{ 
		return myHero.passed;
	}
	void createEnemy(int world);
	void show(); //���ڿ��������֡��������ﶯ̬Ч��
	void action(int KEY, scene *myScene); //���ڷ�Ӧ����Ķ�����Ϊ
	int getScore() 
	{
		return score;
	}
};


//�˴�inline�÷�������Ϊ ��C++17 �Ժ� inline ��	inline����ӵ��һ�����ԣ������ڳ�����ӵ�ж���һ�ζ��壬ֻҪÿ����������ڲ�ͬ�ı��뵥Ԫ��
//���ڷ� static inline �����ͱ��� (C++17 ��)�������ж����ͬ
//ʹ��inline���Է�ֹ�ڼ�������ʵ�ֵ�ͷ�ļ�֮���໥���������µı������������⣬��α���inline�����޹�

/*
#include "Role.h"
#include<graphics.h>
#include"Mydefine.h"
#include<math.h>
#include"Rule.h"
#include<conio.h>
#include"Enemy.h"
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")   //����Ϸ�������Ҫ�õ���



inline role::role(int world)
{
	//����Ϊ��ɫ����
	myHero.x = X0; //���ú궨�峣�����г�ʼ
	myHero.y = X0;
	myHero.xx = myHero.x; //�������ǵ�ǰ�����λ��(��ʼ����λ��
	myHero.yy = myHero.y;
	myHero.x0 = 0; //���������Ϣ��ʼ��
	myHero.vX = 0;
	myHero.vY = 0;
	myHero.turn = 1; //���ǵ��˶�����Ϊ����
	myHero.direction.x = 0; //��������ķ���
	myHero.direction.y = 0;
	myHero.isFly = true; //bool�ͱ����ܺõķ�Ӧ�����ﵱǰ��״̬
	myHero.died = false;
	myHero.ending = false;
	myHero.passed = false;

	//�������ڶ���չʾ�Լ���������չʾ
	hero_iframe = 1; //���ڿ������Ǵ�ͼƬ��֡��
	enemy_iframe = 1;
	score = 0;
	loadimage(&img_hero, "res\\role.bmp");
	loadimage(&img_enemy, "res\\ani.bmp");
	loadimage(&img_showBomb, "res\\ani.bmp");

	for (int i = 0; i<ENEMY_TOTE; i++)
	{
		myEnemy[i].x = 0;
		myEnemy[i].y = 0;
		myEnemy[i].turn = 0;
	}
	for (int j = 0; j<BOMB_NUMBER; j++)
	{
		bombs[j].x = 0;
		bombs[j].y = 0;
		bomb_iframe[j] = 0;
	}


	createEnemy(world); //��������,��������

	mciSendString("open res\\����.mp3 alias music_died", NULL, 0, NULL);
	mciSendString("open res\\��.mp3 alias music_jump", NULL, 0, NULL);
	mciSendString("open res\\���.mp3 alias music_coin", NULL, 0, NULL);
	mciSendString("open res\\�ȵ���.mp3 alias music_tread", NULL, 0, NULL);
}


//������Ϊ��������
inline void role::createEnemy(int world)
{
	if (world == 1)
	{
		Enemy emy[] = { { 3,8,1 },{ 18,7,-1 },{ 25,7,1 },{ 28,8,-1 },{ 33,8,-1 },{ 39,8,1 },{ 68,3,1 },{ 66,8,-1 },{ 81,6,1 },{ 92,6,1 } };
		//�������˵����� ��һ��������Ϊ���˵�����,����������Ϊ���˵��˶�����
		int i = 0;
		//����������ĵ��˴��ݸ�myEnemy������ɿ��Ƶ��˵ľ�����Ϊ�Լ���̬չʾ
		while (i <= sizeof(emy) / sizeof(emy[0]))
		{
			myEnemy[i].x = emy[i].x*WIDTH;//�����ص���д���
			myEnemy[i].y = emy[i].y*HEIGHT;
			myEnemy[i].turn = emy[i].turn;
			i++;
		}
	}
	else if (world == 2)
	{
		Enemy emy[] = { { 18,8,1 },{ 24,5,1 },{ 28,5,-1 },{ 44,9,1 },{ 99,4,1 },{ 99,8,1 } };
		int i = 0;
		while (i <= sizeof(emy) / sizeof(emy[0]))
		{
			myEnemy[i].x = emy[i].x*WIDTH;
			myEnemy[i].y = emy[i].y*HEIGHT;
			myEnemy[i].turn = emy[i].turn;
			i++;
		}
	}
	else if (world == 3)
	{
		Enemy emy[] = { { 25,3,-1 },{ 31,3,1 },{ 39,3,-1 },{ 50,3,-1 },{ 68,3,1 },{ 66,8,-1 },{ 86,8,1 } };
		int i = 0;
		while (i <= sizeof(emy) / sizeof(emy[0]))
		{
			myEnemy[i].x = emy[i].x*WIDTH;
			myEnemy[i].y = emy[i].y*HEIGHT;
			myEnemy[i].turn = emy[i].turn;
			i++;
		}
	}
}

//�������ñ�ըЧ��
inline void role::setBomb(int x, int y)
{
	for (int i = 0; i<BOMB_NUMBER; i++)
	{
		if (bombs[i].x == 0 && bombs[i].y == 0)
		{
			bombs[i].x = x;
			bombs[i].y = y;
			bomb_iframe[i] = 1;
			break;
		}
	}
}

//�����ж������Ƿ��ڵ�ͼ��(�����ж�����������������ж��йؼ�����
inline bool role::isTouch(POINT *p1, POINT *p2)
{
	for (int i = 0; i<4; i++)//�������4��������һ�������ڵ�ͼ�ڣ����ж�Ϊ�Ӵ�����ͼ
	{
		if (p1[i].x >= p2[0].x && p1[i].y >= p2[0].y && p1[i].x <= p2[1].x  &&  p1[i].y <= p2[1].y)
		{
			return true;
		}
	}
	return false;
}



//����˼·���ж����ǵ��ĸ�����(�����ص��λ�ý����ж�)
//�Ƿ�������һ���ڵ�ͼ�ڣ��У����ж�Ϊ������ײ����ͼ
inline MyMap *role::touchMap(int x, int y, scene *myScene)
{
	int xmap = (int)myHero.x0;
	POINT r[4];//����4����������꣨������СһȦ��
	r[0].x = -xmap + x + 1;
	r[0].y = y + 1;
	r[1].x = -xmap + x + WIDTH - 1;
	r[1].y = y + 1;
	r[2].x = -xmap + x + 1;
	r[2].y = y + HEIGHT - 1;
	r[3].x = -xmap + x + WIDTH - 1;
	r[3].y = y + HEIGHT - 1;


	//��getMap�ķ���ֵ�����жϵ�ͼ���
	int i = 0;
	while (myScene->getMap()[i].id>0 && myScene->getMap()[i].id<11 && i<MAP_NUMBER)//��������ͼ������Ϊǰ10�ֵ�ͼ
	{
		POINT m[2];//��ͼ���ϽǶ�������½Ƕ��������

		m[0].x = myScene->getMap()[i].x*WIDTH;
		m[0].y = myScene->getMap()[i].y*HEIGHT;

		//��id��Ϊ��ͼ��֮������֣�id Ϊ��ͼ���ģ��ͼ
		if (myScene->getMap()[i].id == 10)//idΪ10�ĵ�ͼҪ��Щ
		{
			m[1].x = myScene->getMap()[i].x*WIDTH + myScene->getMap()[i].xAmount * 2 * WIDTH;
			m[1].y = myScene->getMap()[i].y*HEIGHT + myScene->getMap()[i].yAmount * 2 * HEIGHT;
		}
		else
		{
			m[1].x = myScene->getMap()[i].x*WIDTH + myScene->getMap()[i].xAmount*WIDTH;
			m[1].y = myScene->getMap()[i].y*HEIGHT + myScene->getMap()[i].yAmount*HEIGHT;
		}
		if (isTouch(r, m))//������������ཻ������ײ
		{
			return &(myScene->getMap()[i]);
		}
		i++;
	}
	return NULL;
}
inline POINT *role::touchCoins(int x, int y, scene *myScene)
{
	//����˼·���ж����ǵ��ĸ������Ƿ�������һ����Ӳ���ڣ��У����ж�Ϊ�������Ե�Ӳ��
	int xmap = (int)myHero.x0;
	POINT r[4];//����4����������꣨������СһȦ��
	r[0].x = -xmap + x + 1;
	r[0].y = y + 1;
	r[1].x = -xmap + x + WIDTH - 1;
	r[1].y = y + 1;
	r[2].x = -xmap + x + 1;
	r[2].y = y + HEIGHT - 1;
	r[3].x = -xmap + x + WIDTH - 1;
	r[3].y = y + HEIGHT - 1;
	int i = 0;
	while (i<COINS_NUMBER)
	{
		POINT m[2];//Ӳ�����ϽǶ�������½Ƕ��������

		m[0].x = myScene->getCoins()[i].x*WIDTH;
		m[0].y = myScene->getCoins()[i].y*HEIGHT;
		m[1].x = m[0].x + WIDTH;
		m[1].y = m[0].y + HEIGHT;
		if (isTouch(r, m))//������������ཻ������ײ
			return &(myScene->getCoins()[i]);
		i++;
	}
	return NULL;
}


//���������жϽ�ɫ�ȹֵ����
inline Enemy *role::touchEnemy(int x, int y, Enemy *emy)
{
	//����˼·���ж����ǵ��ĸ������Ƿ�������һ���ڵ�ͼ�ڣ��У����ж�Ϊ������ײ������
	int xmap = (int)myHero.x0;
	POINT r[4];//����4����������꣨������СһȦ��
	r[0].x = -xmap + x + 1;
	r[0].y = y + 1;
	r[1].x = -xmap + x + WIDTH - 1;
	r[1].y = y + 1;
	r[2].x = -xmap + x + 1;
	r[2].y = y + HEIGHT - 1;
	r[3].x = -xmap + x + WIDTH - 1;
	r[3].y = y + HEIGHT - 1;
	int i = 0;
	while (i<ENEMY_TOTE)//���������ڵ���
	{
		if (emy[i].turn != 0)
		{
			POINT m[2];//�������ϽǶ�������½Ƕ��������
			m[0].x = emy[i].x;
			m[0].y = emy[i].y;
			m[1].x = m[0].x + WIDTH;
			m[1].y = m[0].y + HEIGHT;
			if (isTouch(r, m))//������������ཻ������ײ
			{
				return &emy[i];
			}
		}
		i++;
	}
	return NULL;
}


//�����������ͼƬ�Ķ�̬��ʾ
inline void role::show()
{
	//����������ڿ������ǵĲ�����ʹ���Ǹ��˵ĸо���������·
	//�ı����Ǽ���ͼƬ�ĵڼ�֡
	int rolePos = -(int)myHero.x0 + myHero.x;//���ǵ�λ��
	if (rolePos / STEP % 2 == 0 && rolePos / STEP % 4 != 0)
	{
		hero_iframe = 2;
	}
	else if (rolePos / STEP % 4 == 0)
	{
		hero_iframe = 1;
	}


	//�������ǵķ���
	if (myHero.direction.x == 1)
	{
		myHero.turn = 1;
	}
	else if (myHero.direction.x == -1)
	{
		myHero.turn = -1;
	}
	if (myHero.died == true)
	{
		putimage(myHero.x, myHero.y, WIDTH, HEIGHT, &img_hero, 2 * WIDTH, HEIGHT, SRCAND);
		putimage(myHero.x, myHero.y, WIDTH, HEIGHT, &img_hero, 2 * WIDTH, 0, SRCPAINT);
		//���� SRCAND SRCPAINT ��Ϊ��Ԫ��դ�����룬����μ�easyX�⺯�������ĵ�
	}
	else
	{
		if (myHero.turn == 1)
		{
			putimage(myHero.x, myHero.y, WIDTH, HEIGHT, &img_hero, (hero_iframe - 1)*WIDTH, HEIGHT, SRCAND);
			putimage(myHero.x, myHero.y, WIDTH, HEIGHT, &img_hero, (hero_iframe - 1)*WIDTH, 0, SRCPAINT);
			//���� SRCAND SRCPAINT ��Ϊ��Ԫ��դ�����룬����μ�easyX�⺯�������ĵ�
		}
		else
		{
			putimage(myHero.x, myHero.y, WIDTH, HEIGHT, &img_hero, (hero_iframe - 1)*WIDTH + 3 * WIDTH, HEIGHT, SRCAND);
			putimage(myHero.x, myHero.y, WIDTH, HEIGHT, &img_hero, (hero_iframe - 1)*WIDTH + 3 * WIDTH, 0, SRCPAINT);
			//���� SRCAND SRCPAINT ��Ϊ��Ԫ��դ�����룬����μ�easyX�⺯�������ĵ�
		}
	}
	//����������ڿ��Ƶ��˵Ĳ�����ʹ���˸��˵ĸо���������·
	//�ı���˼���ͼƬ�ĵڼ�֡
	enemy_iframe += TIME * 5;
	if ((int)enemy_iframe == 3)
	{
		enemy_iframe = 1;
	}
	int i = 0;
	while (i<ENEMY_TOTE)
	{
		if (myEnemy[i].turn != 0)
		{
			putimage((int)myHero.x0 + myEnemy[i].x, myEnemy[i].y, WIDTH, HEIGHT, &img_enemy, ((int)enemy_iframe - 1)*WIDTH, HEIGHT, SRCAND);
			putimage((int)myHero.x0 + myEnemy[i].x, myEnemy[i].y, WIDTH, HEIGHT, &img_enemy, ((int)enemy_iframe - 1)*WIDTH, 0, SRCPAINT);
			//���� SRCAND SRCPAINT ��Ϊ��Ԫ��դ�����룬����μ�easyX�⺯�������ĵ�
		}
		i++;
	}

	//����������ڿ��Ʊ�ըЧ��
	for (int j = 0; j<BOMB_NUMBER; j++)
	{
		if (bombs[j].x != 0 && bombs[j].y != 0)
		{
			bomb_iframe[j] += TIME * 10;
			if ((int)bomb_iframe[j] == 5)
			{
				bomb_iframe[j] = 1;
				bombs[j].x = 0;
				bombs[j].y = 0;
			}
			else
			{
				putimage((int)myHero.x0 + bombs[j].x - WIDTH / 2, bombs[j].y - HEIGHT / 2, 2 * WIDTH, 2 * HEIGHT, &img_showBomb, ((int)bomb_iframe[j] - 1) * 2 * WIDTH, 6 * HEIGHT, SRCAND);
				putimage((int)myHero.x0 + bombs[j].x - WIDTH / 2, bombs[j].y - HEIGHT / 2, 2 * WIDTH, 2 * HEIGHT, &img_showBomb, ((int)bomb_iframe[j] - 1) * 2 * WIDTH, 4 * HEIGHT, SRCPAINT);
				//���� SRCAND SRCPAINT ��Ϊ��Ԫ��դ�����룬����μ�easyX�⺯�������ĵ�
			}
		}
	}
}


//�������ڷ�Ӧ���̲������ͼԪ��֮�����ϵ
inline void role::action(int KEY, scene *myScene)
{
	myHero.direction.x = 0;//=0��ʾ���ǲ��������������
	myHero.direction.y = 0;
	double a = 0;//�����˶��ļ��ٶȺ�Ħ��������ļ��ٶ�
	double a1 = 0;
	MyMap *map = NULL;
	if ((KEY&CMD_UP) && myHero.isFly == false && myHero.ending == false)//ֻ�е�����û���ڿ���������û���ص�ʱ������������
	{
		mciSendString("play music_jump from 0", NULL, 0, NULL);
		myHero.isFly = true;//��ʾ�����ڿ���
		myHero.vY = -sqrt(2 * G*REAL_HEIGHT);
	}
	if (myHero.isFly == true)
	{
		myHero.yy = myHero.yy - (-rule::move(myHero.vY, TIME, G)*UNREAL_HEIGHT / REAL_HEIGHT);//move�������ص�λʱ�䣨T���ڣ������������½��ĸ߶�
		myHero.y = (int)myHero.yy;
		map = touchMap(myHero.x, myHero.y + 1, myScene);
		if (map != NULL)
		{
			if (myHero.vY > 0)//��ʾ�����ǽӴ�����ʱ
			{
				myHero.isFly = false;
			}
			myHero.vY = 0;
			myHero.y = (myHero.y + HEIGHT / 2) / HEIGHT * HEIGHT;//���á�+HEIGHT/2������ʾ���ǵ�����
			myHero.yy = myHero.y;
			myHero.direction.y += 1;
		}
		if (myHero.vY>0)
		{
			Enemy *emy = touchEnemy(myHero.x, myHero.y, myEnemy);
			if (emy != NULL)//������ǲȵ�����
			{
				mciSendString("play music_tread from 0", NULL, 0, NULL);
				score += 5;
				//���±�ը�������
				setBomb(emy->x, emy->y);
				emy->x = 0;
				emy->y = 0;
				emy->turn = 0;
			}
			if (myHero.y>YSIZE)
			{
				myHero.died = true; //��ɫ����
				mciSendString("play music_died from 0", NULL, 0, NULL);
			}
		}
	}
	else
	{
		map = touchMap(myHero.x, myHero.y + 1, myScene);
		if (map == NULL)//�������û��������ͼ�����ڿ���
		{
			myHero.isFly = true;
		}
	}
	if (KEY&CMD_DOWN)
	{
	}

	//�˶�״̬���ж�
	if (KEY&CMD_LEFT && myHero.ending == false)
	{
		a -= A_ROLE;
		myHero.direction.x -= 1;
	}
	if (KEY&CMD_RIGHT || myHero.ending == true)
	{
		a += A_ROLE;
		myHero.direction.x += 1;
	}

	//���´��봦������ˮƽ�����ϵ��˶�
	if (myHero.vX*a <= 0 && myHero.vX != 0)
	{
		int k = -(int)(myHero.vX / fabs(myHero.vX));//k������ٶȵķ���
		if (map == NULL)
		{
			a1 = 0;
		}
		else
		{
			a1 = k * G*map->u;//������ʽ��a=mg*u/g�ó�
		}
	}
	double tmp = myHero.vX;
	double H = rule::move(myHero.vX, TIME, a + a1)*UNREAL_HEIGHT / REAL_HEIGHT;
	if (tmp*myHero.vX < 0)
	{
		myHero.vX = 0;
	}
	myHero.xx = myHero.xx + H; //λ��
	myHero.x = (int)myHero.xx; //ʵ��λ��
	if (myScene->isEnding(-(int)myHero.x0 + myHero.x))//����������Ϲ���
	{
		myHero.ending = true;
	}
	if (myHero.x > XSIZE) //�����ﵽ��ͼ���Ҷ˵��ж��Ƿ�ͨ��
	{
		myHero.passed = true;
	}
	if (touchMap(myHero.x, myHero.y, myScene) != NULL)
	{
		if (myHero.x > XRIGHT) //����������������λ�õ�ͼ����ʾ
		{
			myHero.x = XRIGHT;
		}
		else
		{
			myHero.x = (int)(myHero.xx - H);
		}
		myHero.xx = myHero.x;
		myHero.vX = 0;
		a = 0;
		a1 = 0;
	}
	if (fabs(myHero.vX) > V_MAX)  //�����������ǵ�����ٶ�
	{
		myHero.vX = myHero.vX / fabs(myHero.vX)*V_MAX;
	}
	//�жϳ������Ƿ񳬳����ҽ���
	if (myHero.x<XLEFT)  //����������������λ�õ�ͼ����ʾ
	{
		myHero.x = XLEFT;
		myHero.xx = myHero.x;
		myHero.vX = 0;
		a = 0;
	}
	else if (myHero.x>XRIGHT && myHero.ending == false)
	{
		myHero.x0 -= (myHero.x - XRIGHT);
		myHero.x = XRIGHT;
		myHero.xx = myHero.x;
	}



	//���³�����Ƶ��˵��˶�
	int i = 0;
	if ((int)(enemy_iframe * 100) % 2 == 0)//���Ƶ����˶���ˢ��Ƶ��
	{
		while (i<ENEMY_TOTE)
		{
			if (myEnemy[i].turn != 0)
			{
				myEnemy[i].x += myEnemy[i].turn*ENEMY_STEP;
				int x1 = (int)myHero.x0 + myEnemy[i].x;
				int y1 = myEnemy[i].y;
				int x2 = (int)myHero.x0 + myEnemy[i].x + myEnemy[i].turn*WIDTH;
				int y2 = myEnemy[i].y + 1;
				if (touchMap(x1, y1, myScene) != NULL || touchMap(x2, y2, myScene) == NULL)//�����������ǽ�ڻ���û�в���½���ϣ���������෴�����˶�
				{
					myEnemy[i].turn *= -1;
				}
			}
			i++;
		}
	}



	//���´����ж������Ƿ�Ե���ң����Ե���ѽ�ҵ��������
	POINT *p = touchCoins(myHero.x, myHero.y, myScene);
	if (p != NULL)
	{
		mciSendString("play music_coin from 0", NULL, 0, NULL);
		score += 10;
		myScene->setScorePos(p->x, p->y); //���ý������
		p->x = 0; // �������(������˽�Һ��ҵ���ʧ
		p->y = 0;
	}


	//���´����ж������Ƿ�ײ������
	Enemy *emy = touchEnemy(myHero.x, myHero.y, myEnemy);
	if (emy != NULL && myHero.vY <= 0)//����������������ȵ�����
	{
		myHero.died = true;
		mciSendString("play music_died from 0", NULL, 0, NULL);
	}
}*/




