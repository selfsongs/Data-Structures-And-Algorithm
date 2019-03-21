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
 
	for(i = 0; i < N; i++) Check[i] = 0;	//Ϊ�˱�Ǹ��ڵ� ����Ϊû�нڵ�ָ����ڵ� 
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
	for(i = 0; i < N; i++)			//�����ҵ����ڵ� 
		if(Check[i] == 0)
			break;
		Root = i;		
	return Root;		
}
 
int Isomorphic(Tree R1, Tree R2)
{
	//������Ϊ�� 
	if(R1 == Null && R2 == Null)
		return 1;
	//�����ͷǿ���	
	if((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null))
		return 0;
	//�����ĸ��ڵ㲻һ��	
	if(T1[R1].Element != T2[R2].Element)
		return 0;
	//�������������������գ��ж��������Ƿ�һ��	
	if(T1[R1].Left == Null && T2[R2].Left == Null)
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	//�����������������գ������������Ľ��Ԫ�ض�һ�����ж����������Ƿ�һ��	
	if((T1[R1].Left != Null && T2[R2].Left != Null) && (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element))
		return Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right);
	else
	//���� �ж������Ƿ�ͬ�� 
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

