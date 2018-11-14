#include <iostream>
using namespace std;
void swap(int a[], int i, int j)
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
int partition(int a[], int p, int q)
{
	int x=a[p], i=p;
	for(int j=i+1;j<=q;j++)
	{
		if(a[j]<=x)
		{
			i++;
			swap(a,i,j);
		}
	}
	swap(a,p,i);
	return i;
}
void quicksort(int a[], int p, int q)
{
	if(p<q)
	{
		int r = partition(a,p,q);
		quicksort(a,p,r-1);
		quicksort(a,r+1,q);
	}
}
void printArray(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
int main()
{
	int ele,n;
	cout<<"Enter number of elements"<<endl;
	cin>>n;
	int *a = new int[n];
	cout<<"Input Elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	printArray(a,n);	
}
