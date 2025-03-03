#include "stdc++.h"



#define fr first

#define sc second

#define mk make_pair

#define pb push_back

#define ok puts("OK");

#define sz(s) (int)s.size()

#define all(s) s.begin(), s.end()

#define int long long



using namespace std;



int tests, a, b;



int check (int x)

{

    int l = 1, r = x;

    while (r - l > 2)

    {

        int md1 = l + (r - l + 1) / 3, md2 = r - (r - l + 1) / 3;

        if ( md1 * (b + x - md1 + 1) > md2 * (b + x - md2 + 1) )

            r = md2;

        else

            l = md1;

    }

    int ans = l * (b + x - l + 1);



    for (int i = l; i <= r; i++)

        ans = max(ans, i * (b + x - i + 1) );



    return ans;

}



main()

{

    cin >> tests;

    while (tests--)

    {

        cin >> a >> b;

        if (a < b)

            swap(a, b);

        int l = 1, r = b;



        while (r - l > 1)

        {

            int md = (l + r) >> 1;

            if ( (a + 1) * md < a * b )

                l = md;

            else

                r = md;

        }

        int left = b - l - 1;



        l = 0, r = a - left;



        while (r - l > 1)

        {

            int md = (l + r) >> 1;

            if ( check(md) < a * b )

                l = md;

            else

                r = md;

        }

        cout << l + b - 1<< endl;

    }

}
