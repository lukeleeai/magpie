#include "stdc++.h"



#define ll long long



using namespace std;



const int inf = 1e9 + 7;





ll ans = inf, cur;



main()

{

    int n;

    cin >> n;



    for (int i = 0; i < n; i++)

    {

        int a, b;

        scanf("%d%d", &a, &b);



        cur += a;



        if (a > b)

            ans = min(ans, b * 1LL);

    }



    if (ans == inf)

    {

        cout << 0;

        return 0;

    }

    cout << cur - ans;

}




