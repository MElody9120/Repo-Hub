#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SuperCompress.h" 

using namespace std;

// 统计源文件各字节
void count_file(HuffNode nodes[], char filename[], long &flength){
	FILE *fp; 
	
	fp = fopen(filename, "rb");
	
	if (fp == NULL){
		cout<<endl<<"文件打开失败"<<endl<<endl;
		return;
	}
	
	unsigned char c;	//接收读取的一个字节
	flength = 0;		//保存文件的字节数,初始为0
	
	while (!feof(fp))
	{
		//从文件中读取一个字节到c
		fread(&c, 1, 1, fp);
		nodes[c].count++;
		
		//统计源文件长度,每读一字节长度+1
		flength++;
	}
	
	// 多计算了一次
	flength--;
	nodes[c].count--;

	cout<<endl<<"源文件的总长度="<<flength<<endl;

	cout<<endl<<"下标\t字节值\t权值\n"<<endl;
	
	for (int i = 0; i < 257; i++){
		printf("%d\t%x\t%d\n", i, i, nodes[i].count);
	}

	//关闭文件
	fclose(fp);
}

// 生成哈夫曼树
void creat_hmtree(HuffNode nodes[], int &n){
	// 初始化 
	for (int i = 0; i < 512; i++){
		if (nodes[i].count != 0){
			//如果有权值，设置叶子结点的字节(符)
			nodes[i].ch = (unsigned char)i;
		}
		else{
			//如果没有权值，表示该字符没有在文件中使用
			nodes[i].ch = 0;
		}
		
		//对结点进行初始化，所有结点的父节点都不存在，左右孩子都不存在
		nodes[i].parent = -1;
		nodes[i].lch = -1;
		nodes[i].rch = -1;
	}
	
	//将前256个元素根据频率（权值）从大到小排序
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
	

	// 权值为0的结点不参与构造哈夫曼树，
	// 因此判断数组中有权值结点的个数，用来构造哈夫曼树

	for (int i = 0; i < 256; i++){
		// 因为从大到小排序，所以一旦发现权值为0，后面都为0
		if (nodes[i].count == 0){
			n = i;
			break;
		}	
	}
	
	int m = 2*n-1;
	long min, pt;
	
	//构建哈夫曼树的后n-1个结点
	for (int i = n; i < m; i++){
		
		// 先找左孩子
		 
		//预设的最大权值，即结点出现的最大次数
		min = 0x7FFFFFFF;
		
		for (int j = 0; j < i; j++){
			
			// parent!=-1 说明该结点已在哈夫曼树中，跳出循环重新选择新节点
			if (nodes[j].parent != -1) continue;
				
			if (min > nodes[j].count){
				pt = j;					//min最小时的下标
				min = nodes[j].count;	//min为最小
			}
		}
		
		//上面已经取出最小的，把它作为哈夫曼树的左结点，设置好相关信息
		nodes[pt].parent = i;
		nodes[i].count = nodes[pt].count;
		nodes[i].lch = pt;
		
		// 再找右孩子 
	
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
	
	printf("\n叶子结点数量n=%d, 总结点数量m=%d\n", n, m);

	printf("\n下标\t字节值\t权值\t父结点\t左孩子\t右孩子\n\n");
	
	for (int i = 0; i < m; i++){
		printf("%d\t%x\t%d\t%d\t%d\t%d\n", i,i, nodes[i].count, nodes[i].parent,nodes[i].lch, nodes[i].rch);
	}
	
}

// 生成哈夫曼编码
void creat_hmcode(HuffNode nodes[], int n){

	//为每一个叶子结点编码
	for (int i = 0; i < n; i++){
		
		int f = i;
		
		//AscII码为0的字符，即为\0结束符
		// 这样以把bits当成一个字符串，用字符串函数操作
		nodes[i].bits[0] = 0;
		
		// 遍历直到根节点 
		while (nodes[f].parent != -1)
		{
			int j = f;	//也就是i
			
			f = nodes[f].parent;
			
			// 左孩子编码0
			if (nodes[f].lch == j){
				j = strlen(nodes[i].bits);
				
				// 拷贝，留出位置放当前的编码
				// j+1意味拷贝时把\0复制，memmove不出现重叠部分被覆盖
				memmove(nodes[i].bits + 1, nodes[i].bits, j + 1);
				
				//依次存储连接"0" "1"编码
				nodes[i].bits[0] = '0';//左分支记为0
			}
			else{
				// 右孩子编码1
				j = strlen(nodes[i].bits);
				
				// 拷贝，留出位置放当前的编码
				// j+1意味拷贝时把\0复制，memmove不出现重叠部分被覆盖
				memmove(nodes[i].bits + 1, nodes[i].bits, j + 1);
				
				// 依次存储连接"0" "1"编码
				nodes[i].bits[0] = '1';
			}
		}
	}
	
	printf("\n下标\t字节值\t权值\t编码\n\n");
	
	int m = 2*n+1;
	for (int i = 0; i < m; i++){
		printf("%d\t%x\t%d\t%s\n", i, i, nodes[i].count,nodes[i].bits);
	} 

}

// 压缩文件
void compress(HuffNode nodes[], int n,char sourcefile[], char filename[], long &flength){
	FILE *ifp,*ofp;
	
	// 打开源文件读取 
	ifp = fopen(sourcefile, "rb");
	if (ifp == NULL){
		cout<<endl<<"打开"<<sourcefile<<"文件失败"<<endl<<endl;
		return;
	}
	
	//打开目标文件进行写入
	ofp = fopen(filename, "wb");
	if (ofp == NULL){
		cout<<"打开"<<filename<<"文件失败"<<endl<<endl;
		return;
	}
	
	// SEEK_SET指文件头，将文件指针指向待压缩文件的开始位置
	fseek(ifp, 0, SEEK_SET);
	
	// 在压缩文件头写入文件的总长度，占2个字节
	fwrite(&flength, sizeof(int), 1, ofp);
	
	// 重定位压缩文件指针，从头偏移8个字节，
	// 留出空间写其他信息，并写入哈夫曼编码准备
	fseek(ofp, 8, SEEK_SET);

	//编码源文件
	char buf[512];		//定义缓冲区，保存字节的huffman编码
	buf[0] = 0;			//初始为'\0'
	long newf = 0;		//统计字符个数，可判断源文件是否读完
	int pt1 = 8;		//统计文件的长度，哈夫曼编码从第8个字节开始写入
	
	int f = 0;
	unsigned char c;
	int size;

	//扫描源文件
	while (!feof(ifp))
	{
		// 从文件中读取一个字符，
		// 读取一个字节后，光标位置后移一个字节。
		c = fgetc(ifp);
		f++;
		
		for (int i = 0; i < n; i++){
			//找到取出字符对应哈夫曼树中叶子结点，并得到相应的下标去找相应的编码
			if (c == nodes[i].ch) {
				//找到当前字符的哈夫曼编码，连接到buf中
				strcat(buf, nodes[i].bits);
				break;
			}
		}
				
		// 若长度大于8，进行拆分写入，
		// 若小于8，则继续取下一个字符的哈夫曼码凑一个字节，凑满写入
		
		size = strlen(buf);		//统计该字符编码的长度
		c = 0;
		
		//若当前编码的长度大于等于8，则要进行拆分，分两个字节存
		while (size >= 8){
			// 使用位移运算，将字符串0011转换成二进制数字0011 
			for (int i = 0; i < 8; i++){
				if (buf[i] == '1'){
					c = (c << 1) | 1; // 左移运算，用0补齐，所以对于1，要使用或运算，变成1 
				}
				else{
					c = c << 1;
				}	
			}
			
			fwrite(&c, 1, 1, ofp);
			pt1++;
			
			//把buf后一个字节起的所有内容复制到buf中，即一个字节取
			strcpy(buf, buf + 8);
			
			size = strlen(buf);
		}
		
		//若源文件所有的字符取完，结束
		if (f == flength) break;
	}
	
	// 有多余的，用0补齐 
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
		
		//把最后一个字节写入文件中
		fwrite(&c, 1, 1, ofp);
		pt1++;
	}
	
	//写入剩余文件信息
	fseek(ofp, 4, SEEK_SET);				//移动文件指针位置到第4个字节
	fwrite(&pt1, sizeof(long), 1, ofp);		//写入统计压缩后文件的长度，4个字节
	
	fseek(ofp, pt1, SEEK_SET);				//移动文件指针到压缩后文件尾
	fwrite(&n, sizeof(long), 1, ofp);		//写入节点数目，即总的不同字节的个数

	for (int i = 0; i < n; i++){
		
		//写入每个节点的代表的字符
		fwrite(&(nodes[i].ch), 1, 1, ofp);
		
		//写入每个字符哈夫曼编码的长度
		c = strlen(nodes[i].bits);
		fwrite(&c, 1, 1, ofp);
		
		//统计哈夫曼长度
		size = strlen(nodes[i].bits);
		
		//若存储的位数不是8的倍数，则补0
		if (size % 8 != 0){
			for (int newf = size % 8; newf < 8; newf++){
				strcat(nodes[i].bits, "0");		//011 00000
			}	
		}
		
		//将哈夫曼编码字符串变成二进制数
		//这里检查是否到了字符串末尾
		while (nodes[i].bits[0] != 0){
			c = 0;
			//字符的有效存储不超过8位，则对有效位数左移实现补0
			for (int j = 0; j < 8; j++)
			{
				if (nodes[i].bits[j] == '1'){
					c = (c << 1) | 1;
				}
				else{
					c = c << 1;	
				}	
			}
			
			//继续转换后面的字符串
			strcpy(nodes[i].bits, nodes[i].bits + 8);
			fwrite(&c, 1, 1, ofp);
		}
	}
	
	//压缩后的文件大小
	long length2 = pt1--;
	//计算文件的压缩率
	double div = ((double)flength - (double)length2) / (double)flength;
	
	//关闭文件
	fclose(ifp);
	fclose(ofp);
	
	printf("\n\t压缩文件成功！\n");
	printf("\t压缩率为 %f%%\n\n", div * 100);

}

// 解压文件 
void uncompress(){
	
	HuffNode nodes[512];
	
	char buf[512];		//定义缓冲区，保存字节的huffman编码
	buf[0] = 0;			//初始为'\0'
	
	char filename[255];		//	压缩文件 
	char outputfile[255];	// 解压文件 
	char bx[255];
	
	unsigned char c;
	long n,m,p;
	
	FILE *ifp, *ofp;
	long flength,f;
	
	printf("\t请您输入需要解压缩的文件名: ");
	gets(filename);
	
	//以二进制只读方式打开文件，ifp指向该文件
	ifp = fopen(filename, "rb");
	if (ifp == NULL)
	{
		printf("\n\t文件打开失败！\n\n");
		return;
	}
	
	printf("\t将在当前目录下解压，请您输入解压缩后的文件名包括拓展名: ");
	gets(outputfile);
	
	//以二进制写方式打开outpufile文件,ofp指向该文件
	ofp = fopen(outputfile, "wb");
	if (ofp == NULL)
	{
		printf("\n\t解压缩文件打开失败！\n\n");
		return;
	}
	
	//读取文件信息
	fread(&flength, sizeof(long), 1, ifp);	//读取未压缩时源文件长度
	fread(&f, sizeof(long), 1, ifp);		//读取压缩文件的长度，位于第4个字节处
	
	fseek(ifp, f, SEEK_SET);			//将文件指针定位到存储节点总数的位置
	fread(&n, sizeof(long), 1, ifp);	//读取节点数
	
	//重构Huffman树及Huffman编码
	//构造Huffman树的n个叶子结点
	for (int i = 0; i < n; i++)
	{
		fread(&nodes[i].ch, 1, 1, ifp);		//读取一个字节，得到huffman树的一个节点
		fread(&c, 1, 1, ifp);				//读取字符对应的哈夫曼编码长度
		
		p = (long)c;
		nodes[i].count = p;			//count由保存结点权值改为保存结点的编码长度
		nodes[i].bits[0] = 0;		//初始编码为'\0'
		
		if (p % 8>0){
			m = p / 8 + 1;	//字节数
		}
		else{
			m = p / 8;
		}
			
		for (int j = 0; j < m; j++)
		{
			//每次取出一个字节
			fread(&c, 1, 1, ifp);
			int f = c;
			
			_itoa(f, buf, 2);	//将f转换为二进制表示的字符串
			f = strlen(buf);	//long变成二进制时，如不足8位则补0
			
			for (int l = 8; l > f; l--)
			{
				strcat(nodes[i].bits, "0");//先在哈夫曼树结点编码补0
			}
			
			//补足0后连接已转好的01字符串
			strcat(nodes[i].bits, buf);
		}
		
		//设置结束符
		nodes[i].bits[p] = 0;
	}
	
	//根据哈夫曼编码的长短，对结点进行排序，编码短的在前面
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
	
	p = strlen(nodes[n - 1].bits);	//编码的最大长度
	fseek(ifp, 8, SEEK_SET);		//定位文件指针存放原文件哈夫曼编码的位置
	
	m = 0;
	bx[0] = 0;	//每次处理的解码的字符串
	
	// 通过哈夫曼编码的长短，依次解码，
	// 从原来的位存储还原到字节存储
	while (1)
	{
		// 读出最长编码长度的数据 
		// bx保存该数据编码的01串，可能是一个字节，可能是多个字节 
		while (strlen(bx) < (unsigned int)p)
		{
			//取一个字符,转换成二进制01
			fread(&c, 1, 1, ifp);
			f = c;
			
			_itoa(f, buf, 2);		//将f转换为二进制表示的字符串
			f = strlen(buf);		//long变成二进制时，如不足8位则补0
			
			//在单字节内对相应位置补0
			for (int l = 8; l > f; l--)
			{
				strcat(bx, "0");
			}
			
			strcat(bx, buf);
		}
		
		for (int i = 0; i < n; i++)
		{
			//找到编码，memcmp按字节比较 
			if (memcmp(nodes[i].bits, bx, nodes[i].count) == 0){
				//比较成功后，需继续往后判断bx对应的其他字符
				// 也就是把后面的数据（如果有的话）覆盖前面的已经处理的数据 
				strcpy(bx, bx + nodes[i].count);
				
				c = nodes[i].ch;		//得到匹配后的哈夫曼编码对应的字符
				fwrite(&c, 1, 1, ofp);	//将得到的字符写入目标文件
				
				break;
			}
				
		}

		m++;
		
		if (m == flength) break;	//flength是原文件长度
	}
	
	//关闭
	fclose(ifp);
	fclose(ofp);
	
	printf("\n\t解压缩文件成功！\n");
	
	//对解压缩后文件和原文件相同性比较进行判断（根据文件大小）
	if (m == flength){
		printf("\t解压缩文件与原文件相同!\n\n");
	}	
	else{
		printf("\t解压缩文件与原文件不同!\n\n");
	}

}
