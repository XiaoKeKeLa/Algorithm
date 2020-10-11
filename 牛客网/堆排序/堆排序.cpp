#include<bits/stdc++.h>
using namespace std; 

void swap(int *a,int n,int m)
{
	int t;
	t=a[n];
	a[n]=a[m];
	a[m]=t;
 } 
 void heapify(int *a,int index,int heapsize)
 {
 	int left=index*2+1;
 	while(left<heapsize)//判断左孩子是否越界，若越界说明左孩子已经到达最下面 
 	{
 		//比较两个孩子谁的值大 ，谁的值大谁就是largest 
 		int largest=left+1<heapsize&&a[left+1]>a[left]?left+1:left;
 		//比较父节点和孩子节点的大小，若父节点较大，则无需交换 
 		largest=a[largest]>a[index]?largest:index; 
 		if(largest==index)
 		break;
 		swap(a,largest,index);
 		index=largest;
 		left=index*2+1;
	 }
 }
void heapInsert(int *a,int index)//把数组调成大根堆 
{
	while(a[index]>a[(index-1)/2])
	{
		swap(a,index,(index-1)/2);
		index=(index-1)/2;
	}
}

void heapSort(int *a,int n)
{
	if(a==NULL||n<2)
	return ;
	for(int i=0;i<n;i++)
	heapInsert(a,i);
	int heapSize=n;
	swap(a,0,--heapSize);//交换后大根堆的最大的值到数组最后一个位置 
	while(heapSize>0)
	{
		//每次都把数组中0-heapSize调整成大根堆 
		heapify(a,0,heapSize);
		swap(a,0,--heapSize);
	 } 
	
}
 int main()
 {
 	int n;
 	cin>>n;
 	int a[n];
 	for(int i=0;i<n;i++)
 	{
 		cin>>a[i];
	 }
	 heapSort(a,n);
	  for(int i=0;i<n;i++)
	  cout<<a[i]<<" ";
	  cout<<endl;
 	return 0;
 }
