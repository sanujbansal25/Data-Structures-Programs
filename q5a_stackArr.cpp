#include<iostream>
using namespace std;
class stack
{
	int top, a[100];
	public:
		stack()
		{
			top=-1;
		}
		void push(int i)
		{
			++top;
			a[top]=i;
		}
		void pop()
		{
			if(top==-1)
			{
				cout<<"Stack empty already!"<<endl;
			}
			else
			{
			int x=top;
			--top;
			cout<<a[x]<<" popped successfully!"<<endl;
			}
		}
		void display()
		{
			int x=top;
			while(x>=0)
			{
				cout<<a[x]<<endl;
				x--;
			}
		}
		int topE()
		{
			return a[top];
		}
};
int main()
{
	int c,ele,choice;
	stack s;
	do
	{
		cout<<"*********MENU*********"<<endl;
		cout<<"1. PUSH"<<endl;
		cout<<"2. POP"<<endl;
		cout<<"3. DISPLAY ALL ELEMENTS OF STACK"<<endl;
		cout<<"4. DISPLAY TOP"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Enter the element to be pushed"<<endl;
					cin>>ele;
					s.push(ele);
				break;
			case 2: s.pop();
				break;
			case 3: s.display();
				break;
			case 4: cout<<"The top element of stack is "<<s.topE()<<endl;
				break;
			default:
				cout<<"Invalid choice!"<<endl;
				break;
		}
	cout<<"Do you want to continue? (1-yes or 0-no)"<<endl;
	cin>>c;
	}while(c!=0);
}

