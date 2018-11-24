#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5];
    int i,j,k;
    int check,rem=0;

    cout<<"Enter numbers: ";
    for(i=0; i<5; i++){
        cin>>a[i];
    }

    cout<<"Enter the value You want to search: ";
    cin>>check;

    for(j=0; j<5; j++){
        if(a[j]==check){
            rem=1;
            break;
        }
    }
    if(rem==1)
        cout<<"The number exists";
     else
        cout<<"The number doesn't exist";
    return 0;
}
