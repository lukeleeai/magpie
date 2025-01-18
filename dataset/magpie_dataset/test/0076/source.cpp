#include"stdc++.h"

using namespace std;



int main()

{

    int n, m, i, j;

    cin>>n>>m;

    int p;

    string s;

    bool mark[n+1]= {};

    int wcnt[n+1]= {};

    for(i=0; i<m; i++)

    {

        cin>>p>>s;

        if(s=="AC")

            mark[p]=1;

        else if(mark[p]==0)

            wcnt[p]++;

    }

    int cor=0, pen=0;

    for(i=1; i<=n; i++)

    {

        if(mark[i]==1)

        {

            cor++;

            pen+=wcnt[i];

        }

    }

    cout<<cor<<' '<<pen;

}
