#include"stdc++.h"



#define fi first

#define se second

#define ll long long

#define pb push_back

#define mp make_pair

#define mt make_tuple



using namespace std;



int niz[100010];

vector<int> graf[100010];

vector<pair<int, int>> res;



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



    string s;

    cin >> s;

    int n = s.size();

    for(int i = 1; i <= n; i++)

        niz[i] = s[i-1] - '0';

    bool ok = true;

    if(niz[1] == 0 || niz[n] == 1) ok = false;

    for(int i = 1; i <= n/2; i++)

        if(niz[i] != niz[n - i]) {ok = false; break;}



    if(!ok) {cout << -1; return 0;}



    int tr = 1;

    for(int i = 1; i < n; i++)

    {

        res.pb(mp(i+1, tr));



        if(niz[i] == 1)

            tr = i + 1;

    }

    for(int i = 0; i < res.size(); i++)

        cout << res[i].fi << " " << res[i].se << "\n";





    return 0;

}
