#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

#define GG  {puts("No");continue;}

const int maxn=100005;

typedef long long ll;

int ufs1[maxn];ll w1[maxn];

int ufs2[maxn];ll w2[maxn];

struct node{

  int x,y,val;

  void read(){

    scanf("%d%d%d",&x,&y,&val);

  }

}P[maxn];

bool cmpx(const node &A,const node &B){

  return A.x<B.x;

}

bool cmpy(const node &A,const node &B){

  return A.y<B.y;

}

int find1(int x){

  if(x==ufs1[x])return x;

  int rt=find1(ufs1[x]);

  w1[x]+=w1[ufs1[x]];

  return ufs1[x]=rt;

}

int find2(int x){

  if(x==ufs2[x])return x;

  int rt=find2(ufs2[x]);

  w2[x]+=w2[ufs2[x]];

  return ufs2[x]=rt;

}

bool link1(int a,int b,ll w){

  if(find1(a)!=find1(b)){

    int ra=find1(a),rb=find1(b);

    ufs1[ra]=ufs1[rb];

    w1[ra]=w+w1[b]-w1[a];

    return true;

  }else{

    return w1[a]==w+w1[b];

  }

}

bool link2(int a,int b,ll w){

  if(find2(a)!=find2(b)){

    int ra=find2(a),rb=find2(b);

    ufs2[ra]=ufs2[rb];

    w2[ra]=w+w2[b]-w2[a];

    return true;

  }else{

    return w2[a]==w+w2[b];

  }

}

ll Min1[maxn],Min2[maxn];

int main(){

//  freopen("then.in","r",stdin);

//  freopen("then.out","w",stdout);

  int tests;tests=1;

  while(tests--){

    bool flag=true;

    int R,C;scanf("%d%d",&R,&C);

    for(int i=1;i<=R;++i){

      ufs1[i]=i;w1[i]=0;

    }

    for(int i=1;i<=C;++i){

      ufs2[i]=i;w2[i]=0;

    }

    int n;scanf("%d",&n);

    for(int i=1;i<=n;++i)P[i].read();

    for(int i=1;i<=n;++i)if(P[i].val<0)flag=false;

    sort(P+1,P+n+1,cmpx);

    for(int i=1;i<n;++i)

      if(P[i].x==P[i+1].x)

	if(!link2(P[i].y,P[i+1].y,P[i+1].val-P[i].val))flag=false;



    sort(P+1,P+n+1,cmpy);

    for(int i=1;i<n;++i)

      if(P[i].y==P[i+1].y)

	if(!link1(P[i].x,P[i+1].x,P[i+1].val-P[i].val))flag=false;



    memset(Min1,0x3f,sizeof(Min1));

    memset(Min2,0x3f,sizeof(Min2));

    for(int i=1;i<=n;++i){

      int rt=find1(P[i].x);

      Min1[rt]=min(Min1[rt],P[i].val+w1[P[i].x]);

    }

    for(int i=1;i<=R;++i){

      int rt=find1(i);

      Min2[rt]=min(Min2[rt],-w1[i]);

    }

    for(int i=1;i<=R;++i)

      if(ufs1[i]==i&&Min1[i]+Min2[i]<0)

	flag=false;



    // memset(Min1,0x3f,sizeof(Min1));

    // memset(Min2,0x3f,sizeof(Min2));

    // for(int i=1;i<=n;++i){

    //   int rt=find2(P[i].y);

    //   Min1[rt]=min(Min1[rt],P[i].val+w2[P[i].y]);

    // }

    // for(int i=1;i<=C;++i){

    //   int rt=find2(i);

    //   Min2[rt]=min(Min2[rt],-w2[i]);

    // }

    // for(int i=1;i<=C;++i)

    //   if(ufs2[i]==i&&Min1[i]+Min2[i]<0)

    // 	flag=false;

    

    printf("%s\n",flag?"Yes":"No");

  }

  return 0;

}