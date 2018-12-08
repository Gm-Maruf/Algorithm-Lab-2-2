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
int searching(int s);

void creating(int x)
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

int searching(int s)
{
    int check=0;
    node* temp=head;
    while(temp != NULL){
        if(temp->data == s){
            check=1;
            break;
        }
        temp=temp->link;
    }
    return check;
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
    int s;
    cout<<"Enter the value You want to search in: ";
    cin>>s;
    int check = searching(s);
    if(check == 1)
        cout<<"Number exists on the list";
    else
        cout<<"Number doesn't exist on the list";
    return 0;
}


