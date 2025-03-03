#include"stdc++.h"

using namespace std;

typedef long long lli;

typedef long li;

typedef int in;

typedef double dub;

#define fst first

#define scnd second

#define pub push_back

#define pob pop_back

#define mkp make_pair

#define lb lower_bound

#define ub upper_bound

int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    long long h,n,a[100005],i,sum;

    while(cin>>h>>n)

    {

        sum=0;

        for(i=0;i<n;i++)

        {

            cin>>a[i];

            sum=sum+a[i];

        }

        if(sum>=h)

        {

            cout<<"Yes"<<endl;

        }

        else

        cout<<"No"<<endl;

    }

    return 0;

}


