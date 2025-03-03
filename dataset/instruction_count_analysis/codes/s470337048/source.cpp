#include "stdc++.h"

using namespace std;



bool cmp(const pair<int,int> &a,const pair<int,int> &b){

	if( a.first != b.first ) return a.first < b.first;

	else return a.second > b.second;

}

int main(){

	int n,W;

	int t = 1;

	while( cin >> W >> n && W ){

		vector< pair<int,int> > cur;

		cur.push_back({0,0});

		for(int i = 0 ; i < n ; i++){

			int w,c;

			scanf("%d,%d",&c,&w);

			for(int j = 0 , t = cur.size() ; j < t ; j++ )

				cur.push_back(pair<int,int>(cur[j].first+w,cur[j].second+c));

			sort(cur.begin(),cur.end(),cmp);

			int maxi = -1;

			vector< pair<int,int> > nex;

			for(int j = 0 ; j < cur.size() ; j++){

				if( maxi >= cur[j].second ) continue;



				if( cur[j].first <= W ) nex.push_back(cur[j]);

				maxi = cur[j].second;

			}cur = nex;

		}

		int ans = 0, ans2 ;

		for(int i = 0 ; i < cur.size() ; i++){

			if( cur[i].first <= W ){

				ans = cur[i].second;

				ans2 = cur[i].first;

			}

		}



		cout << "Case " << t++ << ":" << endl;

		cout << ans << endl;

		cout << ans2 << endl;

	}

}