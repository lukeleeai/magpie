#include"stdc++.h"

using namespace std;

int main(void)

{

    std::ios::sync_with_stdio(false);

    long long int n,k,a,b,c,d=1e15;

    cin>>n>>k;

    int x[n];

    for(int i=0;i<n;i++)

    {

        cin>>x[i];

    }

    for(int i=0;i+k-1<n;i++)

    {

        a=i;

        b=i+k-1;

        c=min(abs(x[a])+abs(x[a]-x[b]), abs(x[b])+abs(x[a]-x[b]));

        d=min(c,d);

    }

    cout<<d<<endl;

}
