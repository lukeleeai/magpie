#include <iostream>

using namespace std;



#define rep(i,n) rep2(i,0,n)

#define rep2(i,m,n) for(int i=m;i<n;i++)



int w,h,ans,dy[]={-1,0,1,0},dx[]={0,-1,0,1};

char c[22][22];



void dfs(int y,int x){

	ans++;

	c[y][x]='#';

	rep(i,4){

		int ny=y+dy[i],nx=x+dx[i];

		if(0<=ny && ny<h && 0<=nx && nx<w && c[ny][nx]=='.')dfs(ny,nx);

	}

}



int main(){

	while(cin>>w>>h&&w){

		ans=0;

		int y,x;

		rep(i,h)rep(j,w){

			cin>>c[i][j];

			if(c[i][j]=='@')y=i,x=j;

		}

		dfs(y,x);

		cout<<ans<<endl;

	}

}