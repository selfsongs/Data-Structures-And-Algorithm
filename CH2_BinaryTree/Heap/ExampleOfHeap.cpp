//��һϵ�и������ֲ��뵽һ����ʼΪ�յ�С����H[]�������������
//��С��'i',��ӡ��H[i]��������·����

#define MAXN 1001
#define MINH -1001

int H[MAXN],size;

void Create()
{
	size=0;
	H[0]=MINH;//���ø��� 
}

void Insert(int X)
{
	//��X����H,����ʡ�Լ����Ƿ������Ĵ���
	int i;
	for(i=++size;H[i/2]>X;i/=2)
	    H[i]=H[i/2];
	H[i]=X; 
} 

int main()
{
	//����n��m 
	//�����������н���
	//��m��Ҫ�󣺴�ӡ������·��
	int n,m,x,i,j;
	scanf("%d%d",&n,&m);
	Create();//��ʼ����
	for(i=0;i<n;i++){//��������뷽ʽ����
	    scanf("%d",&x);
	    Inset(x);
	} 
	for(i=0;i<m;i++){
		scanf("%d",&j);
		printf("%d",H[j]);
		while(j>1){//�ظ������������� 
			j/=2;
			printf("%d",H[j]);
		}
		printf("\n"); 
	} 
	return 0;
}
