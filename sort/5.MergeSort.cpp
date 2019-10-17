#include<stdio.h>
#include<stdlib.h>

/*
�������arr[start...mid]�������arr[mid+1...end]�鲢Ϊ�����temp[0...end-start+1],
�����ٽ�temp[0...end-start+1]���Ƶ�arr[start...end]��ʹarr[start...end]����
*/
void Merge(int *arr,int *temp,int start,int mid,int end) {
	int i = start;
	int j = mid+1;
	int k = 0;
	
	//================������������������֮��Ƚ�����С�ķ���temp����Ĳ���������һ���ٷ��룬������ʵ��������
	
	//�Ƚ��������������е�Ԫ�أ�����С��Ԫ�ز��뵽temp�� 
	while(i<=mid && j<=end) {
		if(arr[i]<=arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	
	//================��������ʱtemp�����Ԫ������С�� 

	//��arr������ʣ���Ԫ�ظ��Ƶ�temp��
	//���������ֻ����ִ������һ��
	while(i<=mid)
		temp[k++] = arr[i++];
	while(j<=end)
		temp[k++] = arr[j++];
		
	//================��������Ϊ�����С��Ԫ�ؼ�����temp��������߰�ʣ�µģ��ȵ�ǰtemp���Ԫ�أ�����  

	//��temp�е�Ԫ�ظ��Ƶ�arr�У�ʹarr[start...end]����
	for(i=0; i<k; i++)
		arr[i+start] = temp[i];
	
	//================��������ʱtemp�����Ԫ����������˵ģ���ֵ��arr
		
}

/*
�ݹ�˼��
 
����temp�����arr[start...end]�ڵ�Ԫ�ؽ��й鲢����
�鲢������˳��Ϊ��С����
*/
void MSort(int *arr,int *temp,int start,int end) {
	if(start < end) {
		int mid = (start+end)/2;//2·�鲢 
		MSort(arr,temp,start,mid);		//��ߵݹ�����
		MSort(arr,temp,mid+1,end);		//�ұߵݹ�����
		Merge(arr,temp,start,mid,end);	//�������й鲢
	}
}
/*
���������㷨��װ����
*/
void MergeSort(int *arr,int len) {
	int *temp = (int *)malloc(len*sizeof(int));//������ʱ�ռ䣬�����ͷţ�
	MSort(arr,temp,0,len-1);
	free(temp);
	temp = 0;
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

	printf("�鲢������˳��");
	MergeSort(arr,num);
	for(i=0; i<num; i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}
