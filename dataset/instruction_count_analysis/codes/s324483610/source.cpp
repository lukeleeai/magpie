#include "stdc++.h"

using namespace std;

#define fastIO ios::sync_with_stdio(0), cin.tie(0)

#define endl '\n'

#define ft first

#define sd second

#define pb push_back

#define pob pop_back()

#define pf push_front

#define pof pop_front()

typedef long long ll;

typedef pair<int,int> pii;

typedef pair<char,char> pcc;

typedef pair<long long,long long> pll;



int main() {

    fastIO;

    int n, rta = 0;

    cin >> n;

    int perm[n];

    for(int i = 0; i < n; i++){

        cin >> perm[i];

    }

    for(int i = 1; i < n-1; i++){

        vector<int> x;

        for(int j = i-1; j <= i+1; j++){

            x.pb(perm[j]);

        }

        sort(x.begin(), x.end());

        if(x[1] == perm[i]) rta++;

    }

    cout << rta << endl;

    return 0;

}


