#include<stdio.h>
#include<stdlib.h>
/*
ð��������˳��Ϊ��С����
*/
void BubbleSortV1(int *arr,int arrLen) {

	int i,j,temp;
	for(i=0; i<arrLen-1; i++)
		for(j=0; j<arrLen-i-1; j++)
			if(arr[j] > arr[j+1]) {// ����Ԫ�������Ա�
				temp = arr[j];// Ԫ�ؽ���
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
}
/*
���Է��֣������б�����Ǹ������Ѿ����������ʱ���������˴��������ò������Ǿ��ǲ�ͣ�ıȽϡ�
����һ���Ľ��㷨���ǣ�������ʣ�������Ѿ��������֮��ֹͣ�����ȽϵĲ�����
*/
void BubbleSortV2(int *arr,int arrLen) {
	int i,j,temp;
	bool flag = true;   //�����־λ���ж��Ƿ��Ѿ��������
	for(i=0; i<arrLen-1 && flag; i++) {
		flag = false;
		for(j=0; j<arrLen-i-1; j++)
			if(arr[j] > arr[j+1]) {
				//������˱Ƚ�û�����ݷ���������˵�������Ѿ����
				//��flagһֱΪfalse���Ӷ��˳�ѭ�������ٽ�����һ�˵ıȽ�
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = exchange;
				flag = true;
			}
	}
}


int main() {
	int arrLen;
	printf("�����������Ԫ�صĸ�����");
	scanf("%d",&arrLen);

	int i;
	int *arr = (int *)malloc(arrLen*sizeof(int));
	printf("������������%d��Ԫ�أ�����Ϊ��������",arrLen);
	for(i=0; i<arrLen; i++)
		scanf("%d",arr+i);

	printf("ð��������˳��");
	BubbleSortV1(arr,arrLen);
	for(i=0; i<arrLen; i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}
