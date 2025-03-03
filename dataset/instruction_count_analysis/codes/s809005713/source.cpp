#include<map>

#include<cmath>

#include<ctime>

#include<queue>

#include<vector>

#include<cstdio>

#include<cstring>

#include<algorithm>

#define qmin(x,y) (x=min(x,y))

#define qmax(x,y) (x=max(x,y))

#define mp(x,y) make_pair(x,y)

using namespace std;

typedef long long ll;

typedef pair<int,int> pii;

inline int read(){

	int ans=0,fh=1;

	char ch=getchar();

	while(ch<'0'||ch>'9'){

		if(ch=='-') fh=-1;

		ch=getchar();

	}

	while(ch>='0'&&ch<='9')

		ans=ans*10+ch-'0',ch=getchar();

	return ans*fh;

}

int n,m,d;

int main(){

//	freopen("nh.in","r",stdin);

//	freopen("zhy.out","w",stdout);

	n=read(),m=read(),d=read();

	for(int i=1;i<=n;i++){

		for(int j=1;j<=m;j++){

			int x=i+j+m,y=i-j+m;

			if((x/d)&1){

				if((y/d)&1) printf("R");

				else printf("Y");

			}

			else{

				if((y/d)&1) printf("G");

				else printf("B");

			}

		}

		printf("\n");

	}

	return 0;

}
























