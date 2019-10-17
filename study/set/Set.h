//思想，开辟数组空间【都是他妈的二进制】，然后用一些二进制操作【求余，与】判断值是否存在于数组中 
typedef struct bitset * Set;
typedef struct bitset {
	int  setsize;	   	//集合大小
	int  arraysize;	   	//位数组大小
	unsigned short *v;	//位数组
} Bitset;

//集合初始化
Set SetInit(int size) {
	int i;
	Set S = (bitset *)malloc(sizeof *S);
	S->setsize = size;
	//存储大小为 setsize 的集合所需的无符号短整数位数
	S->arraysize = (size+15)>>4;//为什么要加15？因为加设元素有33个，33+15除以16等于2，那么v[0],v[1]只能存32个元素！所以要加15扩大到v[3]
	S->v=(unsigned short *)malloc(size*sizeof(unsigned short));
	for(i=0; i<size; i++)
		S->v[i]=0;
	return S;
}

//赋值
void SetAssign(Set A,Set B) {
	int i;
	if(A->setsize!= B->setsize) throw "Sets are not the same size";
	for(i=0; i<A->arraysize; i++) A->v[i] = B->v[i];
}

//位屏蔽函数
unsigned short BitMask(int x) {
	//17 & 15 = 1
	//int(x) & 15 取余操作 ，对16取余 
	return 1 << (int(x) & 15);//求出余数，然后把1左移余数位，目的？？--》假设x=17，那么返回 yyyy000010 
}
//下标定位函数：查询一个元素x，要先定位在那个v[0],v[1],v[3]里面  
int ArrayIndex(int x) {
	//除以16就可以定位元素在那个数组里面 
	return int(x) >> 4;//对于正数来说，右移1位相当于除以2，目的？？--》假设x=17那么返回v[1](31~16)  xxxx000010 其中的1代表17！ 
}
//读取，判断元素是否存在
int SetMember(int x, Set S) {
	if (x < 0 || x >= S->setsize) throw "BadInput";
	return S->v[ArrayIndex(x)] & BitMask(x);//--》注意：上面的 yyyy000010  与 xxxx000010 相&返回1，那么证明17存在于集合中 
}

//插入
void SetInsert(int x,Set S) {
	if(x<0||x>=S->setsize) throw "Invalid member refence";
	S->v[ArrayIndex(x)] |= BitMask(x);//--》用或，如果已存在 1|1还是 = 1，不存在0|1=1 把值填进去！ 
}
//删除
void SetDelete(int x,Set S) {
	if(x<0||x>=S->setsize) throw "Invalid member refence";
	S->v[ArrayIndex(x)] &=~ BitMask(x);  //--》两步 1.~ BitMask(x) 对它非一下 000100 -> 111011 这样再与数组里面的元素相与，就会把第3个元素置0，并且保证其他元素不变 
}


//判断集合相同
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

//并集
Set SetUnion(Set A, Set B) {
	int i;
	Set tmp=SetInit(A->setsize);
	for (i = 0; i < A->arraysize; i++) tmp->v[i] = A->v[i] | B->v[i];
	return tmp;
}

//交集
Set SetIntersection(Set A,Set B) {
	int i;
	Set tmp=SetInit(A->setsize);
	for (i = 0; i < A->arraysize; i++) tmp->v[i] = A->v[i] & B->v[i];
	return tmp;
}

//差集
Set SetDifference(Set A,Set B) {
	int i;
	Set tmp=SetInit(A->setsize);
	for (i = 0; i < A->arraysize; i++) tmp->v[i] = A->v[i] ^ (A->v[i] & B->v[i]);
	return tmp;
}


