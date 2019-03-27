//�����������
typedef struct TreeNode* HuffmanTree;
struct TreeNode{
	int Weight;
	HuffmanTree Left,Right; 
}; 
//���ö�����������������ʱ�临�Ӷ�O(NlogN) 
HuffmanTree Huffman(MinHeap H)
{
	//����H->Size��Ȩֵ�Ѿ�����H->Elements[]->Weight��
	int i;
	HuffmanTree T;
	BuildMinHeap(H);//��H->Elements[]��Ȩֵ����Ϊ��Сֵ
	for(i=1;i<H->Size;i++){ //H->Size-1�κϲ�
	    T=malloc(sizeof(struct TreeNode));//�����½��
		T->Left=DeleteMin(H);//����С����ɾ��һ��ֵ��С�Ľ�㣬��Ϊ��T�����ӽ��
		T->Right=DeleteMin(H);//�ڴ���С����ɾ��һ��ֵ��С��㣬��Ϊ��T�����ӽڵ�
		T->Weight=T->Left->Weight+T->Right->Weight;//������Ȩֵ 
		Insert(H,T);//����T������С�� 
	}
	T=DeleteMin(H);//������С����ɾ����Ϊ����㣬������T�з��� 
	return T;
}

