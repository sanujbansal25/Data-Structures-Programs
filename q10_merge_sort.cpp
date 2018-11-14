#include <iostream>
using namespace std;
void selection_sort(int *a, int n)
{
	int min;
	for(int i=0;i<n;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				int temp=a[j];
				a[j]=a[min];
				a[min]=temp;
			}
		}
	}
}
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]) 
{ 
    int i = 0, j = 0, k = 0; 
    while (i<n1 && j <n2) 
    { 
        if (arr1[i] < arr2[j]) 
            arr3[k++] = arr1[i++]; 
        else
            arr3[k++] = arr2[j++]; 
    } 
    while (i < n1) 
        arr3[k++] = arr1[i++]; 
    while (j < n2) 
        arr3[k++] = arr2[j++]; 
} 
int main()
{
	int n2,ele,n1;
	cout<<"Enter number of elements of array1"<<endl;
	cin>>n1;
	int *a = new int[n1];
	cout<<"Input Elements for array1"<<endl;
	for(int i=0;i<n1;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter number of elements of array2"<<endl;
	cin>>n2;
	int *b = new int[n2];
	cout<<"Input Elements for array2"<<endl;
	for(int i=0;i<n2;i++)
	{
		cin>>b[i];
	}
	selection_sort(a,n1);
	selection_sort(b,n2);
	cout<<"Array 1"<<endl;
	for(int i=0;i<n1;i++)
	{
		cout<<a[i]<<endl;
	}
	cout<<"Array 2"<<endl;
	for(int i=0;i<n2;i++)
	{
		cout<<b[i]<<endl;
	}
	int *c = new int[n1+n2];
	cout<<"Sorted"<<endl;
	mergeArrays(a,b,n1,n2,c);
	for(int i=0;i<(n1+n2);i++)
	{
		cout<<c[i]<<endl;
	}
	}
