#include <iostream>
using namespace std;
struct node
{
	int key;
	node *left, *right;
};
node * newnode(int value)
{
	node *temp = new node();
	temp->key=value;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node * insert(node * root, int value)
{
	if(root==NULL)
	{
		root=newnode(value);
	}
	else if(value < root->key)
	{
		root->left=insert(root->left,value);
	}
	else if(value > root->key)
	{
		root->right=insert(root->right,value);
	}
	return root;
}
node * search(node *root, int v)
{
	if(root==NULL || v== root->key)
	{
		return root;
	}
	else if( v < root->key)
	{
		search(root->left, v);
	}
	else if( v > root->key)
	{
		search(root->left,v);
	}
}
node *minNode(node *root)
{
	node *t = root;
	while(t->left!=NULL)
	{
		t=t->left;
	}
	return t;
}
node * deletenode(node *root, int v)
{
	node *temp=new node();
	if(root==NULL)
	{
		return root;
	}
	else if(v < root->key)
	{
		root->left=deletenode(root->left,v);
	}
	else if(v > root->key)
	{
		root->right=deletenode(root->right,v);
	}
	else 
	{
		if(root->left==NULL)
		{
			temp = root->right;
			delete(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			temp = root->left;
			delete(root);
			return temp;
		}
		node *t = minNode(root->right);
		root->key=t->key;
		root->right=deletenode(root->right,t->key);		
	}
	return root;
}
void preorder(node *root)
{
	if(root==NULL)
	{
		return ;
	}
	cout<<root->key<<endl;
	preorder(root->left);
	preorder(root->right);
}
void inorder(node *root)
{
	if(root==NULL)
	{
		return ;
	}
	inorder(root->left);
	cout<<root->key<<endl;
	inorder(root->right);
}
void postorder(node *root)
{
	if(root==NULL)
	{
		return ;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->key<<endl;
}
int main()
{
	node *root=NULL,*delNode;
	int c=1,choice,value,ch2;
	while(c!=0)
	{
		cout<<"***********MENU***********"<<endl;
		cout<<"1. Insert a new element"<<endl;
		cout<<"2. Delete an existing element"<<endl;
		cout<<"3. Traversal"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1 :
					 cout<<"Enter the value of the node to be inserted"<<endl;
					 cin>>value;
					 root=insert(root,value);
					 cout<<"Node inserted successfully!"<<endl;
				break;
			case 2 : 
					 cout<<"Enter the value of the node to be deleted"<<endl;
					 cin>>value;
					 	root= deletenode(root,value);
					 
				break;
			case 3 : 
					 cout<<"***MENU***"<<endl;
					 cout<<"1. Pre Order"<<endl;
					 cout<<"2. In Order"<<endl;
					 cout<<"3. Post Order"<<endl;
					 cout<<"Enter your choice of traversal"<<endl;
					 cin>>ch2;
					 switch(ch2)
					 {
					 	case 1 : preorder(root);
					 		break;
					 	case 2:  inorder(root);
					 		break;
					 	case 3:	postorder(root);
					 		break;
					 }
				break;
		}
		cout<<"Do you want to continue?"<<endl;
		cin>>c;
	
	}
}
