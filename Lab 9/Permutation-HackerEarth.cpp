#include<iostream>
using namespace std;
int insertion_sort(int a[],int n)
{
    int c=0,value,hole;
    for(int i=1; i<n-1; i++)
    {
        value=a[i];
        hole=i;
        while(hole>0 && a[hole-1]>value){
            a[hole]=a[hole-1];
            hole=hole-1;
        }
        a[hole]=value;
        c++;
    }
    return c;
}
int main()
{
    int i,n,a[8],k;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];

    }
    k=insertion_sort(a,n);
    cout<<k;
}
