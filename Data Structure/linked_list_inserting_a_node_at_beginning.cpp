#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* link;
};

node* head;
node* temp_head;
void insertt(int x);
void print();

int main()
{
    head = NULL;
    temp_head = NULL;
    int n;
    cout<<"How many Node you want to create: ";
    cin>>n;
    for(int i=0; i<n; i++){
        int value;
        cout<<"Enter value of Node "<<i+1<<":";
        cin>>value;
        insertt(value);
        print();
    }
    return 0;
}

void insertt(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->link = head;
    head = temp;

    return;
}

void print()
{
    node* temp = head;
    while(temp != NULL){
        cout<<" "<<temp->data;
        temp = temp->link;
    }
    cout<<endl;
    return;
}
