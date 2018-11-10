#include <iostream>
using namespace std;

void insertionsort(int a[], int n);
int sum(int arr[],int n);
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    insertionsort(arr, n);
    int k;
    cin >> k;
    int key[k];
    for (int j=0; j<k; j++){ cin >> key[j];}

    int tot = 0;
    int element =0;
    int num=1;
    int t;
    t= sum(key,k);

    if (t < n)
    {
        cout << -1 ;
        return 0;
    }

    else
    { int i=0;
    while (element < k)
    { int j;
       j =0;
        while ((i < n) and (j < k-element))
        {
         tot = tot + (arr[i])* (num)  ;
         i++;
         j++;

        }
        num++;

        for (int c=0; c < k; c++)
        {
            key[c] = key[c] - 1;
            if (key[c] == 0)
            {
                element ++ ;
            }
        }
    }
}
cout << tot;
return 0;}

void insertionsort(int a[], int n)
{int maximum;
    for (int i=0; i< n-1; i++)
    {
        maximum= i;
        for (int j=i; j<n; j++)
        {
            if(a[j] > a[maximum])
            {
                maximum = j;
            }

        }
       swap(a[maximum],a[i]);
    }
}

int sum(int arr[],int n)
{
    int tot = 0;
    for (int i=0; i<n; i++)
    {
        tot = tot + arr[i];
    }
    return tot;
}
