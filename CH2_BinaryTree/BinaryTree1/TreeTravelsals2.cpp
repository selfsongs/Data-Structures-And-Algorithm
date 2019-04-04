//Tree  travelsals

//非递归中序遍历,自己模拟栈的原理(递归是系统用栈实现，那我们就可以自己用栈实现) 
//Push的顺序为先序遍历,则Pop的顺序给出中序遍历


//由一棵树的先序遍历和中序遍历的结果(保存在数组中)
//怎样得出后序遍历的结果：递归实现 
//prel:先序遍历结果的第一个数在数组pre中的下标
//inL:中序遍历结果的第一个数在数组in中的下标
//postL:后序遍历结果的第一个数在数组post中的下标 
void solve(int preL,int inL,int postL,int n)
{
	if(n==0) return ;
	if(n==1) {
		post[postL]=pre[preL]; 
		return ;
	}
	root=pre[preL];
	post[postL+n-1]=root;
	for(i=0;i<n;i++)
	    if(in[inL+i]==root) break;
	L=i;R=n-L-1;
	solve(preL+1,inL,postL,L);
	solve(preL+L+1,inL+1,postL+L,R); 
} 
