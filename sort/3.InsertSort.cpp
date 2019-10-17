#include<stdio.h>
#include<stdlib.h>


/*
常规插入 
*/
void InsertSort1(int *arr,int len) {
	for(int i = 1; i < len; i++) { //将1~n-1元素插入
		int temp = arr[i]; //temp为待插入元素
		int j = i-1;
		while(j >= 0 && arr[j] > temp) { //当j位置元素大于temp时，指针j往前移，同时将比temp大的元素往后移
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp; //j+1即为temp的正确位置  -- 插入key 
	}
}
/*
常规插入-优化 
*/
void InsertSort2(int *arr,int len) {
	int i;
	//从第1个元素开始循环执行插入排序
	for(i=1; i<len; i++) {
		//将第i个元素分别与前面的元素比较，插入适当的位置
		int key = arr[i];
		if(key<arr[i-1]) {
			//一直向左进行比较，直到插入到适当的位置
			int count = 0;	//用来记录key在与前面元素时向左移动的位置
			while(i>0 && key<arr[i-1]) {
				arr[i] = arr[i-1];
				arr[i-1] = key;
				i--;
				count++;
			}
			//将待插入的数定位到下一个元素，
			//因为后面还要执行i++，所以这里不再加1
			i += count;
		}
	}
}

/*
折半插入
*/
void InsertSort3(int *arr,int len) {
	int i;
	//从第1个元素开始循环执行插入排序
	for(i=1; i<len; i++) {
		int low =0;
		int high = i-1;
		int key = arr[i];
		//循环至要插入的两个点之间
		while(low<=high) {
			int mid = (low+high)/2;
			if(key<arr[mid])
				high = mid-1;
			else
				low = mid+1;
		}
		//循环结束后low=high+1，并且low位置即为key要插入的位置

		//从low到i的元素依次后移一位
		int j;
		for(j=i; j>low; j--)
			arr[j] = arr[j-1];
		//将key插入到low位置处
		arr[low] = key;
	}
}

int main() {
	int num;
	printf("请输入排序的元素的个数：");
	scanf("%d",&num);

	int i;
	int *arr = (int *)malloc(num*sizeof(int));
	printf("请依次输入这%d个元素（必须为整数）：",num);
	for(i=0; i<num; i++)
		scanf("%d",arr+i);

	printf("插入排序后的顺序：");
//	InsertSort1(arr,num);
	InsertSort2(arr,num);
//	InsertSort3(arr,num);

	for(i=0; i<num; i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}
