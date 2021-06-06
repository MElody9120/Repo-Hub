/**
** 使用哈弗曼编码实现文件压缩和解压缩。
** 备注：起个高大上的名字很重要 
**/ 

// 数据节点 
struct HuffNode
{
	unsigned char ch;	//字节符
	long count;  		//字节出现频度
	long parent;		//父节点
	long lch;			//左孩子
	long rch;			//右孩子
	char bits[256];		// 哈夫曼编码
};


// 操作数据的API（函数声明） 

// 统计源文件各字节
void count_file(HuffNode nodes[], char filename[], long &flength);

// 生成哈夫曼树
void creat_hmtree(HuffNode nodes[], int &n);

// 生成哈夫曼编码
void creat_hmcode(HuffNode nodes[], int n);

// 压缩文件
void compress(HuffNode nodes[], int n,char sourcefile[], char filename[], long &flength);

// 解压文件
void uncompress();
