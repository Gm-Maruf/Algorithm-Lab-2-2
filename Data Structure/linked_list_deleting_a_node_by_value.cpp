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

void making(int m);
void print();
void deleting(int d);

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
        cout<<"Enter the value of node "<<i+1<<" :";
        cin>>value;
        making(value);
        print();
    }
    int d;
    cout<<"Enter the value which You want to delete: ";
    cin>>d;
    deleting(d);
    print();

    return 0;

}

void making(int m)
{
    node* temp = new node();
    if(head == NULL)
        head = temp;
    else
        temp_head->link = temp;
    temp->data = m;
    temp->link = NULL;
    temp_head = temp;

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

void deleting(int d)
{
   node* temp=head;
   node* prv=NULL;

   if(d==1){
        head = temp->link;
        return;
   }
   while(temp != NULL){
        if(temp->data==d){
            prv->link = temp->link;
            return;
        }
        prv=temp;
        temp= temp->link;
   }
}

