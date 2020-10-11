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
 	while(left<heapsize)//�ж������Ƿ�Խ�磬��Խ��˵�������Ѿ����������� 
 	{
 		//�Ƚ���������˭��ֵ�� ��˭��ֵ��˭����largest 
 		int largest=left+1<heapsize&&a[left+1]>a[left]?left+1:left;
 		//�Ƚϸ��ڵ�ͺ��ӽڵ�Ĵ�С�������ڵ�ϴ������轻�� 
 		largest=a[largest]>a[index]?largest:index; 
 		if(largest==index)
 		break;
 		swap(a,largest,index);
 		index=largest;
 		left=index*2+1;
	 }
 }
void heapInsert(int *a,int index)//��������ɴ���� 
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
	swap(a,0,--heapSize);//���������ѵ�����ֵ���������һ��λ�� 
	while(heapSize>0)
	{
		//ÿ�ζ���������0-heapSize�����ɴ���� 
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
