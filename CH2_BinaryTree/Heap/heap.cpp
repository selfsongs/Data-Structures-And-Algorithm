//堆Heap
//最大堆得创建
typedef struct HeapStruct *MaxHeap;
struct HeapStruct{
	ElementType *Elements;//存储堆元素的数组
	int Size;             //堆得当前元素个数
	int Capacity;         //堆得最大容量 
}; 

MaxHeap Create(int MaxSize)
{
	//创建容量为MaxSize的空的最大堆
	MaxHeap H=malloc(sizeof(struct HeapStruct));
	H->Elements=malloc((MaxSize+1)*sizeof(ElementType));
	H->Size=0;
	H->Capacity=MaxSize;
	H->Elements[0]=MaxData;//定义哨兵为大于堆中所有可能元素的值，便于以后更快操作
	return H; 
} 

//最大堆的插入，T(N)=O(logN) 
void Insert(MaxHeap H,ElementType item)
{
	//将元素item插入最大堆H,其中H->Elements[0]已经定义为哨兵
	int i;
	if(IsFull(H)){
		printf("最大堆已满");
		return; 
	} 
	i=++H->Size;//i指向插入后堆中的最后一个元素的位置
	for(;H->Elements[i/2]<item;i/=2)
	    H->Elements[i]=H->Elements[i/2];//向下过滤结点
	H->Elements[i]=item;//将item插入 
} 

//最大堆得删除,T(N)=O(logN)
//取出根结点（最大值）元素，同时删除堆的一个结点。
ElementType DeleteMax(MaxHeap H)
{
	//从最大堆H中取出键值为最大的元素，并删除一个结点
	int Parent,Child;
	ElementType MaxItem,temp;
	if(IsEmpty(H)){
		printf("最大堆已为空")；
		return ; 
	} 
	MaxItem=H->Elements[1];//取出根节点最大值
	//用最大堆中最后一个元素从根结点开始向上过滤下层结点
	temp=H->Elements[H->Size--];
	for(Parent=1;Parent*2<=H->Size;Parent=Child){
		Child=Parent*2;
		if((Child!=H->Size)&&
		    (H->Elements[Child]<H->Elements[Child+1]))
		    Child++;//Child指向左右子结点的较大者
		if(temp>=H->Elements[Child]) break;
		else//移动temp元素到下一层
		    H->Elements[Parent]=H->Element[Child]; 
	} 
	H->Elements[Parent]=temp;
	return MaxItem;
} 






