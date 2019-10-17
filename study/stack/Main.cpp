typedef int ElemType;      //链栈元素类型为int（ElemType很像java的泛型） 
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
	InitStack_Sq(mystack,10,10);             // 初始化顺序栈
	for(i=0; i<12; i++)
		if(!Push_Sq(mystack,a[i])) {             // a[i]依次进顺序栈
			cout<<"进栈失败！"<<endl;
			return 0;
		}
	if(!GetTop_Sq(mystack,x)) {           // 取栈顶元素并赋值给x
		cout<<"取栈顶元素失败！"<<endl;
		return 0;
	}

	cout<<"当前栈顶数据元素是："<<x<<endl;
	cout<<"当前顺序栈的长度是："<<StackLength_Sq(mystack)<<endl;
	cout<<"依次出栈的数据元素序列为：";
	while(!StackEmpty_Sq(mystack)) {      // 判栈是否非空
		if(!Pop_Sq(mystack,x)) {            // 栈顶元素出栈并赋值给x
			cout<<"出栈失败！"<<endl;
			return 0;
		}
		cout<<x<<' ';
	}
	cout<<endl;
	cout<<"当前顺序栈的长度是："<<StackLength_Sq(mystack)<<endl;
	cout<<endl;
	DestroyStack_Sq(mystack);           // 撤销顺序栈
}

void linkStackTest() {
	LinkStack mystack;
	int i,x,a[]= {6,8,16,2,34,56,7,10,22,45,62,88};
	InitStack_L(mystack);                 // 初始化链栈
	for(i=0; i<12; i++)
		if(!Push_L(mystack,a[i])) {          // a[i]依次进链栈
			cout<<"进栈失败！"<<endl;
			return;
		}
	if(!GetTop_L(mystack,x)) {           // 取栈顶元素并赋值给x
		cout<<"取栈顶元素失败！"<<endl;
		return;
	}
	cout<<"当前栈顶数据元素是："<<x<<endl;
	cout<<"当前链栈的长度是："<<StackLength_L(mystack)<<endl;
// 求链栈的长度并输出
	cout<<"依次出栈的数据元素序列为：";
	while(!StackEmpty_L(mystack)) {     // 判栈是否非空
		if(!Pop_L(mystack,x)) {            // 栈顶元素出栈并赋值给x
			cout<<"出栈失败！"<<endl;
			return;
		}
		cout<<x<<' ';
	}
	cout<<endl;
	cout<<"当前链栈的长度是："<<StackLength_L(mystack)<<endl;
	cout<<endl;
	DestroyStack_L(mystack);             // 撤销链栈
}

int main() {
//	seqStackTest();
	linkStackTest();
	return 0;
}
