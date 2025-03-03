#include <iostream>

#include <vector>

#include <algorithm>

#include <queue>

#include <map>

#include <cstring>



using namespace std;

map< long long, int > mp;

int main()

{

    int n, m;

    cin >> n >> m;

    for( int i = 1; i <= n; ++ i )

    {

        int num;

        cin >> num;

        for( int j = 1; j <= num; ++ j )

        {

            int t;

            cin >> t;

            mp[t] ++;

        }

    }

    int ans = 0;

    for( auto i : mp )

        if( i.second == n ) ans ++;

    cout << ans << endl;

}