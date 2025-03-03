#include "stdc++.h"

const int MAX=5100;

typedef long long ll ;

using namespace std;

int n,k;

ll p[MAX],c[MAX];

vector<ll>v;

int main() {

    cin>>n>>k;

    for(int i=1;i<=n;i++){

        cin>>p[i];

    }

    for(int i=1;i<=n;i++){

        cin>>c[i];

    }

    ll all_max=-INT_MAX;

    for(int i=1;i<=n;i++){

        v=vector<ll>();

        ll now_max=-INT_MAX;

        ll ans=0;

        ll now=-INT_MAX;

        for(int j=p[i];j!=i;j=p[j]){

            ans+=c[j];

            v.push_back(ans);

            now_max=max(now_max,ans);

        }

        ans+=c[i];

        now_max=max(now_max,ans);

        v.push_back(ans);

        int cnt=v.size();

        ll all=v[cnt-1];

        if(k<=cnt){

            for(int j=0;j<k;j++){

                now=max(now,v[j]);

            }

        }else{

            if(all<=0)

                now=now_max;

            else {

                int count=k;

                for (int j = 0; j < k % cnt; j++) {

                    now = max(now, v[j]);

                }

                if (all - now_max + now < 0) {

                    now = now_max;

                    count-=cnt;

                }

                now += count / cnt * all;

            }

        }

        all_max=max(all_max,now);

    }

    cout<<all_max;

    return 0;

}
