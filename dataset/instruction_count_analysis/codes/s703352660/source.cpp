#include "stdc++.h"



using namespace std;



typedef long long ll;

typedef vector<int> vi;

typedef vector<ll> vl;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;



typedef int _loop_int;

#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)

#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)

#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)



#define DEBUG(x) cout<<#x<<": "<<x<<endl

#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl

#define ALL(a) (a).begin(),(a).end()



#define CHMIN(a,b) a=min((a),(b))

#define CHMAX(a,b) a=max((a),(b))



typedef unsigned long long ull;



int n;



#define TUPLE(a,b,c,d) (a | (b<<16) | ((ull)c<<32) | ((ull)d<<48))

#define UNPACK(t,a,b,c,d) int a=((t)&65535),b=(((t)>>16)&65535),c=(((t)>>32)&65535),d=(((t)>>48)&65535)



ull normalize(int a,int b,int c,int d){

  ull r = TUPLE(a,b,c,d);

  REP(_,3){

    swap(a,b);

    swap(b,c);

    swap(c,d);

    CHMIN(r,TUPLE(a,b,c,d));

  }

  return r;

}

ull normalize(ull s){

  UNPACK(s,a,b,c,d);

  return normalize(a,b,c,d);

}

void debunpack(string po,ull s){

  UNPACK(s,a,b,c,d);

  printf("%s%5d%5d%5d%5d\n",po.c_str(),a,b,c,d);

}



int main(){

  // cube, [count,multiply]

  map<ull,pii> mp;

  scanf("%d",&n);

  REP(i,n){

    int a,b,c,d;

    scanf("%d%d%d%d",&a,&b,&c,&d);

    set<ull> S;

    S.insert(TUPLE(a,b,c,d));

    REP(_,3){

      swap(a,b);

      swap(b,c);

      swap(c,d);

      S.insert(TUPLE(a,b,c,d));

    }

    ull s = *S.begin();

    mp[s].first += 1;

    mp[s].second = 4/S.size();

  }

  ull ans = 0;

  for(auto& _s1:mp){

    ull s1 = _s1.first;

    ull u = _s1.second.first;

    _s1.second.first--;

    UNPACK(s1,a,b,c,d);

    for(auto& _s2:mp){

      ull s2 = _s2.first;

      ull v = u * _s2.second.first;

      _s2.second.first--;

      UNPACK(s2,h,g,f,e);

      REP(_,4){

        ull add = v;

        ull s3 = normalize(b,a,e,f);

        ull s4 = normalize(c,b,f,g);

        ull s5 = normalize(d,c,g,h);

        ull s6 = normalize(a,d,h,e);

        bool ok = mp.count(s3) && mp.count(s4) && mp.count(s5) && mp.count(s6);

        if(ok){

          add *= mp[s3].first * mp[s3].second;  mp[s3].first--;

          add *= mp[s4].first * mp[s4].second;  mp[s4].first--;

          add *= mp[s5].first * mp[s5].second;  mp[s5].first--;

          add *= mp[s6].first * mp[s6].second;  mp[s6].first--;

        }else{

          add = 0;

        }

        ans += add;

        if(ok){

          mp[s3].first++;

          mp[s4].first++;

          mp[s5].first++;

          mp[s6].first++;

        }

        swap(e,f);

        swap(f,g);

        swap(g,h);

      }

      _s2.second.first++;

    }

    _s1.second.first++;

  }

  printf("%llu\n",ans/6);

  return 0;

}
