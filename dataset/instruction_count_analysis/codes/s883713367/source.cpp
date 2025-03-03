#include <iostream>

#include <cmath>

#include <stdio.h>

#include <algorithm>

#include <string>

#include <vector>

#include <queue>

#include <deque>

#include <stack>

#include <map>

#include <set>

#include <cstring>



using namespace std;



#define f first

#define s second

#define pb push_back

#define mp make_pair

#define ll long long

#define pii pair < int, int >

#define pll pair < long long, long long>

#define ull unsigned long long

#define vi vector < int >

#define vll vector < long long >

#define sz(a) (int)a.size()

#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)

#define all(a) a.begin(), a.end()

#define sqr(x) ((x) * (x))

#define fname "searching"



const int inf = (int)1e9;

const ll INF = (ll)1e18;

const double eps = 1e-9;

const double pi = acos(-1.0);

const int mod = (int)1e9 + 7;



int n, k;

bool d[10];



int solve(){

    for(int i = n; i < 1000000; ++i){

        string s = to_string(i);

        bool ok = 1;

        for(int j = 0; j < sz(s); ++j){

            if(d[s[j] - '0']){

                ok = 0;

                break;

            }

        }

        if(ok) return i;

    }

    return n;

}



int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cin >> n >> k;

    for(int i = 0, x; i < k; ++i){

        cin >> x;

        d[x] = 1;

    }

    

    cout << solve() << "\n";



    return 0;

}
