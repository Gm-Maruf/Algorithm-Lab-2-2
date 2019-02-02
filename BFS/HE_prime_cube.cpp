#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll parr[1000004]={0},prime1,prime2;
int ps=0;
void prime()
{
    int a[1000004]={0};
    for(int i=2;i<=1000;i++)
    if(a[i]==0)
    {
        for(int j=i*i;j<=1000000;j+=i)
        a[j]=1;
    }
    for(int i=2;i<=1000000;i++)
    if(a[i]==0)
    parr[ps++]=i;
}
ll check(ll val,ll a)
{
    ll low=-1;
    while(parr[++low]<=a)
    ;
    for(ll i=low;i<ps;i++)
    {
        ll temp=val-(parr[i]*parr[i]*parr[i]);
        if(temp<8)
        return 0;
        ll low1=i,high1=ps-1,mid1;
        while(low1<=high1)
        {
            mid1=(low1+high1)/2;
            if(temp>pow(parr[mid1],3))
            low1=mid1+1;
            else if(temp<pow(parr[mid1],3))
            high1=mid1-1;
            else
            {
                prime1=parr[i];prime2=parr[mid1];
                return parr[i];
            }
        }
    }
    return 0;
}
int main()
{
    prime();
    ll n;
    scanf("%lld",&n);
    n-=8;
    for(ll i=1;i<=cbrt(n);i+=2)
    {
        ll val=n-(i*i*i);
        ll ind=check(val,i);
            if(ind>0)
            {
                printf("%lld 2 %lld %lld",i,prime1,prime2);
                return 0;
            }
    }
    cout<<"-1";
    return 0;
}
