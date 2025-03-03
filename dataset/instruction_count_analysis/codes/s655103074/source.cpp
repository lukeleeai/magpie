#include"stdc++.h"

#define F(i,a,b) for(int i=a;i<=(b);++i)

#define F2(i,a,b) for(int i=a;i<(b);++i)

#define dF(i,a,b) for(int i=a;i>=(b);--i)

#define dF2(i,a,b) for(int i=a;i>(b);--i)

#define eF(i,u) for(int i=h[u];i;i=nxt[i])

#define ll long long

#define ld double

using namespace std;



ll Sx,Sy,Tx,Ty;

ll ansi,ansp=0;

int n,cnt,P[200001],Ans;

ll x[200001],y[200001];

ll X[200001],Y[200001],tmp[200001];

ll t[200001];

inline bool cmp(int p1,int p2){return X[p1]<X[p2];}



inline int BS(ll k){

	int l=0,r=cnt,mid,ans;

	while(l<=r){

		mid=l+r>>1;

		if(tmp[mid]>k) ans=mid, l=mid+1;

		else r=mid-1;

	}

	return ans;

}



int main(){

	scanf("%lld%lld%lld%lld",&Sx,&Sy,&Tx,&Ty);

	ansi=abs(Sx-Tx)+abs(Sy-Ty); ansi*=10;

	scanf("%d",&n);

	F(i,1,n) scanf("%lld%lld",x+i,y+i);

	if(Sx==Tx){

		if(Sy>Ty) swap(Sy,Ty);

		F(i,1,n) if(x[i]==Sx&&Sy<y[i]&&y[i]<Ty) ansi-=2, ansp+=10;

		printf("%.15lf",10.*ansi+acos(-1)*ansp); return 0;

	}

	if(Sy==Ty){

		if(Sx>Tx) swap(Sx,Tx);

		F(i,1,n) if(y[i]==Sy&&Sx<x[i]&&x[i]<Tx) ansi-=2, ansp+=10;

		printf("%.15lf",10.*ansi+acos(-1)*ansp); return 0;

	}

	if(Sx>Tx) swap(Sx,Tx), swap(Sy,Ty);

	if(Sy<Ty)

		F(i,1,n) if(Sx<=x[i]&&x[i]<=Tx&&Sy<=y[i]&&y[i]<=Ty) X[++cnt]=x[i], Y[cnt]=y[i], P[cnt]=cnt;

	if(Sy>Ty)

		F(i,1,n) if(Sx<=x[i]&&x[i]<=Tx&&Ty<=y[i]&&y[i]<=Sy) X[++cnt]=x[i], Y[cnt]=y[i], P[cnt]=cnt;

	F(i,1,cnt) t[i]=Y[i];

	sort(t+1,t+cnt+1);

	F(i,1,cnt) Y[i]=lower_bound(t+1,t+cnt+1,Y[i])-t;

	sort(P+1,P+cnt+1,cmp);

	if(Sy<Ty){

		memset(tmp,0x3f,sizeof tmp);

		tmp[0]=0;

		F(i,1,cnt){

			int k=lower_bound(tmp,tmp+cnt+1,Y[P[i]])-tmp;

			tmp[k]=min(tmp[k],Y[P[i]]);

			Ans=max(Ans,k);

		}

		if(Ans==min(abs(Sx-Tx),abs(Sy-Ty))+1) printf("%.15lf",10.*(ansi-2*Ans)+acos(-1)*5*Ans+5*acos(-1));

		else printf("%.15lf",10.*(ansi-2*Ans)+acos(-1)*5*Ans);

	}

	else{

		tmp[0]=0x3f3f3f3f;

		F(i,1,cnt){

			int k=BS(Y[P[i]]);

			tmp[k+1]=max(tmp[k+1],Y[P[i]]);

			Ans=max(Ans,k+1);

		}

		if(Ans==min(abs(Sx-Tx),abs(Sy-Ty))+1) printf("%.15lf",10.*(ansi-2*Ans)+acos(-1)*5*Ans+5*acos(-1));

		else printf("%.15lf",10.*(ansi-2*Ans)+acos(-1)*5*Ans);

	}

	return 0;

}