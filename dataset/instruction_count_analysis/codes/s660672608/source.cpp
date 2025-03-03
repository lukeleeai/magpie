#include "stdc++.h"



#define ll long long

#define ull unsigned long long

#define met(a, x) memset(a,x,sizeof(a));

#define inf 0x3f3f3f3f

#define mp make_pair;



using namespace std;

const int mod = 1e9 + 7;

const int N = 1e6 + 10;

const int M = 1e5 + 10;

int a[M];

map<int,bool> q;

int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int n, k;

    cin >> n >> k;

    int maxn = 0;

    for (int i = 1; i <= n; i++) {

        cin >> a[i];

        q[a[i]]=1;

        maxn = max(maxn, a[i]);

    }

    if (maxn < k) {

        cout << "IMPOSSIBLE" << endl;

    } else {

        if(q[k]==1){

            cout<<"POSSIBLE"<<endl;

            return 0;

        }

        for (int i = 1; i <= n; i++) {

            if(q[a[i]]==1&&q[k-a[i]]==1){

                cout<<"POSSIBLE"<<endl;

                return 0;

            }

        }

        cout<<"IMPOSSIBLE"<<endl;

    }

    return 0;

}


