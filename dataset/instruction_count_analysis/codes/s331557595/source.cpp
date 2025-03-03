#pragma GCC optimize("Ofast")

#include <cassert>

#include <cstdio>

#include <cstdlib>

#include <string>

#include <algorithm>

#include <iostream>

#include <queue>

#include <vector>

#include <bitset>

#include <cmath>

#include <limits>

#include <iostream>

#include <map>

#include <set>

#include <stack>

#include <tuple>

#include <iomanip>

#include <functional>

#include <complex>



using namespace std;



using ll=long long int;

using pii=pair<int,int>;

using pil=pair<int,ll>;

using pli=pair<ll,int>;

using pll=pair<ll,ll>;

using psi=pair<string,int>;

using pis=pair<int,string>;

using psl=pair<string,ll>;

using pls=pair<ll,string>;

using pss=pair<string,string>;



//辺 fromあり

template<typename T >

struct Edge {

  int from, to;

  T cost;



  Edge()=default;

  Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}



  inline bool operator<(const Edge p)const noexcept{

    return cost<p.cost;

  }



  inline bool operator>(const Edge p)const noexcept{

    return cost>p.cost;

  }



};





//辺 fromがない

template<typename T >

struct edge {

  int to;

  T cost;

  edge()=default;

  edge(int to, T cost) : to(to), cost(cost) {}

};

template<typename T>

using edges=vector<edge<T>>;

template<typename T>

using WeightGraph=vector<edges<T>>;



using Graph=vector<vector<int>>;







template<typename T> using vc=vector<T>;

template<typename T> using vvc=vector<vector<T>>;

template<typename T> using vvvc=vector<vector<vector<T>>>;

template<typename T> using vvvvc=vector<vvvc<T>>;

template<typename T> using vvvvvc=vector<vvvvc<T>>;



template<class T,class U>inline constexpr bool chmin(T&a,const U b){if(a<=b)return false;a=b;return true;}

template<class T,class U>inline constexpr bool chmax(T&a,const U b){if(a>=b)return false;a=b;return true;}

#define bit(n,k) ( (n>>k)&1 )



inline void bin101(){

    ios::sync_with_stdio(false);

    cin.tie(nullptr); 

    cout<<fixed<<setprecision(20);

}



template<typename T>

inline void Yes(T flag){

    if(flag) cout<<"Yes"<<endl;

    else cout<<"No"<<endl;

}



template<typename T>

inline void YES(T flag){

    if(flag) cout<<"YES"<<endl;

    else cout<<"NO"<<endl;

}



//1-indexed vector cin

template<typename T>

inline void vin1(vector<T> &v){

    for(int i=1;i<v.size();i++) cin>>v[i];

}



//0-indexed vector cin

template<typename T>

inline void vin0(vector<T> &v){

    for(int i=0;i<v.size();i++) cin>>v[i];

}



//1-indexed vector<vector> cin

template<typename T>

inline void vin1(vector<vector<T>> &v){

    for(int i=1;i<v.size();i++){

        for(int j=1;j<v[i].size();j++) cin>>v[i][j];

    }

}



//0-indexed vector<vector> cin

template<typename T>

inline void vin0(vector<vector<T>> &v){

    for(int i=0;i<v.size();i++){

        for(int j=0;j<v[i].size();j++) cin>>v[i][j];

    }

}







//デバッグ

template<typename T>

inline void vout(const vector<T> &v){

    cout<<"\nstart\n";

    const int sz=v.size();

    for(int i=0;i<sz;i++){

        cout<<i<<" "<<v[i]<<'\n';

    }

    cout<<"end\n"<<endl;

}

//デバッグ

template<typename T>

inline void vout(const vvc<T> &v){

    cout<<"\nstart\n";

    const int sz=v.size();

    for(int i=0;i<sz;i++){

        int ssz=v[i].size();

        for(int j=0;j<ssz;j++){

            cout<<i<<" "<<j<<" "<<v[i][j]<<'\n';

        }

    }

    cout<<"\nend\n"<<endl;

}



//デバッグ(グリッド)

template<typename T>

inline void gvout(const vector<T> &v){

    cout<<"\nstart\n";

    const int sz=v.size();

    for(int i=0;i<sz;i++){

        if(i) cout<<" ";

		cout<<v[i];

    }

    cout<<"\nend\n"<<endl;

}

//デバッグ(グリッド)

template<typename T>

inline void gvout(const vvc<T> &v){

    cout<<"\nstart\n";

    const int sz=v.size();

    for(int i=0;i<sz;i++){

        int ssz=v[i].size();

        for(int j=0;j<ssz;j++){

			if(j) cout<<" ";

            cout<<v[i][j];

        }

		cout<<endl;

    }

    cout<<"end\n"<<endl;

}





//デバッグ

template<typename T>

inline void vout(const vvvc<T> &v){

    cout<<"\nstart\n";

    const int sz=v.size();

    for(int i=0;i<sz;i++){

        int ssz=v[i].size();

        for(int j=0;j<ssz;j++){

            int sssz=v[i][j].size();

            for(int k=0;k<sssz;k++){

                cout<<i<<" "<<j<<" "<<k<<" "<<v[i][j][k]<<'\n';

            }

        }

    }

    cout<<"end\n"<<endl;

}





//pair cout

template<typename T, typename U>

inline ostream &operator<<(ostream &os,const pair<T,U> &p) {

  os<<p.first<<" "<<p.second;

  return os;

}



//pair cin

template<typename T, typename U>

inline istream &operator>>(istream &is,pair<T,U> &p) {

  is>>p.first>>p.second;

  return is;

}



//ソート

template<typename T>

inline void vsort(vector<T> &v){

    sort(v.begin(),v.end());

}



//逆順ソート

template<typename T>

inline void rvsort(vector<T> &v){

  sort(v.rbegin(),v.rend());

}



//要素数a 初期値x

template<typename T>

inline vector<T> vmake(int a,T x){

  return vector<T>(a,x);

}



//data[a][b] 初期値x

template<typename T>

inline vector<vector<T>> vmake(int a,int b,T x){

  return vector<vector<T>>(a, vector<T>(b,x));

}



//data[a][b][c] 初期値x

template<typename T>

inline vector<vector<vector<T>>> vmake(int a,int b,int c,T x){

  return vector<vector<vector<T>>> (a, vector<vector<T>>(b, vector<T>(c, x)));

}



//data[a][b][c][d]　初期値x

template<typename T>

inline vector<vector<vector<vector<T>>>> vmake(int a,int b,int c,int d,T x){

  return vector<vector<vector<vector<T>>>> (a,vvvc<T>(b,vvc<T>(c,vc<T>(d,x))));

}



//data[a][b][c][d][e] 初期値x

template<typename T>

inline vvvvvc<T> vmake(int a,int b,int c,int d,int e,T x){

  return vvvvvc<T> (a,vvvvc<T>(b,vvvc<T>(c,vvc<T>(d,vc<T>(e,x)))));

}



//1ビットの数を返す

inline int popcount(int x){

  return __builtin_popcount(x);

}

//1ビットの数を返す

inline int popcount(ll x){

  return __builtin_popcountll(x);

}



//queのfront() pop()

template<typename T>

inline T pop(queue<T> &que){

    T x=que.front();

    que.pop();

    return x;

}



//priority_que top() pop()

template<typename T>

inline T pop(priority_queue<T> &que){

  T x=que.top();

  que.pop();

  return x;

}



//stack top() pop()

template<typename T>

inline T pop(stack<T> &st){

  T x=st.top();

  st.pop();

  return x;

}



#define SZ(x) ( (int)x.size()  )

#define pb push_back

#define ep emplace_back



/*

満たすものの個数を返す

mode:0 x未満

mode:1 x以下の数

mode:2 x以上の数

mode:3 x超

mode:4 x

*/

template<typename T>

inline int count_bound(vector<T> &v,T x,int mode){

    switch(mode){

        case 0:

            return lower_bound(v.begin(),v.end(),x)-v.begin();

        case 1:

            return upper_bound(v.begin(),v.end(),x)-v.begin();

        case 2:

            return v.end()-lower_bound(v.begin(),v.end(),x);

        case 3:

            return v.end()-upper_bound(v.begin(),v.end(),x);

        case 4:

            return upper_bound(v.begin(),v.end(),x)-lower_bound(v.begin(),v.end(),x);

    }

}



/*

mode:0 xより小さい数で最大の数

mode:1 x以下の数で最大の数

mode:2 x以上の数で最小の数

mode:3 xより大きい数で最小の数

*/

template<typename T>

inline T value_bound(vector<T> &v,T x,int mode){

    switch(mode){

        case 0:

            return *(--lower_bound(v.begin(),v.end(),x));

        case 1:

            return *(--upper_bound(v.begin(),v.end(),x));

        case 2:

            return *lower_bound(v.begin(),v.end(),x);

        case 3:

            return *upper_bound(v.begin(),v.end(),x);

    }

}







constexpr int MAX=1<<30;

constexpr ll MOD=1e9+7;

constexpr int dx[]={1,-1,0,0},dy[]={0,0,-1,1};



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



using DD=double;





#define EPS 1e-10

#define eq(a,b) (abs( (a) - (b) )<EPS)

const DD PI=acosl(-1.0);

constexpr DD INF=1LL<<62;



//点

using P=complex<DD>;

//ベクトル

using V=P;

//線分

struct Segment{

    P a,b;

    Segment()=default;

    Segment(P a,P b) :a(a),b(b){}

    Segment(DD ax,DD ay,DD bx,DD by):a(ax,ay),b(bx,by){}

    Segment(DD r,P a) :a(a),b(a+polar(1.0,r)){} 



};

//直線

using Line=Segment;

//円

struct Circle{

    P p;

    DD r;

    Circle()=default;

    Circle(P p,DD r):p(p),r(r){}

};

using Polygon=vector<P>;



//++++++++++++++++基本計算++++++++++++++//

inline DD torad(const DD &deg){return deg*PI/180;}

inline DD todeg(const DD &rad){return rad*180/PI;}

//内積

inline DD dot(const V &a,const V &b){

    return real(a*conj(b));

}

//外積

inline DD cross(const V &a,const V &b){

    return imag(conj(a)*b);

}

//ベクトルvを反時計回りにr度回転

inline V rotate(const V &v,const DD r){

    return v*V(cos(r),sin(r));

}

inline bool xy(const P &a,const P &b){

    if(real(a)+EPS<=real(b)) return true;

    if(eq(real(a),real(b)) && imag(a)+EPS<imag(b)) return true;

    return false;

}

inline bool yx(const P &a,const P &b){

    if(imag(a)+EPS<imag(b)) return true;

    if(eq(imag(a),imag(b)) && real(a)+EPS<real(b)) return true;

    return false;

}



//++++++++++++++++平行や直交+++++++++++++++//

inline bool isOrthogonal(const V &a,const V &b){

    return eq(dot(a,b),0.0);

}

inline bool isOrthogonal(const Segment &a,const Segment &b){

    return eq(dot(a.a-a.b,b.a-b.b),0);

}

inline bool isParallel(const V &a,const V &b){

    return eq(cross(a,b),0.0);

}

inline bool isParallel(const Segment &a,const Segment &b){

    return eq(cross(a.a-a.b,b.a-b.b),0);

}

//線分a-bに対してcがどの位置にあるか

//ccwの簡略版 反時計回り:1 時計回り:-1 直線上:0

inline int ccw(const P &a,const P &b,const P &c){

    DD cr=cross(b-a,c-a);

    if(cr>EPS) return 1;

    if(cr<-EPS) return -1;

    return 0;

}



//線分a-bに対してcがどの位置にあるか

//反時計回り:1　時計回り:-1 直線上(a,b,c:-2 a,c,b:0 c,a,b:2) 

inline int ccwH(P a,P b,P c){

    b-=a;c-=a;

    if(cross(b,c)>EPS) return 1;

    if(cross(b,c)<-EPS) return -1;

    if(dot(b,c)<-EPS) return 2;

    if(norm(b)<norm(c)) return -2;

    return 0;

}





//+++++++++++++++射影+++++++++++++++++++++//

inline P project(const P &p,const Segment &s){

    V base=s.b-s.a;

    DD r=dot(p-s.a,base)/norm(base);

    return s.a+base*r;

}

inline P reflect(const P &p,const Segment &s){

    return p+(project(p,s)-p)*2.0;

}

/*++++++++++点との距離++++++++++++++++++*/

//点と直線の距離

inline DD dis(const P &p,const Line &l){return abs(cross(l.b-l.a,p-l.a))/abs(l.b-l.a);}

//点と線分の距離

inline DD disPS(const P &p,const Segment &s){

    if( dot(s.b-s.a,p-s.a)<0.0 ) return abs(p-s.a);

    if( dot(s.a-s.b,p-s.b)<0.0 ) return abs(p-s.b);

    return dis(p,s); //点と直線の距離

}





//+++++++++++++++線分と直線+++++++++++++++++//



//線分a-b,c-dは交差するか?

inline bool intersect(const P &a,const P &b,const P &c,const P &d){

    return(ccwH(a,b,c)*ccwH(a,b,d)<=0 && ccwH(c,d,a)*ccwH(c,d,b)<=0);

}

//線分s,tは交差するか？

inline bool intersect(const Segment &s,const Segment &t){

    return intersect(s.a,s.b,t.a,t.b);

}

//線分と線分の交点

//これをやる前にintersectで判定

inline P crossPoint(const Segment &s,const Segment &t){

    V base=t.b-t.a;

    DD d1=abs(cross(base,s.a-t.a));

    DD d2=abs(cross(base,s.b-t.a));

    DD r=d1/(d1+d2);

    return s.a+(s.b-s.a)*r;

}

//線分と線分の距離

inline DD dis(const Segment &s,const Segment t){

    if(intersect(s,t)) return 0.0;

    return min(min(disPS(t.a,s),disPS(t.b,s)),min(disPS(s.a,t),disPS(s.b,t)) );

}



//+++++++++++円++++++++++++++++//



//円cと直線lの交点

//abs(l,c.p)<c.r+EPSが必要

pair<P,P> crossPoint(const Line &l,const Circle &c){

    P pr=project(c.p,l);

    V e=(l.b-l.a)/(abs(l.b-l.a));

    DD base=sqrt(c.r*c.r-norm(pr-c.p));

    return make_pair(pr+e*base,pr-e*base);

}

//線分sと円cの交点

vector<P> crossPointSC(const Segment &s,const Circle &c){

    vector<P> ret;

    if(dis(c.p,s)>=c.r+EPS) return ret;

    auto p=crossPoint(s,c);

    if(dot(p.first-s.a,s.b-s.a)>0 && dot(p.first-s.b,s.a-s.b)>0) ret.push_back(p.first);

    if(dot(p.second-s.a,s.b-s.a)>0 && dot(p.second-s.b,s.a-s.b)>0) ret.push_back(p.second);

    if(xy(s.a,s.b)) sort(ret.begin(),ret.end(),xy);

    else sort(ret.rbegin(),ret.rend(),xy);

    return ret;

}



//共通接線の数

//離れている:4 外接:3 交わる:2 内接:1 内包:0

inline int intersect(const Circle &a,const Circle &b){

    DD d=abs(a.p-b.p);

    if(d>a.r+b.r+EPS) return 4;

    if(eq(d,a.r+b.r)) return 3;

    if(eq(d,abs(a.r-b.r))) return 1;

    if(d<abs(a.r-b.r)-EPS) return 0;

    return 2;

}



//円c1と円c2の交点

//これを使う前に交点があるかどうかを判定する

vector<P> crossPoint(const Circle &a,const Circle &b){

    vector<P> ret;

    if(abs(a.p-b.p)>a.r+b.r+EPS) return ret;

    DD d=abs(a.p-b.p);

    DD s=acos((a.r*a.r+d*d-b.r*b.r)/(2*a.r*d));

    DD t=arg(b.p-a.p);

    if(eq(s,0)) ret.emplace_back(a.p+polar(a.r,t+s));

    else ret.push_back(a.p+polar(a.r,t+s)),ret.push_back(a.p+polar(a.r,t-s));

    return ret;

}



//pがcの外にあるかの判定が必要

vector<P> TanLine(const P &p,const Circle &c){

    vector<P> ret;

    DD d=abs(p-c.p);

    if(d<=c.r-EPS) return ret;

    if(eq(d,c.r)){

        ret.push_back(p);

        return ret;

    } 

    return crossPoint(c,Circle(p,sqrt(d*d-c.r*c.r)));

}

//https://ei1333.github.io/luzhiled/snippets/geometry/template.html

//↑すごい。丸写し

//円c1,c2の共通接線

//接点をつないで線にしている(１個だけ追加するときに注意)

vector<Line> TanLine(Circle a,Circle b){

    vector<Line> ret;

    if(a.r<b.r) swap(a,b);

    DD g=abs(a.p-b.p);

    if(eq(g,0)) return ret;

    V u=(b.p-a.p)/g;

    V v=rotate(u,PI*0.5);

    for(DD s:{-1,1}){

        DD h=(a.r+s*b.r)/g;

        if(eq(1-h*h,0)){

            ret.emplace_back(a.p+u*a.r,a.p+(u+v)*a.r);

        }else if(1-h*h>0){

            V uu=u*h,vv=v*sqrt(1-h*h);

            ret.emplace_back(a.p+(uu+vv)*a.r,b.p-(uu+vv)*b.r*s);

            ret.emplace_back(a.p+(uu-vv)*a.r,b.p-(uu-vv)*b.r*s);

        }

    }

    return ret;

}



/*+++++++++++++++++++三角形+++++++++++++++++*/

//外心

//isParallel()を使って判定を忘れずに

P circumcenter(const P &a,const P &b,const P &c){

    DD ad=norm(b-c);

    DD bd=norm(c-a);

    DD cd=norm(a-b);

    P s=a*ad*(bd+cd-ad)+ b*bd*(cd+ad-bd)+ c*cd*(ad+bd-cd);

    DD t=ad*(bd+cd-ad)+ bd*(cd+ad-bd)+ cd*(ad+bd-cd);

    return s/t;

}



/*+++++++++++++++++++多角形+++++++++++++++++++*/

//IN:2 ON:1 OUT:0

//点がどの位置にあるか

int contains(const P &p,const Polygon &g){

    int n=(int)g.size();

    bool x=false;

    for(int i=0;i<n;i++){

        V a=g[i]-p,b=g[(i+1)%n]-p;

        if(eq(cross(a,b),0) && dot(a,b)<EPS) return 1;

        if(imag(a)>imag(b)) swap(a,b);

        if(imag(a)<EPS && EPS<imag(b) && cross(a,b)>EPS) x=!x;

    }

    return (x?2:0);

}

//凸性判定

bool isConvex(const Polygon &g){

    int n=(int)g.size();

    int flag=0;

    int t;

    for(int i=0;i<n;i++){

        V a(g[(i+1)%n]-g[i]),b(g[(i+2)%n]-g[i]);

        if(cross(a,b)>EPS) t=1;

        else if(cross(a,b)<-EPS) t=-1;

        else continue;

        if(flag==-t) return false;

        flag=t;

    }

    return true;

}



//凸包　アンドリューのアルゴリズム

//https://github.com/drken1215/algorithm/blob/master/Geometry/All.cpp←螺旋本より早そう

//j=1:返上の点を含まない　j=-1:含む

//反時計回りの多角形を返す

//sはソートされる

Polygon ConvexHull(Polygon &s,const int j){

    int sz=(int)s.size();

    if(sz<3) return s;

    sort(s.begin(),s.end(),yx);



    int n=0;

    Polygon res(2*sz);

    for(int i=0;i<sz;i++){

        while(n>=2 && cross(res[n-1]-res[n-2],s[i]-res[n-2])<EPS*j){

            n--;

        }

        res[n]=s[i];

        n++;

    }

    int t=n+1;

    for(int i=sz-2;i>=0;i--){

        while(n>=t && cross(res[n-1]-res[n-2],s[i]-res[n-2])<EPS*j){

            n--;

        }

        res[n]=s[i];

        n++;

    }

    res.resize(n-1);

    return res;

}



//符号付き面積

//反時計回りの図形なら正

//https://imagingsolution.net/math/calc_n_point_area/

DD Area(const Polygon &g){

    DD ret=0.0;

    int n=(int)g.size();

    for(int i=0;i<n;i++){

        ret+=cross(g[i],g[(i+1)%n]);

    }

    return ret/2.0L;

}





signed main(){

	bin101();

    using T=pair<DD,DD>;

    map<T,int> M;

    vector<P> v;

    int N;

    cin>>N;

    for(int i=0;i<N;i++){

        DD x,y;

        cin>>x>>y;

        v.emplace_back(x,y);

        M[T(x,y)]=i;

    }

    auto C=ConvexHull(v,-1);

    //vout(C);

    vector<DD> ret(N);

    int cz=C.size();

    for(int i=0;i<cz;i++){

        V s=C[(i-1+cz)%cz]-C[i];

        V t=C[(i+1)%cz]-C[i];

        //cout<<s<<" "<<t<<endl;

        DD theta=acos(dot(s,t)/(abs(s)*abs(t)));

        theta=PI-theta;

        ret[M[T(C[i].real(),C[i].imag())]]=theta/(2*PI);

    }

    for(int i=0;i<N;i++){

        cout<<ret[i]<<endl;

    }

}
