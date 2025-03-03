#include"stdc++.h"

using namespace std;

#define ll long long

#define ull unsigned long long

#define mp make_pair

typedef pair<int,int> pii;

ll a[200009];

ll n;ll k;

int main()

{

    scanf("%d%lld",&n,&k);

    for(int i=0;i<n;i++)scanf("%lld",&a[i]);

    sort(a,a+n);

    ll l=-1e18,r=1e18;

    ll answer;

    while(l<=r)

    {

        ll mid=(l+r)/2;ll cnt=0;

        for(int i=0;i<n;i++)

        {

            if(a[i]>0){

                cnt+=upper_bound(a,a+n,(long double)mid/a[i])-a;

            }

            else if(a[i]<0){

                cnt+=n-(lower_bound(a,a+n,(long double)mid/a[i])-a);

            }

            else if(mid>=0)cnt+=n;

            if(a[i]*a[i]<=mid)cnt--;

        }

        if(cnt>=k*2)answer=mid,r=mid-1;

        else l=mid+1;

    }

    cout<<answer<<endl;

    return 0;

}