#include<iostream>

#include<vector>

#include<algorithm>

#include<cmath>

#include<string>



using namespace std;



#define rep(i, n) for(int i = 0; i < n; i++)

#define repn(i, n) for(int i = 1; i <= n; i++)

#define repr(i, n) for(int i = (n-1); i >= 0; i--)

#define all(x) (x).begin(), (x).end()

#define lint long long



const int MAX_V = 100005;

vector<int> to[MAX_V];

bool seen[MAX_V];





int dfs(int s){

    seen[s] = true;

    if(to[s].empty()) return 1;

    else return dfs(to[s][0]) + 1;

}



int main(){

    int n, k; cin>>n>> k;

    int R, S, P; cin>>R>>S>>P;

    string t; cin >> t;



    for(int i = 0; i < n-k; i++){

        if(t[i] == t[i+k]){

            to[i].push_back(i+k);

        }

    }



    long ans = 0;

    rep(i, n){

        if(!seen[i]){

            int res = (dfs(i) + 1) / 2;

            int po;

            if(t[i] == 'r') po = P;

            else if(t[i] == 's') po = R;

            else po = S;

            ans += po * res;

        }

    }



    cout << ans << endl;

}