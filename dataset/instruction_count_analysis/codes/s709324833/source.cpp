    #include"stdc++.h"

     

    using namespace std;

     

    const int MaxN = 1e5 + 15;

     

    int n, h;

     

    pair<int, int> a[MaxN];

    long long c[MaxN];

     

    int main()

    {

        ios_base :: sync_with_stdio(false);

        cin.tie(NULL);

     

        cin >> n >> h;

     

        int mx = 0;

     

        for(int i = 1; i <= n; ++i)

        {

            cin >> a[i].second >> a[i].first;

            mx = max(mx, a[i].second);

        }

        sort(a + 1, a + n + 1);

        for(int i = n; i; --i)

            c[i] = c[i + 1] + a[i].first;

     

        long long ans = 1e9;

     

        for(int i = n + 1; i; --i)

        {

            if(c[i] >= h)

                ans = min(ans, n - i + 1ll);

            else

                ans = min(ans, n - i + 1 + (h - c[i]) / mx + ((h - c[i]) % mx ? 1 : 0));

        }

     

        cout << ans << '\n';

        return 0;

    }