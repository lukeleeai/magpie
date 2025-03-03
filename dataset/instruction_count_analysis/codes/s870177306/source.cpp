#include"stdc++.h"



#define ll long long

#define fornum(A,B,C) for(A=B;A<C;++A)

#define pii pair<int,int>

#define pll pair<ll,ll>



using namespace std;



/////////////////////////////////////////////////////



ll N;

string S[202020];

ll i, j, k;

ll ans = 1;

int main(){

    scanf("%lld", &N);

    fornum(i,0,N){

        cin >> S[i];

    }

    sort(S, S + N);

    string s = S[0];

    j = 0;

    fornum(i,1,N+1){

        if(s!=S[i]){

            ans = max(ans,i - j);

            j = i;

            s = S[i];

        }

    }

    s = S[0];

    j = 0;

    fornum(i,1,N+1){

        if(s!=S[i]){

            if(ans==i-j){

                

                cout << s << endl;

            }

            j = i;

            s = S[i];

        }

    }



    return 0;

}