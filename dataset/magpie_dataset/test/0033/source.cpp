#include "stdc++.h"

#define Mod 1000000007

#define eps 1e-6

#define ll long long

#define INF 0x3f3f3f3f

#define MEM(x, y) memset(x, y, sizeof(x))

#define Maxn 1000000 + 10

using namespace std;

int n;

int h;

int result = 0;

int main()

{

    cin >> n >> h;

    while (n--)

    {

        int x;

        cin >> x;

        if (x >= h)

            result++;

    }

    cout << result << endl;

}
