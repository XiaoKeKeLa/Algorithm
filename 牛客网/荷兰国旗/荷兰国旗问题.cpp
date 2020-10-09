#include<bits/stdc++.h>
using namespace std; 
void swap(int *a,int n,int m)
{
	int t;
	t=a[n];
	a[n]=a[m];
	a[m]=t;
 } 

void partition(int *a,int L,int R,int num)
{
	int less=L-1;
	int more=R+1;
	while(L<more)
	{
		//L一直都是指向正在进行比较的数字 
		if(a[L]<num)//如果小于num，less区域就要向右扩大，less++和L进行交换 
		swap(a,++less,L++);
		else if(a[L]>num)//如果小于num，more区域就要向左扩大，--more和L进行交换 
		swap(a,L,--more);
		else if(a[L]==num)//如果等于num，则直接把L++，这样即可保证相等区域一直没有变动。 
		{ 
			L++;
		}
	}

}
 int main()
 {
 	int n,num;
 	cin>>n>>num;
 	int a[n];
 	for(int i=0;i<n;i++)
 	{
 		cin>>a[i];
	 }
	 partition(a,0,n-1,num);
	  for(int i=0;i<n;i++)
	  cout<<a[i]<<" ";
	  cout<<endl;
 	return 0;
 }
