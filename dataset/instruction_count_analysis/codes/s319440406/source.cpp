#include <iostream>

#include <string>

#include <vector>

#include <set>

#include <cmath>

#include <algorithm>

#include <iomanip>

#include <queue>

using ll = long long;

using namespace std;

int a[100010];

int main(void)

{

    int N;

    cin >> N;

    for (int i = 0; i < N; ++i)

    {

        cin >> a[i];

        a[i]--;

    }



    int ans = 0;



    for (int i = 0; i < N; ++i)

    {

        if (i == a[i])

        {

            ans++;

            i++;

        }

    }

    cout << ans << endl;

    return 0;

}