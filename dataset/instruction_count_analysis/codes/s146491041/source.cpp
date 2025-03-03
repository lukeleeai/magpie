#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;



typedef long long ll;

const int N = 2e5 + 10, OO = 0x3f3f3f3f, mod = 1e9 + 7;



#define PI acos(-1)

#define clr(arr, val) memset(arr, val, sizeof(arr))

#define loop(i, n) for (int i = 0; i < int(n); i++)

#define rloop(i, n) for (int i = int(n) - 1; i >= 0; i--)

#define xloop(i, a, b) for (int i = int(a); i <= int(b); i++)

#define ALL(v) ((v).begin()), ((v).end())

#define SZ(v) ((int)((v).size()))

//int dx[] = {1, 0, -1, 0};

//int dy[] = {0, 1, 0, -1}; //4 Direction

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};

int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //8 direction

//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction



int n , dp[N];

string s , t;



int solve(int idx){

  if(idx == n)

    return 0;

  int &ret = dp[idx];

  if(~ret) return ret;

  if(s[idx] == t[idx])

    return ret = solve(idx+1);

  ret = OO;

  return ret = min(ret , solve(idx+1)+1);



}



int main()

{

  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);



  cin >> s >> t;

  n = SZ(s);

  memset(dp , -1 , sizeof dp);

  printf("%d\n" , solve(0));



  return 0;

}
