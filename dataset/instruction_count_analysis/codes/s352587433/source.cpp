#include "stdc++.h"

using namespace std ;

const int N = 2e5 + 10 ;

int a[N] , b[N] , c[N] , d[N] ;

int n , m ;

int h[N * 2] , ne[N * 2] , e[N * 2] , w[N * 2] , vis[N * 2] ;

int idx , use[N] ;

int get(int x)

{

  return lower_bound(d + 1 , d + n + 1 , x) - d ;

}

void add(int a , int b , int c)

{

  e[idx] = b , ne[idx] = h[a] , w[idx] = c ,  h[a] = idx ++ ;

}

int dfs(int u)

{

  vis[u] = 1 ;

  int x = c[u] ;

  for(int i = h[u] ; ~i ; i = ne[i])

   {

     int v = e[i] ;

     if(!vis[v] && dfs(v))

      x ^= 1 , use[w[i]] = 1 ;

   }

  return x ;

}

int main()

{

  for(int i = 0 ;i < N ;i ++) h[i] = -1 ;

  ios::sync_with_stdio(false) ;

  cin.tie(0) , cout.tie(0) ;

  cin >> n >> m ;

  for(int i = 1; i <= n ; i ++) cin >> a[i] >> b[i] , d[i] = a[i] ;

  sort(d + 1 , d + n + 1) ;

  for(int i = 1; i <= n ;i ++)

   c[get(a[i])] = b[i] ;

  for(int i = n + 1; i >= 1 ;i --) c[i] ^= c[i - 1] ;

  for(int i = 1; i <= m ;i ++)

   {

     int l , r ;

     cin >> l >> r ;

     l = get(l) , r = lower_bound(d + 1 , d + n + 1 , r + 1 ) - d  ;



  //   cout << r << " rr " ;



     if(l <= r)

     add(l , r  , i) , add(r  , l , i) ;

   }

   // puts("") ;

   for(int i = 1; i <= n + 1 ;i ++)

    if(!vis[i] && dfs(i))

     {

       cout << -1 << endl ;

       return 0 ;

     }

     int ans =  0 ;

     for(int i = 1; i <= m ;i ++)

      if(use[i]) ans ++ ;

    cout << ans << endl ;

    for(int i = 1;i <= m ;i ++)

     if(use[i])

      cout << i << " " ;

}
