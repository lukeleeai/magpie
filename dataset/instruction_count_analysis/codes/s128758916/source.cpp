   #include "stdc++.h"

//    #include <boost/multiprecision/cpp_int.hpp>

  //  using namespace boost::multiprecision;

 #define int  long long

 #define inf  1000000007

 #define pa pair<int,int>

 #define ll long long

 #define pal pair<double,double>

  #define PI 3.14159265358979323846

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

                                 

                                int Gcd(int v,int b){

                                	if(v==0) return b;

                                	if(b==0) return v;

                                	if(v>b) return Gcd(b,v);

                                	if(v==b) return b;

                                	if(b%v==0) return v;

                                	return Gcd(v,b%v);

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

                int inv[1000110];

                



                

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







int v[(1<<18)+10];



int w[(1<<18)+10];



bool hikaku(pa x,pa y){

	if(x.second!=y.second)return x.second<y.second;

	return y.first<x.first;

}





vector<pa> ch(vector<pa> ve,int L){

	

	

	

	vector<pa> Q(1);

	Q[0]=mp(0,0);

	

	for(auto v:ve){

		//vector<pa> R;

		

		//for(auto q:Q)if(q.second+v.second<=L)R.pb(v+q);

		

		vector<pa> ima;

		int i=0;

		int j=0;

		int z=Q.size();

		while(1){

			if(i==z && j==z)break;

			else if(i==z){

				ima.pb(Q[j]+v);

				j++;

			}

			else if(j==z){

				ima.pb(Q[i]);

				i++;

			}

			else{

				if(Q[i].second<Q[j].second+v.second || (Q[i].second==Q[j].second+v.second && Q[i].first>Q[j].first+v.first)){

					ima.pb(Q[i]);

					i++;

				}

				else {

					ima.pb(Q[j]+v);

					j++;

				}

			}

			

		}

		while(ima.back().second>L)ima.pop_back();

		swap(ima,Q);

	}

	

	for(int i=1;i<Q.size();i++)Q[i].first=max(Q[i].first,Q[i-1].first);

	return Q;

}



void solve(){

	int t,W;

	cin>>t>>W;

	vector<pa> ve[2];

	int cnt=0;

	while(t>=1){

		ve[cnt].pb(mp(v[t],w[t]));

		cnt^=1;

		t/=2;

	}

	



	

	vector<pa> s1=ch(ve[0],W);

	vector<pa> s2=ch(ve[1],W);

	t=s2.size();

	t--;

	int ans=0;

	for(int i=0;i<s1.size();i++){

		while(s1[i].second+s2[t].second>W)t--;

		ans=max(ans,s1[i].first+s2[t].first);

	}

	cout<<ans<<endl;

}



signed main(){

	cin.tie(0);

	ios::sync_with_stdio(false);



	int n;

	cin>>n;

	for(int i=1;i<=n;i++)cin>>v[i]>>w[i];

	

	int q;

	cin>>q;

	for(int i=0;i<q;i++)solve();

	return 0;

 }