#include  "stdc++.h"

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

using namespace std;



const int vmax=100010;



vector<int> graph[vmax],ord,low,scc,par;

stack<int>s;



void dfs(int v,int p,int &k){

	ord[v]=k++;

	low[v]=ord[v];

	par[v]=p;

	s.push(v); // S

	for(auto &i:graph[v]){

		if(ord[i]==-1){

			dfs(i,v,k);

			low[v]=min(low[v],low[i]);

		//}else if(i!=p){    // B,A

		}else if(scc[i]==-1){ // S

			low[v]=min(low[v],ord[i]);

		}

	}

	if(ord[v]==low[v]){

		while(1){

			int u=s.top();s.pop();

			scc[u]=v;

			if(u==v) break;

		}

	}  //S

}



void lowlink(int n){

	int k=0;

	ord.assign(n,-1),low.resize(n);

	scc.assign(n,-1),par.resize(n);

	rep(i,n) if(ord[i]==-1) dfs(i,-1,k);

}



int main(void){

	int v,e;

	cin >> v >> e;

	rep(loop,e){

		int a,b;

		cin >> a >> b;

		graph[a].push_back(b);

		// graph[b].push_back(a); // B,A



	}

	lowlink(v);



/*	rep(i,v){

		cout << "ord[" << i << "]=" << ord[i]  << endl;

		cout << "low[" << i << "]=" << low[i]  << endl;

	}

*/



// Bridge

/*	vector<pair<int,int>> bridge;

	rep(i,v){

		int j=par[i];

		if(j==-1)

			continue;

		if(ord[i] < low[j] || ord[j] < low[i] ){

			auto in=make_pair(i,j);

			if(in.second<=in.first) swap(in.first,in.second);

			bridge.pb(in);

		}

	}

	sort(bridge.begin(),bridge.end());

	for(auto &i:bridge)

		cout << i.first << " " << i.second << endl;

*/



// Articulation Points

/*	vi articulation_point;

	rep(i,v){

		if(i){

			bool ok=false;

			for(auto &j:graph[i]){

				if(i==par[j]&&ord[i]<=low[j])

					ok=true;

			}

			if(ok) articulation_point.push_back(i);

		}else{

			int d=0;

			rep(j,v) if(par[j]==0) d++;

			if(d>=2) articulation_point.push_back(i);

		}

	}

	sort(articulation_point.begin(),articulation_point.end());

	for(auto &i:articulation_point)

		cout << i << endl;

*/

// Strongly Connected Components



	int q;

	cin >> q;

	rep(loop,q){

		int a,b;

		cin >> a >> b;

		cout << (scc[a]==scc[b]) << endl;

	}



	return 0;

}