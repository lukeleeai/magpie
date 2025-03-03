// #include "stdc++.h"

#include <cstdio>

#include <algorithm>

#include <iostream>

#include <emmintrin.h>



using namespace std;



typedef long long ll;



typedef int _loop_int;

#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)

#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl



#define CHMAX(a,b) a=max((a),(b))



int n,m;

unsigned int a[5000] __attribute__((aligned(16)));

unsigned int b[5000*256] __attribute__((aligned(16)));

unsigned int mx[256] __attribute__((aligned(16)));



unsigned long long tmp[2] __attribute__((aligned(16)));



static inline __m128i __attribute__((always_inline))

po_mm_max_epi32(__m128i a, __m128i b){

  __asm__("pmaxsd %1, %0" : "+x" (a) : "xm" (b));

  return a;

}



void f1(int x){

  // REP(i,m)CHMAX(mx[i],b[256*x+i]);

  for(int i=0;i<m;i+=4){

    __m128i xx = _mm_load_si128((__m128i*)(mx+i));

    __m128i yy = _mm_load_si128((__m128i*)(b+256*x+i));

    xx = po_mm_max_epi32(xx,yy);

    _mm_store_si128((__m128i*)(mx+i), xx);

  }

}

ll f2(){

  // ll ret = 0;

  // REP(i,m)ret += mx[i];

  // return ret;

  __m128i x = _mm_setzero_si128();

  __m128i y = _mm_setzero_si128();

  const __m128i zero = _mm_setzero_si128();



  for(int i=0;i<m;i+=4){

    __m128i xx = _mm_load_si128((__m128i*)(mx+i));

    __m128i yy = _mm_unpackhi_epi32(xx,zero);

            xx = _mm_unpacklo_epi32(xx,zero);

    x = _mm_add_epi64(x,xx);

    y = _mm_add_epi64(y,yy);

  }

  x = _mm_add_epi64(x,y);

  _mm_store_si128((__m128i*)tmp, x);

  return tmp[0] + tmp[1];

}



int main(){

  scanf("%d%d",&n,&m);

  REP(i,n-1)scanf("%u",a+i);

  REP(i,n)REP(j,m)scanf("%u",&b[256*i+j]);

  // REP(i,n-1)a[i]=1;

  // REP(i,n)REP(j,m)b[256*i+j]=1;



  ll ans = 0;

  REP(l,n){

    ll lensum = 0;

    REP(j,m)mx[j]=0;

    f1(l);

    CHMAX(ans,f2()-lensum);

    FOR(r,l+1,n){

      lensum += a[r-1];

      f1(r);

      CHMAX(ans,f2()-lensum);

    }

  }

  printf("%lld\n",ans);

  return 0;

}