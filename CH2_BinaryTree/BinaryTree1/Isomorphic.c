#include<stdio.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
    ElementType Element;
	Tree Left;
	Tree Right;	
}T1[MaxTree],T2[MaxTree];
Tree BuildTree(struct TreeNode T[]);

int main()
{
    Tree R1,R2;
	R1=BuildTree(T1);
	R2=BuildTree(T2);
	if(Isomorphic(R1,R2)) 
	    printf("Yes\n");
	    
	else printf("No\n");
    
    return 0;
}
//构建树，以静态链表(类似结构数组)的方式存储
Tree BuildTree(struct TreeNode T[])
{
    Tree Root=Null;
    int check[MaxTree];
    int N,i;
    char cl,cr,ch;
    scanf("%d\n",&N);
	if(N){
	        for(i=0;i<N;i++) check[i]=0;
	        for(i=0;i<N;i++){
			    scanf("%c %c %c",&T[i].Element,&cl,&cr);
			    ch=getchar();
			    if(cl!='-'){
				         T[i].Left=cl-'0';
						 check[T[i].Left]=1;//标记，方便找出根节点
				}
				else 
					T[i].Left=Null;
				if(cr!='-'){
					T[i].Right=cr-'0';
					check[T[i].Right]=1;
				}
				else
					T[i].Right=Null;
            }
			for(i=0;i<N;i++)
			    if(!check[i])break;
            Root=i;//根节点的下标			
        }
		return Root;
}		

//判断两棵树是否同构
int Isomorphic(Tree R1,Tree R2)
{
	//都为空,默认同构
    if((R1==Null)&&(R2==Null))
	    return 1;
	//一棵树为空，一棵树不为空
	if(((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null)))
		return 0;
	//根节点元素不相同
	if(T1[R1].Element!=T2[R2].Element)
		return 0;
	//根节点左孩子节点都为空,判断右子树是否一样
	if((T1[R1].Left==Null)&&(T2[R2].Left==Null))
		return Isomorphic(T1[R1].Right,T2[R2].Right);//递归
	//根节点左孩子节点都不为空且左子树的节点元素都一样，则判断左子树和左子树是否一样且右子树与右子树是否一样
	if((T1[R1].Left!=Null&&T2[R2].Left!=Null)&&(T1[T1[R1].Left].Element==T2[T2[R2].Left].Element))
	   return (Isomorphic(T1[R1].Left,T2[R2].Left)&&Isomorphic(T1[R1].Right,T2[R2].Right));
	//否则，判断两树是否同构
	//这里的否则包含两个含义：
	//1.根节点的左孩子节点一个为空，一个不为空;
	//2.根节点的左孩子节点都不为空，但左子树的节点元素不一样;
	else
		return(Isomorphic(T1[R1].Left,T2[R2].Right)&&Isomorphic(T1[R1].Right,T2[R2].Left));
}
