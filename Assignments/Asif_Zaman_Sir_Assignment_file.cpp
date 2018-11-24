#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int num[100];
    int t=0,c=0;

    ifstream Ran_Num("Random_Numbers.txt");
    ofstream Asc_Ordr("Ascending_Order.txt");
    ofstream Des_Ordr("Descending_Order.txt");

    if(Ran_Num)
    {
        while(getline(Ran_Num,str))
        {
            stringstream convert(str);
            convert>>num[t];
            c=t++;
        }
        Ran_Num.close();
    }

    else
        cout<<"Can't open file";

    for(int i=0; i<t; i++)
    {
        for(int j=i+1; j<t; j++)
        {
            if(num[i]>num[j])
            {
                int tmp=num[i];
                num[i]=num[j];
                num[j]=tmp;
            }
        }
    }

    if(Asc_Ordr)
    {
        for(int j=0; j<t; j++)
        Asc_Ordr<<num[j]<<endl;
  	}
  	else
        cout <<"Unable to open file";

    if(Des_Ordr)
    {
        for(int j=c; 0<j; j--)
        Des_Ordr<<num[j]<<endl;
    }
    else
        cout <<"Can't open file";

    Asc_Ordr.close();
    Des_Ordr.close();

    return 0;
}
