//是否是同一棵搜索树的问题
/*
给定一个插入序列就可以唯一确定一棵二叉搜索树。
然而，一棵给定的二叉树却可以由多种不同的插入序列得到。 
判别两个序列是否对应相同搜索树的方法：
1：分别建两棵搜索树的判别方法 ：建立两棵树，然后比较根节点元素，左右结点元素，递归比较。 
2：不建树的判别方法 :以根结点作为分界线，将数据分为左右两边，再去比较，递归 
3：建一棵树，在判别其他序列是否与该树一致 ：(1)搜索树表示 (2)建搜索树T (3) 判别一序列是否与搜索树T一致。 
*/ 

//(1)搜索树表示
typedef struct TreeNode* Tree;
struct TreeNode{
	int v;
	Tree Left,Right;
	int flag;//判别是否被访问了的标志 
};

//需要设计的主要函数：
//(1)读数据建搜索树T
//(2)判别一序列是否与T构成一样的搜索树 

//程序框架
int main()
{
	//对每组数据
	//读入N和L
	//根据第一行序列建树T
	//依据树T分别判别后面的L个序列是否能与T形成同一搜索树并输出结果
    int N L i;
	Tree T;
	scanf("%d",&N);
	while(N){
		scanf("%d",&L);
		T=MakeTree(N);
		for(i=0;i<L;i++){
			if(Judge(T,N)) 
			    printf("Yes\n");
			else 
			    printf("No\n");
			ResetT(T);//清除T中的标志flag 
		}
		FreeTree(T);
		scanf("%d",&N);
	}	
	return 0;
	 
} 


Tree MakeTree(int N)
{
	Tree T;
	int i,V;
	scanf("%d",&V);
	T=NewNode(V);
	for(i=1;i<N;i++){
		scanf("%d",&V);
		T=Insert(T,V);
	}
	return T;
}

Tree Insert(Tree T,int V)
{
	if(!T)
	    T=NewNode(V);
	else{
		if(V>T-v)
		    T->Right=Insert(T->Right,V);
		else
		    T->Left=Insert(T->Left,V); 
	}
	return T;
}

Tree NewNode(int V)
{
	Tree T=(Tree)malloc(sizeof(struct TreeNode));
	T->v=V;
	T->Left=T->Right=NULL;
	T->flag=0;
	return T;
}

int check(Tree T,int V)
{
	if(T->flag){
		if(V<T->v)
		    return check(T->Left,V);
		else if(V>T->v)
		    return check(T->Right,V);
		else 
		    return 0;
	}
	else{
		if(V==T->v){
			T->flag=1;
			return 1;
		}
		else
		    return 0;
	}
}

int Judge(Tree T,int N)
{
	int i,V,flag=0;//flag：0代表目前还一致，1代表已经不一致
	//注意这里的flag与TreeNode中的结构体不一样 ，
	//这里设置flag是为了保证，即使出现不一致了，也不马上就返回， 
	//而是继续把此次的N个数输入完成 
	scanf("%d",&V);
	if(V!=T->v)
	    flag=1;
	else
	    T->flag=1;//T->flag不是flag哟 
	for(i=1;i<N;i++){
		scanf("%d",&V);
		if((!flag)&&(!check(T,V)))//这里若flag=1,则check(T,V)不会被调用 
		    flag=1;
	}
	if(flag)
	    return 0;
	else
	    return 1;
}

//清除T中各个结点的flag标志
void ResetT(Tree T){
	if(T->Left)
	    ResetT(T->Left);
	if(T->Right)
	    ResetT(T->Right);
	T->flag=0;
} 

//释放T的空间
void FreeTree(Tree T){
	if(T->Left)
	    FreeTree(T->Left);
	if(T->Right)
	    FreeTree(T->Right);
	free(T);
}
