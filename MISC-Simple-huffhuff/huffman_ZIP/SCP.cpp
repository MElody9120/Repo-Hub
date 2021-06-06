/**
** ����ѹ������ 
**/

#include <iostream>
#include <stdio.h> 

#include "SuperCompress.h" 

using namespace std;

void compress(){
	
	HuffNode nodes[512];
	
	long flength;
	char filename[255];
	char distfilename[255];
	int n;

	// ��ʼ��
	for(int i=0;i<512;i++){
		nodes[i].bits[0] = 0;
		nodes[i].ch = 0;
		nodes[i].count = 0;
		nodes[i].lch = 0;
		nodes[i].rch = 0;
		nodes[i].parent = 0;
	}
	
	//��ȡ�ļ�·��
	cout<<endl<<"��������Ҫѹ�����ļ���: "<<endl;
	gets(filename);
	
	count_file(nodes,filename,flength);
	creat_hmtree(nodes,n);
	creat_hmcode(nodes,n);
	
	cout<<endl<<"������ѹ������ļ���: "<<endl;
	gets(distfilename);
	
	compress(nodes,n,filename,distfilename,flength);
	
}

int main(){
	
	int choice;
	
	//�˵�������
	while (1)
	{
		printf("\t_________________________________________________________\n");
		printf("\n");
		printf("\t                  *  ѹ������ѹ�� С����  *\n");
		printf("\t_________________________________________________________\n");
		printf("\t_________________________________________________________\n");
		printf("\t|\t\t\t\t\t\t\t|\n");
		printf("\t|1.ѹ��\t\t\t\t\t\t\t|\n");
		printf("\t|2.��ѹ��\t\t\t\t\t\t|\n");
		printf("\t|0.�˳�\t\t\t\t\t\t\t|\n");
		printf("\t|_______________________________________________________|\n");
		printf("\n");
		printf("\n");
		
		//���û���������ݴ���
		do
		{
			printf("\n\t��ѡ����Ӧ����(0-2):");
			choice = getchar();
			
			getchar(); // ����س��ַ� 
						
			if (choice != '0'&&choice != '1'&&choice != '2')
			{
				printf("\t@_@�����������������0-2֮�䣡\n");
				printf("\t��������һ�飡\n");
			}
			
		} while (choice != '0'&&choice != '1'&&choice != '2');
		
		if (choice == '1')
		{
			compress();
		}
		else if (choice == '2')
		{
			uncompress();
		}
		else
		{
			printf("\t��ӭ���ٴ�ʹ�øù���^-^\n");
			exit(0);//�˳��ù���
		}
		
		system("pause");
		system("cls");//����
	}
	
	return 0;
}
