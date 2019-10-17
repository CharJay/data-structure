# include <iostream>
# include <iomanip>
# include "stdio.h"         
# include "stdlib.h"
# include "Set.h"

using namespace std;


void setTest(){
	int size = 15;
	int i;
	Set set = SetInit(size);
	
	SetInsert(0,set);
	SetInsert(1,set);
	SetInsert(12,set);
	SetInsert(1,set);
//	SetDelete(14,set);

	cout<<"======2"<<endl;

	
	cout<<set->arraysize<<endl;
	cout<<"======3"<<endl;
	for(i=0; i<size; i++) 
		cout<<SetMember(i,set)<<endl;//�ж�Ԫ���ͷŴ��� 
}

//���ϵ�Ӧ�ã����n�ڵ����� 
void printPrimes(int n){
	int m,k,count;
	Set s = SetInit(n+1);
	for(m = 2;m<=n;m++){
		SetInsert(m,s);
	}
	for(m=2;m*m<=n;m++){
		if(SetMember(m,s)){
			for(k=m+m;k<=n;k+=m){
				if(SetMember(k,s)) SetDelete(k,s);
			}
		}
	}
	count = 1;
	for(m = 2;m<=n;m++){
		if(SetMember(m,s)){
			cout<< m << " ";
			if(count++%10 == 0) cout<<endl;
		}
	}
	
}

int main(){
	
	setTest();//����ֻ��һ��key��valueû�й��� 
//	printPrimes(50);
	
	return 1;
}
