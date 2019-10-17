#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*
算法导论版划分
*/
int Partition1(int *a,int low ,int high) {
	if(a==NULL || low>high)
		return -1;

	int small = low-1;
	int j;
	for(j=low; j<high; j++) {
		if(a[j]<a[high]) {
			small++;
			if(small != j)
				swap(&a[small],&a[j]);
		}
	}
	small++;
	swap(&a[small],&a[high]);
	return small;
}
/*
划分规则2
*/
int Partition2(int *a,int low ,int high) {
	if(a==NULL || low>high)
		return -1;
		
	int i = low,j = high+1;
	int temp = a[low];

	while(1) {
		while(a[++i] < temp); //i向右扫描
		while(a[--j] > temp); //j向左扫描
		if(i >= j) break; //当i超过j时扫描结束
		swap(&a[i],&a[j]); //交换i、j位置元素
	}
	swap(&a[j],&a[high]);

	return j;
}

/*
随机选取枢轴元素
*/
int Random_Partition(int *A,int low,int high) {
	//设置随机种子
	srand((unsigned)time(0));
	int index = low + rand()%(high-low+1);
	swap(&A[index],&A[high]);
	return Partition1(A,low,high);
}


/*
快速排序函数，通过递归实现
*/
void QuickSort(int *a,int low,int high) {
	int pos;

	if(low < high) {
		pos = Partition1(a,low,high);
//		pos = Partition2(a,low,high);
//		pos = Random_Partition(a,low,high);
		QuickSort(a,low,pos-1);		//左边子序列排序
		QuickSort(a,pos+1,high);	//右边子序列排序
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

	printf("快速排序后的顺序：");
	QuickSort(arr,0,num-1);
	for(i=0; i<num; i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}


