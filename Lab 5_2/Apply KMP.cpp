#include<bits/stdc++.h>
using namespace std;

int main(){
    string P, T;
    cin>>P >>T;
    int n = P.length(), j=0, found = 0;
    int kmp[n];
    kmp[0] = 0;
    for(int i=1; i<n; i++){
        if(P[i] == P[j]){
            j++;
        }
        else{
            while(j>0 and P[i] != P[j]){
                j = kmp[j-1];
            }
            if(P[i] == P[j]) j++;
        }
        kmp[i] = j;
    }
    j = 0;
    for(int i=0; i<T.length(); i++){
        if(j == n){
            found++;
            j = kmp[j-1];
        }
        if(T[i] == P[j]){
            j++;
        }
        else{
            while(j>0 and T[i]!=P[j]){
                j = kmp[j-1];
            }
            if(T[i] == P[j]) j++;
        }
    }
    if(j == n) found++;
    cout<<found;
}
