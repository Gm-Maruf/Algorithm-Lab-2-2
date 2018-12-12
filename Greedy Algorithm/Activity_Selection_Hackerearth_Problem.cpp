#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int l,i;
    cin>>str;
    l=str.length();
    for(i=0;i<l;i++){
        if(str[i]=='?'){
            if(i!=0 || i!=l-1){
            if(str[i+1]=='a' || str[i-1]=='a')
            str[i]='b';
            else
            str[i]='a';
        }
        else{
            if(i==0){
                if(str[i+1]=='a')
                str[i]='b';
                else
                str[i]='a';
            }
            else{
                if(str[i-1]=='a')
                str[i]='b';
                else
                str[i]='a';
            }
        }
    }

}
cout<<str;
}
