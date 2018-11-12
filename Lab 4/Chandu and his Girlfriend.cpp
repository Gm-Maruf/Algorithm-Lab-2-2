#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int Arr[N];
        for(int i=0; i<N; i++)
        {
            cin>>Arr[i];
        }

        sort(Arr,Arr+N,cmp);
        for(int i=0; i<N; i++)
        {
            cout<<Arr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
