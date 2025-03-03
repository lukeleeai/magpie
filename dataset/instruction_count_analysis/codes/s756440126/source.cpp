#include "stdc++.h"

#define ll long long

using namespace std;



vector<int> buf;



int main()

{

    int N, h[100], c = 0;

    vector<vector<int>> T(1000, vector<int>(100, 0));

    int ans = 0;

    cin >> N;

    for (int i = 0; i < 100; i++)

    {

        h[i] = 0;

    }

    for (int i = 0; i < N; i++)

    {

        cin >> h[i];

    }

    for (int i = 0; i < 100; i++)

    {

        for (int j = 0; j < N; j++)

        {

            if (h[j] > i)

            {

                T[i][j] = 1;

            }

        }

    }

    for (int i = 0; i < 100; i++)

    {

        for (int j = 0; j < N; j++)

        {

            c = 0;

            while (T[i][j] == 1)

            {

                j++;

                c++;

            }

            if (c != 0)

            {

                ans++;

            }

        }

    }

    cout << ans << endl;

    return 0;

}