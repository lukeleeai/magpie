#include<cstdio>



using namespace std;



int n,s;

int memo[1024][1000];



int search(int stat,int sum,int dep){

	if(dep==n)	return memo[stat][sum]=(s==sum);

	if(~memo[stat][sum])	return memo[stat][sum];

//	if(sum>s)	return 0;



	int cnt=0;

	for(int i=0;i<10;i++){

		if((stat&(1<<i))==0){

			stat|=1<<i;

			cnt+=search(stat,sum+i*(n-dep),dep+1);

			stat&=~(1<<i);

		}

	}

	return memo[stat][sum]=cnt;

}



int main(){

	for(;~scanf("%d%d",&n,&s);){

		for(int i=0;i<1024;i++)for(int j=0;j<1000;j++)	memo[i][j]=-1;

		if(n>10 || s>=1000){

			puts("0");

			continue;

		}

		printf("%d\n",search(0,0,0));

	}

	return 0;

}