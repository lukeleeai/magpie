#include "stdc++.h"

typedef long long ll;

using namespace std;

const int N = 2e5+10 , M = 5e5+10, OO = 0x3f3f3f3f ,  MOD = 1e9+7;

const double EPS = 1e-3;

#define M_PI 3.14159265358979323846

#define clr(arr,val) memset(arr , val , sizeof (arr))

#define loop(i,n) for(int i = 0;i < int(n);i++)

#define rloop(i,n) for(int i = int(n)-1;i >= 0;i--)

#define range(i,a,b) for(int i = int(a);i <= int(b);i++)

#define pb push_back

#define F first

#define S second

#define all(v) ((v).begin()) , ((v).end())

#define sz(v)  ((int)((v).size()))

typedef pair <int,int> pii ;

typedef vector < pii > vii ;

typedef vector < int > vi;

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction

//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

//freopen("input.txt", "r", stdin);

//freopen("output.txt", "w", stdout);







int n,x;

int a[N],b[N],c[N];

ll dp[N][4];





ll solve(int idx, int preC){ //preColour = (1 : a) -- (2 : b) -- (3 : c) -- (0 : invalid)



    if(idx == n) return 0;



    ll& ret = dp[idx][preC];

    if(~ret) return ret;



    ret = -OO;

    if(preC != 1) ret = max(ret, solve(idx+1 , 1)+a[idx]);

    if(preC != 2) ret = max(ret, solve(idx+1 , 2)+b[idx]);

    if(preC != 3) ret = max(ret, solve(idx+1 , 3)+c[idx]);



    return ret;



}







int main(){





    //ios_base::sync_with_stdio(0);

    //cin.tie(0);cout.tie(0);





    scanf("%d",&n);

    for(int i = 0 ; i < n ; ++i)

        scanf("%d %d %d",a+i,b+i,c+i);



    memset(dp, -1 , sizeof dp);

    ll ans = solve(0 , 0);

    printf("%lld\n",ans);







    return 0;

}
