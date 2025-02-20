#include<cstdio>
#include<algorithm>
using namespace std;
bool dp[1000001];
bool isprime(int& x){
  for(int i = 2 ; i * i <= x ; i++ ) if( x % i == 0) return true;
  return false;
}
int solve(int i){
  while(true){ if(dp[i] && !isprime(i)) return i; i--; }
}
int main(){
  int n,x,data[30],ans;
  while(scanf("%d %d",&n,&x) , n){
    for(int i = 0; i <= x; i++) dp[i] = false;
    dp[0] = true;
    for(int i = 0 ; i < n ; i++ ) scanf("%d",&data[i]);
    for(int i = 0 ; i <= x ; i++ ){
      if(dp[i]) for(int j = 0 ; j < n ; j++ )
        if(i + data[j] <= x) dp[i+data[j]] = true;
    }
    if(1 < (ans = solve(x))) printf("%d\n", ans);
    else printf("NA\n");
  }
}
