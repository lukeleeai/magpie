#include "stdc++.h"

#define ll long long

#define INF 1000000005

#define MOD 1000000007

#define EPS 1e-10

#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)

#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)

#define each(a,b) for(auto (a): (b))

#define all(v) (v).begin(),(v).end()

#define len(v) (int)(v).size()

#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())

#define cmx(x,y) x=max(x,y)

#define cmn(x,y) x=min(x,y)

#define fi first

#define se second

#define pb push_back

#define show(x) cout<<#x<<" = "<<(x)<<endl

#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl

#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl

#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl

#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl



using namespace std;



typedef pair<int,int> P;

typedef pair<ll,ll> pll;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef vector<ll> vl;

typedef vector<double> vd;

typedef vector<P> vp;

typedef vector<string> vs;



const int MAX_N = 100005;



//????????°???n

//SCC sc(n);

//sc.comp()??§?????£?????????????§£

//sc.make_graph()??§?????£?????????????§£????????°??????????§????



#define rep(i,n) for(int i=0;i<(int)(n);++i)



class SCC {

public:

	vector<vector<int> > G,rG;

	vector<int> post_order; //??°?????????????????????

	vector<bool> used; //?????§????????????????????????

	vector<int> cmp;	//?±????????????£????????????????????????????????????

	vector<vector<int> > graph;	//?????£?????????????§£????????°??????

	int V,VV;	//?????£?????????????§£?????????????????°

	SCC(int node_size){

		V = node_size;

		G.resize(node_size),rG.resize(node_size),used.resize(node_size,false);

		cmp.resize(node_size);

	}

	void add_edge(int from,int to){

		G[from].push_back(to), rG[to].push_back(from);

	}

	void dfs(int v){

		used[v] = true;

		for(int i=0;i<(int)G[v].size();i++){

			if(!used[G[v][i]]){

				dfs(G[v][i]);

			}

		}

		post_order.push_back(v);

	}

	void rdfs(int v,int k){

		used[v] = true;

		cmp[v] = k;

		for(int i=0;i<(int)rG[v].size();i++){

			if(!used[rG[v][i]]){

				rdfs(rG[v][i],k);

			}

		}

	}

	void solve(){

		fill(used.begin(),used.end(),0);

		post_order.clear();

		for(int v=0;v<V;v++){

			if(!used[v]){

				dfs(v);

			}

		}

		fill(used.begin(),used.end(),0);

		int k=0;

		for(int i=(int)post_order.size()-1;i>=0;i--){

			if(!used[post_order[i]]){

				rdfs(post_order[i],k++);

			}

		}

		VV = k;

	}

	void make_graph(){

		graph.resize(VV);

		rep(i,V){

			rep(j,G[i].size()){

				if(cmp[i] != cmp[G[i][j]]){

					graph[i].push_back(G[i][j]);

				}

			}

		}

	}

};



int main()

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    int n,m;

    cin >> n >> m;

    SCC scc(n);

    rep(i,m){

        int s,t;

        cin >> s >> t;

        scc.add_edge(s,t);

    }

    int q;

    cin >> q;

    scc.solve();

    rep(i,q){

        int u,v;

        cin >> u >> v;

        if(scc.cmp[u] == scc.cmp[v]){

            cout << "1\n";

        }else{

            cout << "0\n";

        }

    }

    return 0;

}