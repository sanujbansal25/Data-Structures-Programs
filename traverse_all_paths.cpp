#include<iostream>
#include<stack>
using namespace std;
struct tree
{
    int data;
    tree *left=NULL;
    tree *right=NULL;
};
class BinaryTree
{
    public:
    stack<int> s;
    int summ=0;
    int flag=0;

    tree* insertion(tree *root,int data)
    {
        if(root==NULL)
        {
            root = new tree;
            root->data = data;
        }
        else if(root->data<data)
        {
            root->right = insertion(root->right,data);
        }
        else if(root->data>data)
        {
            root->left= insertion(root->left,data);
        }
        return root;
    }
    void displayTree(tree* root)
    {
        if(root==NULL)
            return;
        displayTree(root->left);
        cout<<root->data<<" ";
        displayTree(root->right);
    }
    void checkSum(tree* root,int no)
    {
        summ += root->data;
        s.push(root->data);
        if(summ==no)
        {
            printStack();
            flag = 1;
        }
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                s.pop();
                summ -= root->data;
                return;
            }
            else if(root->left==NULL)
            checkSum(root->right,no);
            else
                checkSum(root->left,no);
            if(root->right!=NULL)
                checkSum(root->right,no);
        }
        return;
    }
    void printStack()
    {
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
};
int main()
{
    cout<<"enter the no. of elements to insert in bst "<<endl;
    int n;
    cin>>n;
    tree *root=NULL;
    BinaryTree bst;
    cout<<"enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        root = bst.insertion(root,data);
    }
    bst.displayTree(root);
    cout<<endl;
    int no;
    cin>>no;
    bst.checkSum(root,no);
    if(!bst.flag)
    {
        cout<<"no possible branch or part of branch whose sum is the no. you entered ";
    }
}
