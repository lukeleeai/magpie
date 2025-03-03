#include<iostream>

#include<iomanip>

#include<cassert>

#include<stdexcept>

#include<utility>

#include<functional>

#include<numeric>

#include<cmath>

#include<algorithm>

#include<cstdio>

#include<cstdlib>

#include<array>

#include<stack>

#include<queue>

#include<deque>

#include<vector>

#include<complex>

#include<set>

#include<map>

#include<unordered_map>

#include<unordered_set>

#include<string>

#include<bitset>

#include<memory>

using namespace std;

using ll=long long;



using Field = vector<string>;

const int INF = 1e9;

int dx[]={0,1,0,-1};

int dy[]={1,0,-1,0};

void solve(int h,int w){

    Field f(h);

    for(int i=0;i<h;i++) cin>>f[i];



    auto isRange=[&](int i,int j){

        return 0<=i && i<h && 0<=j && j<w;

    };

    auto isMovable=[&](int i,int j){

        return isRange(i,j) && f[i][j]!='x';

    };

    int si=-1,sj=-1;

    int ndirt = 0;

    vector<vector<int>> dirt(h,vector<int>(w,-1));

    for(int i=0;i<h;i++){

        for(int j=0;j<w;j++){

            if(f[i][j]=='o') si=i,sj=j;

            else if(f[i][j]=='*') dirt[i][j] = ndirt++;

        }

    }

    assert(si!=-1 && sj!=-1);

    vector<vector<vector<int>>> dp(1<<ndirt,vector<vector<int>>(h,vector<int>(w,INF)));

    struct X{

        int mask;

        int i,j;

    };

    queue<X> que;

    auto push=[&](int mask,int i,int j,int score){

        dp[mask][i][j]=score;

        que.push({mask,i,j});

    };

    push(0,si,sj,0);



    while(!que.empty()){

        auto tmp = que.front(); que.pop();

        int i=tmp.i,j = tmp.j,mask = tmp.mask;

        if(mask==(1<<ndirt)-1){

            cout<<dp[mask][i][j]<<endl;

            return;

        }

        for(int k=0;k<4;k++){

            int toi = i+dx[k],toj=j+dy[k];

            if(isMovable(toi,toj)){

                int tomask = mask;

                if(dirt[toi][toj]!=-1){

                    tomask |= (1<<dirt[toi][toj]);

                }

                if(dp[mask][i][j]+1<dp[tomask][toi][toj]){

                    push(tomask,toi,toj,dp[mask][i][j]+1);

                }

            }

        }

    }

    

    cout<<-1<<endl;

    return;

}

int main(){

    int w,h;

    while(cin>>w>>h,!(w==0 && h==0)){

        solve(h,w);

    }

    

    return 0;

}


