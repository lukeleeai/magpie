#include "stdc++.h"

#define LL long long

using namespace std;



const int N = 1e5;



int n,k,cnt0 = 0;

LL a[N+10];



int main()

{

    ios::sync_with_stdio(0),cin.tie(0);

    cin >> n >> k;

    for (int i = 1;i <= n;i++){

        cin >> a[i];

        if (a[i]==0) cnt0++;

    }

    if(k==1&&cnt0){cout<<"0\n";return 0;}

    if (cnt0==0) a[++n] = 0;

    sort(a+1,a+1+n);

    int idx = 1;

    for (int i = 1;i <= n;i++) if (a[i]==0) idx = i;

    LL ans = 1e18;

    for (int i = 1;i <= n;i++){

        LL temp = 0;

        int cnt = 0;

        temp = temp + abs(a[idx]-a[i]);

        cnt+=abs(idx-i);

        if (cnt0) cnt++;

        if (cnt>k) continue;

        if (cnt==k){

            ans = min(ans,temp);

            continue;

        }

        if (i<idx){

            if (idx+k-cnt<=n){

                temp = temp + 2*abs(a[idx+k-cnt]-a[idx]);

                ans = min(ans,temp);

            }else continue;

        }else{

            if (idx-(k-cnt)>=1){

                temp = temp + 2*abs(a[idx]-a[idx-(k-cnt)]);

                ans = min(ans,temp);

            }

        }

    }

    cout<<ans<<endl;

    return 0;

}
