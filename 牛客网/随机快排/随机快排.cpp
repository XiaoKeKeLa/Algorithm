#include<bits/stdc++.h>
#define random(x) rand()%(x)
using namespace std; 

void swap(int *a,int n,int m)
{
	int t;
	t=a[n];
	a[n]=a[m];
	a[m]=t;
 } 
 int * partition(int *a,int L,int R)
{
	int less=L-1;
	int more=R;
	while(L<more)
	{
		if(a[L]<a[R])
		swap(a,++less,L++);
		else if(a[L]>a[R])
		swap(a,L,--more);
		else if(a[L]==a[R]) 
		{ 
			L++;
		}
	}
	swap(a,more,R);
	int p[2]={less+1,more};
	return p;
}
void quicksort(int *a,int L,int R)
{
	if(L<R)
	{
		swap(a,random(R-L+1),R);//与经典快排不同，随机在数组中选择一个数字进行比较 
		int *p=partition(a,L,R);
		quicksort(a,L,p[0]-1);
		quicksort(a,p[1]+1,R);
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
	 quicksort(a,0,n);
	  for(int i=0;i<n;i++)
	  cout<<a[i]<<" ";
	  cout<<endl;
 	return 0;
 }
