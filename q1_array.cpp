#include<iostream>
using namespace std;
int n;
void insert(int a[], int value, int position)
{
	++n;
	for(int i=n-1;i>(position);i--)
	{
		if(i==(position))
		{
			a[i]=value;
		}
		else
		{
			a[i]=a[i-1];
		}
	}
}
void deleteElement(int a[], int pos)
{
	for(int i=pos;i<(n-1);i++)
	{
		a[i]=a[i+1];
	}
	n=n-1;
}
int search(int a[], int y)
{
	int pos,flag=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==y)
		{
			pos=i;
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		return pos;
	}
	else
	{
		return -1;
	}
}
void display(int a[], int n)
{
	cout<<"Array Elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" "<<endl;
	}
}
int main()
{
	int choice,c=1,a[100];
	int x;
	cout<<"Enter x no. of elements"<<endl;
	cin>>x;
	n=x;
	for(int i=0;i<x;i++)
	{
		cin>>a[i];
	}
	while(c!=0)
	{
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				int p,v;
				cout<<"Enter the value to be inserted"<<endl;
				cin>>v;
				cout<<"Enter the position at which value to be inserted"<<endl;
				cin>>p;
				insert(a,v,p); 
				break;
			case 2:
				int pos;
				cout<<"Enter the position at which element to be deleted"<<endl;
				cin>>pos;
				deleteElement(a,pos-1);
				break;
			case 3:
				int y;
				cout<<"Enter the element to be searched for"<<endl;
				cin>>y;
				x=search(a,y);
				if(x==-1)
				{
					cout<<"Element not found in the array"<<endl;
				}
				else
				{
					cout<<"Element found at the index "<<x<<endl;
				}
				break;
			case 4:
				display(a,n);
				break;
		}
		cout<<"Do you want to continue?(1-yes or 0-no)"<<endl;
		cin>>c;
	}
}
