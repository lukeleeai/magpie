#pragma GCC optimize(3) 

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

#define db long double

#define inf 200001

#define INF (ll)1e15 

#define pi acos(-1)

#define mxbit 30

#define rd(n) {n=0;char ch;int f=0;do{ch=getchar();if(ch=='-'){f=1;}}while(ch<'0'||ch>'9');while('0'<=ch&&ch<='9'){n=(n<<1)+(n<<3)+ch-48;ch=getchar();}if(f)n=-n;}

using namespace std;



char str[inf];

int nxt[inf];

ll sum[26][inf];

int n,lens;



void getnxt(void){

	int k=0;

    nxt[0]=0;

    for (int i=2;i<=n;i++){

        while (k && str[k+1]!=str[i]){

            k=nxt[k];

        }

        if (str[k+1]==str[i]){

            k++;

        }

        nxt[i]=k;

    }

    return;

}



ll query(ll x,int p){

	if (x<n){

		return sum[p][x];

	}

	ll a=sum[p][lens],b=sum[p][n];

	ll l1=lens,l2=n;

    while(l1+l2<x){

    	a+=b;

		swap(a,b);

		l1+=l2;

		swap(l1,l2);

	}

    return b+query(x-l2,p);

}



int main(){

	scanf("%s",str+1);

	n=strlen(str+1)/2;

	getnxt();

	lens=n-nxt[n];

	for (int i=0;i<26;i++){

		for (int j=1;j<=n;j++){

			sum[i][j]=sum[i][j-1]+(str[j]-'a'==i);

		}

	}

	ll l,r;

	rd(l) rd(r)

	for (int i=0;i<26;i++){

		printf("%lld ",query(r,i)-query(l-1,i));

	}

	return 0;

}