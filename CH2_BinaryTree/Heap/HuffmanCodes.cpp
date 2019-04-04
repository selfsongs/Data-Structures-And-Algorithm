//Huffman Codes哈夫曼编码的特点：
//1:最优编码：总长度（WPL)最小
//2:无歧义解码：前缀码--数据仅存于叶子结点
//3:没有度为1的结点--满足1,2则必满足3

//核心最优编码长度
MinHeap H=CreateHeap(N);//创建一个空的、容量为N的最小堆
H=ReadData(N);//将f[]读入H->Data[]中
HuffmanTree T=Huffman(H);//建立Huffman树 
int CodeLen=WPL(T,0);//计算最优编码总长度WPL

int WPL(HuffmanTree T,int Depth)
{
	if(!T->Left&&!T->Right)
	    return (Depth*T->Weight);
	else//否则T一定有2个孩子
	    return (WPL(T->Left,Depth+1)
		        +WPL(T->Right,Depth+1)); 
}
