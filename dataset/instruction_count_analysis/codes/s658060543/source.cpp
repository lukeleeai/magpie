#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

#define rep(i, n) for (ll i = 0; i < n; i++)

#define FOR(i, a, b) for (ll i = a; i < b; i++)

#define len(v) ll(v.size())



//vector書き出し

template <class T>

void cout_vec(const vector<T> &vec1){

  rep(i,len(vec1)){

    cout<<vec1[i]<<' ';

  }

  cout<<'\n';

}



typedef pair<int,int> P;

const ll mod=1e9+7;



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    int h,w;

    cin>>h>>w;

    vector<vector<char> > a(1010,vector<char>(1010));

    vector<int> dx={1,-1,0,0},dy={0,0,1,-1};

    vector<vector<int> > d(1010,vector<int>(1010,-1));

    queue<P> que;

    FOR(i,1,h+1){

      FOR(j,1,w+1){

        cin>>a[i][j];

        if(a[i][j]=='#'){

          que.push({i,j});

          d[i][j]=0;

        }

      }

    }

    while(!que.empty()){

      P p=que.front();

      que.pop();

      rep(i,4){

        int nx=p.first+dx[i],ny=p.second+dy[i];

        if(1<=nx && nx<=h && 1<=ny && ny<=w && d[nx][ny]==-1){

          d[nx][ny]=d[p.first][p.second]+1;

          que.push({nx,ny});

        }

      }

    }

    int ans=0;

    FOR(i,1,h+1){

      FOR(j,1,w+1){

        if(ans<d[i][j]) ans=d[i][j];

      }

    }

    cout<<ans<<endl;

}