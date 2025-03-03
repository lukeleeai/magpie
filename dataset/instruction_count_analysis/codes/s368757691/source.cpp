// #include "stdc++.h"

#include <cctype>

#include <cstdio>

#include <algorithm>

#include <emmintrin.h>



using std::scanf;

using std::printf;

using std::max;

using std::isdigit;



typedef long long ll;



typedef int _loop_int;

#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)

#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)



#define __my_getchar getchar_unlocked

inline void read(unsigned int &x){

  x=0;char c;

  while(!isdigit(c=__my_getchar()));

  x=c-'0';

  while(isdigit(c=__my_getchar()))x=10*x+(c-'0');

}



unsigned int n,m;

const int MAX_N = 5000;

const int MAX_M = 200;

unsigned int a[MAX_N] __attribute__((aligned(16)));

unsigned int b[MAX_N * MAX_M] __attribute__((aligned(16)));

unsigned int mx[MAX_M] __attribute__((aligned(16)));



static inline __m128i __attribute__((always_inline))

po_mm_max_epi32(__m128i a, __m128i b){

  __asm__("pmaxsd %1, %0" : "+x" (a) : "xm" (b));

  return a;

}

unsigned long long tmp[2] __attribute__((aligned(16)));



// // max of two array

// // a[i] = max(a[i], b[i])

// void vec_chmax(int n, unsigned int *a, unsigned int *b){

//   for(int i=0;i<n;i+=4){

//     __m128i xx = _mm_load_si128((__m128i*)(a+i));

//     __m128i yy = _mm_load_si128((__m128i*)(b+i));

//     xx = po_mm_max_epi32(xx,yy);

//     _mm_store_si128((__m128i*)(a+i), xx);

//   }

// }



// // sum of array

// // Σa[i]

// ll vec_sumll(int n, unsigned int *a){

//   __m128i x = _mm_setzero_si128();

//   __m128i y = _mm_setzero_si128();

//   const __m128i zero = _mm_setzero_si128();

 

//   for(int i=0;i<n;i+=4){

//     __m128i xx = _mm_load_si128((__m128i*)(a+i));

//     __m128i yy = _mm_unpackhi_epi32(xx,zero);

//             xx = _mm_unpacklo_epi32(xx,zero);

//     x = _mm_add_epi64(x,xx);

//     y = _mm_add_epi64(y,yy);

//   }

//   x = _mm_add_epi64(x,y);

//   _mm_store_si128((__m128i*)tmp, x);

//   return tmp[0] + tmp[1];

// }



inline ll func(int z,ll sub){

  // vec_chmax(m,mx,b+MAX_M*z);

  // return vec_sumll(m,mx)-sub;

  __m128i x = _mm_setzero_si128();

  const __m128i zero = _mm_setzero_si128();

  for(int i=0;i<m;i+=4){

    __m128i xx = _mm_load_si128((__m128i*)(mx+i));

    __m128i yy = _mm_load_si128((__m128i*)(b+MAX_M*z+i));

    xx = po_mm_max_epi32(xx,yy);

    _mm_store_si128((__m128i*)(mx+i), xx);

    yy = _mm_unpackhi_epi32(xx,zero);

    xx = _mm_unpacklo_epi32(xx,zero);

    x = _mm_add_epi64(x,xx);

    x = _mm_add_epi64(x,yy);

  }

  _mm_store_si128((__m128i*)tmp, x);

  return tmp[0]+tmp[1]-sub;

}



int main(){

  read(n);read(m);

  REP(i,n-1)read(a[i]);

  REP(i,n)REP(j,m)read(b[MAX_M*i+j]);



  ll ans = 0;

  REP(l,n){

    ll lensum = 0;

    REP(j,m)mx[j]=0;

    ans = max(ans, func(l,lensum));



    FOR(r,l+1,n){

      lensum += a[r-1];

      ans = max(ans, func(r,lensum));

    }

  }

  printf("%lld\n",ans);

  return 0;

}
