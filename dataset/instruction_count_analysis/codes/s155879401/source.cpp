#include"stdc++.h"

using namespace std;

 

#define pb push_back

#define ll long long

#define maxn 500005

#define fr(i,j,k) for(int i=j;i<k;i++)

#define f(n) fr(i,0,n)

#define f1(n) fr(i,1,n+1)

#define ms(i) memset(i,0,sizeof(i));

#define ms1(i) memset(i,-1,sizeof(i));

#define F first

#define S second



int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int n;

    cin >> n;

    ll num1 = 0, num2 = 0;

    f(n){

        ll a, b;

        cin >> a >> b;

        ll l = 0, r = 1e18/max(a,b) + 5;

        while(l < r - 1){

            ll m = (l + r) >> 1;

            ll aa = a * m, bb = b * m;

            if(aa >= num1 && bb >= num2){

                r = m;

            }

            else{

                l = m;

            }

        }

        num1 = r * a;

        num2 = r * b;

    }

    cout << num1 + num2 << '\n';

}