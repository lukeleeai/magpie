#include "stdc++.h"

using namespace std;

inline void boost(){ 

	ios_base::sync_with_stdio(0); 

	cin.tie(0); 

}



int f[90001];

int main(){

	boost();

	int h,w,d;

	cin>>h>>w>>d;

	map <int, pair <int, int> >adr;

	for(int i=1; i<=h; i++){

		for(int j=1; j<=w; j++){

			int x;

			cin>>x;

			adr[x].first = i;

			adr[x].second = j;

		}

	}

	for(int i=1; i<=h*w; i++){

			if( i <= d)

				f[i] = 0;

			else{

				f[i] = f[i-d] + abs(adr[i].first - adr[i-d].first) + abs(adr[i].second - adr[i-d].second);

			}

	}

	int q;

	cin>>q;

	int z,y;

	vector <int> ans;

	for(int i=0; i<q; i++){

		cin>>z>>y;

		ans.push_back(f[y] - f[z]);

	}

	for(int i = 0 ; i<ans.size(); i++){

		cout<<ans[i]<<endl;

	}

}