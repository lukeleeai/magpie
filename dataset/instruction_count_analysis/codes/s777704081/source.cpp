#include "stdc++.h"



#define fr first

#define sc second

#define mk make_pair

#define pb push_back

#define sz(s) (int)s.size()

#define all(s) s.begin(), s.end()

#define int long long



using namespace std;



const int N = 30005;



int n, u[N], sum = 0, m;



vector <int> ans;



main()

{

    cin >> n;

    m = n;

    if (n == 3)

    {

        puts("2 5 63");

        return 0;

    }

    ans.push_back(2);

    sum = 2;

    u[2] = 1;

    n--;

    for (int i = 30000; ; i -= 2)

    {

        if (n == 2)

        {

            sum -= ans.back();

            i = ans.back();

            u[i] = 0;

            ans.pop_back();

            while (u[i] || (sum + i) % 30 != 0)

                i -= 2;



            sum += i;

            u[i] = 1;

            ans.push_back(i);

            break;

        }

        sum += i;

        ans.pb(i);

        u[i] = 1;

        n--;



        if (i < 100 && n % 10 == 0)

        {

            sum -= ans.back();

            i = ans.back();

            u[i] = 0;

            ans.pop_back();

            while (u[i] || (sum + i) % 30 != 0)

                i -= 2;

            sum += i;

            u[i] = 1;

            ans.push_back(i);

            break;

        }

    }

    /***/

    sum = 0;

    for (int i = 30000; ; i -= 3)

    {

        if (u[i] || i % 2 == 0) continue;



        if (n == 0)

        {

            sum -= ans.back();

            i = ans.back();

            u[i] = 0;

            ans.pop_back();

            while (u[i] || (sum + i) % 30 != 0)

                i -= 3;



            sum += i;

            u[i] = 1;

            ans.push_back(i);

            break;

        }

        sum += i;

        ans.pb(i);

        u[i] = 1;

        n--;



        if (i < 500 && n % 6 == 0)

        {

            sum -= ans.back();

            i = ans.back();

            u[i] = 0;

            ans.pop_back();

            while (u[i] || (sum + i) % 30 != 0)

                i -= 3;



            sum += i;

            u[i] = 1;

            ans.push_back(i);

            break;

        }

    }

    /***/

    sum = 0;

    for (int i = 30000; ; i -= 5)

    {

        if (u[i]) continue;



        if (n == 0)

        {

            sum -= ans.back();

            i = ans.back();

            u[i] = 0;

            ans.pop_back();

            while (u[i] || (sum + i) % 30 != 0)

                i -= 5;



            sum += i;

            u[i] = 1;

            ans.push_back(i);

            break;

        }

        sum += i;

        ans.pb(i);

        u[i] = 1;

        n--;

    }

    int gcd = 0;

    sum = 0;

    assert(ans.size() == m);



    for (auto to : ans) sum += to, gcd = __gcd(to, gcd);



    assert( gcd == 1 );

    for (auto to : ans)

    {

        assert( __gcd( to, sum - to ) != 1 );

    }



    for (auto to : ans)

        cout << to << " ";

}
