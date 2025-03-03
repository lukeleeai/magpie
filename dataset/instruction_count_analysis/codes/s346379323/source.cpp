

#include"stdc++.h"

#define lln long long int

#define llu unsigned lln

#define sc(n) scanf("%d",&n);

#define scl(n) scanf("%lld",&n);

#define scd(n) scanf("%lf",&n);

#define pf(res) printf("%d\n",res);

#define pfl(res) printf("%lld\n",res);

#define pfd(res) printf("%lf\n",res);

#define maxii 200005

using namespace std;

typedef pair<int,int> pii;

typedef pair<lln,lln> pll;

 vector<int> vi[maxii];

 vector<int>::iterator child;

typedef vector<lln> vl;

typedef vector<pii> vii;

typedef vector<pll> vll;





int arr[maxii];

int arr2[maxii];





int main()

{

    lln a,b,x;

    cin>>a>>b>>x;

    lln res1=a/x;

    lln res2=b/x;

    lln res=res2-res1;

    if(a%x==0)res++;

    cout<<res;



}








