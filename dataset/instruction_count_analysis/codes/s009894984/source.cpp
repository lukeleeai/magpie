#include"stdc++.h"



#define ll long long

#define met(a, x) memset(a,x,sizeof(a))

#define inf 0x3f3f3f3f

#define ull unsigned long long

#define mp make_pair



using namespace std;

const int mod = 998244353;

const int N = 3e5 + 10;

const int M = 1e6 + 10;

ll a[100];



bool cmp(ll x, ll y) {

    return x > y;

}



ll C[300][300];



void init() {

    met(C, 0);

    C[0][0] = 1;

    for (int i = 1; i <= 50; i++) {

        C[i][0] = 1;

        for (int j = 1; j <= i; j++)

            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];

    }

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    init();

    int n, l, r;

    cin >> n >> l >> r;

        for (int i = 1; i <= n; i++)

            cin >> a[i];

        sort(a + 1, a + 1 + n, cmp);

        double ans=0;

        for(int i=1;i<=l;i++){

            ans+=a[i]*1.0;

        }

        ans/=l;

        int num=0,cnt=0;

        for(int i=1;i<=n;i++){

            if(a[i]==a[l]){

                num++;

                if(i<=l){

                    cnt++;

                }

            }

        }

        ll sum=0;

        if(cnt==l){

            for(int i=l;i<=r;i++){

                sum+=C[num][i];

            }

        }else{

            sum+=C[num][cnt];

        }

        cout<<fixed<<setprecision(10)<<ans<<endl<<sum<<endl;

    

    return 0;

}