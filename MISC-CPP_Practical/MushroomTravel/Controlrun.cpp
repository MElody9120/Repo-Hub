#include "Control.h"
#include <conio.h>
#include "Mydefine.h"
#include<graphics.h>
#include<cstdlib>
control::control()
{
	key = 0;
}
control::~control()
{
}
int control::getKey()
{
	if (kbhit()) //kbhit()�����ж��Ƿ��м�������
	{
		key = GetCommand();
	}
	if (key & CMD_ESC)//���������ͣ��
	{
		pauseClick();//��ͣ��Ϸ 
	}
	return key;
}
int control::GetCommand()
{
	int c = 0;
	if (GetAsyncKeyState(0X25)) //���������ֵ����м��̶������ 16���Ʊ�ʾ
	{
		c = CMD_LEFT;
	}
	if (GetAsyncKeyState(0X27))
	{
		c |= CMD_RIGHT;
	}
	if (GetAsyncKeyState(0X26))
	{
		c |= CMD_UP;
	}
	if (GetAsyncKeyState(0X28))
	{
		c |= CMD_DOWN;
	}
	if (GetAsyncKeyState(0X1B))
	{
		c |= CMD_ESC;
	}
	return c;
}

//��ͣ�����ͼ����ʾ
void control::pauseClick()
{
	BeginBatchDraw();
	POINT points[8] = { { XSIZE / 2 - 45,YSIZE / 3 },{ XSIZE / 2 + 45,YSIZE / 3 },{ XSIZE / 2 + 45,YSIZE / 3 + 90 },{ XSIZE / 2 - 45,YSIZE / 3 + 90 } };
	setfillcolor(GREEN);
	fillpolygon(points, 4);
	setbkmode(TRANSPARENT);
	settextstyle(20, 0, "��Բ�Ӵ�");
	RECT r2 = { XSIZE / 2 - 45,YSIZE / 3,XSIZE / 2 + 45,YSIZE / 3 + 30 }; rectangle(XSIZE / 2 - 45, YSIZE / 3, XSIZE / 2 + 45, YSIZE / 3 + 30);
	drawtext("��ʼ", &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r3 = { XSIZE / 2 - 45,YSIZE / 3 + 30,XSIZE / 2 + 45,YSIZE / 3 + 60 }; rectangle(XSIZE / 2 - 45, YSIZE / 3 + 30, XSIZE / 2 + 45, YSIZE / 3 + 60);
	drawtext("����", &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r4 = { XSIZE / 2 - 45,YSIZE / 3 + 60,XSIZE / 2 + 45,YSIZE / 3 + 90 }; rectangle(XSIZE / 2 - 45, YSIZE / 3 + 60, XSIZE / 2 + 45, YSIZE / 3 + 90);
	drawtext("�ص����˵�", &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	FlushBatchDraw();
	FlushMouseMsgBuffer();//��������Ϣ���У���������(PYȺ��dalao֪����껺��������ȡ63�������Ϣ����������򲻻������ȡ
	while (true)
	{
		BeginBatchDraw();
		MOUSEMSG m = GetMouseMsg();//��׽��ꡣEasyX�⺯��
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			EndBatchDraw();
			if (m.x>XSIZE / 2 - 45 && m.x<XSIZE / 2 + 45 && m.y>YSIZE / 3 && m.y<YSIZE / 3 + 30)//���ѡ�񡰻ص���Ϸ�����򷵻�VIR_RETURN
			{
				key = VIR_RETURN;
				return;
			}
			else if (m.x>XSIZE / 2 - 45 && m.x<XSIZE / 2 + 45 && m.y>YSIZE / 3 + 30 && m.y<YSIZE / 3 + 60)//���ѡ�����¿�ʼ�����򷵻�VIR_RESTART
			{
				key = VIR_RESTART;
				return;
			}
			else if (m.x>XSIZE / 2 - 45 && m.x<XSIZE / 2 + 45 && m.y>YSIZE / 3 + 60 && m.y<YSIZE / 3 + 90)//���ѡ�����˵������򷵻�VIR_HOME
			{
				key = VIR_HOME;
				return;
			}
		case WM_MOUSEMOVE:
			RECT r;
			int i;
			for (i = 0; i<3; i++)
			{
				if (m.x>XSIZE / 2 - 45 && m.x<XSIZE / 2 + 45 && m.y>YSIZE / 3 + i * 30 && m.y<YSIZE / 3 + 30 + i * 30)
				{
					r.left = XSIZE / 2 - 45;
					r.top = YSIZE / 3 + i * 30;
					r.right = XSIZE / 2 + 45;
					r.bottom = YSIZE / 3 + 30 + i * 30;
					POINT points[8] = { { r.left,r.top },{ r.right,r.top },{ r.right,r.bottom },{ r.left,r.bottom } };
					setfillcolor(RED);
					fillpolygon(points, 4);
					setbkmode(TRANSPARENT);
					switch (i)
					{
					case 0:
						drawtext("��ʼ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						break;
					case 1:
						drawtext("����", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						break;
					case 2:
						drawtext("�ص����˵�", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						break;
					}
				}
				else
				{
					if (getpixel(XSIZE / 2 - 45 + 1, YSIZE / 3 + i * 30 + 1) == RED)
					{
						r.left = XSIZE / 2 - 45;
						r.top = YSIZE / 3 + i * 30;
						r.right = XSIZE / 2 + 45;
						r.bottom = YSIZE / 3 + 30 + i * 30;
						POINT points[8] = { { r.left,r.top },{ r.right,r.top },{ r.right,r.bottom },{ r.left,r.bottom } };
						setfillcolor(GREEN);
						fillpolygon(points, 4);
						setbkmode(TRANSPARENT);
						switch (i)
						{
						case 0:
							drawtext("��ʼ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
							break;
						case 1:
							drawtext("����", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
							break;
						case 2:
							drawtext("�ص����˵�", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
							break;
						}
					}
					FlushBatchDraw();
				}
			}
		}
	}
}

//��Ϸ��ʼ�����ͼ����ʾ
void control::gameStart()
{
	cleardevice();

	//Menu�˵��ı���ͼ
	IMAGE img1;
	loadimage(&img1, "res\\Menu_bg.bmp", XSIZE, 5 * YSIZE);
	putimage(0, -YSIZE, &img1);
    
	//Menu�˵����ݵĹ���
	settextstyle(40, 0, "��Բ�Ӵ�");
	RECT r1 = { 0, 0, XSIZE, YSIZE / 3 };
	drawtext("Ģ��������", &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(20, 0, "��Բ�Ӵ�");
	RECT r2 = { XSIZE / 2 - 45,YSIZE / 3,XSIZE / 2 + 45,YSIZE / 3 + 30 }; rectangle(XSIZE / 2 - 45, YSIZE / 3, XSIZE / 2 + 45, YSIZE / 3 + 30);
	drawtext("��ʼ", &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r3 = { XSIZE / 2 - 45,YSIZE / 3 + 30,XSIZE / 2 + 45,YSIZE / 3 + 60 }; rectangle(XSIZE / 2 - 45, YSIZE / 3 + 30, XSIZE / 2 + 45, YSIZE / 3 + 60);
	drawtext("����", &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r4 = { XSIZE / 2 - 45,YSIZE / 3 + 60,XSIZE / 2 + 45,YSIZE / 3 + 90 }; rectangle(XSIZE / 2 - 45, YSIZE / 3 + 60, XSIZE / 2 + 45, YSIZE / 3 + 90);
	drawtext("����", &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r5 = { XSIZE / 2 - 45,YSIZE / 3 + 90,XSIZE / 2 + 45,YSIZE / 3 + 120 }; rectangle(XSIZE / 2 - 45, YSIZE / 3 + 90, XSIZE / 2 + 45, YSIZE / 3 + 120);
	drawtext("�˳�", &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	bool HOME = true, INTRODUCTION = false, OPERATION = false;//true��ʾ���ڵ�ǰҳ��
	// �ֱ��ʾ ������ ���ܽ��� �������ܽ���

	MOUSEMSG m; //easyX�����Դ��Ĳ�׽��꺯��
	while (HOME) //������������
	{
		BeginBatchDraw();
		m = GetMouseMsg(); // m Ϊ��겶׽�����ķ���ֵ
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			EndBatchDraw();
			if (m.x>XSIZE / 2 - 45 && m.x<XSIZE / 2 + 45 && m.y>YSIZE / 3 && m.y<YSIZE / 3 + 30 && HOME == 1 && INTRODUCTION == 0 && OPERATION == 0)//���ѡ�񡰿�ʼ��Ϸ��
			{
				HOME = false;
				break;
			}
			else if (m.x>XSIZE / 2 - 45 && m.x<XSIZE / 2 + 45 && m.y>YSIZE / 3 + 30 && m.y<YSIZE / 3 + 60 && HOME == 1 && OPERATION == 0)//���ѡ����Ϸ���ܡ�
			{
				INTRODUCTION = true;
				cleardevice();
				rectangle(50, 50, 213, 220);
				outtextxy(52, 52, "���ܣ�");
				outtextxy(52, 82, "Ģ��������");
				outtextxy(52, 132, "������");
				outtextxy(52, 152, "Melody && Minnie");
				RECT R1 = { XSIZE - 46,YSIZE - 26,XSIZE - 2,YSIZE - 2 }; rectangle(XSIZE - 46, YSIZE - 26, XSIZE - 2, YSIZE - 2);
				drawtext("����", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				break;
			}
			else if (m.x>XSIZE / 2 - 45 && m.x<XSIZE / 2 + 45 && m.y>YSIZE / 3 + 60 && m.y<YSIZE / 3 + 90 && HOME == 1 && INTRODUCTION == 0)//���ѡ�񡰲���˵����
			{
				OPERATION = true;
				cleardevice();
				rectangle(50, 50, 213, 220);
				outtextxy(52, 52, "������");
				outtextxy(52, 72, "�� ����");
				outtextxy(52, 92, "�ң�����");
				outtextxy(52, 112, "���� ����");
				outtextxy(52, 152, "��ͣ��Esc��");
				RECT R2 = { XSIZE - 46,YSIZE - 26,XSIZE - 2,YSIZE - 2 }; rectangle(XSIZE - 46, YSIZE - 26, XSIZE - 2, YSIZE - 2);
				drawtext("����", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				break;
			}
			else if (m.x > XSIZE / 2 - 45 && m.x<XSIZE / 2 + 45 && m.y>YSIZE / 3 + 90 && m.y < YSIZE / 3 + 120 && HOME == 1 && INTRODUCTION == 0 && OPERATION == 0)//���ѡ���˳���Ϸ��
			{
				exit(0); //�˳���Ϸ
			}
			else if (m.x>XSIZE - 46 && m.x<XSIZE - 3 && m.y>YSIZE - 26 && m.y<YSIZE - 3 && (INTRODUCTION == 1 || OPERATION == 1))//���ѡ�񡰷��ء�
			{
				cleardevice(); //����������������Ļ���ݡ��������ݲ鿴easyX�⺯������
				HOME = false, INTRODUCTION = false, OPERATION = false;
				gameStart();
			}
			else
			{
				break;
			}
		case WM_MOUSEMOVE: //����ƶ���Ϣ��easyX���Դ�
			RECT r;
			if (INTRODUCTION == 1 || OPERATION == 1)
			{
				if (m.x>XSIZE - 46 && m.x<XSIZE - 3 && m.y>YSIZE - 26 && m.y<YSIZE - 3)
				{
					r.left = XSIZE - 46;
					r.top = YSIZE - 26;
					r.right = XSIZE - 2;
					r.bottom = YSIZE - 2;
					POINT points[8] = { { r.left,r.top },{ r.right,r.top },{ r.right,r.bottom },{ r.left,r.bottom } };
					setfillcolor(RED);
					fillpolygon(points, 4);
					setbkmode(TRANSPARENT);
					drawtext("����", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}
				else
				{
					if (getpixel(XSIZE - 46 + 1, YSIZE - 26 + 1) == RED)
					{
						r.left = XSIZE - 46;
						r.top = YSIZE - 26;
						r.right = XSIZE - 2;
						r.bottom = YSIZE - 2;
						POINT points[8] = { { r.left,r.top },{ r.right,r.top },{ r.right,r.bottom },{ r.left,r.bottom } };
						setfillcolor(BLACK);
						fillpolygon(points, 4);
						setbkmode(TRANSPARENT);
						drawtext("����", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					}
				}
			}
			else
			{
				for (int i = 0; i<4; i++)
				{
					if (m.x>XSIZE / 2 - 45 && m.x<XSIZE / 2 + 45 && m.y>YSIZE / 3 + i * 30 && m.y<YSIZE / 3 + 30 + i * 30)
					{
						r.left = XSIZE / 2 - 45;
						r.top = YSIZE / 3 + i * 30;
						r.right = XSIZE / 2 + 45;
						r.bottom = YSIZE / 3 + 30 + i * 30;
						POINT points[8] = { { r.left,r.top },{ r.right,r.top },{ r.right,r.bottom },{ r.left,r.bottom } };
						setfillcolor(RED);
						fillpolygon(points, 4);
						setbkmode(TRANSPARENT);
						switch (i)
						{
						case 0:
							drawtext("��ʼ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
							break;
						case 1:
							drawtext("����", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
							break;
						case 2:
							drawtext("����", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
							break;
						case 3:
							drawtext("�˳�", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
							break;
						}
					}
					else
					{
						if (getpixel(XSIZE / 2 - 45 + 1, YSIZE / 3 + i * 30 + 1) == RED)//����������ڻ�ȡ�����ɫ.easyX��
						{
							r.left = XSIZE / 2 - 45;
							r.top = YSIZE / 3 + i * 30;
							r.right = XSIZE / 2 + 45;
							r.bottom = YSIZE / 3 + 30 + i * 30;
							POINT points[4] = { { r.left,r.top },{ r.right,r.top },{ r.right,r.bottom },{ r.left,r.bottom } };
							setfillcolor(BLACK);
							fillpolygon(points, 4);
							setbkmode(TRANSPARENT);
							switch (i)
							{
							case 0:
								drawtext("��ʼ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
								break;
							case 1:
								drawtext("����", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
								break;
							case 2:
								drawtext("����", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
								break;
							case 3:
								drawtext("�˳�", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
								break;
							}
						}
					}
				}
			}
			FlushBatchDraw();
			break;
		default:
			break;
		}
	}
}
void control::showScore(int score)
{
	settextstyle(0, 0, "����");
	char s1[20] = "����:  ";
	char s2[5];
	itoa(score, s2, 10);//��� outtextxy �ĺ���ԭ�� ��ֻ�����ַ���
	strcat(s1, s2);
	setbkmode(TRANSPARENT);
	outtextxy(10, 10, s1);
	setbkmode(OPAQUE);
}

void control::showLevel(int level)
{
	settextstyle(0, 0, "����");
	char s1[20] = "�ؿ�:  ";
	char s2[2];
	itoa(level, s2, 10);//��� outtextxy �ĺ���ԭ�� ��ֻ�����ַ���
	strcat(s1, s2);
	setbkmode(TRANSPARENT);
	outtextxy(XSIZE - 100, 10, s1);
	setbkmode(OPAQUE);
}

void control::showDied(int life)
{
	cleardevice();
	char s1[20] = "�����������:  ";
	char s2[2];
	itoa(life, s2, 10);//��� outtextxy �ĺ���ԭ�� ��ֻ�����ַ���
	outtextxy(XSIZE / 2 - 63, YSIZE / 3, s1);
	outtextxy(XSIZE / 2-10, YSIZE / 2 - 20, s2);
	Sleep(2000);
}

void control::showGameOver()
{
	IMAGE img;
	loadimage(&img, "res\\home.bmp", XSIZE, 5 * YSIZE);
	putimage(0, -YSIZE, &img);
	Sleep(6500);
}

void control::showPassed(int world)
{
	cleardevice();
	char s1[20] = "�ؿ�:  ";
	char s2[2];
	itoa(world, s2, 10);//��� outtextxy �ĺ���ԭ�� ��ֻ�����ַ���
	outtextxy(XSIZE / 2 - 20, YSIZE / 3, s1);
	outtextxy(XSIZE / 2, YSIZE / 2 - 10, s2);
	Sleep(2000);
}

void control::showPassedAll()
{
	IMAGE img;
	loadimage(&img, "res\\home.bmp", XSIZE, 5 * YSIZE);
	putimage(0, -3 * YSIZE, &img);
	Sleep(7800);
}