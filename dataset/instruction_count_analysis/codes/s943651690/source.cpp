// #include"stdc++.h"

#include<cmath>

#include<cstdio>

#include<cstring>

#include<algorithm>



using namespace std;

 

typedef long long ll;

#define For(i,x,y) for(int i=x; i<y; ++i)

#define mem(x,y) memset(x,y,sizeof(x))

#define ALL(a) a.begin(),a.end()

#define PII pair<int,int>

#define INF 0x3f3f3f3f

#define DOF 0x7f7f7f7f

#define se second

#define fi first

#define endl '\n'



template <typename T>

inline void read(T &r){

    static char c; r=0; int f=1;

    for(c=getchar(); c<'0'||c>'9'; c=getchar()) if(c=='-')f=-1; 

    for(; c>='0'&&c<='9'; r=(r<<1)+(r<<3)+(c^48),c=getchar());

    r*=f;

} // -_-



const int N = 1e3 + 105;



int main(){

    ll n;

    scanf("%lld", &n);

    printf("%lld\n", (1 + n)*n/2 - n);

    // system("pause");

}