#pragma GCC target("avx")

#pragma GCC optimize("O3")

#pragma GCC optimize("unroll-loops")

#include<stdio.h>

#include<cstdio>



int v[2000001];

char s[2000001],t[500002];

void Zalgorithm(int N){

  int i=1,j=0,k=0;

  while(i<N){

    while(i+j<N&&s[i+j]==s[j])++j;

    v[i]=j;

    if(!j){

      ++i;

      continue;

    }

    k=1;

    while(v[k]+k<j){

      v[i+k]=v[k];

      ++k;

    }

    i+=k;

    j-=k;

  }

}

int i,j,K,quef[1000001],ques[1000001],size;

int main(){

  int N,ng=500001,mid;

  std::fgets(t,1000000,stdin);

  std::fgets(s,1000000,stdin);

  while(ng-K>1){

    mid=(ng+K)>>1;

    (s[mid]?K:ng)=mid;

  }

  while(t[i]!='\n'){

    s[K+i]=t[i];++i;

  }

  N=i;

  i+=K;

  while(i<2000001){

    s[i++]=t[j++];

    j*=j<N;

  }

  N=(K+N-1)/N*N;

  Zalgorithm(N+K*2);

  for(i=0;i<N;++i){

    if(v[i+K]<K)ques[size++]=i+K-(i+K>=N)*N;

  }

  for(i=0;i<N;++i){

    if(i==size){

      puts("-1");

      return 0;

    }

    if(v[ques[i]+=K]>=K){

      ques[size]=ques[i]-N*(ques[i]>=N);

      quef[size++]=quef[i]+1;

    }

  }

  printf("%d\n",quef[N-1]);

}