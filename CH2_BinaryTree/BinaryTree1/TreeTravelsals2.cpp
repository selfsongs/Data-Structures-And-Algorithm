//Tree  travelsals

//�ǵݹ��������,�Լ�ģ��ջ��ԭ��(�ݹ���ϵͳ��ջʵ�֣������ǾͿ����Լ���ջʵ��) 
//Push��˳��Ϊ�������,��Pop��˳������������


//��һ�����������������������Ľ��(������������)
//�����ó���������Ľ�����ݹ�ʵ�� 
//prel:�����������ĵ�һ����������pre�е��±�
//inL:�����������ĵ�һ����������in�е��±�
//postL:�����������ĵ�һ����������post�е��±� 
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
