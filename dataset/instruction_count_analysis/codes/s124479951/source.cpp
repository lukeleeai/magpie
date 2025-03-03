#include<iostream>

#include<vector>

#include<algorithm>

#include<list>

#include<set>

using namespace std;



int n;



vector<int> fenech(1000001);

vector<int> sunuke(1000001);

set<int> se;



void dfs(int c,int depth,vector<vector<int> >& tree,bool f){



	if(f){

		fenech[c] = depth;

	}else{

		sunuke[c] = depth;

	}



	for(int i=0;i<tree[c].size();++i){

		int next = tree[c][i];

		if(se.find(next) != se.end()) continue;

		se.insert(next);

		dfs(next,depth+1,tree,f);

	}

}





int main(){

	cin >> n;

	vector<vector<int> > tree(n+1);



	int a,b;

	for(int i=1;i<n;++i){

		cin >> a >> b;

		tree[a].push_back(b);

		tree[b].push_back(a);

	}



	se.insert(1);

	dfs(1,0,tree,true);

	se.clear();

	se.insert(n);

	dfs(n,0,tree,false);



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




