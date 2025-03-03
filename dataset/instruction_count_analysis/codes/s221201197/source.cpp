

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

   string a;

   getline(cin,a);

   int len=a.length() ;

   cout<<a[0];

   for(int i=1;i<len;i++)

   {

       if(a[i]>='A' && a[i]<='Z' && a[i-1]==' ')

       {

           cout<<a[i];

       }

   }

}








