// Atcoder beginner round 174 C - Repsept





#include <cstdio>

 

int k;

bool v[1000010];

 

int main()

{

	scanf("%d",&k);

	for(int i=1,now=7%k;;i++){

		if(v[now])return printf("-1"),0;

		if(!now)return printf("%d",i),0;

		v[now]=true;now=now*10+7;now%=k;

	}

}