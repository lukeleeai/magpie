#include<iostream>

#include<climits>

#include<string>

#include<stack>

#include<vector>

#include<map>

#include<queue>

#include<algorithm>

#include<cmath>

using namespace std;

#define fr first

#define sc second

#define INF INT_MAX

typedef pair<int,int> Pi;

typedef pair< Pi,pair<Pi,int> > P;

struct Edge{

  int to,denger;

  Edge(){}

  Edge(int to,int denger):to(to),denger(denger){};

};

int n,m;

int m_cost[151][11][(151+1)/2+1];

vector<vector<Edge> > info;

int Dijkstra();

int main(){

  while(cin >> n >> m && n||m){

    info.resize(n);

    for(int i=0,k;i<n;i++){

      cin >> k;

      for(int j=0,t,d;j<k;j++){

        cin >> t >> d;

        info[i].push_back(Edge(t,d));

      }

    }

    cout << Dijkstra() << endl;

    info.clear();

  }

}

int Dijkstra(){

  for(int i=0;i<151;i++){

    for(int j=0;j<11;j++){

      for(int k=0;k<(151+1)/2+1;k++){

        m_cost[i][j][k] = INF;

      }

    }

  }

  priority_queue<P,vector<P>,greater<P> > que;

  for(int i=0,l=info[0].size();i<l;i++){

    que.push(P(Pi(0,m),make_pair(Pi(0,info[0][i].to),info[0][i].denger)));

    m_cost[0][i][m] = 0;

  }

  if(m != 0){

    for(int i=0,l=info[1].size();i<l;i++){

      que.push(P(Pi(0,m-1),make_pair(Pi(1,info[1][i].to),info[1][i].denger)));

      m_cost[1][i][m-1] = 0;

    }

  }

  while(!que.empty()){

    P p = que.top();

    int den = p.fr.fr,limit = p.fr.sc,slip=p.sc.sc;

    Pi pt = Pi(p.sc.fr.fr,p.sc.fr.sc);

    que.pop();

    if(pt.fr + 1 >= n) return den;

    for(int j=1;j<3;j++){

      if(j==2 && limit == 0) break;

      if(j==2 && pt.fr + 1 == n) break;

      if(j==2 && pt.fr + 2 == n) return den;

      if(j==1 && pt.fr + 1 == n) return den;

      for(int i=0,l=info[pt.fr+j].size();i<l;i++){

        int next_now = info[pt.fr+j][i].to;

        int next_den = info[pt.fr+j][i].denger;

        int hmhm = den + (slip + next_den) * abs(next_now - pt.sc);

        if(hmhm < m_cost[pt.fr+j][i][limit-(j-1)]){

          m_cost[pt.fr+j][i][limit-(j-1)] = hmhm;

          que.push(P(Pi(hmhm,limit-(j-1)),make_pair(Pi(pt.fr+j,next_now),next_den)));

        }

      }

    }

  }

}