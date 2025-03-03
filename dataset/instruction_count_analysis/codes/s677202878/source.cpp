#define ll long long

#define pi acos(-1.0)

#define Go "\n"

#define bye return 0

#define Afor(i,b) for(int i=0;i<b;i++)

#include"stdc++.h"

using namespace std;

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll N,i,s=0;

    cin>>N;

    for(i=1;i<=N;i++)

    {

        if(i%3!=0&&i%5!=0)

        {

            s=s+i;

        }

    }

    cout<<s<<Go;

    bye;



}
