#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

#define rep(i, n) for (ll i = 0; i < n; i++)

#define FOR(i, a, b) for (ll i = a; i < b; i++)

#define is(a, b) a == b

#define len(v) ll(v.size())



class UnionFind {

public:

	vector<int> par;//親の番号

    vector<int> rank;//木の深さ

 

	UnionFind(int n){//全ての要素に対して自身が根となるように初期化, 木の深さは0になる

		rep(i,n){

            par.push_back(i);

            rank.push_back(0);

        }

	}

 

	int find(int x) {//木の根を求める

		if(par[x]==x){

            return x;

        }else{

            return par[x]=find(par[x]);

        }

	}

 

	void unite(int x,int y){//xとyの属する集合を併合

        x=find(x);

        y=find(y);

        if(x==y) return;

        if(rank[x]<rank[y]){//木の深さが小さい方を大きい方へ繋げる

            par[x]=y;

        }else{

            par[y]=x;

            if(rank[x]==rank[y]) rank[x]++;

        }

    }



    bool same(int x,int y){//xとyが同じ集合に属するか否か

        return find(x)==find(y);

    }

};

//x以下の要素への最小index, ソートしてから使ってね

template <class T> 

int former(const vector<T> &v, T x){

  return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;

}

//x以上の要素への最小index

template <class T> 

int latter(const vector<T> &v, T x){

  return lower_bound(v.begin(), v.end(), x) - v.begin();

}

//vector書き出し

template <class T>

void cout_vec(const vector<T> &vec1){

  rep(i,len(vec1)){

    cout<<vec1[i]<<' ';

  }

  cout<<'\n';

}

//nCk

template <class T>

T comb(T n,T k){

    T ans=1;

    FOR(i,n-k+1,n+1){

        ans*=i;

    }

    FOR(i,1,k+1){

        ans/=i;

    }

    return ans;

}

//a,bの最大公約数

template <class T>

T gcd(T a,T b) {

	if (b == 0) return a;

	else return gcd(b, a % b);

}

//素因数分解

template <class T>

map<T,T> prime_factor(T x){

    map<T,T> ans;

    for(T i=2;i*i<=x;i++){

        while(x%i==0){

            x/=i;

            ans[i]++;

        }

    }

    if (x!=1){

        ans[x]=1;

    }

    return ans;

}

//約数列挙

template <class T>

vector<T> divisor(T x){

    vector<T> res;

    for(T i=1;i*i<=x;i++){

        if(x%i==0){

            res.push_back(i);

            if(i!=x/i){

                res.push_back(x/i);

            }

        }

    }

    return res;

}

//素数判定

template <class T>

bool is_prime(T x){

    for(T i=2;i*i<=x;i++){

        if(x%i==0){

            return false;

        }

    }

    return x!=1;

}



const ll inf=1e9+7;



ll mult(ll n,ll m){//n^m%infを求める

    if(m==1){

        return n%inf;

    }else if(m%2==0){//オーバーフロー防止のためにn^(m/2)*n^(m/2)を考える

        ll t=mult(n,m/2);

        return (t*t)%inf;

    }else{//奇数の時はn^(m-1)*nを考える

        ll t=mult(n,m-1);

        return (t*n)%inf;

    }

}



typedef pair<int,int> P;

int h,w;

int cnt=0;//初めの状態の白の個数

int in=pow(10,6);

int ans=0;

vector<vector<char>> ma(1010,vector<char>(1010));

vector<vector<int>> d(1010,vector<int>(1010,in));

deque<P> que;

vector<int> dx={1,0,-1,0};

vector<int> dy={0,1,0,-1};



void bfs(){

    d[1][1]=0;

    que.push_back(P(1,1));

    while(!que.empty()){

        P p=que.front();

        que.pop_front();

        if(p.first==h && p.second==w){

            break;

        }

        rep(i,4){

            int nx=p.first+dx[i];

            int ny=p.second+dy[i];

            if(1<=nx && nx<=h && 1<=ny && ny<=w && ma[nx][ny]!='#' && d[nx][ny]==in){

                que.push_back(P(nx,ny));

                d[nx][ny]=d[p.first][p.second]+1;

            }

        }

    }

}



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    cin>>h>>w;

    FOR(i,1,h+1){

        FOR(j,1,w+1){

            cin>>ma[i][j];  

            if(ma[i][j]=='.'){

                cnt++;

            } 

        }

    }

    bfs();

    if(d[h][w]==in){

        cout<<-1<<endl;

    }else{

        cout<<cnt-(d[h][w]+1)<<endl;

    }

}