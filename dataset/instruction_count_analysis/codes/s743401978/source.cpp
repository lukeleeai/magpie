#include <iostream>

#include <cstdio>

#include <vector>

#include <set>

#include <map>

#include <queue>

#include <deque>

#include <stack>

#include <algorithm>

#include <cstring>

#include <functional>

#include <cmath>

#include <complex>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)

#define rep1(i,n) for(int i=1;i<=(n);++i)

#define all(c) (c).begin(),(c).end()

#define fs first

#define sc second

#define pb push_back

#define show(x) cout << #x << " " << x << endl

typedef double D;

typedef complex<D> P;

typedef pair<P,P> L;

typedef vector<P> Pol;

D eps=1e-9;

inline D dot(P a,P b){

	return real(conj(a)*b);

}

inline D cro(P a,P b){

	return imag(conj(a)*b);

}

int ccw(P a,P b,P c){

	if(cro(b-a,c-a)>eps) return 1;

	if(abs(abs(a-c)+abs(c-b)-abs(a-b))<eps) return 0;

	return -1;

}

inline P perp(L l,P p){

	D t=dot(p-l.fs,l.fs-l.sc)/norm(l.fs-l.sc);

	return l.fs+t*(l.fs-l.sc);

}

inline bool iSP(L s,P p){

	P a=s.fs,b=s.sc,c=p;

	return abs(abs(a-c)+abs(c-b)-abs(a-b))<eps;

}

inline D dSP(L s,P p){

	P q=perp(s,p);

	return iSP(s,q) ? abs(p-q) : min(abs(p-s.fs),abs(p-s.sc));

}

inline P intLL(L a,L b){

	D t=cro(a.sc-a.fs,a.sc-b.fs)/cro(a.sc-a.fs,b.sc-b.fs);

	return b.fs+t*(b.sc-b.fs);

}

int N;

Pol pol;

P p[100];

bool contain(Pol pol,P p){

	bool in=false;

	rep(i,N){

		P a=pol[i]-p,b=pol[(i+1)%N]-p;

		if(ccw(a,b,P(0,0))==0) return false;

		if(imag(a)>imag(b)) swap(a,b);

		if(imag(a)<=eps && eps<imag(b) && ccw(P(0,0),a,b)==1) in=!in;

	}

	return in;

}

bool check(D m){

	rep(i,N) rep(k,i){

//		show(i);

		P a=p[i],b=p[(i+1)%N],c=p[k],d=p[(k+1)%N];

		P x=(b-a)*P(0,1),y=(d-c)*P(0,1);

		x=x/abs(x)*m,y=y/abs(y)*m;

		L l1=L(a+x,b+x),l2=L(c+y,d+y);

		P q=intLL(l1,l2);

		if(!contain(pol,q)) continue;

		int cnt=0;

		rep(j,N){

//			show(j);

			L l=L(p[j],p[(j+1)%N]);

//			show(dSP(l,q));

//			show(m);

			if(dSP(l,q)+eps<m) cnt++;

		}

//		show(cnt);

		if(cnt==0) return false;

	}

	return true;

}



int main(){

	while(true){

		cin>>N;

		if(N==0) break;

		pol.clear();

		rep(i,N){

			int xx,yy;

			cin>>xx>>yy;

			p[i]=P(xx,yy);

			pol.pb(p[i]);

		}

		D ub=10000,lb=0;

		rep(tt,40){

			D m=(ub+lb)/2;

			if(check(m)) ub=m;

			else lb=m;

		}

//		check(2.0);

/*		if(abs(ub-1.1965)<1e-2){

			cout<<N<<endl;

			rep(i,N){

				cout<<p[i].real()<<" "<<p[i].imag()<<endl;

			}

		}*/

		printf("%.12f\n",ub);

	}

}