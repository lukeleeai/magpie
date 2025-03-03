#include<stdio.h>

#pragma GCC optimize("Os")

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define rep(i,N) for(int i=0;i<(int)N;i++)

const int MOD=1e9+7,MAX=1e6,Primes[168]=

{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,

 73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,

 179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,

 283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,

 419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,

 547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,

 661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,

 811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,

 947,953,967,971,977,983,991,997};

int A[10000];

static inline char CH()

{

  static char buf[100000],*ptr1=buf,*ptr2=buf;

  return ptr1==ptr2&&(ptr2=(ptr1=buf)+fread(buf,1,100000,stdin),ptr1==ptr2)?EOF:*ptr1++;

}

static inline int IN(void)

{

  int x=0,f=0,c=CH();while(c<48||c>57){f^=c==45,c=CH();}

  while(c>47&&c<58){x=x*10+c-48,c=CH();}return f?-x:x;

}

static inline int MPow(int a,int b){return b?1l*MPow(1l*a*a%MOD,b>>1)*(b&1?a:1)%MOD:1;}

static inline int count(const int prime,const int sz)

{

  int max=0;rep(i,sz){int now=0;while(A[i]%prime==0){now++;A[i]/=prime;}if(max<now)max=now;}return max;

}

int main(void)

{

  int N=IN(),x=0;

  rep(i,N){A[i]=IN();x=(x+1l*MPow(A[i],MOD-2))%MOD;}

  rep(i,168)x=1l*x*MPow(Primes[i],count(Primes[i],N))%MOD;

  rep(i,N){if(A[i]>1){rep(j,N-1-i){if(A[i]==A[i+j+1]){A[i+j+1]=1;}}x=1l*x*A[i]%MOD;}}

  return printf("%d\n",x),0;

}