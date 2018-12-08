#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* link;
};
node* head;
node* temp_head;

void creating(int x);
void print();

void inserting(int x)
{
    node* temp = new node();
    if(head==NULL)
        head=temp;
    else
    {
        temp_head->link=temp;
    }
    temp->data=x;
    temp->link=NULL;
    temp_head=temp;

    return;
}
void print()
{
    node* temp=head;
    while(temp != NULL){
        cout<<" "<<temp->data;
        temp=temp->link;
    }
    cout<<endl;
    return;
}

int main()
{
    head = NULL;
    temp_head = NULL;

    int n;
    cout<<"How many node You want to create: ";
    cin>>n;
    for(int i=0; i<n; i++){
        int value;
        cout<<"Enter the value of Node "<<i+1<<" :";
        cin>>value;
        creating(value);
        print();
    }
    return 0;
}

