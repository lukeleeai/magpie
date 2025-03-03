#include<iostream>

#include<set>

#include<algorithm>

#include<cmath>

#include<cstdio>

#include<cassert>

#include<climits> 



#define REP(i,s,n) for(int i=s;i<n;i++)

#define rep(i,n) REP(i,0,n)

#define inf (1<<29)

#define MAX 300002

 

using namespace std;

typedef unsigned long long ull;



ull extgcd(ull a,ull b,ull& x,ull& y)

{

  ull d = a;

  if(b != 0){

    d = extgcd(b,a%b,y,x);

    y -= (a/b)*x;

  }

  else

    x = 1,y = 0;

  return d;

}



ull mod_inv(ull a,ull m)

{

  ull x,y;

  extgcd(a,m,x,y);

  return (m+x%m)%m;

}





int n,m,L,R,keta;

char s[MAX],o[5];

set<ull> ans;

const ull B = 9973ULL;

const ull inv = 9063375710536127837ULL;

//const ull B = 973;

ull H,Bmax[MAX];



 



int main()

{

 

  //cout << ULLONG_MAX << endl;

  //cout << mod_inv(1000000007ULL,18446744073709551615ULL) << endl; 



  Bmax[0] = 1ULL;

  REP(i,1,MAX)Bmax[i] = Bmax[i-1] * B;

  L = R = keta = 0;

  scanf("%d %d",&n,&m);

  scanf("%s",&s[0]);

  H = s[0];





  rep(_,m)

    {

      scanf("%s",&o[0]);

 

      if(o[0] == 'R')

	{

	  if(o[1] == '+')

	    {

	      H = H * B + s[++R];

	    }

	  else

	    {

	      //H = (H - s[R--]) * invB;

	      H = (H - s[R--]) * inv;

	    }

	}

      else

	{

	  if(o[1] == '+')

	    {

	      H = H - Bmax[R-L] * s[L++];

	    }

	  else

	    {

	      H = H + Bmax[R+1-L] * s[L-1];

	      L--;

	    }

	}

      /*

	cout << "Bmax = " << Bmax << endl;

	cout << "[" << L << "," << R << "]" << endl;

	cout << "s : ";

	REP(i,L,R+1)cout << s[i];

	cout << endl;

	cout << "hash : " << H << endl;

      */

      ans.insert(H);

    } 

  

  cout << ans.size() << endl;

 

  return 0;

}