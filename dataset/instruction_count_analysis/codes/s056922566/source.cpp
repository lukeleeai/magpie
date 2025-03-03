// D - Friend Suggestions

#include "stdc++.h"

using namespace std;

using vi = vector<int>;

using vvi = vector<vi>;

#define rp(i,s,e) for(int i=(s);i<(e);++i)



#define MAX 100000+1

int N,M,K;

vvi F(MAX),B(MAX);//friend,block

vi gid(MAX);



int bfs(int root){

	queue<int> q;

	q.push(root);

	while(!q.empty()){

		int p = q.front(); q.pop();

		if(gid[p]) continue;

		gid[p] = root;

		for(auto c:F[p]) q.push(c);

	}

	return root;

}



int main(){

	cin>>N>>M>>K;



	rp(i,0,M){

		int s,t; cin>>s>>t;

		F[s].push_back(t);

		F[t].push_back(s);

	}



	vi cnt(N+1);

	rp(i,1,N+1) cnt[gid[bfs(i)]]++;



	rp(i,0,K){

		int s,t; cin>>s>>t;

		if(gid[s] != gid[t]) continue;

		B[s].push_back(t);

		B[t].push_back(s);

	}



	int self = 1;

	rp(i,1,N+1) cout<< cnt[gid[i]]-F[i].size()-B[i].size()-self <<" ";



}