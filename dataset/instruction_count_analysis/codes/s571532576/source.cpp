#include "stdc++.h"



using namespace std;





int confere[10000000];





vector<vector<pair<int,int>>>v;





void dfs(int i,int j,int peso){



	if(confere[i]!=-1) return;



	if(peso%2==0) confere[i]=j;

	else confere[i]= (j+1)%2;





	for(int s=0;s<v[i].size();s++){



		dfs(v[i][s].first, confere[i],v[i][s].second);

	}



}



int main(){



	int n;

	int u,u2,w;

	cin >> n;



	for(int i=0;i<n+10;i++){

		vector<pair<int,int>>s;

		v.push_back(s);

	}



	for(int i=0;i<n+10;i++){

		confere[i]=-1;

	}

	n--;



	for(int i=0;i<n;i++){

		cin >> u >> u2 >> w;

		v[u].push_back(make_pair(u2,w));

		v[u2].push_back(make_pair(u,w));

	}

	dfs(1,0,0);



	for(int i=1;i<=n+1;i++)

		cout << confere[i] << endl;

	return 0;

}