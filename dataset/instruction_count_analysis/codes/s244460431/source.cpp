// Aimi Haraguni >> Konomi Suzuki >> Yui >>  Ikimono Gakari >> Garnidelia >> Kalafina >> Eir Aoi.   .. dude?

// Ztoking the best of the best

// Kirito >> Naofumi >> Yun Che >> Hao

// .... Sempre Amei Você ...

 

// Sempre amei você

// Mesmo de longe sem te ter

// Você me deu forças para viver

// E ser quem eu queria ser

// 

// 

// Você nunca verá uma menina como ela

// Mais linda em sentimentos que romance de novela

// Bela, ingênua, tipo como cinderela

// Sorte é do homem que estiver ao lado dela

// Guerreira, não compare com as demais

// Lutou muito para cumprir a exigência de seus pais

// Sua força vai além do que cê pensa ser capaz

// Essa menina não desiste daquilo que vai atrás, mas

// Eu fui tão cego pra não ver

// Que apenas ao meu lado ela queria viver

// Enquanto que por outra pessoa eu quis correr

// Ela não desistiu de mim mesmo eu a fazendo sofrer

// Que idiota, como eu não pude perceber?

// Que a menina que me amava estava sempre ali pra ver

// Eu sei que esse sentimento eu não mereço ter

// Mas desta vez eu vou tentar com meus erros aprender

//

// 

// Sempre amei você

// Mesmo de longe sem te ter

// Você me deu forças para viver

// E ser quem eu queria ser

// 

// 

// Ela sempre esteve lá, pra me ajudar

// Quando eu caí, me fez levantar

// Lutei tanto por meu sonho que sempre quis alcançar

// Que acabei ficando cego sem poder enxergar

// Eu nem consegui notar

// Que bem na minha frente era quem deveria amar

// Sempre achei que estava certo e que não podia errar

// Mas só mesmo quando perde pra então valorizar

// E eu perdi, e finalmente entendi

// Que quem eu procurava estava sempre ali

// Levou muito tempo pra ficha cair

// Como eu fui tapado, eu tenho que admitir

// Essa menina conseguiu me surpreender

// Seu olhar estava sempre além do que eu podia ver

// Eu tive que a perder, só pra perceber

// Que ao lado dela é onde eu quero viver

// 

// 

// Sempre amei você

// Mesmo de longe sem te ter

// Você me deu forças para viver

// E ser quem eu queria ser

// 

// 

// Eu tive que a perder

// Pra que pudesse perceber

// Que ao lado dela

// É onde eu quero viver

// Sim, um dia pode ser o fim

// Pode ser tarde demais e tudo acabar assim

// Mas pra ela eu vou dizer

// Não volto com minha palavra

// Com você quero viver

// 

// 

// Sempre amei você

// Mesmo de longe sem te ter

// Você me deu forças para viver

// E ser quem eu queria ser 

 

 

// #pragma GCC optimize ("Ofast,unroll-loops")

// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

 

#include "stdc++.h"

#include<ext/pb_ds/assoc_container.hpp>

 

#define pb push_back

#define ff  first

#define ss second

#define tm1 first

#define tm2 second.first

#define tm3 second.second

#define sz(x) ll(x.size())

#define fill(x, v) memset(x, v, sizeof(x))

#define all(v) (v).begin(), (v).end()

#define FER(i,a,b) for(ll i=ll(a); i< ll(b); ++i)

#define IFR(i,a,b) for(ll i=ll(a); i>=ll(b); --i )

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

 

#define N 6800000

#define kk 550

#define mod1 1000000007

#define mod2 1000000009

#define bas 987625403

#define sqr(x) (x)*(x)  

#define INF 5000000000000000

 

using namespace std;

using namespace __gnu_pbds;

 

typedef long long ll;

typedef pair<ll, ll> ii;

typedef pair<ll, ii > tri;

typedef vector<ll> vi;

typedef vector<ii> vii;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;

 

#define trace(...) f(#__VA_ARGS__, __VA_ARGS__)

 

template<typename t> void f(const char* x, t&& val1){

    cout<<x<< " : "<<val1<<endl;

}

 

template<typename t1, typename... t2> void f(const char* x, t1&& val1, t2&&... val2){

    const char* xd=strchr(x+1, ',');

    cout.write(x, xd-x)<<" : "<<val1<<" | ";

    f(xd+1, val2...);

}



 

struct ST{

	ll n, t[1<<18];

	inline ll Op(ll &val1, ll &val2){

		return val1+val2;

	}

	inline void build(){

		IFR(i, n-1, 1) t[i]=Op(t[i<<1], t[i<<1|1]);

	}

	inline void modify(ll l, ll r, ll val){

		for(l+=n, r+=n; l<r; l>>=1, r>>=1){

			if(l&1) t[l++]+=val;

			if(r&1) t[--r]+=val;

		}

	}

	inline ll que(ll p){

		ll ans=0;

		for(p+=n; p>0; p>>=1) ans+=t[p];

		return ans;

	}

}st;

 

inline tri transform(ll a, ll b, ll n){

	ll lim=(n+1)/2;

	if(n&1){

		if(b<=lim) return {0, {a-1, b-a+1}};

		if(a==lim) return {1, {a, b-a}};

		if(a>lim) return {1, {a-1, b-a+1}};

		ll left=lim-a, right=b-lim;

		if(left==right) return {-1, {a-1, 0}};

		if(left<right){

			ll add=right-left;

			ll idx=b-add;

			return {1, {idx, add}};

		}

		else{

			ll add=left-right;

			return {0, {a-1, add}};

		}	

	}

	else{

		if(b<=lim) return {0, {a-1, b-a+1}};

		if(a>lim) return {1, {a-1, b-a+1}};

		ll left=lim-a+1, right=b-lim;

		if(left==right) return {-1, {a-1, 0}};

		if(left<right){

			ll add=right-left;

			ll idx=b-add;

			return {1, {idx, add}};

		}

		else{

			ll add=left-right;

			return {0, {a-1, add}};

		}

	}

}

 

inline ll check(ll n){

	FER(i,0,(n+1)/2){

		ll t1=st.que(i), t2=st.que(n-1-i);

		if(t1!=t2) return 0;

	}

	return 1;

}



vi queriesL[1<<17], queriesR[1<<17];

vi graph[1<<17];

ll ar[1<<17], vis[1<<17];

inline void dfs(ll u, ll &sum){

	vis[u]++;

	sum+=ar[u];

	for(auto xd: graph[u]) if(!vis[xd]) dfs(xd, sum);

}

int main(){

	fastio;

	string s; cin>>s;

	ll q, n=sz(s); cin>>q;

	st.n=n;

	ar[0]=0, ar[n+1]=0;

	FER(i,0,st.n) {

		ll valor=(s[i]-'a'+0);

		ar[i+1]=valor;

	}

	vi tnt;

	FER(i,0,n+1){

		tnt.pb(ar[i+1]-ar[i]);

		graph[i].pb(n-i);

	}

	FER(i,0,sz(tnt)) ar[i]=tnt[i]%26;

	FER(i,0,q){

		ll a, b; cin>>a>>b;

		tri cur=transform(a, b, n);

		if(cur.tm1==-1) continue;

		ll x=cur.tm2, y=cur.tm3+cur.tm2;

		graph[x].pb(y);

		graph[y].pb(x);

	}

	ll flag=1;

	FER(i,0,n+1) if(!vis[i]){

		ll sum=0;

		dfs(i, sum);

		if(sum%26) flag=0;

	}

	flag? cout<<"YES"<<"\n": cout<<"NO"<<"\n";

	return 0;

}