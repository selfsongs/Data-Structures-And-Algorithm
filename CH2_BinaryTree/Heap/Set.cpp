//���鼯�ı�ʾ
//�ýṹ����洢

//��������ʦ��
typedef struct{
	ElementType Data;
	int parent;
}SetType;

//��������֮---����ĳ��Ԫ�����ڵļ���(�ø�����ʾ)
int Find(SetType S[],ElementType X)
{
	//������S�в���ֵΪX��Ԫ�������ļ���
	//MaxSize��ȫ�ֱ�����Ϊ����S����󳤶�
	int i;
	for(i=0;i<MaxSize&&S[i].Data!=X;i++);
	if(i>=MaxSize)return -1;//δ�ҵ�X,����-1
	for(;S[i].Parent>=0;i=S[i].Parent);//�ҵ������Ϊֹ 
	return i;//�ҵ�X�������ϣ������������������S�е�С�� 
} 

//��������֮---������
//�ֱ��ҵ�X1��X2����Ԫ�����ڼ������ĸ����
//������ǲ�ͬ����������һ�����ڵ�ĸ����ָ�����ó���һ�����ڵ�������±� 
void Union(SetType S[],ElementType X1,ElementType X2) 
{
	int Root1,Root2;
	Root1=Find(S,X1);
	Root2=Find(S,X2);
	if(Root2!=Root2) S[Root2].Parent=Root1; 
}

//Ϊ�˸��ƺϲ��Ժ�Ĳ������ܣ����Բ���С�ļ��Ϻϲ�����Դ�ļ�����
//�޸�Union������ǰ����������洢����ʱ��parent=-1�ı�ʾ�����
//����Ϊ�˻��ÿ�������ܹ��ж��ٸ�Ԫ�أ����Խ�������parent�޸�Ϊ: -Ԫ��������
//���磬һ��������5��Ԫ�أ�����Խ��������parent��Ϊ��-5�������������֪���˼��ϵ�Ԫ����Ŀ 





/**********************************************************************/ 

//��Խ��ʦ 
//�򻯵ļ��ϵı�ʾ
typedef int ElementType;//Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ
typedef int SetName;//Ĭ�ϸ������±���Ϊ��������
typedef ElementType[MaxSize] SetType;

SetName Find(SetType S,ElementType X)
{
	//Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1
	for(;S[X]>=0;X=S[X]);
	return X; 
}

//����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ����
void Union(SetType S,SetName Root1,SetName Root2)
{
	S[Root2]=Root1; 
}






