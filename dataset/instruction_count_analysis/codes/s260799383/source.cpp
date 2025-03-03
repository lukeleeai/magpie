#include <iostream>

#include <vector>

#include <deque>

#include <math.h>

#include <set>

#include <iomanip>

#include <time.h>

#include <list>

#include <stdio.h>

#include <queue>

#include <map>

#include <algorithm>

#include <assert.h>

#include <memory.h>



#define mk make_pair

#define sc second

#define fr first

#define pb emplace_back

#define all(s) s.begin(), s.end()

#define sz(s) ( (int)s.size() )

#define int long long



using namespace std;



string s;



int mp[1500], n, res;



main ()

{

    cin >> s;

    s = ' ' + s;

    n = sz(s) - 1;

    for (int i = 1; i <= n; i++)

        mp[ s[i] ]++;



    res = n * (n + 1) / 2;



    for (int i = 'a'; i <= 'z'; i++)

        res -= mp[i] * (mp[i] + 1) / 2;



    cout << res + 1 << endl;

}
