#include "stdc++.h"

#define foi for(int i=0; i<n; i++)

#define foj for(int j=0; j<n; j++)

#define ll long long int

#define vi vector<int>

#define maxn 200005

#define mod 1000000007

using namespace std;



int cnt[30];

char c;

int main() {

    int n;

    cin >> n;

    foi {

        cin >> c;

        cnt[c-'a']++;

    }

    ll ans=1;

    for (int i=0; i<30; i++) {

        ans=ans*(cnt[i]+1)%mod;

    }

    ans--;

    if (ans<0) ans+=mod;

    cout << ans << '\n';

    return 0;

}
