   #include "stdc++.h"

 

//    #include <boost/multiprecision/cpp_int.hpp>

// #define int long long

 #define inf  1000000007

 #define pa pair<int,int>

 #define ll long long

 #define pal pair<double,double>

 #define ppap pair<pa,int>

  #define PI 3.14159265358979323846

  #define paa pair<int,char>

  #define  mp make_pair

  #define  pb push_back

  #define EPS (1e-8)

                                          

    int dx[8]={0,1,0,-1,1,1,-1,-1};

    int dy[8]={1,0,-1,0,-1,1,1,-1};

                                            using namespace std;

                                   			class pa3{

                                            	public:

                                            	int x;

                                   				int y,z;

                                            	pa3(int x=0,int y=0,int z=0):x(x),y(y),z(z) {}

                                            	bool operator < (const pa3 &p) const{

                                            		if(x!=p.x) return x<p.x;

                                            		if(y!=p.y) return y<p.y;

                                            		 return z<p.z;

                                            		//return x != p.x ? x<p.x: y<p.y;

                                            	}

                                   				bool operator > (const pa3 &p) const{

                                            		if(x!=p.x) return x>p.x;

                                            		if(y!=p.y) return y>p.y;

                                            		 return z>p.z;

                                            		//return x != p.x ? x<p.x: y<p.y;

                                            	}

                                            	bool operator == (const pa3 &p) const{

                                            		return x==p.x && y==p.y && z==p.z;

                                            	}

                                            		bool operator != (const pa3 &p) const{

                                            			return !( x==p.x && y==p.y && z==p.z);

                                            	}

                                            

                                            };

                                            

                                            class pa4{

                                            	public:

                                            	int x;

                                            	int y,z,w;

                                            	pa4(int x=0,int y=0,int z=0,int w=0):x(x),y(y),z(z),w(w) {}

                                            	bool operator < (const pa4 &p) const{

                                            		if(x!=p.x) return x<p.x;

                                            		if(y!=p.y) return y<p.y;

                                            		if(z!=p.z)return z<p.z;

                                            		return w<p.w;

                                            		//return x != p.x ? x<p.x: y<p.y;

                                            	}

                                            	bool operator > (const pa4 &p) const{

                                            		if(x!=p.x) return x>p.x;

                                            		if(y!=p.y) return y>p.y;

                                            		if(z!=p.z)return z>p.z;

                                            		return w>p.w;

                                            		//return x != p.x ? x<p.x: y<p.y;

                                            	}

                                            	bool operator == (const pa4 &p) const{

                                            		return x==p.x && y==p.y && z==p.z &&w==p.w;

                                            	}

                                            		

                                            

                                            };

                                            class pa2{

                                            	public:

                                            	int x,y;

                                            	pa2(int x=0,int y=0):x(x),y(y) {}

                                            	pa2 operator + (pa2 p) {return pa2(x+p.x,y+p.y);}

                                            	pa2 operator - (pa2 p) {return pa2(x-p.x,y-p.y);}

                                            	bool operator < (const pa2 &p) const{

                                            		return y != p.y ? y<p.y: x<p.x;

                                            	}

                                            	bool operator > (const pa2 &p) const{

                                            		return x != p.x ? x<p.x: y<p.y;

                                            	}

                                            	bool operator == (const pa2 &p) const{

                                            		return abs(x-p.x)==0 && abs(y-p.y)==0;

                                            	}

                                            	bool operator != (const pa2 &p) const{

                                            		return !(abs(x-p.x)==0 && abs(y-p.y)==0);

                                            	}

                                            		

                                            

                                            };

                                            

 

                      

                                string itos( int i ) {

                                ostringstream s ;

                                s << i ;

                                return s.str() ;

                                }

                                 

                                int gcd(int v,int b){

                                	if(v==0) return b;

                                	if(b==0) return v;

                                	if(v>b) return gcd(b,v);

                                	if(v==b) return b;

                                	if(b%v==0) return v;

                                	return gcd(v,b%v);

                                }

                 

                            

                                int mod;

int extgcd(int a, int b, int &x, int &y) {

    if (b == 0) {

        x = 1;

        y = 0;

        return a;

    }

    int d = extgcd(b, a%b, y, x);

    y -= a/b * x;

    return d;

}

pa operator+(const pa & l,const pa & r) {   

    return {l.first+r.first,l.second+r.second};                                    

}    

pa operator-(const pa & l,const pa & r) {   

    return {l.first-r.first,l.second-r.second};                                    

}  

                int beki(int wa,int rr,int warukazu){

                	if(rr==0) return 1%warukazu;

                	if(rr==1) return wa%warukazu;

                	wa%=warukazu;

                	if(rr%2==1) return ((ll)beki(wa,rr-1,warukazu)*(ll)wa)%warukazu;

                	ll zx=beki(wa,rr/2,warukazu);

                	return (zx*zx)%warukazu;

                }

 

                              

                int pr[1000100];

                int inv[1000010];

                



                

    			int comb(int nn,int rr){

    				if(rr<0 || rr>nn || nn<0) return 0;

    				int r=pr[nn]*inv[rr];

    				r%=mod;

    				r*=inv[nn-rr];

    				r%=mod;

    				return r;

    			}

               

                void gya(int ert){

                	pr[0]=1;

                	for(int i=1;i<=ert;i++){

                		pr[i]=((ll)pr[i-1]*i)%mod;

                	}

                		inv[ert]=beki(pr[ert],mod-2,mod);

                	for(int i=ert-1;i>=0;i--){

                		inv[i]=(ll)inv[i+1]*(i+1)%mod;

                	}

                }

                

              //   cin.tie(0);

    		//	ios::sync_with_stdio(false);

    			//priority_queue<pa3,vector<pa3>,greater<pa3>> pq;            

                 //sort(ve.begin(),ve.end(),greater<int>());

 //   mt19937(clock_per_sec);

  //  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()) ;

bool hikaku(pa x,pa y){

	if(x.second!=y.second)return x.second<y.second;

	return y.first<x.first;

}







vector<pa> ve[30];



int v[(1<<18)+10]={};



int w[(1<<18)+10]={};





const int D=9;

vector<pa> que[(1<<18)+10];

int ans[200020];

void dfs(int r,int dep,int n){

	if(r>n)return;

	if(dep==D+1){

		ve[dep].clear();

		ve[dep].pb(mp(0,0));

		ve[dep].pb(mp(v[r],w[r]));

		

	}

	else{

		vector<pa> tmp;

		for(auto vv:ve[dep-1])if(vv.second+w[r]<=100000)tmp.pb(vv+mp(v[r],w[r]));

		ve[dep].clear();

		int i=0,j=0;

		while(1){

			if(i==(int) ve[dep-1].size() &&j==(int) tmp.size()  )break;

			else if(i==(int) ve[dep-1].size()){

				ve[dep].pb(tmp[j]);

				j++;

			}

			else if(j==(int) tmp.size()){

				ve[dep].pb(ve[dep-1][i]);

				i++;

			}

			else{

				if(ve[dep-1][i].second < tmp[j].second || (ve[dep-1][i].second == tmp[j].second && ve[dep-1][i].first >= tmp[j].first) ){

					ve[dep].pb(ve[dep-1][i]);

					i++;

				}

				else{

					ve[dep].pb(tmp[j]);

				j++;

				}

			}

		}

		//cout<<ve[dep].size()<<endl;

	}

	for(int i=1;i<(int)ve[dep].size();i++)ve[dep][i].first=max(ve[dep][i].first,ve[dep][i-1].first);

	

	for(auto q:que[r]){

		if(dep<=D){

			int f=0;

			for(auto v:ve[dep])if(v.second<=q.second)f=max(f,v.first);

			ans[q.first]=f;

		}

		else{

			int e=ve[dep].size();

			e--;

			int f=0;

			for(auto vv:ve[D])if(vv.second<=q.second){

				while(ve[dep][e].second+vv.second>q.second)e--;

				f=max(f,ve[dep][e].first+vv.first);

			}

			ans[q.first]=f;

		}

	}

	dfs(2*r,dep+1,n);

	dfs(2*r+1,dep+1,n);

	

}



signed main(){

	cin.tie(0);

	ios::sync_with_stdio(false);

	

	//const int d=9;

	int n;

	cin>>n;

	for(int i=1;i<=n;i++)cin>>v[i]>>w[i];

	ve[0].pb(mp(0,0));

	int q;

	cin>>q;

	for(int i=0;i<q;i++){

		int t,W;

		cin>>t>>W;

		que[t].pb(mp(i,W));

	}

	

	dfs(1,1,n);

	for(int i=0;i<q;i++)cout<<ans[i]<<endl;

	

	

	return 0;

 }
