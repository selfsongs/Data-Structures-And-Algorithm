#include <stdio.h>
#define Tree int
#define Null -1
#define MAXSIZE 10
 
 
struct Node{
	char Element;
	Tree Left;
	Tree Right;
}T1[MAXSIZE], T2[MAXSIZE];
 
Tree BuildTree(struct Node T[])
{
	int N, i, Root;
	char ch, cl, cr;
	
	scanf("%d", &N);
	ch = getchar();
	
	int Check[N];
 
	for(i = 0; i < N; i++) Check[i] = 0;	//为了标记根节点 ，因为没有节点指向根节点 
	for(i = 0; i < N; i++){
		scanf("%c %c %c", &T[i].Element, &cl, &cr);
		ch = getchar();
		if(cl != '-'){
			T[i].Left = cl - '0';
			Check[T[i].Left] = 1;
		}
		else
			T[i].Left = Null;
		if(cr != '-'){
			T[i].Right = cr - '0';
			Check[T[i].Right] = 1;
		}
		else
			T[i].Right = Null;	
	}
	for(i = 0; i < N; i++)			//遍历找到根节点 
		if(Check[i] == 0)
			break;
		Root = i;		
	return Root;		
}
 
int Isomorphic(Tree R1, Tree R2)
{
	//两树都为空 
	if(R1 == Null && R2 == Null)
		return 1;
	//空树和非空树	
	if((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null))
		return 0;
	//两树的根节点不一样	
	if(T1[R1].Element != T2[R2].Element)
		return 0;
	//若过两树的左子树都空，判断右子树是否一样	
	if(T1[R1].Left == Null && T2[R2].Left == Null)
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	//若两树的左子树不空，并且左子树的结点元素都一样，判断左右子树是否一样	
	if((T1[R1].Left != Null && T2[R2].Left != Null) && (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element))
		return Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right);
	else
	//否则 判断两树是否同构 
		return Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left);				
}
 
int main()
{
	Tree R1, R2;
	
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if(Isomorphic(R1, R2)) 
	    printf("Yes");	
	else
		printf("No");
	return 0;
}

