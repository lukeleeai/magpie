#include"stdc++.h"



#define ll long long

#define fornum(A,B,C) for(A=B;A<C;++A)

#define pii pair<int,int>

#define pll pair<ll,ll>



using namespace std;



/////////////////////////////////////////////////////



ll N;

char S[202020][14];

pll s[202020];

ll i, j, k;

ll ans = 1;

int main(){

    scanf("%lld", &N);

    fornum(i,0,N){

        scanf("%s", S[i]);

        k = 0;

        fornum(j,0,10){

            k *= 30;

            if(S[i][j])

                k += S[i][j] - 'a' + 1;

        }

        s[i] = {k, i};

    }

    sort(s, s + N);

    j = 0;

    fornum(i,1,N+1){

        if(s[j].first!=s[i].first){

            ans = max(ans, i - j);

            j = i;

        }

    }



    j = 0;

    fornum(i,1,N+1){

        if(s[j].first!=s[i].first){

            if(i-j==ans){

                printf("%s\n", S[s[j].second]);

            }

            j = i;

        }

    }



    return 0;

}