#include"stdc++.h"

using namespace std;

#define INS(x) x.begin(),x.end()

int a[25];

int main()

{

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;

    cin>>n;

    for (int i=0;i<n;i++)

        cin>>a[i];

    vector<int> b;

    int ans=0;

    for (int i=0;i<n-2;i++)

    {

        b.clear();

        for (int j=0;j<3;j++)

            b.push_back(a[i+j]);

        sort(INS(b));

        if (a[i]!=a[i+1]&&a[i+1]!=a[i+2]&&a[i+1]==b[1]) ans++;

    }

    cout<<ans<<'\n'; 

    return 0;

}