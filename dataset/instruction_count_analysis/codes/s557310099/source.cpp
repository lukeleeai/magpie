#include<cmath>

#include<cstdio>

#include<vector>

#include<algorithm>



#define rep(i,n) for(int i=0;i<(n);i++)



using namespace std;



const double EPS=1e-7;

const double PI=acos(-1);



template<class T>

struct point{

	T x,y;

	point operator+(const point &a)const{ return (point){x+a.x,y+a.y}; }

	point operator-(const point &a)const{ return (point){x-a.x,y-a.y}; }

};



template<class T>

point<T> operator*(T c,const point<T> &a){ return (point<T>){c*a.x,c*a.y}; }



bool operator==(const point<double> &a,const point<double> &b){

	return abs(a.x-b.x)<EPS && abs(a.y-b.y)<EPS;

}



template<class T>

double abs(const point<T> &a){ return sqrt(a.x*a.x+a.y*a.y); }



template<class T>

T cross(const point<T> &a,const point<T> &b){ return a.x*b.y-a.y*b.x; }



point<double> rot(const point<double> &a,double theta){

	return (point<double>){a.x*cos(theta)-a.y*sin(theta),a.x*sin(theta)+a.y*cos(theta)};

}



template<class T>

double arg(const point<T> &a){

	double t=atan2(a.y,a.x);

	return t<0?t+2*PI:t;

}



template<class T>

struct segment{ point<T> a,b; };



enum{CCW=1,CW=-1,ON=0};

int ccw(const point<double> &a,const point<double> &b,const point<double> &c){

	double rdir=cross(b-a,c-a);

	if(rdir> EPS) return CCW;

	if(rdir<-EPS) return CW;

	return ON;

}



template<class T>

double dist(const point<T> &a,const point<T> &b){

	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}



bool cover(const segment<double> &S,const point<double> &p){

	return dist(S.a,p)+dist(p,S.b)<dist(S.a,S.b)+EPS;

}



bool intersect(const segment<double> &S1,const segment<double> &S2){

	if(max(S1.a.x,S1.b.x)+EPS<min(S2.a.x,S2.b.x)

	|| max(S1.a.y,S1.b.y)+EPS<min(S2.a.y,S2.b.y)

	|| max(S2.a.x,S2.b.x)+EPS<min(S1.a.x,S1.b.x)

	|| max(S2.a.y,S2.b.y)+EPS<min(S1.a.y,S1.b.y)) return false;

	return ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b)<=0

		&& ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b)<=0;

}



point<double> get_intersect(const segment<double> &S1,const segment<double> &S2){

	double a1=cross(S1.b-S1.a,S2.b-S2.a);

	double a2=cross(S1.b-S1.a,S1.b-S2.a);

	if(abs(a1)<EPS){

		if(cover(S1,S2.a)) return S2.a;

		if(cover(S1,S2.b)) return S2.b;

		if(cover(S2,S1.a)) return S1.a;

		return S1.b;

	}

	return S2.a+a2/a1*(S2.b-S2.a);

}



int n,m,K;

point<double> P[50]; // 村



point<double> star[50]; // 単位円周を m 等分割した点



vector< pair<double,double> > in; // 点が星の内部にあるか判定するための情報. 星の輪郭の各頂点についての <角度,中心からの距離>

point<double> in2[100]; // 極座標で書かれた in を直交座標に直したもの ( 高速化のため )



void get_intersect(const point<double> *G1,const point<double> *G2,int &sz,point<double> *res){

	segment<double> S1[50],S2[50]; // 星の辺

	rep(i,m){

		S1[i].a=G1[i];

		S1[i].b=G1[(i+K)%m];

		S2[i].a=G2[i];

		S2[i].b=G2[(i+K)%m];

	}

	rep(i,m) rep(j,m) if(intersect(S1[i],S2[j])) res[sz++]=get_intersect(S1[i],S2[j]);

}



bool cover(double R,const point<double> &cen,const point<double> &p){

	if(p==cen) return true;



	double phi=arg(p-cen),d=dist(p,cen);

	if(d>R+EPS) return false;



	if(phi<in[0].first+EPS) phi+=2*PI;

	int i=upper_bound(in.begin(),in.end(),make_pair(phi,0.0))-in.begin()-1;

	return ccw(R*in2[i],R*in2[(i+1)%in.size()],p-cen)!=CW;

}



// p1, p2 : 星の境界上にある二つの村

bool check(double R,const point<double> &p1,const point<double> &p2){

	point<double> G1[50],G2[50]; // 星を上下反転させて, それぞれ p1, p2 が中心に来るように平行移動したもの

	rep(k,m){

		point<double> p=R*(point<double>){star[k].x,-star[k].y};

		G1[k]=p+p1;

		G2[k]=p+p2;

	}



	int sz=0;

	static point<double> Q[50*50]; // 星の中心の候補点

	get_intersect(G1,G2,sz,Q);

	Q[sz++]=(point<double>){0,0}; // これを入れないと間違う



	rep(k,sz){

		bool ok=true;

		rep(l,n) if(!cover(R,Q[k],P[l])) { ok=false; break; }

		if(ok) return true;

	}

	return false;

}



int main(){

	for(;scanf("%d%d%d",&n,&m,&K),n;){

		rep(i,n) scanf("%lf%lf",&P[i].x,&P[i].y);



		rep(i,m) star[i]=rot((point<double>){1,0},2*i*PI/m+PI/2);



		in.clear();

		rep(i,m){

			in.push_back(make_pair(arg(star[i]),abs(star[i])));

			if(K>1){

				segment<double> S1={star[i],star[(i+K)%m]};

				segment<double> S2={star[(i+1)%m],star[(i+1-K+m)%m]};

				point<double> p=get_intersect(S1,S2);

				in.push_back(make_pair(arg(p),abs(p)));

			}

		}

		sort(in.begin(),in.end());

		rep(i,in.size()){

			in2[i].x=in[i].second*cos(in[i].first);

			in2[i].y=in[i].second*sin(in[i].first);

		}



		double ans=5000;

		// p, q が半径 R1 の星の境界として採用できるとしても, 半径 R2(>R1) の星の境界に採用できるかどうかはわからない(と思う)ので多分嘘解法

		rep(i,n) for(int j=i+1;j<n;j++) { // 星の境界上の二点を決めうち

			if(!check(ans+EPS,P[i],P[j])) continue; // 解がよくなる見込みがないので二分探索しない



			double lo=0,hi=ans;

			while(hi-lo>1e-7){

				double mi=(lo+hi)/2;

				if(check(mi,P[i],P[j])) hi=mi; else lo=mi;

			}

			ans=lo;

		}



		printf("%.9f\n",ans);

	}



	return 0;

}