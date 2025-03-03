   #include "stdc++.h"

 

//    #include <boost/multiprecision/cpp_int.hpp>

 #define int long long

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



vector<pa> hoge[300000];

int n;

struct unionfind{

	private:

	public:

	

vector<int> par,ranks,kosuu;

	

	void shoki(int N){

		par.resize(N+1,0);

		ranks.resize(N+1,0);

		kosuu.resize(N+1,1);

		for(int i=0;i<=N;i++){

			par[i]=i;

			hoge[i].pb(mp(i/(n+2),i%(n+2)));

		}

		

	}



	int root(int x){

		return par[x]==x ? x : par[x]=root(par[x]);

	}



	bool same(int x,int y){

		return root(x)==root(y);

	}

	bool is_root(int x){

		return x==root(x);

	}

	void unite(int x,int y){

 		x=root(x);

	 	y=root(y);

		int xx=kosuu[x],yy=kosuu[y];

	 	if(x==y) return;

		if(ranks[x]<ranks[y]){

			par[x]=y;

			kosuu[y]=yy+xx;

			

			while(hoge[x].size()){

				hoge[y].pb(hoge[x].back());

				hoge[x].pop_back();

			}

		}

	 	else {

			par[y]=x;

			if(ranks[x]==ranks[y]) ranks[x]=ranks[x]+1;

	 		kosuu[x]=yy+xx;

	 		

	 		

			while(hoge[y].size()){

				hoge[x].pb(hoge[y].back());

				hoge[y].pop_back();

			}

	 	}

		return;

	}

};





unionfind uf;

int a[510][510]={};

int dis[510][510]={};



int ch(int x,int y){

	return (n+2)*x+y;

}

int sumi[300000]={};

signed main(){

	cin.tie(0);

	ios::sync_with_stdio(false);

	cin>>n;

//	uf.shoki((n+2)*(n+2));

	

	

//	int n;

	

	vector<int>P(n*n);

	for(int i=0;i<n*n;i++)cin>>P[i];

	

	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=1;

	for(int i=0;i<=n+1;i++)for(int j=0;j<=n+1;j++){

			dis[i][j]=min({i,j,n+1-i,n+1-j});

	//	cout<<uf.root(ch(i,j))<<endl;

	}

	/*

	for(int i=0;i<=n;i++){

		uf.unite(ch(0,i),ch(0,i+1));

		uf.unite(ch(n+1,i),ch(n+1,i+1));

		uf.unite(ch(i,0),ch(i+1,0));

		uf.unite(ch(i,n+1),ch(i+1,n+1));

		

	}

	*/

	

	int ans=0;

	

	

	for(int i=1;i<=n*n;i++){

		int r=P[i-1];

		int x=(r-1)/n+1;

		int y=(r-1)%n+1;

	//	cout<<x<<" "<<y<<endl;

		a[x][y]=0;

		queue<pa>qu;

		dis[x][y]--;



		int ne=dis[x][y];

		for(int t=0;t<4;t++){

			int X=x+dx[t];

			int Y=y+dy[t];

			if(X>0 &&Y>0&&X<=n&&Y<=n)if(a[X][Y]==0){

	//			cout<<"!   "<<X<<" "<<Y<<endl;

	//			uf.unite(ch(x,y),ch(X,Y));

	//			cout<<x<<" "<<y<<"  "<<X<<" "<<Y<<endl;

				ne=min(ne,dis[X][Y]);

			}

		}

		

		qu.push(mp(ch(x,y),ne));

		//cout<<ne<<endl;

	//	cout<<x<<" "<<y<<endl;

	//	cout<<"!   "<<uf.root(ch(x,y))<<endl;

		int cnt=0;

		while(qu.size()){

			pa z=qu.front();

			qu.pop();

			if(sumi[z.first]==i)continue;

			sumi[z.first]=i;

			pa v=mp(z.first/(n+2),z.first%(n+2));

			

		//	if(dis[v.first][v.second]==z.second)continue;

			dis[v.first][v.second]=z.second;



			{

				for(int t=0;t<4;t++){

					int X=dx[t]+v.first;

					int Y=dy[t]+v.second;

			//	cout<<X<<" "<<Y<<" "<<z.second+a[X][Y]<<endl;

				if(X>0 &&Y>0&&X<=n&&Y<=n)if(dis[X][Y]>z.second+a[X][Y]){

					qu.push(mp(ch(X,Y),z.second+a[X][Y]));

			//		cout<<"d"<<"   "<<X<<" "<<Y<<endl;

				}

				}

			}

			

			

		

		}

	//	cout<<dis[x][y]<<endl;

		ans+=dis[x][y];

		

		/*

		for(int i=1;i<=n;i++){

			for(int j=1;j<=n;j++)cout<<dis[i][j];

			cout<<endl;

		}

		*/

		

	}

	

	cout<<ans<<endl;



	return 0;

 }
