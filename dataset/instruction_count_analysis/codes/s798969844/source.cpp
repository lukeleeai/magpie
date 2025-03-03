#include"stdc++.h"

using namespace std;



typedef pair<pair<int,int>,int> State;



int w,h;

const int INF=1e8;



bool isrange(pair<int,int> x){

	return (0<=x.first && x.first<h && 0<=x.second && x.second<w);

}



int dx[4]={1,-1,0,0};

int dy[4]={0,0,1,-1};





int main(){

	while(cin>>w>>h,w){

		vector<string> c(h);

		for(int i=0;i<h;i++) cin>>c[i];

		vector<pair<int,int>> dust;

		pair<int,int> robot;

		for(int i=0;i<h;i++){

			for(int j=0;j<w;j++){

				auto place=make_pair(i,j);

				if(c[i][j]=='o'){

					robot=place;

				}

				if(c[i][j]=='*'){

					dust.push_back(place);

				}

			}	

		}

		State tate=make_pair(robot,0);

		pair<State,int> first_state=make_pair(tate,0);

		int res=INF;

		map<State,int> dp;

		queue<pair<State,int>> q;

		q.push(first_state);

		while(!q.empty()&& res==INF){

			auto pstate=q.front();

			q.pop();

			State state=pstate.first;

			auto now=state.first;

			for(int i=0;i<4;i++){		

				pair<int,int> to=make_pair(now.first+dx[i],now.second+dy[i]);

				if(isrange(to) && c[to.first][to.second]!='x'){

					int bit=state.second;

					if(c[to.first][to.second]=='*'){

						for(int i=0;i<dust.size();i++){

							if(dust[i]==to && ((~bit) & (1<<i))){

								bit+=(1<<i);

							}

						}



					}

					auto tostate=make_pair(to,bit);

					if(dp.count(tostate)) continue;

					dp[tostate]=pstate.second+1;

					if(bit==(1<<dust.size())-1){

						res=pstate.second+1;

					}

					q.push(make_pair(tostate,pstate.second+1));

				}

			}





		}

		if(res==INF) res=-1;

		cout<<res<<endl;

	}





}