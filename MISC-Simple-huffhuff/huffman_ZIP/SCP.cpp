/**
** 超级压缩工具 
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

	// 初始化
	for(int i=0;i<512;i++){
		nodes[i].bits[0] = 0;
		nodes[i].ch = 0;
		nodes[i].count = 0;
		nodes[i].lch = 0;
		nodes[i].rch = 0;
		nodes[i].parent = 0;
	}
	
	//获取文件路径
	cout<<endl<<"请输入需要压缩的文件名: "<<endl;
	gets(filename);
	
	count_file(nodes,filename,flength);
	creat_hmtree(nodes,n);
	creat_hmcode(nodes,n);
	
	cout<<endl<<"请输入压缩后的文件名: "<<endl;
	gets(distfilename);
	
	compress(nodes,n,filename,distfilename,flength);
	
}

int main(){
	
	int choice;
	
	//菜单工具栏
	while (1)
	{
		printf("\t_________________________________________________________\n");
		printf("\n");
		printf("\t                  *  压缩、解压缩 小工具  *\n");
		printf("\t_________________________________________________________\n");
		printf("\t_________________________________________________________\n");
		printf("\t|\t\t\t\t\t\t\t|\n");
		printf("\t|1.压缩\t\t\t\t\t\t\t|\n");
		printf("\t|2.解压缩\t\t\t\t\t\t|\n");
		printf("\t|0.退出\t\t\t\t\t\t\t|\n");
		printf("\t|_______________________________________________________|\n");
		printf("\n");
		printf("\n");
		
		//对用户输入进行容错处理
		do
		{
			printf("\n\t请选择相应功能(0-2):");
			choice = getchar();
			
			getchar(); // 清除回车字符 
						
			if (choice != '0'&&choice != '1'&&choice != '2')
			{
				printf("\t@_@请检查您输入的数字在0-2之间！\n");
				printf("\t请再输入一遍！\n");
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
			printf("\t欢迎您再次使用该工具^-^\n");
			exit(0);//退出该工具
		}
		
		system("pause");
		system("cls");//清屏
	}
	
	return 0;
}
