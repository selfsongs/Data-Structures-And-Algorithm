//BinarySearchTree
//���ң�β�ݹ鷽ʽ ��Ч�ʲ��� 
Position Find(ElementType X,BinTree BST)
{
	if(!BST) return NULL;//����������NULL 
	if(X>BST->Data)
	    return Find(X,BST->Right);//���������ϲ��� 
	else if(X<BST->Data)
	    return Find(X,BST->Left);//���������ϲ��� 
	else
	    return BST;//���ҳɹ������ؽڵ�ĵ�ַ 
} 

//���ң��ǵݹ麯��ʵ�֣����õ����ķ�ʽ��Ч�ʱȵݹ鷽ʽ�� 
Position IterFind(ElementType X,BinTree BST)
{
	while(BST){
		if(X>BST->Data)
		    BST=BST->Right;
		else if(X<BST->Data)
		    BST=BST->Left;
		else
		    return BST;
	}
	return NULL;//����ʧ�� 
} 

//�ݹ������Сֵ���������ַ 
Position FindMin(BinTree BST)
{
	if(!BST)
	    return NULL;
	else if(!BST->Left)
	    return BST;
	else
	    return FindMin(BST->Left);
} 
//�����������ֵ���������ַ 
Position FindMax(BinTree BST)
{
	if(BST)
	    while(BST->Right)
	        BST=BST->Right;
	return BST;
}


// ����:�ݹ鷽ʽ 
BinTree Insert(ElementType X,BinTree BST) 
{
	if(!BST){
		//��ԭ��Ϊ�գ����ɲ�����һ�����Ķ��������� 
		BST=malloc(sizeof(struct TreeNode));
		BST->Data=X;
		BST->Left=BST->Right=NULL;
	}else{//��ʼ��Ҫ����Ԫ�ص�λ�� 
	    if(X<BST->Data)
	        BST->Left=Insert(X,BST->Left);//�ݹ���������� 
	    else if(X>BST->Data)
	        BST->Right=Insert(X,BST->Right);//�ݹ����������
	    }
	return BST; 
}

//ɾ����
 BinTree Delete(ElementType X,BinTree BST)
 {
 	Position Tmp;
 	if(!BST)
	    printf("Ҫɾ����Ԫ��δ�ҵ�")��
	else{ 
	    if(X<BST->Data)
	        BST->Left=Delete(X,BST->Left);//�������ݹ�ɾ��
	    else if(X>BST->Data)
	        BST->Right=Delete(X,BST->Right);//�������ݹ�ɾ��
	    else{//�ҵ�Ҫɾ���Ľ��
	        if(BST->Left&&BST->Right){//��ɾ����������������ӽ�� 
	    	    Tmp=FindMin(BST->Right);//��������������С��Ԫ�����ɾ�����
			    BST->Data=Tmp->Data;
			    BST->Right=Delete(BST->Data,BST->Right);
		    }else{//��ɾ�������һ�������ӽ�� 
			    Tmp=BST;
			    if(!BST->Left)//���Һ��ӻ����ӽ��
			        BST=BST->Right;
			    else if(!BST->Right)//�����ӻ����ӽ��
			        BST=BST->Left;
			free(Tmp); 
		    }
	        }
        }
	return BST;
 } 
