//Tue Dec 22 22:01:34 JST 2009

#include<set>

#include<iostream>

#include<queue>

#include<algorithm>

using namespace std;

#define REP(i,b,n) for(int i=b;i<n;i++)

#define rep(i,n)   REP(i,0,n)

#define mp make_pair

int dx[]={0,1,1,0,-1,-1};

int dy[]={-1,-1,0,1,1,0};

#define CONNECT true

#define UNCONNECT false

#define CANMOVE true

#define CANNOTMOVE false



class state{

public:

  int len;

  int x[8],y[8];

  int cnt;

  bool is_connected(int,int);

  bool can_good_pos(int);

  void make_next(int,queue<state>&,set<state>&,bool,set<pair<int,int> > &);

  

  bool operator<(const state & a)const{

    rep(i,len){

      if ( x[i]!=a.x[i])return x[i]<a.x[i];

      if ( y[i]!=a.y[i])return y[i]<a.y[i];

    }

    return false;

  }

  

};



bool state::is_connected(int me,int you){

  if ( x[me]==x[you]){

    if ( y[me]-1 == y[you] || y[me]+1 == y[you] || y[me]==y[you])return CONNECT;

  }else if ( x[me]+1 == x[you]){

    if (y[me] ==y[you] || y[me]-1==y[you])return CONNECT;

  }else if ( x[me]-1==x[you]){

    if (y[me] ==y[you] || y[me]+1 == y[you])return CONNECT;

  }

  

  return UNCONNECT;

}



bool state::can_good_pos(int cur){

  rep(i,cur-1){

    if ( is_connected(cur,i)==CONNECT)return false;//©ªÌOÈOÌâÂÆÂÈªÁÄ¢éÌÅ¾ßB

  }

  if (cur==0 ||  is_connected(cur,cur-1)==CONNECT)return true;//©ªÆOÌâÂÆÂÈªÁÄ¢éÌÅ¨

  return false;

}



  

void state::make_next(int now,queue<state>&Q,set<state>&S,bool flag,set<pair<int,int> > & NG){

  if ( now == len){

    if ( S.find((*this))==S.end()){

      cnt++;

      S.insert(*this);

      Q.push(*this);

      cnt--;

    }

    return;

  }

  

  //don't move

  

  if (can_good_pos(now) ){

    make_next(now+1,Q,S,CANMOVE,NG);

  }

  

  if ( flag == CANNOTMOVE)return;//OÌª®¢Ä½ç©ªÍ®¯È¢

  

  rep(i,6){

    x[now]+=dx[i];

    y[now]+=dy[i];

    

    

    if (NG.find(mp(x[now],y[now])) == NG.end() && can_good_pos(now)){

      make_next(now+1,Q,S,CANNOTMOVE,NG);//©ªª®¢½çÌÍ®¯È¢B

    }

    x[now]-=dx[i];

    y[now]-=dy[i];

  }

  

}









int bfs(state ini,int dx,int dy,set<pair<int,int> > &NG){

  queue<state> Q;

  set<state> S;

  Q.push(ini);

  S.insert(ini);

  while(!Q.empty()){

    state now = Q.front();

    Q.pop();

    if ( (max(now.x[0],dx)-min(now.x[0],dx)+max(now.y[0],dy)-min(now.y[0],dy))/2+now.cnt>20)continue;

    if ( now.x[0]==dx && now.y[0]==dy){

      return now.cnt;

    }

    now.make_next(0,Q,S,CANMOVE,NG);

  }

  return -1;

}





main(){

  int n,m,dx,dy;

  while(cin>>n && n){

    state ini;

    set<pair<int,int> > NG;

    

    ini.len=n;

    ini.cnt=0;

    rep(i,n)cin>>ini.x[i]>>ini.y[i];

    cin>>m;

    rep(i,m){

      int f,s;

      cin>>f>>s;

      NG.insert(mp(f,s));

    }

    cin>>dx>>dy;

    cout << bfs(ini,dx,dy,NG)<<endl;

  }

  return false;

}