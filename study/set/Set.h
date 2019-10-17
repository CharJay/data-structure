//˼�룬��������ռ䡾��������Ķ����ơ���Ȼ����һЩ�����Ʋ��������࣬�롿�ж�ֵ�Ƿ������������ 
typedef struct bitset * Set;
typedef struct bitset {
	int  setsize;	   	//���ϴ�С
	int  arraysize;	   	//λ�����С
	unsigned short *v;	//λ����
} Bitset;

//���ϳ�ʼ��
Set SetInit(int size) {
	int i;
	Set S = (bitset *)malloc(sizeof *S);
	S->setsize = size;
	//�洢��СΪ setsize �ļ���������޷��Ŷ�����λ��
	S->arraysize = (size+15)>>4;//ΪʲôҪ��15����Ϊ����Ԫ����33����33+15����16����2����ôv[0],v[1]ֻ�ܴ�32��Ԫ�أ�����Ҫ��15����v[3]
	S->v=(unsigned short *)malloc(size*sizeof(unsigned short));
	for(i=0; i<size; i++)
		S->v[i]=0;
	return S;
}

//��ֵ
void SetAssign(Set A,Set B) {
	int i;
	if(A->setsize!= B->setsize) throw "Sets are not the same size";
	for(i=0; i<A->arraysize; i++) A->v[i] = B->v[i];
}

//λ���κ���
unsigned short BitMask(int x) {
	//17 & 15 = 1
	//int(x) & 15 ȡ����� ����16ȡ�� 
	return 1 << (int(x) & 15);//���������Ȼ���1��������λ��Ŀ�ģ���--������x=17����ô���� yyyy000010 
}
//�±궨λ��������ѯһ��Ԫ��x��Ҫ�ȶ�λ���Ǹ�v[0],v[1],v[3]����  
int ArrayIndex(int x) {
	//����16�Ϳ��Զ�λԪ�����Ǹ��������� 
	return int(x) >> 4;//����������˵������1λ�൱�ڳ���2��Ŀ�ģ���--������x=17��ô����v[1](31~16)  xxxx000010 ���е�1����17�� 
}
//��ȡ���ж�Ԫ���Ƿ����
int SetMember(int x, Set S) {
	if (x < 0 || x >= S->setsize) throw "BadInput";
	return S->v[ArrayIndex(x)] & BitMask(x);//--��ע�⣺����� yyyy000010  �� xxxx000010 ��&����1����ô֤��17�����ڼ����� 
}

//����
void SetInsert(int x,Set S) {
	if(x<0||x>=S->setsize) throw "Invalid member refence";
	S->v[ArrayIndex(x)] |= BitMask(x);//--���û�����Ѵ��� 1|1���� = 1��������0|1=1 ��ֵ���ȥ�� 
}
//ɾ��
void SetDelete(int x,Set S) {
	if(x<0||x>=S->setsize) throw "Invalid member refence";
	S->v[ArrayIndex(x)] &=~ BitMask(x);  //--������ 1.~ BitMask(x) ������һ�� 000100 -> 111011 �����������������Ԫ�����룬�ͻ�ѵ�3��Ԫ����0�����ұ�֤����Ԫ�ز��� 
}


//�жϼ�����ͬ
int SetEqual(Set A,Set B) {
	int i,retval = 1;
	if(A->setsize!= B->setsize) throw "Sets are not the same size";
	for(i=0; i<A->arraysize; i++)
		if(A->v[i]!=B->v[i]) {
			retval = 0;
			break;
		}
	return retval;
}

//����
Set SetUnion(Set A, Set B) {
	int i;
	Set tmp=SetInit(A->setsize);
	for (i = 0; i < A->arraysize; i++) tmp->v[i] = A->v[i] | B->v[i];
	return tmp;
}

//����
Set SetIntersection(Set A,Set B) {
	int i;
	Set tmp=SetInit(A->setsize);
	for (i = 0; i < A->arraysize; i++) tmp->v[i] = A->v[i] & B->v[i];
	return tmp;
}

//�
Set SetDifference(Set A,Set B) {
	int i;
	Set tmp=SetInit(A->setsize);
	for (i = 0; i < A->arraysize; i++) tmp->v[i] = A->v[i] ^ (A->v[i] & B->v[i]);
	return tmp;
}


