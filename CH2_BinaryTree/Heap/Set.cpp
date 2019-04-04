//并查集的表示
//用结构数组存储

//何钦铭老师：
typedef struct{
	ElementType Data;
	int parent;
}SetType;

//集合运算之---查找某个元素所在的集合(用根结点表示)
int Find(SetType S[],ElementType X)
{
	//在数组S中查找值为X的元素所属的集合
	//MaxSize是全局变量，为数组S的最大长度
	int i;
	for(i=0;i<MaxSize&&S[i].Data!=X;i++);
	if(i>=MaxSize)return -1;//未找到X,返回-1
	for(;S[i].Parent>=0;i=S[i].Parent);//找到根结点为止 
	return i;//找到X所属集合，返回树根结点在数组S中的小标 
} 

//集合运算之---并运算
//分别找到X1和X2两个元素所在集合树的根结点
//如果它们不同根，则将其中一个根节点的父结点指针设置成另一个根节点的数组下标 
void Union(SetType S[],ElementType X1,ElementType X2) 
{
	int Root1,Root2;
	Root1=Find(S,X1);
	Root2=Find(S,X2);
	if(Root2!=Root2) S[Root2].Parent=Root1; 
}

//为了改善合并以后的查找性能，可以采用小的集合合并到相对大的集合中
//修改Union函数，前面在用数组存储集合时，parent=-1的表示根结点
//我们为了获得每个集合总共有多少个元素，可以将根结点的parent修改为: -元素总数；
//例如，一个集合有5个元素，则可以将其根结点的parent设为：-5；这样就巧妙地知道了集合的元素数目 





/**********************************************************************/ 

//陈越老师 
//简化的集合的表示
typedef int ElementType;//默认元素可以用非负整数表示
typedef int SetName;//默认根结点的下标作为集合名称
typedef ElementType[MaxSize] SetType;

SetName Find(SetType S,ElementType X)
{
	//默认集合元素全部初始化为-1
	for(;S[X]>=0;X=S[X]);
	return X; 
}

//这里默认Root1和Root2是不同集合的根结点
void Union(SetType S,SetName Root1,SetName Root2)
{
	S[Root2]=Root1; 
}






