#include<stdio.h>

#pragma GCC optimize("O2")

#pragma GCC optimize("O3")

#pragma GCC target("avx")

#define swap(a,b) (a+=b,b=a-b,a-=b)

#define rep(i,N) for(int i=0;i<(int)N;i++)

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

static inline void OUT(long x){if(x<0)putchar('-'),x=-x;if(x>=10)OUT(x/10);putchar(x%10+48);}

static inline void AscRadix32(int *a,const int sz,const int minus)

{

  /*http://users.encs.concordia.ca/~chvatal/notes/rsort.html*/

  int x,shift=0,elem[256],temp[sz];

  while(shift<32)

  {

    int bucket[256]={0};

    rep(i,sz){x=(a[i]>>shift)&255;bucket[x]++;temp[i]=a[i];}

    elem[0]=0;rep(i,255)elem[i+1]=elem[i]+bucket[i];

    rep(i,sz){x=(temp[i]>>shift)&255;a[elem[x]]=temp[i];elem[x]++;}

    shift+=8;

  }

  rep(i,minus/2)swap(a[sz-minus+i],a[sz-1-i]);

  rep(i,(sz-minus)/2)swap(a[i],a[sz-minus-1-i]);

  rep(i,sz/2)swap(a[i],a[sz-1-i]);

}

int main(void)

{

  int N=IN(),c=CH(),i=0,m=0,p=0,z=0,temp,A[N];

  long K=0,low=-1e18,mid,high=-low,count;while(c>47&&c<58){K=K*10+c-48,c=CH();}

  rep(j,N){A[j]=IN();if(A[j]<0)m++;else if(A[j]>0)p++;else z++;}

  AscRadix32(A,N,m);

  if(K>1l*m*p&&K<1l*m*p+1l*z*(N-1)/2)return puts("0"),0;else temp=0;

  if(K<=1l*m*p)high=1l;else low=-1l;

  while(high-low>1)

  {

    mid=(low+high)/2,count=0;

    if(!mid)count=1l*m*p;

    else if(mid>0)

    {

      count=1l*m*p+1l*z*(m+p)+1l*z*(z-1)/2;temp=N-1;i=m+z;if(count>=K){high=mid;continue;}

      while(i<N){while(1l*A[temp]*A[i]>=mid){temp--;}if(temp>i)count+=1l*temp-i,i++;else break;}

      temp=0;i=m-1;if(count>=K){high=mid;continue;}

      while(i>=0){while(1l*A[temp]*A[i]>=mid){temp++;}if(temp<i)count+=1l*i-temp,i--;else break;}

    }

    else

    {

      temp=m-1;i=N-1;

      while(i>=m+z){while(temp>=0&&1l*A[temp]*A[i]>=mid){temp--;}if(temp>=0){count+=1l*temp+1;}i--;}

    }

    if(count<K)low=mid;else high=mid;

  }

  return OUT(low),0;

}