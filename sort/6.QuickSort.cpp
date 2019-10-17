#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*
�㷨���۰滮��
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
���ֹ���2
*/
int Partition2(int *a,int low ,int high) {
	if(a==NULL || low>high)
		return -1;
		
	int i = low,j = high+1;
	int temp = a[low];

	while(1) {
		while(a[++i] < temp); //i����ɨ��
		while(a[--j] > temp); //j����ɨ��
		if(i >= j) break; //��i����jʱɨ�����
		swap(&a[i],&a[j]); //����i��jλ��Ԫ��
	}
	swap(&a[j],&a[high]);

	return j;
}

/*
���ѡȡ����Ԫ��
*/
int Random_Partition(int *A,int low,int high) {
	//�����������
	srand((unsigned)time(0));
	int index = low + rand()%(high-low+1);
	swap(&A[index],&A[high]);
	return Partition1(A,low,high);
}


/*
������������ͨ���ݹ�ʵ��
*/
void QuickSort(int *a,int low,int high) {
	int pos;

	if(low < high) {
		pos = Partition1(a,low,high);
//		pos = Partition2(a,low,high);
//		pos = Random_Partition(a,low,high);
		QuickSort(a,low,pos-1);		//�������������
		QuickSort(a,pos+1,high);	//�ұ�����������
	}
}


int main() {
	int num;
	printf("�����������Ԫ�صĸ�����");
	scanf("%d",&num);

	int i;
	int *arr = (int *)malloc(num*sizeof(int));
	printf("������������%d��Ԫ�أ�����Ϊ��������",num);
	for(i=0; i<num; i++)
		scanf("%d",arr+i);

	printf("����������˳��");
	QuickSort(arr,0,num-1);
	for(i=0; i<num; i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}


