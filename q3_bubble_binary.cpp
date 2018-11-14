#include <iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x) 
{ 
if (r >= l) 
{ 
		int mid = l + (r - l)/2; 
		if (arr[mid] == x) 
			return mid; 

		if (arr[mid] > x) 
			return binarySearch(arr, l, mid-1, x); 
 
		return binarySearch(arr, mid+1, r, x); 
	}	 
return -1; 
} 
void bubblesort(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j+1]<a[j])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main()
{
	int element,n,a[100];
	cout<<"Enter number of elements"<<endl;
	cin>>n;
	cout<<"Input elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bubblesort(a,n);
	cout<<"Enter the element to be searched"<<endl;
	cin>>element;
	int x= binarySearch(a,0,n-1,element);
	if(x==-1)
	{
		cout<<"Element not found"<<endl;
	}
	else
	{
		cout<<"Element found at index "<<x<<endl;
	}
}
