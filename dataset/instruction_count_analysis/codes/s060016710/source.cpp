#include"stdc++.h"

#define ll long long

#define inf 0x3f3f3f3f

#define fi first

#define se second

#define pb push_back

#define mkp make_pair

#define pa pair<int,int>

const int N=1e6+10;

const int mod=1e9+7;

using namespace std;



struct Point{int x,y;};

struct segment{Point p1,p2;};

struct endpoint

{

  Point p; int id,type; 

  endpoint(){}

  endpoint(Point p,int id,int type):p(p),id(id),type(type){}

  bool operator < (const endpoint &ep)const {return p.y==ep.p.y?type<ep.type:p.y<ep.p.y;}

};

int sweep(vector<segment> v)

{

   vector<endpoint> ep;

   for(int i=0,sz=v.size();i<sz;i++)

   {

      segment &e=v[i];

      if(e.p1.x==e.p2.x)

      {

         if(e.p1.y>e.p2.y) swap(e.p1,e.p2);

         ep.pb(endpoint(e.p1,i,0));

         ep.pb(endpoint(e.p2,i,3));

      }

      else 

      {

         if(e.p1.x>e.p2.x) swap(e.p1,e.p2);

         ep.pb(endpoint(e.p1,i,1));

         ep.pb(endpoint(e.p2,i,2));

      }

   }

   sort(ep.begin(),ep.end()); 

   int ans=0; set<int> s; s.insert(inf);

   for(auto e: ep)

   {

      if(e.type==0) s.insert(e.p.x);

      else if(e.type==3) s.erase(e.p.x);

      else if(e.type==1) ans+=distance(s.lower_bound(v[e.id].p1.x),s.upper_bound(v[e.id].p2.x));

   }

 return ans;

}

int main()  

{  

     int n;  scanf("%d",&n);

     vector<segment> v; segment t;

     for(int i=1;i<=n;i++) scanf("%d%d%d%d",&t.p1.x,&t.p1.y,&t.p2.x,&t.p2.y),v.pb(t);

     printf("%d\n",sweep(v));

return 0;  

}  
