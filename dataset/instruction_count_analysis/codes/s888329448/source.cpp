#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cassert>

#include<cmath>

#include<vector>

#include<map>

#include<set>

#include<string>

#include<queue>

#include<stack>

using namespace std;

#define MOD 1000000007

#define MOD2 998244353

#define INF ((1<<30)-1)

#define LINF (1LL<<60)

#define EPS (1e-10)

typedef long long Int;

typedef pair<Int, Int> P;



Int n, c;

Int dp[220000];

Int h[220000];



Int calc(P f, Int x){

    return f.first * x + f.second;

}



struct CHTrick{

    vector<Int> to;

    vector<P> f;



    CHTrick(){}



    void add_line(Int a, Int b){

        P new_f = P(a, b);

        if(f.empty()){

            f.push_back(new_f);

            return;

        }

        if(calc(new_f, INF) >= calc(f.back(), INF))return;

        if(calc(new_f, -INF) <= calc(f.front(), -INF)){

            f.clear();

            to.clear();

            f.push_back(new_f);

            return;

        }



        while(!to.empty()){

            int lastl = to.back() + 1;

            if(calc(new_f, lastl) <= calc(f.back(), lastl)){

                f.pop_back();

                to.pop_back();

            }

            else break;                

        }



        int bottom;

        if(to.empty())bottom = -INF;

        else bottom = to.back() + 1; //f.back();

        int top = INF;//new_f



        while(top - bottom > 1){

            int mid = (top + bottom) / 2;

            if(calc(new_f, mid) <= calc(f.back(), mid))top = mid;

            else bottom = mid;

        }

        to.push_back(bottom);

        f.push_back(new_f);

    }

    

    Int get_min(int x){

        Int ind = lower_bound(to.begin(), to.end(), x) - to.begin();

        return calc(f[ind], x);

    }

};



int main(){

    cin >> n >> c;

    for(int i = 0;i < n;i++)cin >> h[i];

    CHTrick ch;

    

    dp[0] = 0;

    ch.add_line(-2*h[0], dp[0] + h[0] * h[0]);

    for(int i = 1;i < n;i++){

        dp[i] = ch.get_min(h[i]) + h[i] * h[i] + c;

        ch.add_line(-2*h[i], dp[i] + h[i] * h[i]);

    }

    cout << dp[n-1] << endl;    

    return 0;

}