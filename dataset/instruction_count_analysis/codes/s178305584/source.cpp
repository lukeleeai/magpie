 /******************************************************************************



                         بسم الله الرحمن الرحيم

                     Author: Mst: Mhamuda Khatun

                               RUCSE27



*******************************************************************************/



#include"stdc++.h"

using namespace std;

#define ull unsigned long long

#define ll long long

#define pi 2*acos(0.0)

#define f first

#define s second

#define pb push_back

#define gap ' '

#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}

#define mod 1000000007

#define MAX 1000000000000

#define N 305



int main()

{

    fastio;

    int n,len,i,cnt=0;

    cin>>n;

    string x;

    for(i=1;i<=n;i++)

    {

        x=to_string(i);

        len=x.size();



        if(len%2==1)

            cnt++;

    }

    cout<<cnt;

    cout<<"\n";

    return 0;   //:D

}




