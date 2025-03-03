#include"stdc++.h"

#define il inline

#define stt static

#define rg register

#define ll long long

#define db double

#define pii pair<int,int>

#define mp make_pair

#define fst first

#define snd second

#define pb push_back

#define y1 substitute_of_y1

#define DEBUG(x) cerr<<#x" = "<<x<<endl;

using namespace std;



template<typename T> il T rd(){

	T nmb=0;int sgn=0;char chr=getchar();

	while(!isdigit(chr)){if(chr=='-')sgn=1;chr=getchar();}

	while(isdigit(chr)){nmb=(nmb<<3)+(nmb<<1)+chr-'0';chr=getchar();}

	return sgn?-nmb:nmb;

}

template<typename T> void wt(T nmb){

	if(nmb>9)wt(nmb/10);

	putchar(nmb%10+'0');

}

template<typename T> il void cmax(T &x,T y){x=x>y?x:y;}

template<typename T> il void cmin(T &x,T y){x=x<y?x:y;}

inline void proc_status(){

	ifstream t ("/proc/self/status");

	cerr<<string(istreambuf_iterator<char>(t),istreambuf_iterator<char>())<<endl;

	/*freopen("/proc/self/status","r",stdin);

	char ch[100];

	while(scanf("%s",ch)!=EOF)cerr<<ch<<endl;*/

}



const int L=2e5+10;

const int P=1e9+7;



il int pwr(int x,int y){

	int z=1;

	for(;y;y>>=1,x=(ll)x*x%P)

		if(y&1)z=(ll)z*x%P;

	return z;

}

int fac[L],inv[L];

il void getfac(int n){

	fac[0]=1;

	for(int i=1;i<=n;++i)

		fac[i]=(ll)fac[i-1]*i%P;

	inv[n]=pwr(fac[n],P-2);

	for(int i=n;i;--i)

		inv[i-1]=(ll)inv[i]*i%P;

}

il int C(int n,int m){

	if(n<0||m<0||n<m)return 0;

	return (ll)fac[n]*inv[m]%P*inv[n-m]%P;

}



int F[L];

int get(int x){return x==F[x]?x:F[x]=get(F[x]);}



int To[L<<1],Fs[L],Nx[L<<1],W[L<<1],E;

il void Add(int x,int y,int z){

	To[++E]=y;

	Nx[E]=Fs[x];

	Fs[x]=E;

	W[E]=z;

}



vector<int>vec[L];



int to[L<<1],fs[L],nx[L<<1],w[L<<1],e;

il void add(int x,int y,int z){

	to[++e]=y;

	nx[e]=fs[x];

	fs[x]=e;

	w[e]=z;

}



int st[L],top;

int in[L];



int stx[L],wgt[L],tp;

int num[L],val[L],cnt;

int vis[L];

int Flg;

void findcir(int x,int f){

	stx[++tp]=x,vis[x]=1;

	for(int i=fs[x];i;i=nx[i]){

		int k=to[i];

		if(k==f)continue;

		wgt[tp]=w[i];

		if(!Flg&&vis[k]){

			Flg=1;

			int lb=tp;

			while(stx[lb]!=k)--lb;

			for(int t=lb;t<=tp;++t)

				num[t-lb+1]=stx[t],val[t-lb+1]=wgt[t];

			cnt=tp-lb+1;

		}

		else if(!vis[k])findcir(k,x);

	}

	--tp,vis[x]=0;

}



int Fa[L];

int Vis[L],Wgt[L];

int res;

int ans[L],siz[L];

void dfs(int x,int f){

	siz[x]=ans[x]=1;

	for(int i=fs[x];i;i=nx[i]){

		int k=to[i];

		if(k==f||Vis[k])continue;

		Vis[k]=1,Wgt[k]=w[i];

		if(w[i]<Wgt[x])Fa[k]=x;

		else Fa[k]=0;

		dfs(k,x);

		if(Fa[k]){

			ans[x]=(ll)ans[x]*ans[k]%P*C(siz[x]+siz[k]-1,siz[k])%P;

			siz[x]+=siz[k];

		}

	}

}



il int Pre(int x){return x==1?cnt:x-1;}

il int Nxt(int x){return x==cnt?1:x+1;}



int main(){

	int n=rd<int>();

	int lim=n<<1;

	for(int i=1;i<=lim;++i)F[i]=i;

	for(int i=1;i<=lim;++i){

		int x=rd<int>(),y=rd<int>();

		Add(x,y+n,x+y),Add(y+n,x,x+y);

		F[get(x)]=get(y+n);

	}

	for(int i=1;i<=lim;++i)

		vec[get(i)].pb(i);

	getfac(lim);

	int Ans=1,Sum=0;

	for(int T=1;T<=lim;++T){

		if(vec[T].empty())continue;

		top=0;

		int cnta=(int)vec[T].size(),cntb=0;

		for(int t=vec[T].size()-1;~t;--t){

			int x=vec[T][t];

			st[++top]=x;

			for(int i=Fs[x];i;i=Nx[i]){

				int k=To[i];

				if(get(k)==get(x)){

					++cntb;

					add(x,k,W[i]),++in[k];//反向边在枚举到k时加

				}

			}

		}

		cntb>>=1;

		if(cnta^cntb)return puts("0"),0;





		tp=0,Flg=0;

		findcir(st[1],0);





		int Res=0,Siz=0;

		res=1;

		for(int i=1;i<=cnt;++i)

			Vis[num[i]]=1,Wgt[num[i]]=val[i];

		for(int i=1;i<=cnt;++i)

			dfs(num[i],0);

		for(int i=1;i<=cnt;++i){

			int nxt=Nxt(i);

			if(Wgt[num[i]]<Wgt[num[nxt]])Fa[num[i]]=num[nxt];

			else Fa[num[i]]=0;

		}

		for(int i=1;i<=cnt;++i){

			if(Fa[num[i]])continue;

			for(int k=Nxt(i);Fa[num[k]];k=Nxt(k)){

				int nxt=Nxt(k);

				ans[num[nxt]]=(ll)ans[num[nxt]]*ans[num[k]]%P*C(siz[num[nxt]]+siz[num[k]]-1,siz[num[k]])%P;

				siz[num[nxt]]+=siz[num[k]];

			}

		}

		Siz=0;

		for(int i=1;i<=top;++i){

			if(Fa[st[i]])continue;

			res=(ll)res*ans[st[i]]%P*C(Siz+siz[st[i]],siz[st[i]])%P;

			Siz+=siz[st[i]];

		}

		for(int i=1;i<=top;++i)

			Vis[st[i]]=Wgt[st[i]]=0;

		(Res+=res)%=P;



		res=1;

		for(int i=1;i<=cnt;++i)

			Vis[num[i]]=1,Wgt[num[i]]=i==1?val[cnt]:val[i-1];

		for(int i=1;i<=cnt;++i)

			dfs(num[i],0);

		for(int i=1;i<=cnt;++i){

			int nxt=Pre(i);

			if(Wgt[num[i]]<Wgt[num[nxt]])Fa[num[i]]=num[nxt];

			else Fa[num[i]]=0;

		}

		for(int i=1;i<=cnt;++i){

			if(Fa[num[i]])continue;

			for(int k=Pre(i);Fa[num[k]];k=Pre(k)){

				int nxt=Pre(k);

				ans[num[nxt]]=(ll)ans[num[nxt]]*ans[num[k]]%P*C(siz[num[nxt]]+siz[num[k]]-1,siz[num[k]])%P;

				siz[num[nxt]]+=siz[num[k]];

			}

		}

		Siz=0;

		for(int i=1;i<=top;++i){

			if(Fa[st[i]])continue;

			res=(ll)res*ans[st[i]]%P*C(Siz+siz[st[i]],siz[st[i]])%P;

			Siz+=siz[st[i]];

		}

		for(int i=1;i<=top;++i)

			Vis[st[i]]=Wgt[st[i]]=0;

		(Res+=res)%=P;



		Ans=(ll)Ans*Res%P*C(Sum+cnta,cnta)%P;

		Sum+=cnta;





		for(int i=1;i<=top;++i)

			fs[st[i]]=in[st[i]]=vis[st[i]]=0;//

		e=0;

	}

	printf("%d\n",Ans);

	return 0;

}