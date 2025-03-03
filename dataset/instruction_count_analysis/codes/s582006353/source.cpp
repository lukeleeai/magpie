#include<vector>

#include<algorithm>

#include<tuple>

#include<iostream>

using namespace std;



/*

enumerate non-bridge

*/



using pint=pair<int,int>;



struct EnumerateBridges{

	vector<vector<pint>>G;

	int N,M;



	vector<int>vis,ord,low;



	EnumerateBridges(int n):N(n),M(0),G(n),vis(n),ord(n),low(n){}



	void addEdge(int a,int b){

		G[a].emplace_back(b,M);

		G[b].emplace_back(a,M);

		M++;

	}



	void dfs(int v,int p,int &k,vector<int>&bridge){

		vis[v]=true;

		ord[v]=k;

		low[v]=ord[v];



		k++;

		

		for(auto &e:G[v]){

			int u,id;

			tie(u,id)=e;



			if(u==p)continue;



			if(!vis[u]){

				dfs(u,v,k,bridge);

				low[v]=min(low[v],low[u]);

				if(ord[v]<low[u])bridge.push_back(id);

			}

			else{

				low[v]=min(low[v],ord[u]);

			}

		}

	}



	vector<int>enumerate(){

		vector<int>bridge;

		int k=0;

		dfs(0,-1,k,bridge);

		return bridge;

	}

};



//O(M)

vector<int>enumerate(int N,vector<int>&A,vector<int>&B,vector<int>&used){

	int M=A.size();

	EnumerateBridges eb(N);

	for(int i=0;i<M;i++){

		if(used[i])continue;

		eb.addEdge(A[i],B[i]);

	}



	vector<int>nb(M,1);

	auto bs=eb.enumerate();

	for(auto k:bs)nb[k]=0;



	vector<int>ret;

	for(int i=0;i<M;i++)if(nb[i])ret.push_back(i);

	return ret;

}



/*

A[i]--B[i] i=1,2,...,M

C[i]--D[i] i=1,2,...,M

*/

int solve(int N,vector<int>&A,vector<int>&B,vector<int>&C,vector<int>&D){

	int M=A.size();

	for(int i=0;i<M;i++){

		A[i]--;B[i]--;C[i]--;D[i]--;

	}

	vector<int>used(M);



	while(true){



		auto src=enumerate(N,A,B,used);

		auto snk=enumerate(N,C,D,used);



		//exchange graph

		vector<vector<int>>EG(M);

		for(int i=0;i<M;i++){

			if(!used[i])continue;

			used[i]=false;



			auto listY1=enumerate(N,A,B,used);

			auto listY2=enumerate(N,C,D,used);

			for(auto j:listY1)EG[i].push_back(j);

			for(auto j:listY2)EG[j].push_back(i);



			used[i]=true;

		}

	}

}



int main(){

	int N,M;cin>>N>>M;

	vector<int>A(M),B(M);

	EnumerateBridges eb(N);

	for(int i=0;i<M;i++){

		cin>>A[i]>>B[i];

		eb.addEdge(A[i],B[i]);

		if(A[i]>B[i])swap(A[i],B[i]);

	}



	auto bs=eb.enumerate();

	vector<pint>ans;

	for(auto k:bs)ans.emplace_back(A[k],B[k]);

	sort(ans.begin(),ans.end());

	for(int i=0;i<ans.size();i++){

		cout<<ans[i].first<<" "<<ans[i].second<<endl;

	}

	return 0;

}
