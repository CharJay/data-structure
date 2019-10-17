#include<stdio.h>
#include<stdlib.h>
/*
冒泡排序后的顺序为从小到大
*/
void BubbleSortV1(int *arr,int arrLen) {

	int i,j,temp;
	for(i=0; i<arrLen-1; i++)
		for(j=0; j<arrLen-i-1; j++)
			if(arr[j] > arr[j+1]) {// 相邻元素两两对比
				temp = arr[j];// 元素交换
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
}
/*
可以发现，当序列本身就是个几乎已经有序的序列时，其中做了大量的无用操作，那就是不停的比较。
所以一个改进算法就是，当发现剩余序列已经是有序的之后，停止继续比较的操作。
*/
void BubbleSortV2(int *arr,int arrLen) {
	int i,j,temp;
	bool flag = true;   //增设标志位，判断是否已经完成排序
	for(i=0; i<arrLen-1 && flag; i++) {
		flag = false;
		for(j=0; j<arrLen-i-1; j++)
			if(arr[j] > arr[j+1]) {
				//如果本趟比较没有数据发生交换，说明排序已经完成
				//则flag一直为false，从而退出循环，不再进行下一趟的比较
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = exchange;
				flag = true;
			}
	}
}


int main() {
	int arrLen;
	printf("请输入排序的元素的个数：");
	scanf("%d",&arrLen);

	int i;
	int *arr = (int *)malloc(arrLen*sizeof(int));
	printf("请依次输入这%d个元素（必须为整数）：",arrLen);
	for(i=0; i<arrLen; i++)
		scanf("%d",arr+i);

	printf("冒泡排序后的顺序：");
	BubbleSortV1(arr,arrLen);
	for(i=0; i<arrLen; i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}
