#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class stack
{
	node *top;
	public:
		stack()
		{
			top=NULL;
		}
		void push(int i)
		{
			node *temp=new node();
			node *ptr;
			temp->data=i;
			temp->next=NULL;
			if(top==NULL)
			{
				top=temp;
			}
			else
			{
				ptr=top;
				top=temp;
				top->next=ptr;
			}
		}
		void pop()
		{
			if(top==NULL)
			{
				cout<<"Stack empty already!"<<endl;
			}
			else
			{
				node *x=top;
				top=x->next;
				cout<<"Element popped successfully!"<<endl;
			}
		}
		void display()
		{
			node *x=top;
			while(x!=NULL)
			{
				cout<<x->data<<endl;
				x=x->next;
			}
		}
		int topE()
		{
			return top->data;
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

