#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* root;
node* insertt(node* root, int data);
node* getnode(int data);
bool searchh(node* root, int data);

int main()
{

    root = NULL;
    int x;
	cout<<"\nEnter the value how much value you want to input: ";
	cin>>x;
	for(int i=0;i<x;i++){
		int data;
		cin>>data;
		root = insertt(root,data);
	}
    int n;
    cout<<"Enter the number which you want to search: ";
    cin>>n;
    if(searchh(root,n) == true)
    {
        cout<<"The number exists!\n";
    }
    else
    {
        cout<<"The number doesn't exist!";
    }

    return 0;
}

node* insertt(node* root, int data)
{
    if(root == NULL)
    {
        root = getnode(data);
    }
    else if(data <= root->data)
    {
        root->left = insertt(root->left,data);
    }
    else if(data < root->data)
    {
        root->right = insertt(root->right,data);
    }
    return root;
}

node* getnode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

bool searchh(node* root, int data)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->data == data)
    {
        return true;
    }
    else if(data <= root->data)
    {
        return searchh(root->left,data);
    }
    else
    {
        return searchh(root->right,data);
    }
}
