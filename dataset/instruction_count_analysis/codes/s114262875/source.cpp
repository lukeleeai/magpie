                                #include "stdc++.h"

                                #include<iostream>

                                #include<cstdio>

                                #include<vector>

                                #include<queue>

                                #include<map>

                                #include<cstring>

                                #include<string>

                                #include <math.h>

                                #include<algorithm>

                            //    #include <boost/multiprecision/cpp_int.hpp>

                                #include<functional>

                       #define int long long

                                #define inf  10000000000007

                                #define pa pair<int,int>

                                #define ll long long

                                #define pal pair<double,pa>

                                #define ppa pair<pa,int>

                                #define ppap pair<int,pa>

                                #define ssa pair<string,int>

                                #define  mp make_pair

                                #define  pb push_back

                                #define EPS (1e-10)

                                #define equals(a,b) (fabs((a)-(b))<EPS)

                         

                                using namespace std;

                      

                                class Point{

                                	public:

                                	double x,y;

                                	Point(double x=0,double y=0):x(x),y(y) {}

                                	Point operator + (Point p) {return Point(x+p.x,y+p.y);}

                                	Point operator - (Point p) {return Point(x-p.x,y-p.y);}

                                	Point operator * (double a) {return Point(x*a,y*a);}

                                	Point operator / (double a) {return Point(x/a,y/a);}

                                	double absv() {return sqrt(norm());}

                                	double norm() {return x*x+y*y;}

                                	bool operator < (const Point &p) const{

                                		return x != p.x ? x<p.x: y<p.y;

                                	}

                                	bool operator == (const Point &p) const{

                                		return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;

                                	}

                                };

                                typedef Point Vector;

                         

                                struct Segment{

                                Point p1,p2;

                                };

                                 double dot(Vector a,Vector b){

                                	return a.x*b.x+a.y*b.y;

                                }

                                double cross(Vector a,Vector b){

                                	return a.x*b.y-a.y*b.x;

                                }

                            

    bool parareru(Point a,Point b,Point c,Point d){

    //	if(abs(cross(a-b,d-c))<EPS)cout<<"dd "<<cross(a-b,d-c)<<endl;

    	return abs(cross(a-b,d-c))<EPS;

    }

    double distance_ls_p(Point a, Point b, Point c) {

      if ( dot(b-a, c-a) < EPS ) return (c-a).absv();

      if ( dot(a-b, c-b) < EPS ) return (c-b).absv();

      return abs(cross(b-a, c-a)) / (b-a).absv();

    }

    bool is_intersected_ls(Segment a,Segment b) {

    	if(a.p1==b.p1||a.p2==b.p1||a.p1==b.p2||a.p2==b.p2) return false;

    	if(parareru((a.p2),(a.p1),(a.p1),(b.p2))&&parareru((a.p2),(a.p1),(a.p1),(b.p1))){

    //		cout<<"sss"<<endl;

    		if(dot(a.p1-b.p1,a.p1-b.p2)<EPS) return true;

    		if(dot(a.p2-b.p1,a.p2-b.p2)<EPS) return true;

    		if(dot(a.p1-b.p1,a.p2-b.p1)<EPS) return true;

    		if(dot(a.p1-b.p2,a.p2-b.p2)<EPS) return true;

    		return false;

    	}

      else return ( cross(a.p2-a.p1, b.p1-a.p1) * cross(a.p2-a.p1, b.p2-a.p1) < EPS ) && ( cross(b.p2-b.p1, a.p1-b.p1) * cross(b.p2-b.p1, a.p2-b.p1) < EPS );

    }

     

    double segment_dis(Segment a,Segment b){

    	if(is_intersected_ls(a,b))return 0;

    	double r=distance_ls_p(a.p1, a.p2, b.p1);

    	r=min(r,distance_ls_p(a.p1, a.p2, b.p2));

    	r=min(r,distance_ls_p(b.p1, b.p2, a.p2));

    	r=min(r,distance_ls_p(b.p1, b.p2, a.p1));

    	return r;

    }

    Point intersection_ls(Segment a, Segment b) {

      Point ba = b.p2-b.p1;

      double d1 = abs(cross(ba, a.p1-b.p1));

      double d2 = abs(cross(ba, a.p2-b.p1));

      double t = d1 / (d1 + d2);

     

      return a.p1 + (a.p2-a.p1) * t;

    }

     

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

     

                    double distans(double x1,double y1,double x2,double y2){

                    	double rr=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);

                    	return sqrt(rr);

                    	

                    }

                    /*

    int pr[100010];

    //int inv[100010];

    */ 

    int beki(int wa,int rr,int warukazu){

    	if(rr==0) return 1ll;

    	if(rr==1) return wa%warukazu;

    	if(rr%2==1) return (beki(wa,rr-1,warukazu)*wa)%warukazu;

    	int zx=beki(wa,rr/2,warukazu);

    	return (zx*zx)%warukazu;

    }

      /*

    void gya(){

    	pr[0]=1;

    	for(int i=1;i<100010;i++){

    		pr[i]=(pr[i-1]*i)%inf;

    	}

    	for(int i=0;i<100010;i++) inv[i]=beki(pr[i],inf-2);

    	

    }

     

    */

     //sort(ve.begin(),ve.end(),greater<int>());

                             //----------------kokomade tenpure------------

    //vector<double> ans(100000000),ans2(100000000);

    

    int par[200100],ranks[200100],kosuu[200100];     

     

    void shoki(int n){

    	for(int i=0;i<n;i++){

    		par[i]=i;

    		ranks[i]=0;

    		kosuu[i]=1;

    	}

    }

     

    int root(int x){

    	return par[x]==x ? x : par[x]=root(par[x]);

    }

     

    bool same(int x,int y){

    return root(x)==root(y);

    }

     

    void unite(int x,int y){

     x=root(x);

     y=root(y);

    	int xx=kosuu[x],yy=kosuu[y];

     if(x==y) return;

    	if(ranks[x]<ranks[y]){

    		par[x]=y;

    		kosuu[y]=yy+xx;

    	}

     else {

    	par[y]=x;

    	if(ranks[x]==ranks[y]) ranks[x]=ranks[x]+1;

     	kosuu[x]=yy+xx;

     }

    	return;

    }

    



int a[2000][2000]={0};

int k;



void  nu(int e,int h,int zure){

	

	for(int i=zure;i<zure+k;i++){

		a[e+(i%k)][h+i-zure]=1;

	}

}

int l[200020],r[200020];



int kasa[100030]={0};

int imo[100030]={0};

int sumi[100030]={0};

int rootari[100030]={0};

int ans[100040]={0};



signed main(){

string s;

	cin>>s;

	int len=s.length();

	

	int n;

	cin>>n;

	for(int i=0;i<n;i++) {

		cin>>l[i]>>r[i];

		l[i]--;

		r[i]--;

	}

	for(int i=0;i<len/2;i++){

	//	n++;

		l[n]=i;

		r[n]=len-1-i;

	//	cout<<i<<" "<<len-1-i<<endl;

		n++;

	}

	if(len%2==1){

		l[n]=len/2;

		r[n]=len/2;

		n++;

	}

	

	

//	for(int i=0;i<n;i++) cout<<l[i]<<" "<<r[i]<<endl;

	for(int i=0;i<len/2;i++){

		if(s[i]<=s[len-1-i])kasa[i]= s[len-i-1]-s[i];

		else kasa[len-i-1]=-s[len-i-1]+s[i];

	}

	

	imo[0]=kasa[0];

	for(int i=1;i<=len;i++) imo[i]=kasa[i]-kasa[i-1];

	

//	for(int i=0;i<=len;i++) cout<<imo[i]<<" ";

//	cout<<endl;

	shoki(100020);

//	cout<<"d"<<endl;

	for(int i=0;i<n;i++){

//		cout<<l[i]<<" "<<r[i]+1<<endl;

		unite(l[i],r[i]+1);

	//	cout<<l[i]<<" "<<r[i]+1<<endl;

		sumi[l[i]]=1;

		sumi[r[i]+1]=1;

	}

	

	

	for(int i=0;i<=len;i++){

		ans[root(i)]+=imo[i];

	}

	

	for(int i=0;i<=len;i++) rootari[root(i)]=1;

	

	bool b=true;

	for(int i=0;i<=len;i++){

		if(rootari[i]==0) continue;

//		cout<<ans[i]<<endl;

		if(sumi[i]==0 && (ans[i]%26) !=0) b=false;

		if(sumi[i]==1 &&( ans[i]%26)!=0) b=false;

	}

	

	cout<< (b?"YES":"NO")<<endl;

	

	return 0;

}
