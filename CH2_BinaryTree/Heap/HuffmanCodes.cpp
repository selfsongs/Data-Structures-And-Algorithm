//Huffman Codes������������ص㣺
//1:���ű��룺�ܳ��ȣ�WPL)��С
//2:��������룺ǰ׺��--���ݽ�����Ҷ�ӽ��
//3:û�ж�Ϊ1�Ľ��--����1,2�������3

//�������ű��볤��
MinHeap H=CreateHeap(N);//����һ���յġ�����ΪN����С��
H=ReadData(N);//��f[]����H->Data[]��
HuffmanTree T=Huffman(H);//����Huffman�� 
int CodeLen=WPL(T,0);//�������ű����ܳ���WPL

int WPL(HuffmanTree T,int Depth)
{
	if(!T->Left&&!T->Right)
	    return (Depth*T->Weight);
	else//����Tһ����2������
	    return (WPL(T->Left,Depth+1)
		        +WPL(T->Right,Depth+1)); 
}
