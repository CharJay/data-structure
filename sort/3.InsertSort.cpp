#include<stdio.h>
#include<stdlib.h>


/*
������� 
*/
void InsertSort1(int *arr,int len) {
	for(int i = 1; i < len; i++) { //��1~n-1Ԫ�ز���
		int temp = arr[i]; //tempΪ������Ԫ��
		int j = i-1;
		while(j >= 0 && arr[j] > temp) { //��jλ��Ԫ�ش���tempʱ��ָ��j��ǰ�ƣ�ͬʱ����temp���Ԫ��������
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp; //j+1��Ϊtemp����ȷλ��  -- ����key 
	}
}
/*
�������-�Ż� 
*/
void InsertSort2(int *arr,int len) {
	int i;
	//�ӵ�1��Ԫ�ؿ�ʼѭ��ִ�в�������
	for(i=1; i<len; i++) {
		//����i��Ԫ�طֱ���ǰ���Ԫ�رȽϣ������ʵ���λ��
		int key = arr[i];
		if(key<arr[i-1]) {
			//һֱ������бȽϣ�ֱ�����뵽�ʵ���λ��
			int count = 0;	//������¼key����ǰ��Ԫ��ʱ�����ƶ���λ��
			while(i>0 && key<arr[i-1]) {
				arr[i] = arr[i-1];
				arr[i-1] = key;
				i--;
				count++;
			}
			//�������������λ����һ��Ԫ�أ�
			//��Ϊ���滹Ҫִ��i++���������ﲻ�ټ�1
			i += count;
		}
	}
}

/*
�۰����
*/
void InsertSort3(int *arr,int len) {
	int i;
	//�ӵ�1��Ԫ�ؿ�ʼѭ��ִ�в�������
	for(i=1; i<len; i++) {
		int low =0;
		int high = i-1;
		int key = arr[i];
		//ѭ����Ҫ�����������֮��
		while(low<=high) {
			int mid = (low+high)/2;
			if(key<arr[mid])
				high = mid-1;
			else
				low = mid+1;
		}
		//ѭ��������low=high+1������lowλ�ü�ΪkeyҪ�����λ��

		//��low��i��Ԫ�����κ���һλ
		int j;
		for(j=i; j>low; j--)
			arr[j] = arr[j-1];
		//��key���뵽lowλ�ô�
		arr[low] = key;
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
