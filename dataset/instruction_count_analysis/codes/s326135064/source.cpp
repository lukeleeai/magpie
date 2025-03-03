#include <cstdio>

#include <cstring>

#include <algorithm>



using namespace std;



struct Line{

  int h,s,ur,ul,lr,ll;

  Line(){}

  Line(int h,int s, int ur=0, int ul=0, int lr=0, int ll=0):h(h),s(s),ur(ur),ul(ul),lr(lr),ll(ll){}

  bool operator<(const Line &r)const{ return h < r.h; }

};



int N,M,H,K;

int s[1024],p[1024],st[1024];

Line L[100005];



int main(){

  while(scanf("%d%d%d%d",&N,&M,&H,&K) && N||M||H||K){

    for(int i=0;i<N;i++) scanf("%d",&s[i]);

    for(int i=0;i<N;i++) st[i] = i;

    for(int i=0;i<M;i++){

      int a,b;scanf("%d%d", &a,&b); a--;

      L[i] = Line(b,a);

    }



    sort(L, L+M);

    for(int i=0;i<M;i++){

      Line &li = L[i];

      li.ul = st[li.s]; li.ur = st[li.s+1];

      swap(st[li.s], st[li.s+1]);

      li.ll = st[li.s]; li.lr = st[li.s+1];

    }

    for(int i=0;i<N;i++) p[st[i]] = i; // s[p[i]] := get point from p[i] 

    int sum = 0;

    for(int i=0;i<K;i++) sum += s[p[i]];

    int res = sum;

    for(int i=0;i<M;i++){

      Line li = L[i];

      if(0 <= li.ul &&  li.ul < K && 0 <= li.ur && li.ur < K) continue;

      if(K<=li.ur&&K<=li.ul) continue;

      if(0<=li.ul&&li.ul<K){

	res = min(res, sum-s[p[li.ul]]+s[p[li.ur]]);

      }else{

	res = min(res, sum-s[p[li.ur]]+s[p[li.ul]]);

      }

    }



    printf("%d\n", res);

  }

  return 0;

}