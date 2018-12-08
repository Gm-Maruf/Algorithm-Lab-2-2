#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* link;
};
node* head;
node* temp_head;
node* prv;

void making(int x);
void print();
void insertt(int b, int c);

void making(int x)
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
void insertt(int b, int c)
{
   node* new_node = new node();
   if(b==1){
        new_node->link=head;
        head=new_node;
        new_node->data=c;
        return;
   }
   node* temp=head;
   node* prv=NULL;
   int countt=1;
   while(temp != NULL){
        if(countt==b){
            new_node->link= prv->link;
            prv->link=new_node;
            new_node->data= c;
            return;
        }
        prv=temp;
        temp= temp->link;
        countt++;
   }
}


int main()
{
    head = NULL;
    temp_head = NULL;
    prv = NULL;

    int n;
    cout<<"How many node You want to create: ";
    cin>>n;
    for(int i=0; i<n; i++){
        int value;
        cout<<"Enter the value of Node "<<i+1<<" :";
        cin>>value;
        making(value);
        print();
    }
    int k,z;
    cout<<"Enter the position where You want to insert: ";
    cin>>k;
    cout<<"Enter the value of new node: ";
    cin>>z;
    insertt(k,z);
    print();

    return 0;
}
