#include "stdc++.h"

#define rep(i,n) for(int i = 0; i < (n); ++i)

#define srep(i,s,t) for(int i = s; i < t; ++i)

#define drep(i,n) for(int i = (n)-1; i >= 0; --i)

using namespace std;

typedef long long int ll;

typedef pair<int,int> P;

#define yn {puts("Yes");}else{puts("No");}

#define MAX_N 200005



#define ch() getchar()

#define pc(x) putchar(x)

template<typename T>inline void read(T&x){

	int f;char c;

	for(f=1,c=ch();c<'0'||c>'9';c=ch())if(c=='-')f=-f;

	for(x=0;c<='9'&&c>='0';c=ch())x=x*10+(c&15);x*=f;

}



int x[MAX_N], y[MAX_N];



int main() {

    int n, q;

    read(n); read(q);

    ll ans = (ll)(n-2)*(n-2);

    int xx = n;

    int yy = n;

    while(q--){

        int t, z;

        read(t), read(z);

        if(t == 1){

            if(z < xx){

                ans -= yy - 2;

                srep(i,z+1,xx) x[i] = yy;

                xx = z;

            }else{

                ans -= x[z] - 2;

            }

        }else{

            if(z < yy){

                ans -= xx - 2;

                srep(i,z+1,yy) y[i] = xx;

                yy = z;

            }else{

                ans -= y[z] - 2;

            }

        }

    }

    printf("%lld\n", ans);

    return 0;

}




