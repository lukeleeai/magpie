#include <cstdio>



int n,m,d1,d2,cnt,vis[605][605];



void solve(int d){

	int tim=0; while(d%4==0) d/=4,++tim;

	if(d&1){

		for(int i=0;i<m;++i) for(int j=0;j<m;++j){

			if(((i>>tim)+(j>>tim))&1) vis[i][j]=1;

		}

	}

	else{

		for(int i=0;i<m;++i) for(int j=0;j<m;++j){

			if((i>>tim)&1) vis[i][j]=1;

		}

	}

}



int main(){

	scanf("%d%d%d",&n,&d1,&d2); m=n<<1; solve(d1); solve(d2);

	for(int i=0;i<m;++i) for(int j=0;j<m;++j){

		if(!vis[i][j]) printf("%d %d\n",i,j),++cnt;

		if(cnt==n*n) return 0;

	}

}