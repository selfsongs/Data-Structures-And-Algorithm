//BinarySearchTree
//查找：尾递归方式 ，效率不高 
Position Find(ElementType X,BinTree BST)
{
	if(!BST) return NULL;//空树，返回NULL 
	if(X>BST->Data)
	    return Find(X,BST->Right);//在右子树上查找 
	else if(X<BST->Data)
	    return Find(X,BST->Left);//在左子树上查找 
	else
	    return BST;//查找成功，返回节点的地址 
} 

//查找：非递归函数实现，采用迭代的方式，效率比递归方式好 
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
	return NULL;//查找失败 
} 

//递归查找最小值，返回其地址 
Position FindMin(BinTree BST)
{
	if(!BST)
	    return NULL;
	else if(!BST->Left)
	    return BST;
	else
	    return FindMin(BST->Left);
} 
//迭代查找最大值，返回其地址 
Position FindMax(BinTree BST)
{
	if(BST)
	    while(BST->Right)
	        BST=BST->Right;
	return BST;
}


// 插入:递归方式 
BinTree Insert(ElementType X,BinTree BST) 
{
	if(!BST){
		//若原树为空，生成并返回一个结点的二叉搜索树 
		BST=malloc(sizeof(struct TreeNode));
		BST->Data=X;
		BST->Left=BST->Right=NULL;
	}else{//开始找要插入元素的位置 
	    if(X<BST->Data)
	        BST->Left=Insert(X,BST->Left);//递归插入左子树 
	    else if(X>BST->Data)
	        BST->Right=Insert(X,BST->Right);//递归插入右子树
	    }
	return BST; 
}

//删除：
 BinTree Delete(ElementType X,BinTree BST)
 {
 	Position Tmp;
 	if(!BST)
	    printf("要删除的元素未找到")；
	else{ 
	    if(X<BST->Data)
	        BST->Left=Delete(X,BST->Left);//左子树递归删除
	    else if(X>BST->Data)
	        BST->Right=Delete(X,BST->Right);//右子树递归删除
	    else{//找到要删除的结点
	        if(BST->Left&&BST->Right){//被删除结点有左右两个子结点 
	    	    Tmp=FindMin(BST->Right);//在右子树中找最小的元素填充删除结点
			    BST->Data=Tmp->Data;
			    BST->Right=Delete(BST->Data,BST->Right);
		    }else{//被删除结点有一个或无子结点 
			    Tmp=BST;
			    if(!BST->Left)//有右孩子或无子结点
			        BST=BST->Right;
			    else if(!BST->Right)//有左孩子或无子结点
			        BST=BST->Left;
			free(Tmp); 
		    }
	        }
        }
	return BST;
 } 
