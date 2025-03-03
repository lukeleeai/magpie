#include "stdc++.h"

const int MAX=5100;

const int modn=1e9+7;

typedef long long ll ;

#define endl '\n'

#define cwk     freopen("D:\\workplace\\CLion\\in.in","r",stdin),freopen("D:\\workplace\\CLion\\out.out","w",stdout)

using namespace std;

ll n,k,now_maxn,all_maxn;

ll p[MAX],c[MAX];

vector<ll>v[MAX];

int main() {

    cin>>n>>k;

    for(int i=1;i<=n;i++){

        cin>>p[i];

    }

    for(int i=1;i<=n;i++){

        cin>>c[i];

    }

    all_maxn=-INT_MAX;

    for(int i=1;i<=n;i++) {

        now_maxn=-INT_MAX;

        ll ans = 0;

        for (int j = p[i]; j != i; j = p[j]) {

            ans += c[j];

            v[i].push_back(ans);

            now_maxn=max(now_maxn,ans);

        }

        ans+=c[i];

        v[i].push_back(ans);

        now_maxn=max(now_maxn,ans);

        /*for(int j=0;j<v[i].size();j++)

            cout<<v[i][j]<<" ";

        cout<<"\n";*/

        ll all=v[i][v[i].size()-1];

        ll now=-INT_MAX;

        if(all<=0){

            now=now_maxn;

        }else{

            for(int j=0;j<k%v[i].size();j++){

                now=max(now,v[i][j]);

            }

            if(k>=v[i].size()) {

                if (all - now_maxn + now < 0) {

                    now = now_maxn + (k / v[i].size() - 1) * all;

                } else {

                    now += k / v[i].size() * all;

                }

            }

        }

        all_maxn=max(all_maxn,now);

    }

    cout<<all_maxn;

    return 0;

}
