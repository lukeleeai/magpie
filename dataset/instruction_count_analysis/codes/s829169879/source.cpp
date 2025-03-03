#include"stdc++.h"

using namespace std;

int sum=0,n,x,k,ans=0;

int a[1000001];

map<int,int> m; 

int main()

{

    cin>>n>>k;

    for(int i=1;i<=n;i++)

    {

        scanf("%d",&x);

        m[x]++;

    }

    int q=m.size();

    map<int,int>::iterator it=m.begin();

    for(it;it!=m.end();it++)

    {

        a[++sum]=(*it).second;

    }

    sort(a+1,a+sum+1);

    for(int i=1;i<=q-k;i++)

    {

        ans+=a[i];

    }

    cout<<ans<<endl;

    return 0;

 } 