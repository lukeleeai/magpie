#include <iostream>

#include <cstdio>

#include <algorithm>



using namespace std;



const int INF = 0x3f3f3f3f;

const int N = 1e5;



int a[N+10];



int main()

{

    int n, k;

    int cnt0 = 0;

    cin >> n >> k;

    for(int i = 1; i <= n; ++i)

    {

        cin >> a[i];

        if(a[i] == 0)

            cnt0++;

    }

    if(!cnt0)

        a[++n] = 0;

    sort(a+1,a+1+n);

    int idx = 1;

    for(int i = 1; i <= n; ++i)

        if(a[i] == 0)

            idx = i;

    int ans = INF;

    for(int i = 1; i <= n; ++i)

    {

        if(i == idx)

        {

            if(!a[i] && k == 1)

                ans = 0;

            continue;

        }

        int tmp = abs(a[idx]-a[i]);

        int cnt = abs(idx-i);

        if(cnt0)

            cnt++;

        if(cnt > k)

            continue;

        if(cnt == k)

        {

            ans = min(ans,tmp);

            continue;

        }

        //cnt<k

        if(i < idx)

        {

            if(idx+k-cnt <= n)

                ans = min(ans, tmp + 2*a[idx+k-cnt]);

            else

                continue;

        }

        else

        {

            if(idx-k+cnt >= 1)

                ans = min(ans, tmp - 2*a[idx-k+cnt]);

        }

    }

    cout << ans;

    return 0;

}
