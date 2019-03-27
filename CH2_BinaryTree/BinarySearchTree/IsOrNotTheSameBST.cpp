//�Ƿ���ͬһ��������������
/*
����һ���������оͿ���Ψһȷ��һ�ö�����������
Ȼ����һ�ø����Ķ�����ȴ�����ɶ��ֲ�ͬ�Ĳ������еõ��� 
�б����������Ƿ��Ӧ��ͬ�������ķ�����
1���ֱ��������������б𷽷� ��������������Ȼ��Ƚϸ��ڵ�Ԫ�أ����ҽ��Ԫ�أ��ݹ�Ƚϡ� 
2�����������б𷽷� :�Ը������Ϊ�ֽ��ߣ������ݷ�Ϊ�������ߣ���ȥ�Ƚϣ��ݹ� 
3����һ���������б����������Ƿ������һ�� ��(1)��������ʾ (2)��������T (3) �б�һ�����Ƿ���������Tһ�¡� 
*/ 

//(1)��������ʾ
typedef struct TreeNode* Tree;
struct TreeNode{
	int v;
	Tree Left,Right;
	int flag;//�б��Ƿ񱻷����˵ı�־ 
};

//��Ҫ��Ƶ���Ҫ������
//(1)�����ݽ�������T
//(2)�б�һ�����Ƿ���T����һ���������� 

//������
int main()
{
	//��ÿ������
	//����N��L
	//���ݵ�һ�����н���T
	//������T�ֱ��б�����L�������Ƿ�����T�γ�ͬһ��������������
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
			ResetT(T);//���T�еı�־flag 
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
	int i,V,flag=0;//flag��0����Ŀǰ��һ�£�1�����Ѿ���һ��
	//ע�������flag��TreeNode�еĽṹ�岻һ�� ��
	//��������flag��Ϊ�˱�֤����ʹ���ֲ�һ���ˣ�Ҳ�����Ͼͷ��أ� 
	//���Ǽ����Ѵ˴ε�N����������� 
	scanf("%d",&V);
	if(V!=T->v)
	    flag=1;
	else
	    T->flag=1;//T->flag����flagӴ 
	for(i=1;i<N;i++){
		scanf("%d",&V);
		if((!flag)&&(!check(T,V)))//������flag=1,��check(T,V)���ᱻ���� 
		    flag=1;
	}
	if(flag)
	    return 0;
	else
	    return 1;
}

//���T�и�������flag��־
void ResetT(Tree T){
	if(T->Left)
	    ResetT(T->Left);
	if(T->Right)
	    ResetT(T->Right);
	T->flag=0;
} 

//�ͷ�T�Ŀռ�
void FreeTree(Tree T){
	if(T->Left)
	    FreeTree(T->Left);
	if(T->Right)
	    FreeTree(T->Right);
	free(T);
}
