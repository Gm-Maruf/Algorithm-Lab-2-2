#include <bits/stdc++.h>
using namespace std;

long long int arr[2000005],size[2000005],men[2000005],women[2000005];

void initialize(long long int n){
	for(long long int i=1;i<=n;i++){
		arr[i]=i;
		size[i]=1;
		men[i]=0;
		women[i]=0;
	}
}

long long int root(long long int key){
	while(key!=arr[key]){
		key=arr[key];
	}
	return key;
}

void connect(long long int start,long long int end)
{

	long long int root_start=root(start);
	long long int root_end=root(end);
	if(root_start==root_end)
    {
		return;
	}
	else
	{
		if(size[root_start]>=size[root_end])
		{
			arr[root_end]=arr[root_start];
			size[root_start]+=size[root_end];
			size[root_end]=-1;
        }
		else
		{
			arr[root_start]=arr[root_end];
			size[root_end]+=size[root_start];
			size[root_start]=-1;
		}
	}
}

int main()
{
	long long int x,y,start,end,i,q1,q2,q3;
	long long int ans=0;

	//cout<<"Enter x and y"<<endl;
		cin>>x>>y;
        initialize(x+y);

	//cout<<"Enter q1"<<endl;
		cin>>q1;

	for(i=1;i<=q1;i++){
		cin>>start>>end;
		connect(start,end);
	}
	//cout<<"Enter q2"<<endl;
		cin>>q2;
	for(i=1;i<=q2;i++)
    {
		cin>>start>>end;
		connect(start+x,end+x);
	}
	//cout<<"Enter q3"<<endl;
		cin>>q3;
	for(i=1;i<=q3;i++)
    {
		cin>>start>>end;
		connect(start,end+x);
	}
	for(i=1;i<=x+y;i++)
    {
		long long int temp=root(i);
		if(i<=x)
		{
			men[temp]++;
		}

		else
        {
			women[temp]++;
		}
	}
    for(i=1;i<=x+y;i++)
    {
        ans+=(men[i]*(y-women[i]));
    }
	cout<<ans;

	return 0;
}
