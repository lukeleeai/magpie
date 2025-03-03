#include "stdc++.h"

#define mn(a, b) (a < b ? a : b)

#define mx(a, b) (a > b ? a : b)

#define f first

#define s second

#define all(v) (v).begin(), (v).end()

#define base 331

#define db(a) cout<<(a)<<"\n";



using namespace std;



typedef long long ll;

typedef unsigned long long ull;



const ll MOD = 1e9 + 7;



struct mat{

    ll matriz[52][52];

    mat(){

        for(int i = 1; i <= 50; i++){

            for(int j = 1; j <= 50; j++)

                matriz[i][j] = 0;

        }

    }

    friend mat operator *(const mat &a, const mat &b){

        mat c;

        for(int i = 1; i <= 50; i++)

            fill(c.matriz[i] + 1, c.matriz[i] + 51, 0);

        for(int i = 1; i <= 50; i++){

            for(int j = 1; j <= 50; j++){

                for(int k = 1; k <= 50; k++)

                    c.matriz[i][j] = (c.matriz[i][j] + (a.matriz[i][k] * b.matriz[k][j] % MOD)) % MOD;

            }

        }

        return c;

    }

};



mat ident(){

    mat c;

    for(int i = 1; i <= 50; i++)

        c.matriz[i][i] = 1;

    return c;

}



mat qp(ll e, mat b){

    mat a = b, aux = ident();

    if(e == 1)

        return a;

    while(e > 1){

        if(e % 2)

            aux = aux * a;

        a = a * a;

        e /= 2;

    }

    return a * aux;

}





int main(){



    //freopen(".in","r",stdin);

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int n;

    cin>>n;

    ll k;

    cin>>k;

    mat xz;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            cin>>xz.matriz[i][j];

        }

    }

    mat x = qp(k, xz);

    ll sum = 0;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            sum = (sum + x.matriz[i][j]) % MOD;

        }

    }

    cout<<sum;

    return 0;

}
