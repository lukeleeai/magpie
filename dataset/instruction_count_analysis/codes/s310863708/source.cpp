#include<iostream>

#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<algorithm>

#include<cmath>

using namespace std;

int n,m;

int a[100010],b[100010],cnt[100010];

int main(){

	scanf("%d%d",&n,&m);

	int i,j;

	for(i=1;i<=m;++i){

		scanf("%d%d",&a[i],&b[i]);cnt[a[i]]++;cnt[b[i]]++;

	}

	for(i=1;i<=n;++i){

		if(cnt[i]%2!=0){

			printf("NO\n");return 0;

		}

	}

	printf("YES\n");return 0;

}