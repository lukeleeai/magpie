#include<cstdio>

const int MaxN=200010;

int N,K,P[MaxN],pre[MaxN][2],pos[MaxN][2];

int min(int a,int b){return a<b?a:b;}

int max(int a,int b){return a>b?a:b;}

int main(){

	scanf("%d%d",&N,&K);++K;

	for(int i=0;i<N;i++){

		scanf("%d",P+i);

		pre[i+1][0]=min(i%K==0?N:pre[i][0],P[i]);

		pre[i+1][1]=max(i%K==0?0:pre[i][1],P[i]);

	}

	for(int i=N;i--;){

		pos[i][0]=i%K==0?N:min(pos[i+1][0],P[i]);

		pos[i][1]=i%K==0?0:max(pos[i+1][1],P[i]);

	}

	K--;

	int s=0,t=0,fl=0;

	for(int j=1;j<K;j++)if(P[j]<P[j-1])t++;

	for(int i=0,j=K;j<=N;i++,j++){

		if(t){

			s++;

			if(j<N&&(t+=(P[j]<P[j-1])-(P[i+1]<P[i]))&&min(pos[i][0],pre[j+1][0])==P[i]&&max(pos[i][1],pre[j+1][1])==P[j])s--;

		}

		else t+=(P[j]<P[j-1])-(P[i+1]<P[i]),fl=1;

	}

	printf("%d\n",s+fl);

}