#include<stdio.h>
#include<stdlib.h>

/*
将有序的arr[start...mid]和有序的arr[mid+1...end]归并为有序的temp[0...end-start+1],
而后再将temp[0...end-start+1]复制到arr[start...end]，使arr[start...end]有序
*/
void Merge(int *arr,int *temp,int start,int mid,int end) {
	int i = start;
	int j = mid+1;
	int k = 0;
	
	//================解析：就是两个数组之间比较排序，小的放入temp，大的不动，等下一步再放入，这样就实现排序了
	
	//比较两个有序序列中的元素，将较小的元素插入到temp中 
	while(i<=mid && j<=end) {
		if(arr[i]<=arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	
	//================解析：此时temp数组的元素是最小的 

	//将arr序列中剩余的元素复制到temp中
	//这两个语句只可能执行其中一个
	while(i<=mid)
		temp[k++] = arr[i++];
	while(j<=end)
		temp[k++] = arr[j++];
		
	//================解析：因为上面把小的元素加入了temp，所以这边把剩下的（比当前temp大的元素）加入  

	//将temp中的元素复制到arr中，使arr[start...end]有序
	for(i=0; i<k; i++)
		arr[i+start] = temp[i];
	
	//================解析：此时temp数组的元素是排序好了的，赋值给arr
		
}

/*
递归思想
 
借助temp数组对arr[start...end]内的元素进行归并排序
归并排序后的顺序为从小到大
*/
void MSort(int *arr,int *temp,int start,int end) {
	if(start < end) {
		int mid = (start+end)/2;//2路归并 
		MSort(arr,temp,start,mid);		//左边递归排序
		MSort(arr,temp,mid+1,end);		//右边递归排序
		Merge(arr,temp,start,mid,end);	//左右序列归并
	}
}
/*
将该排序算法封装起来
*/
void MergeSort(int *arr,int len) {
	int *temp = (int *)malloc(len*sizeof(int));//开辟临时空间，后续释放！
	MSort(arr,temp,0,len-1);
	free(temp);
	temp = 0;
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

	printf("归并排序后的顺序：");
	MergeSort(arr,num);
	for(i=0; i<num; i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}
