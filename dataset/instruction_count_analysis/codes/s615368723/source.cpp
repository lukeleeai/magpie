

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

  int x1,y1,x2,y2,n,a,b,c;

  x1=0,y1=0;

  cin>>x2>>y2;

  cin>>n;

  for(int i=0;i<n;i++)

  {

      cin>>a>>b>>c;

      if(c==1)

      {

         if(a>x1)

         {

             x1=a;

         }



      }

      else if(c==2)

      {

          if(a<x2)

          {

              x2=a;

          }

      }

      else if(c==3)

      {

          if(b>y1)

          {

              y1=b;

          }

      }

      else if(c==4)

      {

          if(b<y2)

          {

              y2=b;

          }

      }

  }

  int p=x2-x1;

  int q=y2-y1;

  //cout<<p<<" "<<q<<endl;

  if(p<=0 || q<=0)cout<<0;

  else  cout<<p*q;

}








