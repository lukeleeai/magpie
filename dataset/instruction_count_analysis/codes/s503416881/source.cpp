#include<stdio.h>

#define rep(i,N) for(int i=0;i<(int)N;i++)

const int MAX=1e6;

static inline int IN(void)

{

  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}

  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;

}

static inline int GCD(int a,int b){return !b?a:GCD(b,a%b);}

const int Primes[168]=

{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,

 97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,

 227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,

 367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,

 509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,

 661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,

 829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};

const char common[]="not coprime",disjoint[]="pairwise coprime",several[]="setwise coprime";

char esc[1000000];

static inline int Divise(int x)

{

  if(!x){return 0;}

  rep(i,168)

  {

    if(Primes[i]*Primes[i]>x)break;

    if(x%Primes[i])continue;

    if(esc[Primes[i]-1])return 0;

    esc[Primes[i]-1]=1;

    while(x%Primes[i]==0&&x)x/=Primes[i];

  }

  if(x>1){if(esc[x-1])return 0;esc[x-1]=1;}

  return 1;

}

int main(void)

{

  int N=IN(),A=0,flag=0,g=0;

  rep(i,N){A=IN();g=GCD(g,A);if(i&&g!=1){flag=1;}if(!Divise(A)){flag=1;}}

  if(g>1)return puts(common),0;else{if(flag)return puts(several),0;else return puts(disjoint),0;}

}