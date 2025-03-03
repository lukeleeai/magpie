#include<iostream>

#include<vector>

#include<algorithm>

#include<list>

#include<set>

using namespace std;







void dfs(int c,int depth,vector<vector<int> >& tree, vector<int>& memo){

	if(memo[c] != -1) return;

	memo[c] = depth;



	for(int i=0;i<tree[c].size();++i){

		int next = tree[c][i];

		dfs(next,depth+1,tree,memo);

	}

}





int main(){

	int n;

	cin >> n;

	vector<vector<int> > tree(n+1);

	vector<int> fenech(n+1,-1);

	vector<int> sunuke(n+1,-1);



	int a,b;

	for(int i=1;i<n;++i){

		cin >> a >> b;

		tree[a].push_back(b);

		tree[b].push_back(a);

	}



	dfs(1,0,tree,fenech);

	dfs(n,0,tree,sunuke);



	int nfenech = 0;

	int nsunuke = 0;



	for(int i=1;i<=n;++i){

		if(fenech[i] <= sunuke[i]){

			nfenech++;

		}else{

			nsunuke++;

		}

	}



	if(nfenech > nsunuke) cout << "Fennec" <<endl;

	else cout << "Snuke" <<endl;

	

	return 0;

}




