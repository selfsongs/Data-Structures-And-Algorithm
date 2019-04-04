#include<stdio.h>
//��Խ��ʦ 
//�򻯵ļ��ϵı�ʾ
#define MaxSize 1000
typedef int ElementType;//Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ
typedef int SetName;//Ĭ�ϸ������±���Ϊ��������
typedef ElementType SetType[MaxSize];
/*typedef�������飬
  typedef char Line[81]
  Line text,line;//��ʾtext��line����char text[81];char line[81]
*/

void Union(SetType S,SetName Root1,SetName Root2);
SetName Find(SetType S,ElementType X);

void Initialization(SetType S,int n);
void Input_connection(SetType S);
void Check_connection(SetType S);
void Check_network(SetType S,int n);



int main()
{
	/*α���������� 
	��ʼ�����ϣ�
	do{
	        ����һ��ָ��
			����ָ��
		}while(û����) 
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
//����һ��Ԫ���Ƿ������У���������������±� 
SetName Find(SetType S,ElementType X)
{
//û�н���·��ѹ�� 
	//Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1
	for(;S[X]>=0;X=S[X]);
	return X; 
	
//�������ַ���������·��ѹ�� 
	if(S[X]<0) return X;
	else return S[X]=Find(S,S[X]); 
	//�ݹ飺���ҵ������ٰѸ����X�ĸ���㣬�ڷ��ظ�����±ꡣ 
}

void Union(SetType S,SetName Root1,SetName Root2)
{
	//S[Root2]=Root1; //����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ����

//����Ľ���������������,S[Root]=-���� 
   if(S[Root2]<S[Root1])//Root2������Root1���� 
        S[Root1]=Root2;
    else{//���� 
    	if(S[Root1]==S[Root2]) S[Root1]--;//���߼�һ�ȼ��ڸ�������--
		S[Root2]=Root1;//Root2���ߵ��ڻ����Root1���� 	
    }
    
//����Ľ�С�����������ϣ�S[Root]=-Ԫ�ظ���
/*    if(S[Root2]<S[Root1]){
    	S[Root2]+=S[Root1];//�ϲ�����ĸ�����Ԫ�ظ��� 
    	S[Root1]=Root2;
    }
    else{//���� 
    	S[Root1]+=S[Root2];//�ϲ�����ĸ�����Ԫ�ظ��� 
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
	scanf("%d %d",&u,&v);//��������u��v��1��ʼ��
	Root1=Find(S,u-1);      //��Ҫӳ�䵽�����±꣬��0��ʼ 
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








