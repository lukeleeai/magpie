#include"stdc++.h"



#define fi first

#define se second

#define ll long long

#define pb push_back

#define mp make_pair

#define mt make_tuple



using namespace std;



vector<int> graf[100];

map<pair<int, int>, int> grana;

vector<int> svaki[100][100];

bool veza[100];

pair<int, int> niz[30];

bool mark[60];

int n;

ll res = 0;



ll stepen(ll a, int k)

{

    if(k == 0) return 1;

    ll rez = stepen(a, k/2);

    rez *= rez;

    if(k % 2 == 1) rez *= a;

    return rez;

}



bool dfs(int x, int goal, int pret, int ind1, int ind2)

{

    //if(!prvi) cout << x << " * ";

    mark[x] = true;

    if(x == goal)

    {

        mark[x] = false;

        if(pret != 0 && pret != x) svaki[ind1][ind2].pb(grana[mp(min(x, pret), max(x, pret))]);

        return true;

    }

    for(int i = 0; i < graf[x].size(); i++)

    {

        int cvor = graf[x][i];

        if(!mark[cvor])

            if(dfs(cvor, goal, x, ind1, ind2))

            {

                mark[x] = false;

                if(pret != 0 && pret != x) svaki[ind1][ind2].pb(grana[mp(min(x, pret), max(x, pret))]);

                return true;

            }

    }

    mark[x] = false;

    return false;

}





void perm(int ind, int l, int cnt, string s, bool add)

{

    if(ind == l)

    {

        if(cnt != 0) {cout << "kurac"; return;}

        for(int i = 0; i < l; i++)

            if(s[i] == '1')

            {

                int a = min(niz[i].fi,niz[i].se);

                int b = max(niz[i].fi,niz[i].se);

                for(int i = 0; i < svaki[a][b].size(); i++) veza[svaki[a][b][i]] = true;

            }

        int broj = 0;

        for(int i = 1; i <= n; i++) if(veza[i]) broj++;

        //int broj = veza.size();

        //cout << s << " " << broj << "\n";

        broj = n - 1 - broj;

        ll komb = stepen(2, broj);



        if(add) res += komb;

        else res -= komb;

        memset(mark, false, sizeof(mark));

        memset(veza, false, sizeof(veza));

        return;

    }



    if(l - cnt > ind) perm(ind + 1, l, cnt, s + "0", add);

    if(cnt > 0) perm(ind + 1, l, cnt-1, s + "1", add);

}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);





    cin >> n;

    for(int i = 0; i < n - 1; i++)

    {

        int a, b;

        cin >> a >> b;

        graf[a].pb(b);

        graf[b].pb(a);

        grana[mp(min(a,b), max(a,b))] = i+1;

    }

    int m;

    cin >> m;

    for(int i = 0; i < m; i++)

        cin >> niz[i].fi >> niz[i].se;



    for(int i = 0; i < m; i++)

    {

        int a = min(niz[i].fi,niz[i].se);

        int b = max(niz[i].fi,niz[i].se);

        dfs(niz[i].fi, niz[i].se, 0, a, b);

    }



    for(int i = 1; i <= m; i++)

        perm(0, m, i, "", i % 2);



    //cout << res;

    cout << stepen(2, n-1) - res;



    return 0;

}
