#include"stdc++.h"

using namespace std;

string s;

struct node

{

    int a[26];

    node()

    {

        memset(a,0,sizeof(a));

    }

};

node d[52];

int main()

{

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t,i,j,n,m,l,r;

    cin>>n;

    for(i=0;i<n;i++)

    {

        cin>>s;

        m=s.size();

        for(char c:s)

        {

            l=c-97;

            d[i].a[l]++;

        }

    }

    s.clear();

    for(i=0;i<26;i++)

    {

        l=INT_MAX;

        for(j=0;j<n;j++)

        {

            l=min(l,d[j].a[i]);

        }

        for(j=0;j<l;j++)

        {

            s+=(char)(i+97);

        }

    }

    cout<<s<<"\n";

    return 0;

}


