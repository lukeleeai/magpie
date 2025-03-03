#pragma GCC optimize ("Ofast")

#include"stdc++.h"

using namespace std;

void *wmem;

char memarr[96000000];

template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){

  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );

  (*arr)=(T*)(*mem);

  (*mem)=((*arr)+x);

}

template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){

  sort(a, a+N);

}

template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){

  int i;

  pair<T1, T2> *arr;

  walloc1d(&arr, N, &mem);

  for(i=(0);i<(N);i++){

    arr[i].first = a[i];

    arr[i].second = b[i];

  }

  sort(arr, arr+N);

  for(i=(0);i<(N);i++){

    a[i] = arr[i].first;

    b[i] = arr[i].second;

  }

}

inline void rd(int &x){

  int k;

  int m=0;

  x=0;

  for(;;){

    k = getchar_unlocked();

    if(k=='-'){

      m=1;

      break;

    }

    if('0'<=k&&k<='9'){

      x=k-'0';

      break;

    }

  }

  for(;;){

    k = getchar_unlocked();

    if(k<'0'||k>'9'){

      break;

    }

    x=x*10+k-'0';

  }

  if(m){

    x=-x;

  }

}

inline void wt_L(char a){

  putchar_unlocked(a);

}

inline void wt_L(int x){

  int s=0;

  int m=0;

  char f[10];

  if(x<0){

    m=1;

    x=-x;

  }

  while(x){

    f[s++]=x%10;

    x/=10;

  }

  if(!s){

    f[s++]=0;

  }

  if(m){

    putchar_unlocked('-');

  }

  while(s--){

    putchar_unlocked(f[s]+'0');

  }

}

template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){

  int i;

  sz++;

  for(i=sz-1;i>k;i--){

    a[i] = a[i-1];

  }

  a[k] = aval;

}

template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){

  int i;

  sz++;

  for(i=sz-1;i>k;i--){

    a[i] = a[i-1];

  }

  for(i=sz-1;i>k;i--){

    b[i] = b[i-1];

  }

  a[k] = aval;

  b[k] = bval;

}

template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){

  int i;

  sz++;

  for(i=sz-1;i>k;i--){

    a[i] = a[i-1];

  }

  for(i=sz-1;i>k;i--){

    b[i] = b[i-1];

  }

  for(i=sz-1;i>k;i--){

    c[i] = c[i-1];

  }

  a[k] = aval;

  b[k] = bval;

  c[k] = cval;

}

template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){

  int i;

  sz++;

  for(i=sz-1;i>k;i--){

    a[i] = a[i-1];

  }

  for(i=sz-1;i>k;i--){

    b[i] = b[i-1];

  }

  for(i=sz-1;i>k;i--){

    c[i] = c[i-1];

  }

  for(i=sz-1;i>k;i--){

    d[i] = d[i-1];

  }

  a[k] = aval;

  b[k] = bval;

  c[k] = cval;

  d[k] = dval;

}

struct unionFind{

  int *d;

  int N;

  int M;

  inline void malloc(const int n){

    d = (int*)std::malloc(n*sizeof(int));

    M = n;

  }

  inline void free(void){

    std::free(d);

  }

  inline void walloc(const int n, void **mem=&wmem){

    walloc1d(&d, n, mem);

    M = n;

  }

  inline void init(const int n){

    int i;

    N = n;

    for(i=(0);i<(n);i++){

      d[i] = -1;

    }

  }

  inline void init(void){

    init(M);

  }

  inline int get(int a){

    int t = a;

    int k;

    while(d[t]>=0){

      t=d[t];

    }

    while(d[a]>=0){

      k=d[a];

      d[a]=t;

      a=k;

    }

    return a;

  }

  inline int connect(int a, int b){

    if(d[a]>=0){

      a=get(a);

    }

    if(d[b]>=0){

      b=get(b);

    }

    if(a==b){

      return 0;

    }

    if(d[a] < d[b]){

      d[a] += d[b];

      d[b] = a;

    }

    else{

      d[b] += d[a];

      d[a] = b;

    }

    return 1;

  }

  inline int operator()(int a){

    return get(a);

  }

  inline int operator()(int a, int b){

    return connect(a,b);

  }

  inline int& operator[](const int a){

    return d[a];

  }

  inline int size(int a){

    a = get(a);

    return -d[a];

  }

  inline int sizeList(int res[]){

    int i;

    int sz=0;

    for(i=(0);i<(N);i++){

      if(d[i]<0){

        res[sz++] = -d[i];

      }

    }

    return sz;

  }

}

;

struct graph{

  int N;

  int *es;

  int **edge;

  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){

    int i;

    N = N__;

    walloc1d(&es, N, mem);

    walloc1d(&edge, N, mem);

    for(i=(0);i<(N);i++){

      es[i] = 0;

    }

    for(i=(0);i<(M);i++){

      es[A[i]]++;

      es[B[i]]++;

    }

    for(i=(0);i<(N);i++){

      walloc1d(&edge[i], es[i], mem);

    }

    for(i=(0);i<(N);i++){

      es[i] = 0;

    }

    for(i=(0);i<(M);i++){

      edge[A[i]][es[A[i]]++] = B[i];

      edge[B[i]][es[B[i]]++] = A[i];

    }

  }

}

;

template<class T> struct wgraph{

  int N;

  int *es;

  int **edge;

  T **cost;

  graph g;

  void setEdge(int N__, int M, int A[], int B[], T C[], void **mem = &wmem){

    int i;

    N = N__;

    walloc1d(&es, N, mem);

    for(i=(0);i<(N);i++){

      es[i] = 0;

    }

    for(i=(0);i<(M);i++){

      es[A[i]]++;

      es[B[i]]++;

    }

    walloc1d(&edge, N, mem);

    for(i=(0);i<(N);i++){

      walloc1d(&edge[i], es[i], mem);

    }

    walloc1d(&cost, N, mem);

    for(i=(0);i<(N);i++){

      walloc1d(&cost[i], es[i], mem);

    }

    for(i=(0);i<(N);i++){

      es[i] = 0;

    }

    for(i=(0);i<(M);i++){

      edge[A[i]][es[A[i]]] = B[i];

      edge[B[i]][es[B[i]]] = A[i];

      cost[A[i]][es[A[i]]++] = C[i];

      cost[B[i]][es[B[i]]++] = C[i];

    }

    g.N = N;

    g.es = es;

    g.edge = edge;

  }

}

;

int N;

int A[100000];

int B[100000+1];

int M;

int L[200000];

int R[200000];

int ind[200000];

wgraph<int> g;

int vis[100000+1];

int ress;

int res[200000];

void solve(int n, int b = -1){

  int i;

  int j;

  vis[n] = 1;

  for(i=(0);i<(g.es[n]);i++){

    j = g.edge[n][i];

    if(j == b){

      continue;

    }

    solve(j, n);

    if(B[j]){

      {

        auto Q5VJL1cS = (1);

        B[n] ^= Q5VJL1cS;

        B[j] ^= Q5VJL1cS;

      }

      res[ress++] = g.cost[n][i];

    }

  }

}

int main(){

  wmem = memarr;

  int i;

  int j;

  int k;

  int e;

  unionFind uf;

  rd(N);

  rd(M);

  {

    int e98WHCEY;

    for(e98WHCEY=(0);e98WHCEY<(N);e98WHCEY++){

      rd(A[e98WHCEY]);

      rd(B[e98WHCEY]);

    }

  }

  {

    int FmcKpFmN;

    for(FmcKpFmN=(0);FmcKpFmN<(M);FmcKpFmN++){

      rd(L[FmcKpFmN]);

      rd(R[FmcKpFmN]);R[FmcKpFmN] += (1);

    }

  }

  sortA_L(N,A,B);

  for(i=(0);i<(M);i++){

    L[i] = lower_bound(A, A+N, L[i]) - A;

    R[i] = lower_bound(A, A+N, R[i]) - A;

    ind[i] = i;

  }

  uf.malloc(N+1);

  uf.init(N+1);

  k = 0;

  for(i=(0);i<(M);i++){

    if(uf(L[i],R[i])){

      arrInsert(k, k, L, L[i], R, R[i], ind, ind[i]);

    }

  }

  M = k;

  g.setEdge(N+1, M, L, R, ind);

  for(i=(N+1)-1;i>=(1);i--){

    if(B[i]!=B[i-1]){

      B[i] =1;

    }

    else{

      B[i] =0;

    }

  }

  for(i=(0);i<(N+1);i++){

    if(!vis[i]){

      solve(i);

    }

  }

  for(i=(0);i<(N+1);i++){

    if(B[i]){

      wt_L(-1);

      wt_L('\n');

      return 0;

    }

  }

  sortA_L(ress,res);

  wt_L(ress);

  wt_L('\n');

  {

    int jbtyPBGc;

    if(ress==0){

      putchar_unlocked('\n');

    }

    else{

      for(jbtyPBGc=(0);jbtyPBGc<(ress-1);jbtyPBGc++){

        wt_L(res[jbtyPBGc]+1);

        wt_L(' ');

      }

      wt_L(res[jbtyPBGc]+1);

      wt_L('\n');

    }

  }

  return 0;

}

// cLay varsion 20200217-1



// --- original code ---

// int N, A[1d5], B[1d5+1], M, L[2d5], R[2d5], ind[2d5];

// 

// wgraph<int> g;

// int vis[1d5+1];

// int ress, res[2d5];

// 

// void solve(int n, int b = -1){

//   int i, j;

//   vis[n] = 1;

//   rep(i,g.es[n]){

//     j = g.edge[n][i];

//     if(j == b) continue;

//     solve(j, n);

//     if(B[j]) (B[n], B[j]) ^= 1, res[ress++] = g.cost[n][i];

//   }

// }

// 

// {

//   int i, j, k, e;

//   unionFind uf;

// 

//   rd(N,M,(A,B)(N),(L,R++)(M));

//   sortA(N,A,B);

// 

//   rep(i,M){

//     L[i] = lower_bound(A, A+N, L[i]) - A;

//     R[i] = lower_bound(A, A+N, R[i]) - A;

//     ind[i] = i;

//   }

// 

//   uf.malloc(N+1);

//   uf.init(N+1);

//   k = 0;

//   rep(i,M) if(uf(L[i],R[i])) arrInsert(k, k, L, L[i], R, R[i], ind, ind[i]);

//   M = k;

// 

//   g.setEdge(N+1, M, L, R, ind);

//   rrep(i,1,N+1) B[i] = if[B[i]!=B[i-1], 1, 0];

// 

//   rep(i,N+1) if(!vis[i]) solve(i);

// 

//   rep(i,N+1) if(B[i]) wt(-1), return 0;

// 

//   sortA(ress,res);

//   wt(ress);

//   wt(res(ress)+1);

// }
