typedef int ElemType;      //��ջԪ������Ϊint��ElemType����java�ķ��ͣ� 
# include <iostream>
# include <iomanip>
# include "stdio.h"         
# include "stdlib.h"  

# include "SqStack.h"
# include "LinkStack.h" 

using namespace std;

int seqStackTest() {
	SqStack mystack;
	int i,x,a[]= {6,8,16,2,34,56,7,10,22,45,62,88,90,3,9};
	InitStack_Sq(mystack,10,10);             // ��ʼ��˳��ջ
	for(i=0; i<12; i++)
		if(!Push_Sq(mystack,a[i])) {             // a[i]���ν�˳��ջ
			cout<<"��ջʧ�ܣ�"<<endl;
			return 0;
		}
	if(!GetTop_Sq(mystack,x)) {           // ȡջ��Ԫ�ز���ֵ��x
		cout<<"ȡջ��Ԫ��ʧ�ܣ�"<<endl;
		return 0;
	}

	cout<<"��ǰջ������Ԫ���ǣ�"<<x<<endl;
	cout<<"��ǰ˳��ջ�ĳ����ǣ�"<<StackLength_Sq(mystack)<<endl;
	cout<<"���γ�ջ������Ԫ������Ϊ��";
	while(!StackEmpty_Sq(mystack)) {      // ��ջ�Ƿ�ǿ�
		if(!Pop_Sq(mystack,x)) {            // ջ��Ԫ�س�ջ����ֵ��x
			cout<<"��ջʧ�ܣ�"<<endl;
			return 0;
		}
		cout<<x<<' ';
	}
	cout<<endl;
	cout<<"��ǰ˳��ջ�ĳ����ǣ�"<<StackLength_Sq(mystack)<<endl;
	cout<<endl;
	DestroyStack_Sq(mystack);           // ����˳��ջ
}

void linkStackTest() {
	LinkStack mystack;
	int i,x,a[]= {6,8,16,2,34,56,7,10,22,45,62,88};
	InitStack_L(mystack);                 // ��ʼ����ջ
	for(i=0; i<12; i++)
		if(!Push_L(mystack,a[i])) {          // a[i]���ν���ջ
			cout<<"��ջʧ�ܣ�"<<endl;
			return;
		}
	if(!GetTop_L(mystack,x)) {           // ȡջ��Ԫ�ز���ֵ��x
		cout<<"ȡջ��Ԫ��ʧ�ܣ�"<<endl;
		return;
	}
	cout<<"��ǰջ������Ԫ���ǣ�"<<x<<endl;
	cout<<"��ǰ��ջ�ĳ����ǣ�"<<StackLength_L(mystack)<<endl;
// ����ջ�ĳ��Ȳ����
	cout<<"���γ�ջ������Ԫ������Ϊ��";
	while(!StackEmpty_L(mystack)) {     // ��ջ�Ƿ�ǿ�
		if(!Pop_L(mystack,x)) {            // ջ��Ԫ�س�ջ����ֵ��x
			cout<<"��ջʧ�ܣ�"<<endl;
			return;
		}
		cout<<x<<' ';
	}
	cout<<endl;
	cout<<"��ǰ��ջ�ĳ����ǣ�"<<StackLength_L(mystack)<<endl;
	cout<<endl;
	DestroyStack_L(mystack);             // ������ջ
}

int main() {
//	seqStackTest();
	linkStackTest();
	return 0;
}
