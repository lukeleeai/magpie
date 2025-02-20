#include<iostream>

#include<queue>

#include<map>

#include<cstdio>

#include<cmath>

#define INF 500000000

using namespace std;



typedef pair<int,int> P;



int n,m,k;

int l[100100],a[100100],b[100100];

vector<P> g[5000];

int d[5000],w[5000];

int s[5000];



int main(){

  cin >> n >> m >> k;

  for(int i=0;i<m;i++){

    cin >> a[i] >> b[i] >> l[i];

    a[i]--; b[i]--;

    g[a[i]].push_back(P(l[i],b[i]));

    g[b[i]].push_back(P(l[i],a[i]));

  }

 

  for(int i=0;i<k;i++){cin >> s[i]; s[i]--;}



  for(int i=0;i<n;i++)d[i] = INF;

  priority_queue<P,vector<P>,greater<P> > q;

  for(int i=0;i<k;i++){

    d[s[i]] = 0;

    q.push(P(0,s[i]));

  }



  while(q.size()){

    P p = q.top(); q.pop();

    int cost = p.first, pos = p.second;

    

    for(int i=0;i<(int)g[pos].size();i++){

      int dis = cost + g[pos][i].first;

      int next = g[pos][i].second;

      

      if(dis<d[next]){

	d[next] = dis;

	q.push(P(dis,next));

      }

    }

  }



  double ans = 0.0;

  for(int i=0;i<m;i++){

    if(fabs(d[a[i]] - d[b[i]]) >= l[i]){

      ans = max(ans,(double)max(d[a[i]],d[b[i]]));

    }else{

      ans = max(ans,(double)(l[i]+d[a[i]]+d[b[i]])/2);

    }

  }

  cout << (int)(ans+1e-9+0.5) << endl;

}

  