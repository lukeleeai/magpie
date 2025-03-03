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

  #define EPS (1e-10)

                                          

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

                                

                int pr[1200010];

                int inv[1200010];

                

                int beki(int wa,int rr,int warukazu){

                	if(rr==0) return 1%warukazu;

                	if(rr==1) return wa%warukazu;

                	wa%=warukazu;

                	if(rr%2==1) return ((ll)beki(wa,rr-1,warukazu)*(ll)wa)%warukazu;

                	ll zx=beki(wa,rr/2,warukazu);

                	return (zx*zx)%warukazu;

                }



                

    			int comb(int nn,int rr){

    				int r=pr[nn]*inv[rr];

    				r%=mod;

    				r*=inv[nn-rr];

    				r%=mod;

    				return r;

    			}

                

                void gya(int ert){

                	pr[0]=1;

                	for(int i=1;i<=ert;i++){

                		pr[i]=(pr[i-1]*i)%mod;

                	}

                		inv[ert]=beki(pr[ert],mod-2,mod);

                	for(int i=ert-1;i>=0;i--){

                		inv[i]=inv[i+1]*(i+1)%mod;

                	}

                }

                

              //   cin.tie(0);

    		//	ios::sync_with_stdio(false);

    			//priority_queue<pa3,vector<pa3>,greater<pa3>> pq;            

                 //sort(ve.begin(),ve.end(),greater<int>());

//    mt19937(clock_per_sec);

  //  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()) ;

      

       

       

                               //----------------kokomade tenpure------------







	



typedef	struct node{

	

		node* rc;

		node* lc;

		int sub_size;

		int val; // これが数列の値

		int mi;

	

	}node;





vector<int> vec;

typedef struct RBST{

 	private:

	public:





	

	

	 unsigned long long ran(){

 		  static unsigned long long x=123456789,y=362436069,z=521288629,w=88675123; 

   			 unsigned long long t; 

  			  t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) ); 

	}

	

	void fix(node *v){

		if(v==NULL) return;

		

		v->sub_size=1;

		if(v->lc!=NULL)v->sub_size+=v->lc->sub_size;

		if(v->rc!=NULL)v->sub_size+=v->rc->sub_size;

		

		// ここに子→親の操作を書く

		

		v->mi=v->val;

		v->mi=min(v->mi,mi(v->lc));

		

		v->mi=min(v->mi,mi(v->rc));

		return;

	}

	

	int siz(node* v){

		return v==NULL ? 0:v->sub_size;

	}

	

	int mi(node* v){

		return v==NULL? inf*100000ll:v->mi;

	}

	

	

	node* init(const vector<int> &vec,int l,int r){

		if(l>=r) return NULL;

		int c=(l+r)/2;

		node* v=new_node(vec[c]);

		

		v->lc = init(vec,l,c);

		v->rc = init(vec,c+1,r);

		fix(v);

		return v;

	}

	

	node* init(const vector<int> &vec){

		int n=vec.size();

		if(n==0) return NULL;

		

		node* v=init(vec,0,n);

		return v;

	}

	

	node* new_node(int val){

		node* no=new node;

		no->val=val;

		no->sub_size=1;

		no->mi=val;

		no->lc=NULL;

		no->rc=NULL;

		return no;

	}

	

	node* merge(node* l,node* r){

		if(l==NULL) return r;

		if(r==NULL) return l;

		

		unsigned int rr=ran();

		//cout<<rr<<endl;

		if(rr%(siz(l)+siz(r)) <(unsigned int )siz(l)){

			l->rc=merge(l->rc,r);

			fix(l);

			return l;

		}

		else{

			r->lc=merge(l,r->lc);

			fix(r);

			return r;

		}

	}

	

	pair<node* , node*> split(node* v,int k){

		if(v==NULL) return {NULL,NULL};

		

		//int n=v->sub_size;

		//[0,k),[k,n)に分割

		//0<=k<=n

		

		if(siz(v->lc) >= k){

			pair<node* , node*> t1 = split(v->lc,k);

			v->lc=t1.second;

			fix(v);

			return {t1.first,v};

			

		}

		else{

			pair<node*,node*> t1 = split(v->rc,k-siz(v->lc) -1);

			v->rc=t1.first;

			fix(v);

			return {v,t1.second};

		}

		

		

	}

	

	node* insert(node* v,int pos,int val){//pos 項目にvalを挿入 戻り値は新しいroot

		pair<node* , node*> t1=split(v,pos);

		

		return merge(t1.first,merge(new_node(val),t1.second));

	}

	

	pair<node*,int> erase(node *v,int pos){//pos項目を削除　戻り値は新しいrootと消した値

		pair<node* , node*> t1=split(v,pos);

		pair<node* , node*> t2=split(t1.second,1);

		return {merge(t1.first,t2.second),t2.first->val};

	}

	

	

	node* access(node *v,int k){

		if(siz(v->lc)==k) return v;

		if(siz(v->lc)>=k)return access(v->lc,k);

		else return access(v->rc,k-siz(v->lc)-1);

	}

	

	int lower_bound(node *root, int val){ //番兵が必要！！！！

		if(root==NULL) return 0;

		if(root->val>=val){

		//	cout<<val<<endl;

			return lower_bound(root->lc,val);

		}

		return 1+lower_bound(root->rc,val)+siz(root->lc);

	}

	

	int upper_bound(node *root, int val){ //番兵が必要！！！！

		if(root==NULL) return 0;

		if(root->val>val) return upper_bound(root->lc,val);

		

		return 1+upper_bound(root->rc,val)+siz(root->lc);

	}



	

	int rangemin(node* &v,int l,int r){

		if(v==NULL) return inf*10000ll;

		

		

		auto t1=split(v,r);

		auto t2=split(t1.first,l);

		int ima=mi(t2.second);

		

		v=merge(merge(t2.first,t2.second),t1.second);

		

		return ima;

	}

	

void update(node *v,int pos,int val){

	if(pos==siz(v->lc)){

		v->val=val;

		

		fix(v);

		return;

	}

	if(pos<siz(v->lc)){

		update(v->lc,pos,val);

		fix(v);

		return;

	}

	else{

		update(v->rc,pos-siz(v->lc)-1,val);

		fix(v);

		return;

	}

	

}

	

	

	

void sequence(node* v){//いまの数列

	

	if(v->lc!=NULL){

		sequence(v->lc);

	}

	//cout<<"   "<<(v->val)<<" "<<mi(v)<<endl;

	vec.pb(v->val);	

	if(v->rc!=NULL){

		sequence(v->rc);

	}

	

	

}

	

}RBST;





RBST R;



 signed main(){

 	



   // 	       cin.tie(0);

   	//		ios::sync_with_stdio(false);



 	int n,q;

 	cin>>n>>q;

 	

 	vector<int> ve(n);

 	for(int i=0;i<n;i++)ve[i]=2147483647;

 	

 	node* root=R.init(ve);

 	

 	for(int i=0;i<q;i++){

 		

 		int c,x,y;

 		cin>>c>>x>>y;

 		

 		if(c){

 			y++;

 			cout<<R.rangemin(root,x,y)<<endl;

 		}

 		else{

 			R.update(root,x,y);

 		}

 		

 	}



 	

 	return 0;

  }

  
