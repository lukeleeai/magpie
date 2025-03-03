#include<stdio.h>

int t;

int ans = 0;

void dfs(unsigned n,bool k3,bool k5,bool k7){

	if(n>t)return; 

	if(k3&&k5&&k7){

		ans++;	

	}

	dfs(n*10+3,true,k5,k7);

	dfs(n*10+5,k3,true,k7);

	dfs(n*10+7,k3,k5,true);

}



int main(){

	scanf("%d", &t);

	dfs(0,false,false,false);

	

//	dfs(3,true,false,false);

//	dfs(5,false,true,false);

//	dfs(7,false,false,true);

	

	

	printf("%d\n",ans);

	return 0;

}