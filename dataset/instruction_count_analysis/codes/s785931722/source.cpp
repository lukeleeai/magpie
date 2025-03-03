#include<algorithm>//sort,二分探索,など

#include<bitset>//固定長bit集合

#include<cmath>//pow,logなど

#include<complex>//複素数

#include<deque>//両端アクセスのキュー

#include<functional>//sortのgreater

#include<iomanip>//setprecision(浮動小数点の出力の誤差)

#include<iostream>//入出力

#include<map>//map(辞書)

#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)

#include<queue>//キュー

#include<set>//集合

#include<stack>//スタック

#include<string>//文字列

#include<utility>//pair

#include<list>

#include<vector>//可変長配列

using namespace std;

#define rep(i,a) for(int i=0;i<a;i++)

#define mp make_pair

#define pb push_back

#define ll __int64

#define __int64 long long

#define P pair<int,int>

#define PP pair<P,int>

#define F first

#define S second

int dx[8] = { 1,0,-1,0,1,-1,-1,1 };

int dy[8] = { 0,1,0,-1,1,1,-1,-1 };





int n;

map<string, int>ta;



int main() {

    cin >> n;

    rep(i, n) {

        string s;

        cin >> s;

        ta[s]++;

    }



    int cnt = -1;

    for (auto it = ta.begin(); it != ta.end(); it++) {

        cnt = max(cnt, (*it).second);

    }

    for (auto it = ta.begin(); it != ta.end(); it++) {



        if(cnt==(*it).second)

        cout << (*it).first << endl;



    }



    return 0;

}
