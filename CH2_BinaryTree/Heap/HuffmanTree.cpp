//构造哈夫曼树
typedef struct TreeNode* HuffmanTree;
struct TreeNode{
	int Weight;
	HuffmanTree Left,Right; 
}; 
//利用堆来构建哈夫曼树，时间复杂度O(NlogN) 
HuffmanTree Huffman(MinHeap H)
{
	//假设H->Size个权值已经存在H->Elements[]->Weight里
	int i;
	HuffmanTree T;
	BuildMinHeap(H);//将H->Elements[]按权值调整为最小值
	for(i=1;i<H->Size;i++){ //H->Size-1次合并
	    T=malloc(sizeof(struct TreeNode));//建立新结点
		T->Left=DeleteMin(H);//从最小堆中删除一个值最小的结点，作为新T的左子结点
		T->Right=DeleteMin(H);//在从最小堆中删除一个值最小结点，作为新T的右子节点
		T->Weight=T->Left->Weight+T->Right->Weight;//计算新权值 
		Insert(H,T);//将新T插入最小堆 
	}
	T=DeleteMin(H);//最后从最小堆中删除的为根结点，保存在T中返回 
	return T;
}

