#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int vaccin[N];
    int patient[N];
    int sum_vaccin = 0;
    int sum_patient = 0;

    for(int i=0; i<N; i++)
    {
        cin>>vaccin[i];
        sum_vaccin = sum_vaccin + vaccin[i];
    }
    for(int i=0; i<N; i++)
    {
        cin>>patient[i];
        sum_patient = sum_patient + vaccin[i];
    }
    if(sum_patient <= sum_vaccin)
    {
        cout<<"No";
    }
    else
        cout<<"Yes";

    return 0;
}
