//将一系列给定数字插入到一个初始为空的小顶堆H[]。随后对任意给定
//的小标'i',打印从H[i]到根结点的路径。

#define MAXN 1001
#define MINH -1001

int H[MAXN],size;

void Create()
{
	size=0;
	H[0]=MINH;//设置岗哨 
}

void Insert(int X)
{
	//将X插入H,这里省略检查堆是否已满的代码
	int i;
	for(i=++size;H[i/2]>X;i/=2)
	    H[i]=H[i/2];
	H[i]=X; 
} 

int main()
{
	//读入n和m 
	//根据输入序列建堆
	//对m个要求：打印到根的路径
	int n,m,x,i,j;
	scanf("%d%d",&n,&m);
	Create();//初始化堆
	for(i=0;i<n;i++){//以逐个插入方式建堆
	    scanf("%d",&x);
	    Inset(x);
	} 
	for(i=0;i<m;i++){
		scanf("%d",&j);
		printf("%d",H[j]);
		while(j>1){//沿根方向输出各结点 
			j/=2;
			printf("%d",H[j]);
		}
		printf("\n"); 
	} 
	return 0;
}
