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
		//Lһֱ����ָ�����ڽ��бȽϵ����� 
		if(a[L]<num)//���С��num��less�����Ҫ��������less++��L���н��� 
		swap(a,++less,L++);
		else if(a[L]>num)//���С��num��more�����Ҫ��������--more��L���н��� 
		swap(a,L,--more);
		else if(a[L]==num)//�������num����ֱ�Ӱ�L++���������ɱ�֤�������һֱû�б䶯�� 
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
