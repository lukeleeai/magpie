#include"stdc++.h"

using namespace std;

string s[200005];

int main()

{

    ios::sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=0;i<n;i++)

    {

        cin>>s[i];

    }

    sort(s,s+n);

    string s1="";

    long long ans=0;

    for(int i=0;i<n;i++)

    {

        if(s1!=s[i])

        {

            ans++;

            s1=s[i];

        }

    }

    cout<<ans;

}
