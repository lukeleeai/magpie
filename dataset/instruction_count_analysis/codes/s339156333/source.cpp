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

#define ll long long

#define db double

#define inf 200001

#define INF (int)1e9

#define mod (int)(1e9+7)

#define pi acos(-1)

#define rd(n) {n=0;char ch;int f=0;do{ch=getchar();if(ch=='-'){f=1;}}while(ch<'0'||ch>'9');while('0'<=ch&&ch<='9'){n=(n<<1)+(n<<3)+ch-48;ch=getchar();}if(f)n=-n;}

using namespace std;



inline int Min(int a,int b,int c){

	return min(a,min(b,c));

}



int mp[inf][3];

int p[inf],pos[inf],ck[inf];

int n;



int main(){

	rd(n)

	for (int i=1;i<=3;i++){

		for (int j=1;j<=n;j++){

			rd(mp[j][i])

		}

	}

	for (int i=1;i<=n;i++){

		if (mp[i][3]-mp[i][2]==mp[i][2]-mp[i][1] && mp[i][3]-mp[i][2]==1){

			p[i]=0;

		}

		else if (mp[i][2]-mp[i][3]==mp[i][1]-mp[i][2] && mp[i][2]-mp[i][3]==1){

			p[i]=1;

		}

		else{

			puts("No");

			return 0;

		}

		int minv=Min(mp[i][1],mp[i][2],mp[i][3]);

		int dis=abs(i-minv/3-1);

		if (dis&1){

			puts("No");

			return 0;

		}

		pos[minv/3+1]=i;

	}

	int cnt[2]={0,0};

	for (int i=1;i<=n;i++){

		cnt[i&1]+=p[i];

	}

	for (int i=1;i<=n;i++){

		if (!ck[i]){

			ck[i]=1;

			int len=0,now=pos[i];

			while (!ck[now]){

				ck[now]=1;

				now=pos[now];

				len++;

			}

			cnt[!(i&1)]+=len;

		}

	}

	if ((cnt[0]&1) || (cnt[1]&1)){

		puts("No");

		return 0;

	}

	puts("Yes");

	return 0;

}