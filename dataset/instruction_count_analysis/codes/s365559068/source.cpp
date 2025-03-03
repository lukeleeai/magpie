#include<iostream>

#include<vector>

#include<queue>



using namespace std;



vector<int>ve[120000];



int main(){

//	ios::sync_with_stdio(false);

//	cin.tie(0);cout.tie(0);

	int n,k;

	cin>>n>>k;

	int x,y;

	for(int i=0;i<n;i++){

		cin>>x>>y;

		if(x>k) continue;

		int tt=k-x+1;

		ve[tt].push_back(y);

	}

	

	priority_queue<int>q;

	int ans=0;

	for(int i=k;i>=1;i--){

		for(int j=0;j<ve[i].size();j++) q.push(ve[i][j]);

		if(!q.empty()){

			ans+=q.top();

			q.pop();	

		}

	}

	cout<<ans<<"\n";

	

	return 0;

} 