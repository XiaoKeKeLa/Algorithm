#include<bits/stdc++.h>
using namespace std;
long mergeSort(int a[],int n);
long sortProcess(int a[],int L,int R);
long merge(int a[],int L,int mid,int R);
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<mergeSort(a,n)<<endl;		
	return 0;
}
long mergeSort(int a[],int n)
{
	if(a==NULL||n<2)
	return 0;
return sortProcess(a,0,n-1);
}

long sortProcess(int *a,int L,int R)
{
	if(L>=R)
	return 0;
	int mid=L+((R-L)>>1);//�൱��(L+R)/2,����Ч������� 
return	sortProcess(a,L,mid)+sortProcess(a,mid+1,R)+merge(a,L,mid,R);
}

long merge(int *a,int L,int mid,int R)
{
	int help[R-L+1];//����ÿ��merge������� 
	memset(help, 0, sizeof(help));
	int i=0;
	int p1=L;
	int p2=mid+1;
	long rul=0;
	while(p1<=mid&&p2<=R)
	{
		//������p1<m<mid,��a[p1]>a[p2]ʱ��a[m]<a[p2]Ҳ��Ȼ������m������Ϊ mid-p1+1
		//rul+=a[p1]<=a[p2]?(R-p2+1)*a[p1]:0;
		rul+=a[p1]>a[p2]?(mid-p1+1):0;
		help[i++]=a[p1]<=a[p2]?a[p1++]:a[p2++];//ÿ��ѡ��С�����ִ������� 
	}
	//�������ߵ���������ÿ�ζ���ȣ���ʣ�µ�Ԫ��Ҳ��ӵ�help������ 
	while(p1<=mid)
	{
	help[i++]=a[p1++];	
	}
	while(p2<=R)
	{
	help[i++]=a[p2++];	
	}
	for(i=0;i<R-L+1;i++)
	a[L+i]=help[i];
	return rul;
}
