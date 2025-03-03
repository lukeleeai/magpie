/*ILTH      ILTH            ILTHILTHILTH    ILTH        ILTH

  ILTH      ILTH                ILTH        ILTH        ILTH

  ILTH      ILTH                ILTH        ILTHILTHILTHILTH

  ILTH      ILTH                ILTH        ILTH        ILTH

  ILTH      ILTHILTHILTH        ILTH        ILTH        ILTH



  */

#include "stdc++.h"

#define fi first

#define se second

#define pb push_back



using namespace std;

typedef long long ll;

typedef pair<int,int> pii;

const int maxN=300009;

pii a[maxN];

int n,m,bt[maxN];

bool comp(pii a, pii b){

    return a.se-a.fi<b.se-b.fi;

}

void up(int x, int y){

    for (;x<=m; x+=x&-x) bt[x]+=y;

}

int get(int x){

    int res=0;

    for (;x;x-=x&-x) res+=bt[x];

    return res;

}

int main()

{

    cin >> n >> m;

    for (int i=1; i<=n; ++i){

        int l,r;

        cin >> l >> r;

        a[i]={l,r};

    }

    sort(a+1, a+n+1, comp);



    int j=1;

    for (int i=1; i<=m; ++i){

        int res=0;

        while (a[j].se-a[j].fi+1<i && j<=n){

            up(a[j].fi,1);

            up(a[j].se+1,-1);

            ++j;

        }

        res+=n-j+1;

        for (int k=1; k*i<=m; ++k) res+=get(k*i);

        cout << res << "\n";

    }



    return 0;

}
