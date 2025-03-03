#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;



typedef long long ll;

typedef pair<int, int> pii;

typedef pair<int, pii> pipii;

typedef pair<pii, int> piipi;

typedef pair<pii, pii> piipii;



#define mp make_pair

#define fi first

#define se second

#define all(a) (a).begin(), (a).end()

#define sz(a) (int)(a).size()

#define eb emplace_back



piipii c[405];

piipii rotate(piipii x){

    return mp(mp(x.se.se, x.fi.fi), mp(x.fi.se, x.se.fi));

}



ll get_idx(piipii x){

    return x.fi.fi*1ll*1000*1000*1000 + x.fi.se*1ll*1000*1000 + x.se.fi*1ll*1000 + x.se.se;

}

gp_hash_table<ll, int> dp;



void add(piipii p){

    for(int k=0;k<4;k++){

        dp[get_idx(p)]++;

        p = rotate(p);

    }   

}

void del(piipii p){

    for(int k=0;k<4;k++){

        dp[get_idx(p)]--;

        p = rotate(p);

    }

}





int main(){

    int n;

    scanf("%d", &n);   

    for(int i=1;i<=n;i++){

        scanf("%d%d%d%d", &c[i].fi.fi, &c[i].fi.se, &c[i].se.fi, &c[i].se.se);

        add(c[i]);

    }

    double ans = 0;

    for(int i=1;i<=n;i++){

        for(int j=1;j<=n;j++){

            if(i == j) continue;

            piipii p1 = c[i];

            for(int k=0;k<4;k++){

                del(p1);

                piipii p2 = c[j];

                for(int l=0;l<4;l++){

                    del(p2);



                    double res = 1;

                    piipii tmp1 = mp(mp(p1.fi.se, p1.fi.fi), mp(p2.fi.se, p2.fi.fi));

                    piipii tmp2 = mp(mp(p1.fi.se, p2.fi.fi), mp(p2.se.se, p1.se.fi));

                    piipii tmp3 = mp(mp(p1.se.se, p1.se.fi), mp(p2.se.se, p2.se.fi));

                    piipii tmp4 = mp(mp(p2.fi.se, p1.fi.fi), mp(p1.se.se, p2.se.fi));

                    if(dp.find(get_idx(tmp1)) != dp.end()){

                        res *= dp[get_idx(tmp1)];

                        del(tmp1);

                    }

                    else res = 0;

                    if(dp.find(get_idx(tmp2)) != dp.end()){

                        res *= dp[get_idx(tmp2)];

                        del(tmp2);

                    }

                    else res = 0;

                    if(dp.find(get_idx(tmp3)) != dp.end()){

                        res *= dp[get_idx(tmp3)];

                        del(tmp3);

                    }

                    else res = 0;

                    if(dp.find(get_idx(tmp4)) != dp.end()){

                        res *= dp[get_idx(tmp4)];

                        del(tmp4);

                    }

                    else res = 0;



                    ans += res;



                    if(dp.find(get_idx(tmp1)) != dp.end()){

                        add(tmp1);

                    }

                    if(dp.find(get_idx(tmp2)) != dp.end()){

                        add(tmp2);

                    }

                    if(dp.find(get_idx(tmp3)) != dp.end()){

                        add(tmp3);

                    }

                    if(dp.find(get_idx(tmp4)) != dp.end()){

                        add(tmp4);

                    }

                    

                    add(p2);

                    p2 = rotate(p2);

                }



                add(p1);

                p1 = rotate(p1);

            }

        }

    }

    printf("%.0lf\n", ans/24);

}