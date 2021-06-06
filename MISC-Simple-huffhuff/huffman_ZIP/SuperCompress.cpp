#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SuperCompress.h" 

using namespace std;

// ͳ��Դ�ļ����ֽ�
void count_file(HuffNode nodes[], char filename[], long &flength){
	FILE *fp; 
	
	fp = fopen(filename, "rb");
	
	if (fp == NULL){
		cout<<endl<<"�ļ���ʧ��"<<endl<<endl;
		return;
	}
	
	unsigned char c;	//���ն�ȡ��һ���ֽ�
	flength = 0;		//�����ļ����ֽ���,��ʼΪ0
	
	while (!feof(fp))
	{
		//���ļ��ж�ȡһ���ֽڵ�c
		fread(&c, 1, 1, fp);
		nodes[c].count++;
		
		//ͳ��Դ�ļ�����,ÿ��һ�ֽڳ���+1
		flength++;
	}
	
	// �������һ��
	flength--;
	nodes[c].count--;

	cout<<endl<<"Դ�ļ����ܳ���="<<flength<<endl;

	cout<<endl<<"�±�\t�ֽ�ֵ\tȨֵ\n"<<endl;
	
	for (int i = 0; i < 257; i++){
		printf("%d\t%x\t%d\n", i, i, nodes[i].count);
	}

	//�ر��ļ�
	fclose(fp);
}

// ���ɹ�������
void creat_hmtree(HuffNode nodes[], int &n){
	// ��ʼ�� 
	for (int i = 0; i < 512; i++){
		if (nodes[i].count != 0){
			//�����Ȩֵ������Ҷ�ӽ����ֽ�(��)
			nodes[i].ch = (unsigned char)i;
		}
		else{
			//���û��Ȩֵ����ʾ���ַ�û�����ļ���ʹ��
			nodes[i].ch = 0;
		}
		
		//�Խ����г�ʼ�������н��ĸ��ڵ㶼�����ڣ����Һ��Ӷ�������
		nodes[i].parent = -1;
		nodes[i].lch = -1;
		nodes[i].rch = -1;
	}
	
	//��ǰ256��Ԫ�ظ���Ƶ�ʣ�Ȩֵ���Ӵ�С����
	HuffNode tmp;
	for (int i = 0; i <= 255; i++){
		int k = i;
		for (int j = i + 1; j <= 256; j++){
			if (nodes[j].count > nodes[k].count){
				k = j;
			}
		}
			
		if (k != i)
		{
			tmp = nodes[i];
			nodes[i] = nodes[k];
			nodes[k] = tmp;
		}
	}
	

	// ȨֵΪ0�Ľ�㲻���빹�����������
	// ����ж���������Ȩֵ���ĸ��������������������

	for (int i = 0; i < 256; i++){
		// ��Ϊ�Ӵ�С��������һ������ȨֵΪ0�����涼Ϊ0
		if (nodes[i].count == 0){
			n = i;
			break;
		}	
	}
	
	int m = 2*n-1;
	long min, pt;
	
	//�������������ĺ�n-1�����
	for (int i = n; i < m; i++){
		
		// ��������
		 
		//Ԥ������Ȩֵ���������ֵ�������
		min = 0x7FFFFFFF;
		
		for (int j = 0; j < i; j++){
			
			// parent!=-1 ˵���ý�����ڹ��������У�����ѭ������ѡ���½ڵ�
			if (nodes[j].parent != -1) continue;
				
			if (min > nodes[j].count){
				pt = j;					//min��Сʱ���±�
				min = nodes[j].count;	//minΪ��С
			}
		}
		
		//�����Ѿ�ȡ����С�ģ�������Ϊ�������������㣬���ú������Ϣ
		nodes[pt].parent = i;
		nodes[i].count = nodes[pt].count;
		nodes[i].lch = pt;
		
		// �����Һ��� 
	
		min = 0x7FFFFFFF;
		
		for (int j = 0; j < i; j++)
		{
			if (nodes[j].parent != -1) continue;
			if (min > nodes[j].count){
				pt = j;
				min = nodes[j].count;
			}
		}
		
		nodes[pt].parent = i;
		nodes[i].count += nodes[pt].count;
		nodes[i].rch = pt;	
	}
	
	printf("\nҶ�ӽ������n=%d, �ܽ������m=%d\n", n, m);

	printf("\n�±�\t�ֽ�ֵ\tȨֵ\t�����\t����\t�Һ���\n\n");
	
	for (int i = 0; i < m; i++){
		printf("%d\t%x\t%d\t%d\t%d\t%d\n", i,i, nodes[i].count, nodes[i].parent,nodes[i].lch, nodes[i].rch);
	}
	
}

// ���ɹ���������
void creat_hmcode(HuffNode nodes[], int n){

	//Ϊÿһ��Ҷ�ӽ�����
	for (int i = 0; i < n; i++){
		
		int f = i;
		
		//AscII��Ϊ0���ַ�����Ϊ\0������
		// �����԰�bits����һ���ַ��������ַ�����������
		nodes[i].bits[0] = 0;
		
		// ����ֱ�����ڵ� 
		while (nodes[f].parent != -1)
		{
			int j = f;	//Ҳ����i
			
			f = nodes[f].parent;
			
			// ���ӱ���0
			if (nodes[f].lch == j){
				j = strlen(nodes[i].bits);
				
				// ����������λ�÷ŵ�ǰ�ı���
				// j+1��ζ����ʱ��\0���ƣ�memmove�������ص����ֱ�����
				memmove(nodes[i].bits + 1, nodes[i].bits, j + 1);
				
				//���δ洢����"0" "1"����
				nodes[i].bits[0] = '0';//���֧��Ϊ0
			}
			else{
				// �Һ��ӱ���1
				j = strlen(nodes[i].bits);
				
				// ����������λ�÷ŵ�ǰ�ı���
				// j+1��ζ����ʱ��\0���ƣ�memmove�������ص����ֱ�����
				memmove(nodes[i].bits + 1, nodes[i].bits, j + 1);
				
				// ���δ洢����"0" "1"����
				nodes[i].bits[0] = '1';
			}
		}
	}
	
	printf("\n�±�\t�ֽ�ֵ\tȨֵ\t����\n\n");
	
	int m = 2*n+1;
	for (int i = 0; i < m; i++){
		printf("%d\t%x\t%d\t%s\n", i, i, nodes[i].count,nodes[i].bits);
	} 

}

// ѹ���ļ�
void compress(HuffNode nodes[], int n,char sourcefile[], char filename[], long &flength){
	FILE *ifp,*ofp;
	
	// ��Դ�ļ���ȡ 
	ifp = fopen(sourcefile, "rb");
	if (ifp == NULL){
		cout<<endl<<"��"<<sourcefile<<"�ļ�ʧ��"<<endl<<endl;
		return;
	}
	
	//��Ŀ���ļ�����д��
	ofp = fopen(filename, "wb");
	if (ofp == NULL){
		cout<<"��"<<filename<<"�ļ�ʧ��"<<endl<<endl;
		return;
	}
	
	// SEEK_SETָ�ļ�ͷ�����ļ�ָ��ָ���ѹ���ļ��Ŀ�ʼλ��
	fseek(ifp, 0, SEEK_SET);
	
	// ��ѹ���ļ�ͷд���ļ����ܳ��ȣ�ռ2���ֽ�
	fwrite(&flength, sizeof(int), 1, ofp);
	
	// �ض�λѹ���ļ�ָ�룬��ͷƫ��8���ֽڣ�
	// �����ռ�д������Ϣ����д�����������׼��
	fseek(ofp, 8, SEEK_SET);

	//����Դ�ļ�
	char buf[512];		//���建�����������ֽڵ�huffman����
	buf[0] = 0;			//��ʼΪ'\0'
	long newf = 0;		//ͳ���ַ����������ж�Դ�ļ��Ƿ����
	int pt1 = 8;		//ͳ���ļ��ĳ��ȣ�����������ӵ�8���ֽڿ�ʼд��
	
	int f = 0;
	unsigned char c;
	int size;

	//ɨ��Դ�ļ�
	while (!feof(ifp))
	{
		// ���ļ��ж�ȡһ���ַ���
		// ��ȡһ���ֽں󣬹��λ�ú���һ���ֽڡ�
		c = fgetc(ifp);
		f++;
		
		for (int i = 0; i < n; i++){
			//�ҵ�ȡ���ַ���Ӧ����������Ҷ�ӽ�㣬���õ���Ӧ���±�ȥ����Ӧ�ı���
			if (c == nodes[i].ch) {
				//�ҵ���ǰ�ַ��Ĺ��������룬���ӵ�buf��
				strcat(buf, nodes[i].bits);
				break;
			}
		}
				
		// �����ȴ���8�����в��д�룬
		// ��С��8�������ȡ��һ���ַ��Ĺ��������һ���ֽڣ�����д��
		
		size = strlen(buf);		//ͳ�Ƹ��ַ�����ĳ���
		c = 0;
		
		//����ǰ����ĳ��ȴ��ڵ���8����Ҫ���в�֣��������ֽڴ�
		while (size >= 8){
			// ʹ��λ�����㣬���ַ���0011ת���ɶ���������0011 
			for (int i = 0; i < 8; i++){
				if (buf[i] == '1'){
					c = (c << 1) | 1; // �������㣬��0���룬���Զ���1��Ҫʹ�û����㣬���1 
				}
				else{
					c = c << 1;
				}	
			}
			
			fwrite(&c, 1, 1, ofp);
			pt1++;
			
			//��buf��һ���ֽ�����������ݸ��Ƶ�buf�У���һ���ֽ�ȡ
			strcpy(buf, buf + 8);
			
			size = strlen(buf);
		}
		
		//��Դ�ļ����е��ַ�ȡ�꣬����
		if (f == flength) break;
	}
	
	// �ж���ģ���0���� 
	if (size > 0){
		strcat(buf, "00000000");
		for (int i = 0; i < 8; i++){
			if (buf[i] == '1'){
				c = (c << 1) | 1;
			}	
			else{
				c = c << 1;
			}	
		}
		
		//�����һ���ֽ�д���ļ���
		fwrite(&c, 1, 1, ofp);
		pt1++;
	}
	
	//д��ʣ���ļ���Ϣ
	fseek(ofp, 4, SEEK_SET);				//�ƶ��ļ�ָ��λ�õ���4���ֽ�
	fwrite(&pt1, sizeof(long), 1, ofp);		//д��ͳ��ѹ�����ļ��ĳ��ȣ�4���ֽ�
	
	fseek(ofp, pt1, SEEK_SET);				//�ƶ��ļ�ָ�뵽ѹ�����ļ�β
	fwrite(&n, sizeof(long), 1, ofp);		//д��ڵ���Ŀ�����ܵĲ�ͬ�ֽڵĸ���

	for (int i = 0; i < n; i++){
		
		//д��ÿ���ڵ�Ĵ�����ַ�
		fwrite(&(nodes[i].ch), 1, 1, ofp);
		
		//д��ÿ���ַ�����������ĳ���
		c = strlen(nodes[i].bits);
		fwrite(&c, 1, 1, ofp);
		
		//ͳ�ƹ���������
		size = strlen(nodes[i].bits);
		
		//���洢��λ������8�ı�������0
		if (size % 8 != 0){
			for (int newf = size % 8; newf < 8; newf++){
				strcat(nodes[i].bits, "0");		//011 00000
			}	
		}
		
		//�������������ַ�����ɶ�������
		//�������Ƿ����ַ���ĩβ
		while (nodes[i].bits[0] != 0){
			c = 0;
			//�ַ�����Ч�洢������8λ�������Чλ������ʵ�ֲ�0
			for (int j = 0; j < 8; j++)
			{
				if (nodes[i].bits[j] == '1'){
					c = (c << 1) | 1;
				}
				else{
					c = c << 1;	
				}	
			}
			
			//����ת��������ַ���
			strcpy(nodes[i].bits, nodes[i].bits + 8);
			fwrite(&c, 1, 1, ofp);
		}
	}
	
	//ѹ������ļ���С
	long length2 = pt1--;
	//�����ļ���ѹ����
	double div = ((double)flength - (double)length2) / (double)flength;
	
	//�ر��ļ�
	fclose(ifp);
	fclose(ofp);
	
	printf("\n\tѹ���ļ��ɹ���\n");
	printf("\tѹ����Ϊ %f%%\n\n", div * 100);

}

// ��ѹ�ļ� 
void uncompress(){
	
	HuffNode nodes[512];
	
	char buf[512];		//���建�����������ֽڵ�huffman����
	buf[0] = 0;			//��ʼΪ'\0'
	
	char filename[255];		//	ѹ���ļ� 
	char outputfile[255];	// ��ѹ�ļ� 
	char bx[255];
	
	unsigned char c;
	long n,m,p;
	
	FILE *ifp, *ofp;
	long flength,f;
	
	printf("\t����������Ҫ��ѹ�����ļ���: ");
	gets(filename);
	
	//�Զ�����ֻ����ʽ���ļ���ifpָ����ļ�
	ifp = fopen(filename, "rb");
	if (ifp == NULL)
	{
		printf("\n\t�ļ���ʧ�ܣ�\n\n");
		return;
	}
	
	printf("\t���ڵ�ǰĿ¼�½�ѹ�����������ѹ������ļ���������չ��: ");
	gets(outputfile);
	
	//�Զ�����д��ʽ��outpufile�ļ�,ofpָ����ļ�
	ofp = fopen(outputfile, "wb");
	if (ofp == NULL)
	{
		printf("\n\t��ѹ���ļ���ʧ�ܣ�\n\n");
		return;
	}
	
	//��ȡ�ļ���Ϣ
	fread(&flength, sizeof(long), 1, ifp);	//��ȡδѹ��ʱԴ�ļ�����
	fread(&f, sizeof(long), 1, ifp);		//��ȡѹ���ļ��ĳ��ȣ�λ�ڵ�4���ֽڴ�
	
	fseek(ifp, f, SEEK_SET);			//���ļ�ָ�붨λ���洢�ڵ�������λ��
	fread(&n, sizeof(long), 1, ifp);	//��ȡ�ڵ���
	
	//�ع�Huffman����Huffman����
	//����Huffman����n��Ҷ�ӽ��
	for (int i = 0; i < n; i++)
	{
		fread(&nodes[i].ch, 1, 1, ifp);		//��ȡһ���ֽڣ��õ�huffman����һ���ڵ�
		fread(&c, 1, 1, ifp);				//��ȡ�ַ���Ӧ�Ĺ��������볤��
		
		p = (long)c;
		nodes[i].count = p;			//count�ɱ�����Ȩֵ��Ϊ������ı��볤��
		nodes[i].bits[0] = 0;		//��ʼ����Ϊ'\0'
		
		if (p % 8>0){
			m = p / 8 + 1;	//�ֽ���
		}
		else{
			m = p / 8;
		}
			
		for (int j = 0; j < m; j++)
		{
			//ÿ��ȡ��һ���ֽ�
			fread(&c, 1, 1, ifp);
			int f = c;
			
			_itoa(f, buf, 2);	//��fת��Ϊ�����Ʊ�ʾ���ַ���
			f = strlen(buf);	//long��ɶ�����ʱ���粻��8λ��0
			
			for (int l = 8; l > f; l--)
			{
				strcat(nodes[i].bits, "0");//���ڹ������������벹0
			}
			
			//����0��������ת�õ�01�ַ���
			strcat(nodes[i].bits, buf);
		}
		
		//���ý�����
		nodes[i].bits[p] = 0;
	}
	
	//���ݹ���������ĳ��̣��Խ��������򣬱���̵���ǰ��
	HuffNode tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strlen(nodes[i].bits) > strlen(nodes[j].bits))
			{
				tmp = nodes[i];
				nodes[i] = nodes[j];
				nodes[j] = tmp;
			}
		}
	}
	
	p = strlen(nodes[n - 1].bits);	//�������󳤶�
	fseek(ifp, 8, SEEK_SET);		//��λ�ļ�ָ����ԭ�ļ������������λ��
	
	m = 0;
	bx[0] = 0;	//ÿ�δ���Ľ�����ַ���
	
	// ͨ������������ĳ��̣����ν��룬
	// ��ԭ����λ�洢��ԭ���ֽڴ洢
	while (1)
	{
		// ��������볤�ȵ����� 
		// bx��������ݱ����01����������һ���ֽڣ������Ƕ���ֽ� 
		while (strlen(bx) < (unsigned int)p)
		{
			//ȡһ���ַ�,ת���ɶ�����01
			fread(&c, 1, 1, ifp);
			f = c;
			
			_itoa(f, buf, 2);		//��fת��Ϊ�����Ʊ�ʾ���ַ���
			f = strlen(buf);		//long��ɶ�����ʱ���粻��8λ��0
			
			//�ڵ��ֽ��ڶ���Ӧλ�ò�0
			for (int l = 8; l > f; l--)
			{
				strcat(bx, "0");
			}
			
			strcat(bx, buf);
		}
		
		for (int i = 0; i < n; i++)
		{
			//�ҵ����룬memcmp���ֽڱȽ� 
			if (memcmp(nodes[i].bits, bx, nodes[i].count) == 0){
				//�Ƚϳɹ�������������ж�bx��Ӧ�������ַ�
				// Ҳ���ǰѺ�������ݣ�����еĻ�������ǰ����Ѿ���������� 
				strcpy(bx, bx + nodes[i].count);
				
				c = nodes[i].ch;		//�õ�ƥ���Ĺ����������Ӧ���ַ�
				fwrite(&c, 1, 1, ofp);	//���õ����ַ�д��Ŀ���ļ�
				
				break;
			}
				
		}

		m++;
		
		if (m == flength) break;	//flength��ԭ�ļ�����
	}
	
	//�ر�
	fclose(ifp);
	fclose(ofp);
	
	printf("\n\t��ѹ���ļ��ɹ���\n");
	
	//�Խ�ѹ�����ļ���ԭ�ļ���ͬ�ԱȽϽ����жϣ������ļ���С��
	if (m == flength){
		printf("\t��ѹ���ļ���ԭ�ļ���ͬ!\n\n");
	}	
	else{
		printf("\t��ѹ���ļ���ԭ�ļ���ͬ!\n\n");
	}

}
