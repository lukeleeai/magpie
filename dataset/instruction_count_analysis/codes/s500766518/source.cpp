// #define _GLIBCXX_DEBUG

#include "stdc++.h"

using namespace std;

#define uint unsigned int

#define ull  unsigned long long

typedef string str;

typedef long long ll;

typedef double db;

typedef pair<int, int> pii;

typedef map<int, int> mii;

typedef vector<int> vi;

typedef vector<bool> vb;

#define pb push_back

#define fi first

#define se second

#define in insert

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int INF = 1e9 + 5;

const int N = 2e5 + 123;

int main(){

    speed;

    int n;

    cin >> n;

    int a = 0, b = 0, c = 0;

    for(int i = 0; i < n; ++i){

        int x;

        cin >> x;

        if(x % 4 == 0){

            a++;

        }

        else if(x % 2 == 0){

            b++;

        }

        else{

            c++;

        }

    }

    // cout << a << b << c;

    if(a > c - 1){

        cout << "Yes";

    }

    else{

        if(a == c - 1 && b == 0){

            cout << "Yes";

            return 0;

        }

        cout << "No";

    }

}