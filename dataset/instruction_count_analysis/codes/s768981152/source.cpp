

#include<iostream>

#include<set>

#include<algorithm>

#include<cmath>

#include<cstdio>

#include<cassert>

 

#define REP(i,s,n) for(int i=s;i<n;i++)

#define rep(i,n) REP(i,0,n)

#define inf (1<<29)

#define MAX 300001

 

using namespace std;

typedef unsigned long long ull;

int n,m,L,R;

char s[MAX],o[5];

set<ull> ans;

const ull B = 9973ULL;

const ull inv = 9063375710536127837ULL;

ull H,Bmax;

 

int main()

{

 

  Bmax = 1;

  L = R = 0;

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

	      R++;

	      Bmax *= B;

	      H = H + s[R]*Bmax; 

	    }

	  else

	    {

	      H = H - s[R]*Bmax;

	      Bmax = Bmax*inv;

	      R--;

	    }

	}

      else

	{

	  if(o[1] == '+')

	    {

	      H = (H-s[L])*inv;

	      Bmax *= inv;

	      L++;

	    }

	  else

	    {

	      L--;

	      H = H * B + s[L];

	      Bmax *= B;

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