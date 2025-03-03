#include "stdc++.h"

using namespace std;

#define REP(i,n) for (int i=0;i<(n);i++)

#define MOD 1000000007

#define INF MOD

typedef long long ll;

typedef pair<int,int> P;

#define YES(s) s?cout << "YES" << endl:cout << "NO" << endl

#define Yes(s) s?cout << "Yes" << endl:cout << "No" << endl

#define Taka(s) s?cout << "Takahashi" << endl:cout << "Aoki" << endl

//#define int long long 



/*Prim部分*/



vector<pair<int,int>> G[214514];//firstがコスト、secondが行き先



int prim(void){

    priority_queue<P,vector<P>,greater<P>> que;

    bool used[114514]={};

    int res=0;

    que.push({0,0});

    while(!que.empty()){

        P e = que.top();

        que.pop();

        if(used[e.second]==false){

            used[e.second]=true;

            REP(i,G[e.second].size()){

                que.push({G[e.second][i].first,G[e.second][i].second});

            }

            res += e.first;

        }

    }

    return res;

}



/*Prim部分　おわり*/



/*Build?部分*/

struct machi{

  int x,y,num;  

};



bool compx(machi F,machi G){

    if(F.x!=G.x){

        return F.x<G.x;

    }else{

        return F.y<G.y;

    }

}

bool compy(machi F,machi G){

    if(F.y!=G.y){

        return F.y<G.y;

    }else{

        return F.x<G.x;

    }

}





machi city[114514];



/*Build?部分　おわり*/





signed main(){

    int N,x,y;

    cin >> N;

    REP(i,N){

        cin >> x >> y;

        city[i].x = x;

        city[i].y = y;

        city[i].num = i;

    }

    sort(city,city+N,compx);

    REP(i,N-1){

        G[city[i].num].push_back(make_pair(min(abs(city[i].x-city[i+1].x),abs(city[i].y-city[i+1].y)),city[i+1].num));

        G[city[i+1].num].push_back(make_pair(min(abs(city[i].x-city[i+1].x),abs(city[i].y-city[i+1].y)),city[i].num));

        

    }

    sort(city,city+N,compy);

    REP(i,N-1){

        G[city[i].num].push_back(make_pair(min(abs(city[i].x-city[i+1].x),abs(city[i].y-city[i+1].y)),city[i+1].num));

        G[city[i+1].num].push_back(make_pair(min(abs(city[i].x-city[i+1].x),abs(city[i].y-city[i+1].y)),city[i].num));

    }

    int Ans= prim();

    

    cout << Ans << endl;

	return 0;

}
