//Complete Binary Search Tree:完全二叉搜索树
//题目:要求输入一串数据，程序以完全二叉搜索树的形式保存，
//     然后输出这颗树层序遍历的结果 

//树的表示法：链表 VS 数组
//分析：需要的操作：1:填写数字(某种遍历);2:层序遍历
//      一般情况用链表，
//但这里是完全二叉树，不浪费空间，而且用数组保存，层序遍历==直接按数组下标顺序输出
//所以选择数组 

//假设在输入一系列数后，我们已将它们排序好放在一个数组A中,输出结果保存在T数组中 
//ALeft:当前这一段最左边的下标 
//ARight:当前这一段最右边的下标 
//TRoot:当前这一段的根结点的下标
void solve(int ALeft,int ARight,int TRoot)
{
	//初始调用为solve(0,N-1,0)
	n=ARight-ALeft+1;
	if(n==0) return ;
	L=GetLeftLength(n);//计算出n个结点的树其左子树有多少个结点
	T[TRoot]=A[ALeft+L];//当前根结点的下标 
	LeftTRoot=TRoot*2+1;//在当前根结点下的左孩子结点的下标 
	RightTRoot=LeftTRoot+1;//在当前根结点下的右孩子结点的下标 
	solve(ALeft,ALeft+L-1,LeftTRoot);
	sovle(ALeft+L+1,ARight,RightTRoot); 
} 
