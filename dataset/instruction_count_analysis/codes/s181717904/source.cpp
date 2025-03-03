/*

螺旋本 p371



circumcenter:

    https://ja.wikipedia.org/wiki/%E5%A4%96%E6%8E%A5%E5%86%86#%E5%A4%96%E5%BF%83%E3%81%AE%E4%BD%8D%E7%BD%AE

    https://mathtrain.jp/goshin



assertを含む



けんちょんさんのライブラリ

https://github.com/drken1215/algorithm/blob/master/Geometry/All.cpp

ei1333さんのライブラリ

https://ei1333.github.io/luzhiled/snippets/geometry/template.html

//交点がなかった時など、空のvectorを返す方が良い？？？

*/

#pragma GCC optimize("Ofast")

#include "stdc++.h"

using namespace std;



typedef long long ll;

typedef pair<int,int> pii;

typedef pair<int,ll> pil;

typedef pair<ll,int> pli;

typedef pair<ll,ll> pll;



template<class T,class U>constexpr bool chmin(T&a,const U b){if(a<=b)return false;a=b;return true;}

template<class T,class U>constexpr bool chmax(T&a,const U b){if(a>=b)return false;a=b;return true;}

#define bit(n,k) ( (n>>k)&1 )



//デバッグ

template<class T>

void Vout(vector<T> &V){

    cout<<"\nstart\n";

    const int sz=V.size();

    for(int i=0;i<sz;i++){

        cout<<i<<" "<<V[i]<<'\n';

    }

    cout<<"end\n"<<endl;

}



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



constexpr int MAX=1<<30;

constexpr int MOD=1e9+7;

int dx[]={1,-1,0,0},dy[]={0,0,-1,1};



//__builtin_popcount(S);

//#define int ll

//vector<vector<int>> data(3, vector<int>(4));

//vector.resize(a,vector<int>(b,-1));

//vector<vector<vector<要素の型>>> 変数名(要素数1, vector<vector<要素の型>>(要素数2, vector<要素の型>(要素数3, 初期値)));



using DD=double;

#define EPS 1e-10

#define eq(a,b) (abs( (a) - (b) )<EPS)

const DD PI=acosl(-1.0);

constexpr DD INF=1LL<<62;



DD torad(DD deg){return deg*PI/180;}

DD todeg(DD ang){return ang*180/PI;}



struct Point{

    DD x,y;

    Point(DD x=0.0,DD y=0.0): x(x),y(y){}



    inline Point operator + (const Point &p){return Point(x+p.x,y+p.y);}

    inline Point operator - (const Point &p){return Point(x-p.x,y-p.y);}

    inline Point operator * (DD a){return Point(a*x,a*y);}

    inline Point operator / (DD a){return Point(x/a,y/a);}



    bool operator ==(const Point &p) const{

        return abs(x-p.x)<EPS && abs(y-p.y)<EPS;

    }



    DD dis(){return sqrt(norm());} //ベクトルの長さ

    DD norm(){return x*x+y*y;}



};

typedef Point Vector;



//線分

struct Segment{

    Point p1,p2;

    Segment(Point p1=Point(0.0,0.0),Point p2=Point(0.0,0.0)) : p1(p1),p2(p2){}

    Segment(DD x1,DD y1,DD x2,DD y2) :p1(Point(x1,y1)),p2(Point(x2,y2)){}

};

//直線

typedef Segment Line;



//多角形

typedef vector<Point> Polygon;

//円

struct Circle{

    Point c;

    DD r;

    Circle(Point c=0.0,DD r=0.0):c(c),r(r){}

};



/*++++++++基本計算++++++++++++++*/

//内積

inline DD dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}

//外積

inline DD cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}

//ベクトルpの傾きをラジアンで返す

inline DD arg(Vector p){return atan2(p.y,p.x);}

//長さa,角度r(ラジアン)

inline Vector polar(DD a,DD r){return Vector(cos(r)*a,sin(r)*a);}

//sortするときに必要

//operatorに入れるのもアリ

inline bool xy(const Point &a,const Point &b){

    if(a.x+EPS<b.x) return true;

    if(eq(a.x,b.x) && a.y+EPS<b.y) return true;

    return false;

}

inline bool yx(const Point &a,const Point &b){

    if(a.y+EPS<b.y) return true;

    if(eq(a.y,b.y) && a.x+EPS<b.x) return true;

    return false;

}

inline DD norm(Vector p){return p.x*p.x+p.y*p.y;}

//点pを反時計回りにtheta(ラジアン)回転

inline Vector rotate(Vector p,DD theta){

    return Vector(cos(theta)*p.x-sin(theta)*p.y,sin(theta)*p.x+cos(theta)*p.x);

}







/*+++++++++++++++++++++射影++++++++++++++++++++*/

//点pの射影

//pからsに対して垂線を引いたときの交点

inline Point project(Segment s,Point p){

    Vector base=s.p2-s.p1;

    DD r=dot(p-s.p1,base)/base.norm();

    return s.p1+base*r;

}



//線分sを対象軸としたときの、点pの線対称の点

inline Point reflect(Segment s,Point p){

    return p+(project(s,p)-p)*2.0;

}







/*++++++++++点との距離++++++++++++++++++*/

//aとbの距離

//点と点の距離

inline DD dis(Point a,Point b){return (a-b).dis();}

//点と直線の距離

inline DD dis(Line l,Point p){return abs(cross(l.p2-l.p1,p-l.p1))/dis(l.p2,l.p1);}

//線分と点の距離

inline DD disSP(Segment s,Point p){

    if( dot(s.p2-s.p1,p-s.p1)<0.0 ) return dis(p,s.p1);

    if( dot(s.p1-s.p2,p-s.p2)<0.0 ) return dis(p,s.p2);

    return dis(s,p); //点と直線の距離

}



/*++++++++++++++++関係(平行や直交)+++++++++++++++++*/

//直交ならばtrue

//内積が0ならcosθ=0を利用

inline bool isOrthogonal(Vector a,Vector b){return eq(dot(a,b),0.0);}

//4つの点　ベクトルa1-a2,ベクトルb1-b2が直交かどうか

inline bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){return eq(dot(a1-a2,b1-b2),0.0);}

//線分が直交かどうか

inline bool isOrthogonal(Segment s1,Segment s2){return eq(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0);}

//平行ならばtrue

//外積が0ならsinθ=0を利用

inline bool isParallel(Vector a,Vector b){if(abs(cross(a,b))<EPS ) return true;else return false;}

//4つの点　ベクトルa1-a2,ベクトルb1-b2が平行かどうか

inline bool isParallel(Point a1,Point a2,Point b1,Point b2){return isParallel(a1-a2,b1-b2);}

//線分が平行かどうか

inline bool isParallel(Segment s1,Segment s2){return eq(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0 );}



//線分p1-p2に対してp3がどこの位置にあるか？

//反時計回り:1 時計回り:-1 直線上:0

inline int ccw(Point p1,Point p2,Point p3){

    if(cross(p2-p1,p3-p1)>EPS) return 1;

    if(cross(p2-p1,p3-p1)<-EPS) return -1;

    else return 0;

}



//線分p1,p2に対してp3がどこの位置にあるか？

//反時計回り:1　時計回り:-1 直線上(p1,p2,p3:-2 p1,p3,p2:0 p3,p1,p2:2) 

inline int ccwH(Point p1,Point p2,Point p3){

    if(cross(p2-p1,p3-p1)>EPS) return 1;

    if(cross(p2-p1,p3-p1)<-EPS) return -1;

    if(dot(p2-p1,p3-p1)<0) return 2;

    if((p2-p1).norm()<(p3-p1).norm()) return -2;

    return 0;

}



/*+++++++++++線分と直線+++++++++++++++*/

//線分p1-p2と線分p3-p4の交差判定

inline bool intersect(Point p1,Point p2,Point p3,Point p4){

    return(ccwH(p1,p2,p3)*ccwH(p1,p2,p4)<=0 && ccwH(p3,p4,p1)*ccwH(p3,p4,p2)<=0);

}

//線分s1,s2は交差するか？

inline bool intersect(Segment s1,Segment s2){

    return intersect(s1.p1,s1.p2,s2.p1,s2.p2);

}

//線分と線分の交点

//これをやる前にintersectで判定

inline Point crossPoint(Segment s1,Segment s2){

    //assert(intersect(s1,s2)); 

    Vector base=s2.p2-s2.p1;

    DD d1=abs(cross(base,s1.p1-s2.p1));

    DD d2=abs(cross(base,s1.p2-s2.p1));

    DD t=d1/(d1+d2);

    return s1.p1+(s1.p2-s1.p1)*t;

}

//線分と線分の距離

inline DD dis(Segment s1,Segment s2){

    if(intersect(s1,s2)) return 0.0;

    return min(min(disSP(s1,s2.p1),disSP(s1,s2.p2)),min(disSP(s2,s1.p1),disSP(s2,s1.p2)) );

}

//円cと直線lの交点

inline pair<Point,Point> crossPoint(Circle c,Line l){

    assert(dis(l,c.c)<c.r+EPS);

    Point pr=project(l,c.c);

    Vector e=(l.p2-l.p1)/(dis(l.p2,l.p1));

    DD base=sqrt(c.r*c.r-(pr-c.c).norm());

    return make_pair(pr+e*base,pr-e*base);

}



//円と円の関係



//共通接線の数

//離れている:4 外接:3 交わる:2 内接:1 内包:0

inline int intersect(Circle c1,Circle c2){

    DD d=dis(c1.c,c2.c);

    if(d>c1.r+c2.r+EPS) return 4;

    if(eq(d,c1.r+c2.r)) return 3;

    if(eq(d,abs(c1.r-c2.r))) return 1;

    if(d<abs(c1.r-c2.r)-EPS) return 0;

    return 2;

}



//円c1と円c2の交点

//これを使う前に交点があるかどうかを判定する

inline pair<Point,Point> crossPoint(Circle c1,Circle c2){

    assert(dis(c1.c,c2.c)<c1.r+c2.r+EPS);

    DD d=dis(c1.c,c2.c);

    DD a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));

    DD t=arg(c2.c-c1.c);

    return make_pair(c1.c+polar(c1.r,t+a),c1.c+polar(c1.r,t-a));

}



//pがcの外にあるかの判定が必要

inline pair<Point,Point> TanLine(Point &p,Circle &c){

    DD d=dis(p,c.c);

    assert(d>c.r-EPS);

    if(eq(d,c.r)) return make_pair(p,p);

    return crossPoint(c,Circle(p,sqrt(d*d-c.r*c.r)));

}



/*+++++++++++++++++++三角形+++++++++++++++++*/

//外心

//isParallel()を使って判定を忘れずに

inline Point circumcenter(Point A,Point B,Point C){

    assert(!isParallel(A-B,A-C));

    DD a=(B-C).norm();

    DD b=(A-C).norm();

    DD c=(A-B).norm();

    return ( ( A*a*(b+c-a)+ B*b*(c+a-b)+ C*c*(a+b-c) )/  (a*(b+c-a)+ b*(c+a-b)+ c*(a+b-c) ) );

}





/*+++++++++++++++++++多角形+++++++++++++++++++*/

//IN:2 ON:1 OUT:0

//点がどのいちにあるか

int contains(Polygon g,Point p){

    int n=(int)g.size();

    bool x=false;

    for(int i=0;i<n;i++){

        Vector a=g[i]-p,b=g[(i+1)%n]-p;

        if(eq(cross(a,b),0) && dot(a,b)<EPS) return 1;

        if(a.y>b.y) swap(a,b);

        if(a.y<EPS && EPS<b.y && cross(a,b)>EPS) x=!x;

    }

    return (x?2:0);

}

//凸性判定

bool isConvex(Polygon &g){

    int n=(int)g.size();

    int flag=0;

    int t;

    for(int i=0;i<n;i++){

        Vector a(g[(i+1)%n]-g[i]),b(g[(i+2)%n]-g[i]);

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

Polygon ConvexHull(Polygon s,int j){

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

    DD res=0.0;

    int n=(int)g.size();

    for(int i=0;i<n;i++){

        res+=cross(g[i],g[(i+1)%n]);

    }

    return res/2.0L;

}



//反時計回り

//理解が浅い←大体分かった（本当か？）

DD Diameter(Polygon &g){

    g=ConvexHull(g,1);

    int gz=g.size();

    int m=0,M=0;

    for(int i=1;i<gz;i++){

        if(g[i].x<g[m].x) m=i;

        if(g[i].x>g[M].x) M=i;

    }

    DD ret=0;

    int sm=m,sM=M;

    while(m!=sM || M!=sm){

        ret=max(ret,norm(g[m]-g[M]));

        if(cross(g[(m+1)%gz]-g[m],g[(M+1)%gz]-g[M])<0) m=(m+1)%gz;

        else M=(M+1)%gz;

    }

    return sqrt(ret);

}



//凸多角形gをlで切断

//l.p1-l.p2の左側

//gは反時計回り→反時計回りで返す

//時計回り→時計回り

//けんちょんさんのが長かった→読んでおきたい

Polygon ConvexCut(const Polygon &g,Line l){

    Polygon ret;

    int gz=(int)g.size();

    for(int i=0;i<gz;i++){

        Point now=g[i],next=g[(i+1)%gz];

        if(ccw(l.p1,l.p2,now)>=0) ret.push_back(now);

        if(ccw(l.p1,l.p2,now)*ccw(l.p1,l.p2,next)<0){

            ret.push_back(crossPoint(Line(now,next),l));

        }

    }

    return ret;

}



//++++なんか凄いの+++++++++++++++



//最近点対

DD RecClosetPair(Polygon::iterator it,int n){

    if(n<=1) return INF;

    int m=n/2;

    DD x=it[m].x;

    DD d=min(RecClosetPair(it,m),RecClosetPair(it+m,n-m));

    inplace_merge(it,it+m,it+n,yx);

    Polygon v;

    for(int i=0;i<n;i++){

        if(abs(it[i].x-x)>=d) continue;

        for(int j=0;j<v.size();j++){

            DD dy=it[i].y-v[v.size()-1-j].y;

            if(dy>=d) break;

            DD dx=it[i].x-v[v.size()-1-j].x;

            d=min(d,sqrt(dx*dx+dy*dy));

        }

        v.push_back(it[i]);

    }

    return d;

}



DD ClosetPair(Polygon g){

    sort(g.begin(),g.end(),xy);

    return RecClosetPair(g.begin(),g.size());

}



struct EndPoint{

    Point p;

    int seg,st; //入力線分の種類,単点の種類

    EndPoint(){}

    EndPoint(Point p,int seg,int st):p(p),seg(seg),st(st){}



    bool operator < (const EndPoint &ep) const{

        if(eq(p.y,ep.p.y)){

            return st<ep.st; //yが同一の場合は、下端点→左単点→右単点→上単点の順に調べる

        }else return p.y<ep.p.y;

    }

};



EndPoint EP[2*100000];



//誤差が不安 EPSなしでも通った

//マンハッタン幾何　線分交差

int manhattanIntersection(vector<Segment> S){

    int sz=S.size();



    for(int i=0,k=0;i<sz;i++){

        //p1が左下を選ぶようにする

        if(eq(S[i].p1.y,S[i].p2.y)){

            if(S[i].p1.x>S[i].p2.x) swap(S[i].p1,S[i].p2);

        }else if(S[i].p1.y>S[i].p2.y) swap(S[i].p1,S[i].p2);



        if(eq(S[i].p1.y,S[i].p2.y)){

            EP[k++]=EndPoint(S[i].p1,i,1);

            EP[k++]=EndPoint(S[i].p2,i,2);

        }else{

            EP[k++]=EndPoint(S[i].p1,i,0);

            EP[k++]=EndPoint(S[i].p2,i,3);

        }

    }



    sort(EP,EP+2*sz);



    set<DD> BT;

    BT.insert(1000000001);

    int cnt=0;



    for(int i=0;i<2*sz;i++){

        if(EP[i].st==3){

            BT.erase(EP[i].p.x);

        }else if(EP[i].st==0){

            BT.insert(EP[i].p.x);

        }else if(EP[i].st==1){

            auto b=BT.lower_bound(S[EP[i].seg].p1.x-EPS);

            auto e=BT.upper_bound(S[EP[i].seg].p2.x+EPS);

            cnt+=distance(b,e);

        }

    }

    return cnt;

}





signed main(){

    ios::sync_with_stdio(false);

    cin.tie(nullptr); 



    int N;

    cin>>N;

    Polygon g;

    map<pii,int> M;

    for(int i=0;i<N;i++){

        DD x,y;

        cin>>x>>y;

        g.emplace_back(Point(x,y));

        M[pii(x,y)]=i;

    }

    Polygon s=ConvexHull(g,1);

    DD ans[110]={0.0};

    int sz=s.size();

    for(int i=0;i<(int)s.size();i++){

        int now=M[pii(s[i].x,s[i].y)];

        Vector a=s[i]-s[(i+sz-1)%sz],b=s[(i+1)%sz]-s[i];

        a=rotate(a,-PI*0.5); b=rotate(b,-PI*0.5);

        DD bb=arg(b),aa=arg(a);

        if(bb*aa<0 && aa>0){

            bb=2*PI+bb;

        } 

        DD d=bb-aa;

        ans[now]=abs(d/(2*PI) );

    }

    for(int i=0;i<N;i++){

        printf("%.10lf\n",ans[i]);

    }

    

}