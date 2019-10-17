typedef int ElemType;
# include <iostream>
# include <iomanip>
# include "stdio.h"         
# include "stdlib.h"
#include "SqQueue.h"
#include "LinkQueue.h"

using namespace std;

int sqQueue(){
	SqQueue myQueue;
	int i,x,a[]={6,8,16,2,34,56,7,10,22,45,62,88};
	InitQueue_Sq(myQueue,10,10);   //初始画循环队列
	for(i=0;i<12;i++){
		if(!EnQueue_Sq(myQueue,a[i])){
			cout<<"进队失败！"<<endl;
			return 1;
		}
	} 
	if(!GetHead_Sq(myQueue,x)){
		cout<<"取队首元素失败！"<<endl;
		return 1;
	}
	cout<<"当前队首元素数据是："<<x<<endl;
	cout<<"当前顺序队列的长度是："<<QueueLength_Sq(myQueue)<<endl;
//	visualization(myQueue,"showsqlist.dot");
	cout<<"依次出对的数据元素序列为：";
	while(!QueueEmpty_Sq(myQueue)){
		if(!DeQueue_Sq(myQueue,x)){
			cout<<"出对失败"<<endl;
			return 1; 
		}
		cout<<x<<' ';
	} 
	cout <<endl;
	cout<<"当前顺序队列的长度是："<<QueueLength_Sq(myQueue)<<endl;
	cout<<endl;
	DestroyQueue_Sq(myQueue); 
	return 0;
}

int linkQueue(){
	LinkQueue myqueue;
	int i,x,a[]={6,8,16,2,34,56,7,10,22,45,62,88};
	InitQueue_L(myqueue);
	for(i=0;i<12;i++){
		if(!EnQueue_L(myqueue,a[i])){
			cout<<"进队失败！"<<endl;
			return 1;
		}
	}
	if(!GetHead_L(myqueue,x)){
		cout<<"取队首元素失败"<<endl;
		return 1;
	}
	cout<<"当前队首元素数据是："<<x<<endl;
	cout<<"当前链队的长度是："<<QueueLength_L(myqueue)<<endl;
//	visualization(myqueue,"showsqlist.dot");
	cout<<"依次出队的数据元素序列为："<<endl;
	while(!QueueEmpty_L(myqueue)){
		if(!DeQueue_L(myqueue,x)){
			cout<<"出队失败！"<<endl;
			return 1;
		}	
		cout<<x<<' ';
	} 
	cout<<endl;
	cout<<"当前链队的长度是："<<QueueLength_L(myqueue)<<endl;
	DestroyQueue_L(myqueue);
	return 0;
}

int main(){
//	sqQueue();
	linkQueue();
}
