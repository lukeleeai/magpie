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

	if(cro(b-a,c-a)<-eps) return -1;

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

inline bool iLSex(L l, L s){		//intersect(excluding endpoint)

	return cro(l.sc-l.fs,s.fs-l.fs)*cro(l.sc-l.fs,s.sc-l.fs)<-eps;

}

inline P intLL(L a,L b){

	D t=cro(a.sc-a.fs,a.sc-b.fs)/cro(a.sc-a.fs,b.sc-b.fs);

	return b.fs+t*(b.sc-b.fs);

}

inline Pol convexcut(Pol p,L l){	//left

	Pol ret;

	rep(i,p.size()){

		if(ccw(l.fs,l.sc,p[i])!=-1) ret.pb(p[i]);

		L s=L(p[i],p[(i+1)%p.size()]);

		if(iLSex(l,s)) ret.pb(intLL(l,s));

	}

	return ret;

}

int N;

Pol pol,polc;

P p[100];

bool check(D m){

	rep(i,N){

		P a=p[i],b=p[(i+1)%N];

		P x=(b-a)*P(0,1);

		x=x/abs(x)*m;

		L l=L(a+x,b+x);

		pol=convexcut(pol,l);

	}

	return pol.size()==0;

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

		polc=pol;

		D ub=10000,lb=0;

		rep(tt,40){

			pol=polc;

			D m=(ub+lb)/2;

			if(check(m)) ub=m;

			else lb=m;

		}

		printf("%.12f\n",ub);

	}

}