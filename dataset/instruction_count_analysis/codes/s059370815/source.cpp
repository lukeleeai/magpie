//https://atcoder.jp/contests/abc139/submissions/7282608



#include "stdc++.h"

#pragma GCC optimize("O3")

#define REP(i,n) for(int i=0;i<n;i++)

#define REPP(i,n) for(int i=1;i<=n;i++)

const double PI = acos(-1);

const double EPS = 1e-15;

long long INF=(long long)1E17;

#define i_7 (long long)(1E9+7)

long mod(long a){

    long long c=a%i_7;

    if(c>=0)return c;

    return c+i_7;

}

using namespace std;

bool prime_(int n){

    if(n==1){

        return false;

    }else if(n==2){

        return true;

    }else{

        for(int i=2;i<=sqrt(n);i++){

            if(n%i==0){

                return false;

            }

        }

        return true;

    }

}



long long gcd_(long long a, long long b){

    if(a<b){

        swap(a,b);

    }

    if(a%b==0){

        return b;

    }else{

        return gcd_(b,a%b);

    }

}



long long lcm_(long long x, long long y){

    return (x/gcd_(x,y))*y;

}



class UnionFind {

public:

    //各頂点の親の番号を格納する。その頂点自身が親だった場合は-(その集合のサイズ)を入れる。

    vector<int> Parent;



    //クラスを作るときは、Parentの値を全て-1にする。

    //以下のようにすると全てバラバラの頂点として解釈できる。

    UnionFind(int N) {

        Parent = vector<int>(N, -1);

    }



    //Aがどのグループに属しているか調べる

    int root(int A) {

        if (Parent[A] < 0) return A;

        return Parent[A] = root(Parent[A]);

    }



    //自分のいるグループの頂点数を調べる

    int size(int A) {

        return -Parent[root(A)];//先祖をrootで取っておきたい。

    }



    //AとBをくっ付ける

    bool connect(int A, int B) {

        //AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける

        A = root(A);

        B = root(B);

        if (A == B) {

            //すでにくっついてるからくっ付けない

            return false;

        }



        //大きい方(A)に小さいほう(B)をくっ付けたい

        //大小が逆だったらAとBをひっくり返す。

        if (size(A) < size(B)) swap(A, B);



        //Aのサイズを更新する

        Parent[A] += Parent[B];

        //Bの親をAに変更する

        Parent[B] = A;



        return true;

    }

};





int main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    int n;

    cin>>n;

    int a[n][n-1];

    REP(i,n){

        REP(j,n-1){

            cin>>a[i][j];

            a[i][j]--;

        }

    }

    int now[n]={};

    //bool used[n][n-1] = {};

    register int day = 0;

    register bool flag;

    register bool upgrade_;

    register int op;

    while(true){

        upgrade_ = false;

        flag = true;

        int visited[n] = {};

        REP(i,n){

            if(now[i]==n-1)continue;

            flag = false;

            if(visited[i])continue;

            op = a[i][now[i]];

            if(visited[op])continue;

            if(now[op]==n-1)continue;

            if(a[op][now[op]]==i){

                //used[i][now[i]] = true;

                now[i]++;

                visited[i] = true;

                //used[op][now[op]] = true;

                now[op]++;

                visited[op] = true;

                upgrade_ = true;

            }

        }

        if(flag)break;

        if(!upgrade_){

            day = -1;

            break;

        }else{

            day++;

        }

    }

    cout<<day<<endl;

    return 0;

}
