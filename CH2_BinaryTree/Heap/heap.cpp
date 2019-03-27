//��Heap
//���ѵô���
typedef struct HeapStruct *MaxHeap;
struct HeapStruct{
	ElementType *Elements;//�洢��Ԫ�ص�����
	int Size;             //�ѵõ�ǰԪ�ظ���
	int Capacity;         //�ѵ�������� 
}; 

MaxHeap Create(int MaxSize)
{
	//��������ΪMaxSize�Ŀյ�����
	MaxHeap H=malloc(sizeof(struct HeapStruct));
	H->Elements=malloc((MaxSize+1)*sizeof(ElementType));
	H->Size=0;
	H->Capacity=MaxSize;
	H->Elements[0]=MaxData;//�����ڱ�Ϊ���ڶ������п���Ԫ�ص�ֵ�������Ժ�������
	return H; 
} 

//���ѵĲ��룬T(N)=O(logN) 
void Insert(MaxHeap H,ElementType item)
{
	//��Ԫ��item��������H,����H->Elements[0]�Ѿ�����Ϊ�ڱ�
	int i;
	if(IsFull(H)){
		printf("��������");
		return; 
	} 
	i=++H->Size;//iָ��������е����һ��Ԫ�ص�λ��
	for(;H->Elements[i/2]<item;i/=2)
	    H->Elements[i]=H->Elements[i/2];//���¹��˽��
	H->Elements[i]=item;//��item���� 
} 

//���ѵ�ɾ��,T(N)=O(logN)
//ȡ������㣨���ֵ��Ԫ�أ�ͬʱɾ���ѵ�һ����㡣
ElementType DeleteMax(MaxHeap H)
{
	//������H��ȡ����ֵΪ����Ԫ�أ���ɾ��һ�����
	int Parent,Child;
	ElementType MaxItem,temp;
	if(IsEmpty(H)){
		printf("������Ϊ��")��
		return ; 
	} 
	MaxItem=H->Elements[1];//ȡ�����ڵ����ֵ
	//�����������һ��Ԫ�شӸ���㿪ʼ���Ϲ����²���
	temp=H->Elements[H->Size--];
	for(Parent=1;Parent*2<=H->Size;Parent=Child){
		Child=Parent*2;
		if((Child!=H->Size)&&
		    (H->Elements[Child]<H->Elements[Child+1]))
		    Child++;//Childָ�������ӽ��Ľϴ���
		if(temp>=H->Elements[Child]) break;
		else//�ƶ�tempԪ�ص���һ��
		    H->Elements[Parent]=H->Element[Child]; 
	} 
	H->Elements[Parent]=temp;
	return MaxItem;
} 






