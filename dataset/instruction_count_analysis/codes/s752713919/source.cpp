#include "stdc++.h"

using namespace std;



#ifdef LOCAL

	#define D(a) cerr << #a << " = " << a << endl

#else

	#define D(a)

	#define cerr false && cerr

#endif

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)

#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define forn(i,n) forsn(i,0,n)

#define all(a) a.begin(),a.end()

#define si(a) int((a).size())

#define pb emplace_back

#define mp make_pair

#define snd second

#define fst first

using pii = pair<int,int>;

using vi = vector<int>;

using ll = long long;



vi node;

vector<vi> g;

vector<bool> v;



int sum(int n){

    v[n] = true;

    int s = node[n];

    for(int i : g[n]) if(!v[i]) s += sum(i);

    return s;

}



int main() {

	fastio;

	

    string s; cin >> s;

    int n = si(s), sd = n+1, sn = (sd+1)/2;

    vi d(sd);

    s = 'a'+s+'a';

    node = vi(sn), g.resize(sn), v.resize(sn);



    forn(i,sd) d[i] = (26+s[i]-s[i+1]) % 26;

    forn(i,sd/2) node[i] = (52-d[i]-d[sd-i-1]) % 26; 

    if(sd & 1) node[sd/2] = (26-d[sd/2]) % 26;



    int m; cin >> m;

    forn(i,m){

        int x,y; cin >> x >> y; x--;

        if(x >= sd/2) x = sd-x-1;

        if(y >= sd/2) y = sd-y-1;

        g[x].pb(y), g[y].pb(x);

    }

    bool ok = true;

    forn(i,sn) if(!v[i] && sum(i) % 26 != 0) ok = false;

    cout << (ok ? "YES" : "NO") << endl;  

	return 0;

}
