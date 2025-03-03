#include "stdc++.h"

#define rep(i,n) for(int i = 0; i < (n); ++i)

#define srep(i,s,t) for(int i = s; i < t; ++i)

#define drep(i,n) for(int i = (n)-1; i >= 0; --i)

using namespace std;

typedef long long int ll;

typedef pair<int,int> P;

#define yn {puts("Yes");}else{puts("No");}

#define MAX_N 200005



int main() {

    int x[MAX_N] = {}, y[MAX_N] = {};

    int n, q;

    scanf("%d%d", &n,&q);

    ll ans = (ll)(n-2)*(n-2);

    srep(i,2,n){

        x[i] = n;

        y[i] = n;

    }

    int xx = n;

    int yy = n;

    while(q--){

        int t, z;

        scanf("%d%d", &t,&z);

        if(t == 1){

            if(z < xx){

                ans -= yy - 2;

                srep(i,z,xx) x[i] = yy;

                xx = z;

            }else{

                ans -= x[z] - 2;

            }

        }else{

            if(z < yy){

                ans -= xx - 2;

                srep(i,z,yy) y[i] = xx;

                yy = z;

            }else{

                ans -= y[z] - 2;

            }

        }

    }

    cout << ans << endl;

    return 0;

}




