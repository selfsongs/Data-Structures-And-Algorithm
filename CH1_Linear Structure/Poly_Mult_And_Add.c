#include<stdlib.h> 
#include<stdio.h>

typedef struct PolyNode* Polynomial;
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
}; 

Polynomial ReadPoly();
Polynomial Mult(Polynomial,Polynomial);
Polynomial Add(Polynomial,Polynomial);
void PrintPoly(Polynomial);
void Attach(int ,int ,Polynomial *); 

int main()
{
	Polynomial P1,P2,PP,PS;
	P1=ReadPoly();
	P2=ReadPoly();
	PP=Mult(P1,P2);
	PrintPoly(PP);
	PS=Add(P1,P2);
	PrintPoly(PS);
	
	return 0; 
}
void Attach(int c,int e,Polynomial *pRear)
{
	Polynomial P;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->coef=c;
	P->expon=e;
	P->link=NULL;
	(*pRear)->link=P;
	*pRear=P;
}
Polynomial ReadPoly()
{
	Polynomial P,Rear,t; 
	int N,c,e;
	scanf("%d",&N);
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->link=NULL;
	Rear=P;
	while(N--){
		scanf("%d %d",&c,&e);
		Attach(c,e,&Rear);
	}
	t=P;P=P->link;free(t);//删除临时生成的头节点 
	return P;
}

Polynomial Add(Polynomial P1,Polynomial P2)
{
	Polynomial P,Rear,t1,t2,t;
	t1=P1;t2=P2;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->link=NULL;
	Rear=P;
	while(t1&&t2){
		if(t1->expon==t2->expon){
			Attach(t1->coef+t2->coef,t1->expon,&Rear);
			t1=t1->link;t2=t2->link;
		}
		else if(t1->expon>t2->expon){
			Attach(t1->coef,t1->expon,&Rear);
			t1=t1->link;
		}
		else{
			Attach(t2->coef,t2->expon,&Rear);
			t2=t2->link;
		}
	}
	while(t1){
		Attach(t1->coef,t1->expon,&Rear);
		t1=t1->link;
	}
	while(t2){
		Attach(t2->coef,t2->expon,&Rear);
		t2=t2->link;
	}
	t=P;P=P->link;free(t);//删除临时生成的头节点 
	return P;
} 

Polynomial Mult(Polynomial P1,Polynomial P2)
{
	Polynomial P,Rear,t1,t2,t;
	int c,e;
	if(!P1||!P2) return NULL;
	t1=P1;t2=P2;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->link=NULL;
	Rear=P; 
	while(t2){//先用P1的第一项乘以P2得到P
	    Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
		t2=t2->link; 	
	}
	t1=t1->link;
	while(t1){
		t2=P2;Rear=P;
		while(t2){
			e=t1->expon+t2->expon;
			c=t1->coef*t2->coef;
			while(Rear->link&&Rear->link->expon>e)
			   Rear=Rear->link;
			if(Rear->link&&Rear->link->expon==e){
				if(Rear->link->coef+c) //排除系数相加为0 
			        Rear->link->coef+=c;//相同次幂的系数加上去 
			    else{//系数相加为0的项从链表删除 
			    	t=Rear->link;
			    	Rear->link=t->link;
			    	free(t);
			    } 
			}else{//到达链表尾部或者找到应该插入的节点位置了 
			    
				/*t=(Polynomial)malloc(sizeof(struct PolyNode));
				t->link=NULL;
				t->coef=c;t->expon=e;
				t->link=Rear->link
				Rear->link=t;Rear=Rear; 
			    */
			    
				t=Rear->link;//保存插入点的下一个节点 
				Attach(c,e,&Rear);//插入节点 
				Rear->link=t;// 
			}
			t2=t2->link;
		}
		t1=t1->link;
	}
	t=P;P=P->link;free(t);//删除临时生成的头节点
	return P;
}

void PrintPoly(Polynomial P)
{
	int flag=0;//辅助调整输出格式 
	if(!P){
		printf("0 0\n");
		return ;
	}
	while(P){
		if(!flag)
		    flag=1;
		else
		    printf(" ");
		    
		printf("%d %d",P->coef,P->expon);
		P=P->link;	    
	}
	printf("\n");
}
