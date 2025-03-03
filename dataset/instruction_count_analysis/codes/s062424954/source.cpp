#include"stdc++.h"

#define rep(i,a,b) for(int i=a;i<b;i++)

#define rrep(i,a,b) for(int i=a;i>=b;i--)

#define fore(i,a) for(auto &i:a)

#define all(x) (x).begin(),(x).end()

//#pragma GCC optimize ("-O3")

using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

void _main()

{

    int A, B;

    cin >> A >> B;

    array<array<bool, 100>, 100> c;

    rep(i, 0, 100)

    {

        rep(j, 0, 100)

        {

            c[i][j] = i < 50 ? true : false;

        }

    }



    --A;

    --B;



    for (int i = 0; i < 50; i += 2)

    {

        for (int j = 0; j < 100; j += 2)

        {

            if (A == 0)

            {

                break;

            }

            else

            {

                c[i][j] = false;

                --A;

            }

        }

        if (A == 0)

        {

            break;

        }

    }



    for (int i = 51; i < 100; i += 2)

    {

        for (int j = 0; j < 100; j += 2)

        {

            if (B == 0)

            {

                break;

            }

            else

            {

                c[i][j] = true;

                --B;

            }

        }

        if (B == 0)

        {

            break;

        }

    }



    cout << 100 << " " << 100 << endl;

    rep(i, 0, 100)

    {

        rep(j, 0, 100)

        {

            cout << (c[i][j] ? '#' : '.');

        }

        cout << endl;

    }

}
