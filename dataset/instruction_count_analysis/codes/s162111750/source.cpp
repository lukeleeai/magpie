#include "stdc++.h"

using namespace std;



#define ll long long

#define fi first

#define se second

#define inf 1e15



#define N 300005



vector<int>row[N];



multiset<int>Noofbombsincolumnsset;



int bombsineachcolumn[N];



void upd(int pos,int delta){

    

    Noofbombsincolumnsset.erase(Noofbombsincolumnsset.find(bombsineachcolumn[pos]));

    

    bombsineachcolumn[pos]+=delta;

    

    Noofbombsincolumnsset.insert(bombsineachcolumn[pos]);

    

}

int main() {

    

    ios_base::sync_with_stdio(false);

    cin.tie(NULL); cout.tie(NULL);

    

	int t=1;

//	cin>>t;

	while(t--){

	    

	    int n,m,k;

	    cin>>n>>m>>k;

	    

	    for(int i=0;i<m;i++){

	        Noofbombsincolumnsset.insert(0);

	        bombsineachcolumn[i]=0;

	    }

	    for(int i=0;i<k;i++){

	        int x,y;

	        cin>>x>>y;

	        x--;y--;

	        row[x].push_back(y);

	        //add

	        upd(y,1);

	    }

	    int ans=0;

	    

	    for(int i=0;i<n;i++){

	        

	        int cnt=row[i].size();

	        

	        for(auto y:row[i]){

	            //remove

	            upd(y,-1);

	        }

	        

	        cnt+= *Noofbombsincolumnsset.rbegin();

	        

	        ans=max(ans,cnt);

	        

	        for(auto y:row[i]){

	            //add

	            upd(y,1);

	        }

	        

	    }

	    

	    cout<<ans<<"\n";

	    

	    

	}

	return 0;

}
