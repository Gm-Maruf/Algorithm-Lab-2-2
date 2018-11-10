#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int Data[N];
    for(int i=0; i<N; i++)
    {
        cin>>Data[i];
    }

    for(int i=1; i<N; i++)
    {
        int temp = Data[i];
        int j = i-1;

       while ( j >= 0)
       {
           if(Data[j] > temp)
           {
               Data[j+1] = Data[j];
               j--;
           }
           else
            break;
       }
       Data[j+1] = temp;

    }

        int sum=0;
        for(int i=0; i<N; i++)
        {
            if(Data[i]%2==0)
            {
                cout<<Data[i]<<" ";
                sum = sum + Data[i];
            }

        }
        cout<<sum<<" ";

        sum = 0;
        for(int i=0; i<N; i++)
        {
            if(Data[i]%2!=0)
            {
                cout<<Data[i]<<" ";
                sum = sum + Data[i];
            }

        }
        cout<<sum;

        return 0;
    }
