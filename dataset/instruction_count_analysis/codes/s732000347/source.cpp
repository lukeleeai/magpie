#include"stdc++.h"

using namespace std;

#define pi acos(0.0)

#define ll long long

#define f first

#define s second

#define gap ' '

#define pb push_back

int main()

{

    int n,k;

    cin>>n>>k;

    if(((n-2)*(n-1))/2 < k)

    {

        cout<<-1;

        return 0;

    }

    pair<int,int> ara[100005];

    int m=0;

    for(int i=2;i<=n;i++)

    {



       ara[m].f=1;

       ara[m].s=i;

       m++;



    }

    vector<pair<int,int> >p;

    for(int i=2;i<=n;i++)

    {

       for(int j=i+1;j<=n;j++)

       {

          p.pb({i,j});

       }

    }

    for(int i=0;i<((n-2)*(n-1))/2-k;i++)

    {

        ara[m]=p[i];

        m++;



    }

    cout<<m<<endl;

    for(int i=0;i<m;i++)

    {

        cout<<ara[i].f<<gap<<ara[i].s<<endl;

    }





}
