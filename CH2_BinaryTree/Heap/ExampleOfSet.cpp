#include<stdio.h>
//陈越老师 
//简化的集合的表示
#define MaxSize 1000
typedef int ElementType;//默认元素可以用非负整数表示
typedef int SetName;//默认根结点的下标作为集合名称
typedef ElementType SetType[MaxSize];
/*typedef用于数组，
  typedef char Line[81]
  Line text,line;//表示text，line都是char text[81];char line[81]
*/

void Union(SetType S,SetName Root1,SetName Root2);
SetName Find(SetType S,ElementType X);

void Initialization(SetType S,int n);
void Input_connection(SetType S);
void Check_connection(SetType S);
void Check_network(SetType S,int n);



int main()
{
	/*伪代码描述： 
	初始化集合：
	do{
	        读入一条指令
			处理指令
		}while(没结束) 
	return 0;*/
	
	SetType S;
	int n;
	char in;
	scanf("%d",&n);
	Initialization(S,n);
	do{
		scanf("%c",&in);
		switch(in){
			case 'I':Input_connection(S);break;
			case 'C':Check_connection(S);break;
			case 'S':Check_network(S,n);break; 
		}
	} while(in!='S');
	
	return 0;
} 
//查找一个元素是否在树中，并返回其根结点的下标 
SetName Find(SetType S,ElementType X)
{
//没有进行路径压缩 
	//默认集合元素全部初始化为-1
	for(;S[X]>=0;X=S[X]);
	return X; 
	
//下面这种方法进行了路径压缩 
	if(S[X]<0) return X;
	else return S[X]=Find(S,S[X]); 
	//递归：先找到根，再把根变成X的父结点，在返回根结点下标。 
}

void Union(SetType S,SetName Root1,SetName Root2)
{
	//S[Root2]=Root1; //这里默认Root1和Root2是不同集合的根结点

//下面的将矮树贴到高树上,S[Root]=-树高 
   if(S[Root2]<S[Root1])//Root2树高于Root1树高 
        S[Root1]=Root2;
    else{//否则 
    	if(S[Root1]==S[Root2]) S[Root1]--;//树高加一等价于负的树高--
		S[Root2]=Root1;//Root2树高低于或等于Root1树高 	
    }
    
//下面的将小树贴到大树上，S[Root]=-元素个数
/*    if(S[Root2]<S[Root1]){
    	S[Root2]+=S[Root1];//合并后更改根结点的元素个数 
    	S[Root1]=Root2;
    }
    else{//否则 
    	S[Root1]+=S[Root2];//合并后更改根结点的元素个数 
    	S[Root2]=Root1;
    }
*/ 
}



void Initialization(SetType S,int n)
{
	for(int i=0;i<n;i++)
	    S[i]=-1;
}

void Input_connection(SetType S)
{
	ElementType u,v;
	SetName Root1,Root2;
	scanf("%d %d",&u,&v);//计算机标号u，v从1开始，
	Root1=Find(S,u-1);      //需要映射到数组下标，从0开始 
	Root2=Find(S,v-1);
	if(Root1!=Root2)
	    Union(S,Root1,Root2);
}

void Check_connection(SetType S)
{
	ElementType u,v;
	SetName Root1,Root2;
	scanf("%d %d",&u,&v);
	Root1=Find(S,u-1);
	Root2=Find(S,v-1);
	if(Root1==Root2)
	    printf("yes\n");
	else printf("no\n");
}


void Check_network(SetType S,int n)
{
	int i,counter=0;
	for(i=0;i<n;i++){
		if(S[i]<0)
		    counter++;
	}
	if(counter==1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n",counter);
}








