#include <iostream>
using namespace std;
void insertion_sort(int a[], int n)
{
	int i=1,key, j;
	while(i<n)
	{
		key = a[i];
		j=i-1;
		while(j >=0 && a[j] > key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
		i++;
	}
}
void display(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
int main()
{
	int n,ele;
	cout<<"Enter the number of elements of array"<<endl;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	insertion_sort(a,n);
	cout<<"Enter the element to be inserted"<<endl;
	cin>>ele;
	a[n++]=ele;
	insertion_sort(a,n);
	display(a,n);
}
