#include "stdc++.h"

#define rep(i,n) for (int i=0; i< int (n); i++)

using namespace std;

typedef long long ll;



int main(){



int n, m;

cin >> n >> m;

int h[1000000]={0};

rep(i,n) cin >> h[i+1];

int good[1000000]={0};

for(int i=1; i<=m; i++) {

    int a, b;

    cin >> a >> b;

    if(h[a]<=h[b]) good[a]++;

    if(h[b]<=h[a]) good[b]++;

}

int ans=0;

for(int i=1; i<=n; i++){

    if(good[i]==0) ans++;

}



cout << ans << endl;



}