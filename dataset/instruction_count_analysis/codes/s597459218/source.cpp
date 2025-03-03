#include "stdc++.h"

using namespace std;



#define ll long long

#define fi first

#define se second

#define inf 1e15



#define N 300005



int row[N];

int col[N];



vector<int>rowv,colv;



set<pair<int,int>>bomb;



int main() {

    

    ios_base::sync_with_stdio(false);

    cin.tie(NULL); cout.tie(NULL);

    

	int t=1;

	//cin>>t;

	while(t--){

	    

	    int n,m,k;

	    cin>>n>>m>>k;

	    

        int rowh=0,colh=0;

	    for(int i=0;i<k;i++){

	        int x,y;

	        cin>>x>>y;

	        x--;y--;

	        

	        bomb.insert({x,y});

	        

	        row[x]++;

	        col[y]++;

	        

	        rowh=max(rowh,row[x]);

	        colh=max(colh,col[y]);

	    }

	    

	    for(int i=0;i<n;i++){

	        if(row[i]==rowh){

	            rowv.push_back(i);

	        }

	    }

	     for(int i=0;i<m;i++){

	        if(col[i]==colh){

	            colv.push_back(i);

	        }

	    }

	    

	    ll ans=rowh+colh-1;

	    

	    for(auto i:rowv){

	        for(auto j:colv){

	            

	            if(bomb.find({i,j})==bomb.end()){

	                ans++;

	                goto end;

	                

	            }

	        }

	    }

	    

	    end:

	    cout<<ans<<"\n";

	    

	    

	}

	return 0;

}
