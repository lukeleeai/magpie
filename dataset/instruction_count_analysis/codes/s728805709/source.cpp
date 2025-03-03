#include<cstdio>

using namespace std;

int N,f[300001];

char s[300001];

int min(int i,int j){

	return (i<j?i:j);

}

int ans;

int main(){

	scanf("%d %s",&N,s);

	for(int i=1;i<N;i++){

		if(s[i]=='E')	++f[0];

	}

	ans=f[0];

	for(int i=1;i<N;i++){

		int a=f[i-1];

		if(s[i-1]=='W')	++a;

		if(s[i]=='E')	--a;

		f[i]=a;

		ans=min(f[i],ans);

	}

	printf("%d",ans);

	return 0;

}