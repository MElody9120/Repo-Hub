/**
** ʹ�ù���������ʵ���ļ�ѹ���ͽ�ѹ����
** ��ע������ߴ��ϵ����ֺ���Ҫ 
**/ 

// ���ݽڵ� 
struct HuffNode
{
	unsigned char ch;	//�ֽڷ�
	long count;  		//�ֽڳ���Ƶ��
	long parent;		//���ڵ�
	long lch;			//����
	long rch;			//�Һ���
	char bits[256];		// ����������
};


// �������ݵ�API������������ 

// ͳ��Դ�ļ����ֽ�
void count_file(HuffNode nodes[], char filename[], long &flength);

// ���ɹ�������
void creat_hmtree(HuffNode nodes[], int &n);

// ���ɹ���������
void creat_hmcode(HuffNode nodes[], int n);

// ѹ���ļ�
void compress(HuffNode nodes[], int n,char sourcefile[], char filename[], long &flength);

// ��ѹ�ļ�
void uncompress();
