#include <iostream>

#include <vector>

#include <queue>

#include <cstdio>

#include <map>

#define INF (1 << 24)

#define MASK (1 << 10)-1

#define fr first

#define sc second

using namespace std;



typedef pair<double,double> S;

typedef pair<S,int> P;

struct edge{ 

  double to,time; edge(){}

  edge(double to,double time):to(to),time(time){}

};



double n,m,p,a,b,timed[101][1500];

vector <double> ti(11);

vector< vector<edge> > info(101);



void init(){

  for(int i=0;i<101;i++){

    for(int j=0;j<1500;j++) timed[i][j] = INF;

  }

  info.resize(0); info.resize(101);

  ti.resize(0); ti.resize(11);

}



void add_info(){

  double x,y,z;

  cin >> x >> y >> z;

  info[(int)x].push_back(edge(y,z));

  info[(int)y].push_back(edge(x,z));

}



double Dijkstra(){

  priority_queue<P,vector<P>,greater<P> > que;

  que.push(P(S(0,a),MASK));

  timed[(int)a][MASK] = 0;

  while(!que.empty()){

    P p = que.top(); que.pop();

    double now = p.fr.sc,t = p.fr.fr;

    int bit = p.sc;

    if(now == b) return t;

    for(int i=0;i<info[(int)now].size();i++){

      edge e = info[(int)now][i];

      for(int j=0;j<n;j++){

	if(bit >> j & 1){

	  if(e.time/ti[j] + t < timed[(int)e.to][bit & ~(1<<j)]){

	    que.push(P(S(e.time/ti[j]+t,e.to),bit & ~(1<<j)));

	    timed[(int)e.to][bit & ~(1<<j)] = e.time / ti[j] + t;

	  }

	}

      }

    }

  }

  return -1;

}



int main(){

  while(cin>>n>>m>>p>>a>>b,n||m||p||a||b){

    init();

    for(int i=0;i<n;i++) cin >> ti[i];

    for(int i=0;i<p;i++) add_info();

    double d = Dijkstra();

    if(d != -1) printf("%.3f\n",d);

    else cout << "Impossible" << endl;

  }

}