#include "stdc++.h"

using namespace std;

using ll = long long;

#define rep(i,n) for(int i = 0; i < (n); i++)

#define all(v) v.begin(), v.end()

//#define MOD 1000000007

const int INF = 1LL<<30;



int px[90001],py[90001];

int d[90001];



int main() {

    int h,w,D;

    cin>>h>>w>>D;



    rep(i,h){

        rep(j,w){

            int a;

            cin>>a;

            px[a]=i;

            py[a]=j;

        }

    }



    for(int i=D+1;i<=h*w;i++){

        d[i]=d[i-D]+abs(px[i]-px[i-D])+abs(py[i]-py[i-D]);

    }



    int q;

    cin>>q;

    while(q--){

        int l,r;

        cin>>l>>r;

        cout<<d[r]-d[l]<<endl;

    }

}