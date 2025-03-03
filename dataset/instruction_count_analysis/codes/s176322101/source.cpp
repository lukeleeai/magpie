#pragma GCC target("avx")

#pragma GCC optimize("Ofast")

#pragma GCC optimize("unroll-loops")

#include<stdio.h>

#include<cstdio>



int v[1500001];

char s[1500001],t[500002];

void Zalgorithm(int N){

  int j=0;

  for(int i=1;i<N;++i){

    if(i+v[i-j]<j+v[j]){

      v[i]=v[i-j];

    }else{

      int k=j+v[j]-i;

      k*=k>0;

      while(i+k<N&&s[k]==s[i+k])++k;

      v[i]=k;

      j=i;

    }

  }

}

int i,j,K,que[500001],bf,ans,size;

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

  int M=N+(K<<1);

  while(i<M){

    s[i++]=t[j++];

    j*=j<N;

  }

  Zalgorithm(M);

  for(i=0;i<N;++i){

    if(v[i+K]<K)que[size++]=(i+K)%N;

  }

  for(i=0;i<N;++i){

    if(i==size){

      puts("-1");

      return 0;

    }

    if(v[que[i]+=K]>=K){

      que[size++]=que[i]%N;

      if(bf<=i){

        bf=size-1;

        ++ans;

      }

    }

  }

  printf("%d\n",ans);

}