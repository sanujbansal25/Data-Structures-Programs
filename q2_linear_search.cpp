#include <iostream>
using namespace std;
void linear_search(int a[], int n, int ele);
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
	cout<<"Enter the element to be searched"<<endl;
	cin>>ele;
	linear_search(a,n,ele);
}
void linear_search(int a[], int n, int ele)
{
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==ele)
		{
			cout<<ele<<" found at index "<<i<<endl;
			flag=1;
			break;
		}
	}
	if(flag!=1)
	{
		cout<<"Element not found"<<endl;
	}
}
