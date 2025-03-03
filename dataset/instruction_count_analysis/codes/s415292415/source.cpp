#include "stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0;i<int(n);++i)

#define rep1(i,n) for(int i=1;i<=int(n);++i)

#define all(a) a.begin(),a.end()

#define lb(s,x) lower_bound(all(s),x)-s.begin()

#define debug(x) cerr<<#x<<": "<<x<<endl

#define INF 1e9

typedef long long ll;



#define updmax(dp,x) dp=(dp.first == 0 ? x : max(dp,x))



using P = pair<int,int>;



int main(void){

    int n;

    while(cin>>n, n){

        vector<int> p(n);

        rep(i,n) cin>>p[i];

        map<int,P> cur; // cur[coin] = <get,pay>

        cur[0] = {0,0};

        rep(i,n){

            map<int,P> nxt;

            for(auto &itr : cur){

                int coin = itr.first;

                int k = itr.second.first;

                int pay = itr.second.second;

                updmax(nxt[coin], P(k,pay));

                pay -= p[i];

                int mod = p[i]%500;

                if(p[i]%1000 == 0){

                    if(coin>=500) updmax(nxt[coin-500], P(k+1,pay));

                }else if(p[i]%1000 == 500){

                    updmax(nxt[coin], P(k+1,pay));

                }else if(p[i]%1000 <= 500){

                    updmax(nxt[coin+500-mod],P(k+1, pay));

                }else if(mod <= coin){

                    updmax(nxt[coin-mod], P(k+1,pay));

                }else{

                    updmax(nxt[coin+500-mod], P(k,pay));

                }

            }

            cur = move(nxt);

        }

        P res = {0,0};

        for(auto itr : cur){

            res = max(res,itr.second);

        }

        cout<<res.first<<" "<<-res.second<<endl;

    }

    return 0;

}


