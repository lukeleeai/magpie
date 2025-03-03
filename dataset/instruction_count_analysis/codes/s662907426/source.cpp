//#pragma GCC optimize(3)

#include<iostream>

#include<iomanip>

#include<stack>

#include<queue>

#include<list>

#include<vector>

#include<set> 

#include<map>

#include<string>

#include<algorithm>

#include<cmath>

#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<ctime>

#define ll unsigned long long

#define db double

#define inf 3001

#define INF (int)1e8 

#define mod (int)(1e9+7)

#define pi acos(-1)

#define rd(n) {n=0;char ch;int f=0;do{ch=getchar();if(ch=='-'){f=1;}}while(ch<'0'||ch>'9');while('0'<=ch&&ch<='9'){n=(n<<1)+(n<<3)+ch-48;ch=getchar();}if(f)n=-n;}

using namespace std;

int f[2][inf*2];



int DP(int n,int m){

    memset(f,0,sizeof(f));

	int now=0;

	for (int i=0;i<=n;i++){

		f[now][i]=1;

	}

	for (int i=1;i<=m;i++){

		now^=1;

		for (int j=0;j<=n;j++){

			f[now][j]=0;

		}

		for (int j=0;j<=n;j++){

			if(j>0){

                f[now][j-1]=(f[now][j-1]+f[now^1][j])%mod;

                f[now][j]=(f[now][j]+f[now^1][j])%mod;

            }

            if(j<n){

                f[now][j+1]=(f[now][j+1]+f[now^1][j])%mod;

                f[now][j]=(f[now][j]+f[now^1][j])%mod;

            }

		}

	}

	int ans=0;

	for (int i=0;i<=n;i++){

		ans=(ans+f[now][i])%mod;

	}

	return ans;

}



int n,m;



int main(){

	rd(n) rd(m)

	printf("%d\n",(DP(n,m)-DP(n-1,m)+mod)%mod);

	return 0;

}