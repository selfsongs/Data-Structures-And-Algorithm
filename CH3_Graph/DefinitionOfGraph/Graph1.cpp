#include<stdio.h>
#include<stdlib.h>
//���ڽӾ����ʾͼ
#define MaxVertexNum 1000
typedef int DataType;
typedef int WeightType;
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;//������
	int Ne;//����
	WeightType G[MaxVertexNum][MaxVertexNum]; 
	DataType Data[MaxVertexNum];//�涥������� 
}; 
typedef PtrToGNode MGraph;//���ڽӾ���洢��ͼ����
typedef int Vertex;//�ö����±��ʾ���㣬Ϊ���� 

//��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
MGraph CreateGraph(int VertexNum)
{
	Vertex V,W; 
	MGraph Graph;
	Graph=(MGraph)malloc(sizeof(struct GNode));
	Graph->Nv=VertexNum;
	Graph->Ne=0;
	//����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv-1)
	for(V=0;V<Graph->Nv;V++)
	    for(W=0;W<Graph->Nv;W++)
		    Graph->G[V][W]=0;//
	return Graph; 
}

typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1,V2;//�����<V1,V2>
	WeightType Weight;//Ȩ�� 
	
};
typedef PtrToENode Edge;
//����� 
void InsertEdge(MGraph Graph,Edge E)
{
	//�����<V1,V2>
	Graph->G[E->V1][E->V2]=E->Weight;
	//��������ͼ����Ҫ�����<V2,V1>
	Graph->G[E->V2][E->V1]=E->Weight;
}
//��һ��ͼ�ķ���һ 
MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv,i;
	
	scanf("%d",&Nv);
	Graph=CreateGraph(Nv);
	scanf("%d",&(Graph->Ne));
	if(Graph->Ne!=0){
		E=(Edge)malloc(sizeof(struct ENode));
		for(i=0;i<Graph->Ne;i++){
			scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
			InsertEdge(Graph,E);
		}
	}
	//������������ݵĻ�����������
	for(V=0;V<Graph->Nv;V++)
	    scanf("%c",&(Graph->Data[V]));
	return Graph;
} 

//��һ��ͼ�ķ�����:��һ�룬���Ϊɶû����ķ���һ�� 
/*int G[MaxVertexNum][MaxVertexNum],Nv,Ne;
void BuildGraph()
{
	int i,j,v1,v2,w;
	scanf("%d",&Nv);
	//CreateGraph
	for(i=0;i<Nv;i++) 
	    for(j=0;j<Nv;j++)
	        G[i][j]=0;
	scanf("%d",&Ne);
	for(i=0;i<Ne;i++){
		scanf("%d %d %d",&v1,&v2,&w);
	//InsertEdge
		G[v1][v2]=w;
		G[v2][v1]=w;
	}
} 
*/



//���ڽӱ��ʾͼ
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;//�ڽӵ��±�
	WeightType Weight;//��Ȩ��
	PtrToAdjVNode Next; 
};

typedef struct Vnode{
	PtrToAdjVNode FirstEdge;
	DataType Data;//�涥������� 
}AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;//������ 
	int Ne;//���� 
	AdjList G;//�ڽӱ� 
}; 
typedef PtrToGNode LGraph;//���ڽӱ�ʽ�洢��ͼ���� 

//LGraph��ʼ��
 typedef int Vertex;//�ö����±��ʾ���㣬Ϊ����
 LGraph CreateGraph(int VertexNum)
 {
 	Vertex V,W;
 	LGraph Graph;
 	Graph=(LGraph)malloc(sizeof(struct GNode));
 	Graph->Nv=VertexNum;
 	Graph->Ne=0;
 	
 	//Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv-1)
	 for(V=0;V<Graph->Nv;V++)
	     Graph->G[V].FirstEdge=NULL;
	 return Graph;
 }

//��LGraph�����
void InsetEdge(LGraph Graph,Edge E)
{
	/******�����<V1,V2>***********/
	//ΪV2�����µ��ڽӵ�
	 NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	 NewNode->AdjV=E->V2;
	 NewNode->Weight=E->Weight;
	 //��V2����V1�ı�ͷ
	 NewNode->Next=Graph->G[E->V1].FirstEdge;
	 Graph->G[E->V1].FirstEdge=NewNode; 
	 
	 /******��Ϊ����ͼ����Ҫ�����<V2,V1>***********/
	//ΪV1�����µ��ڽӵ�
	 NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	 NewNode->AdjV=E->V1;
	 NewNode->Weight=E->Weight;
	 //��V1����V2�ı�ͷ
	 NewNode->Next=Graph->G[E->V2].FirstEdge;
	 Graph->G[E->V2].FirstEdge=NewNode; 	 
} 

LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv,i;
	
	scanf("%d",&Nv);
	Graph=CreateGraph(Nv);
	scanf("%d",&(Graph->Ne));
	if(Graph->Ne!=0){
		E=(Edge)malloc(sizeof(struct ENode));
		for(i=0;i<2*Graph->Ne;i++){//Ne���ߣ���ÿ���ߵ��������㻥Ϊ�ڽӵ㣬 �ܹ�Ҫѭ��2*Ne�� 
			scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
			InsertEdge(Graph,E);
		}
	}
	//������������ݵĻ�����������
	for(V=0;V<Graph->Nv;V++)
	    scanf("%c",&(Graph->G[V].Data));
	return Graph;
	
} 
