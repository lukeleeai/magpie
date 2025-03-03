#include"stdc++.h"

using namespace std;

const int maxn = 100010;



template<class T>inline void read(T &re)

{

    char ch;int f=1;

    while((ch=getchar())<'0'||ch>'9')

    if(ch=='-')f=-1;

    re=ch-48;

    while((ch=getchar())>='0'&&ch<='9')

    re=(re<<3)+(re<<1)+ch-48;

    re*=f;

}



inline int min(int x,int y){

    return x<y?x:y;

}



struct node{

    int x,y,w;

}ch[maxn];



int fa[maxn];

long long w[maxn],min1[maxn],min2[maxn];



inline bool comp(const node &a,const node &b){

    if(a.y!=b.y)return a.y<b.y;

    return a.x<b.x;

}



inline int getfa(int x){

    if(fa[x]==x)return x;

    int nf=getfa(fa[x]);

    w[x]+=w[fa[x]];

    return fa[x]=nf;

}



inline bool unionn(int a,int b,long long W)

{

    int a1=getfa(a),b1=getfa(b);

    if(a1!=b1){

        fa[a1]=b1;

        w[a1]=W+w[b]-w[a];//b-a+b1-b+a-a1=W+w[b]-w[a]=b1-a1

        return true;

    }

    else return w[a]==W+w[b];//b-a+b1-b=b1-a=w[a] 判断是否会矛盾 

}



int main()

{

//	freopen("then1.in","r",stdin);

//	freopen("then.out","w",stdout);

    int T,r,c,n;

        bool fl=true;

        read(r);read(c);//h l

        read(n);

        for(register int i=1;i<=n;++i){

            read(ch[i].x);read(ch[i].y);read(ch[i].w);//h l val

            if(ch[i].w<0)fl=false;

        }

        if(fl==false){

            printf("No\n");

            return 0;

        }

        else if(r==1){

            printf("Yes\n");

            return 0;

        }

        for(register int i=1;i<=r;++i){

            fa[i]=i;w[i]=0;

        }

        std::sort(ch+1,ch+1+n,comp);

        for(register int i=1;i<n;++i)

        if(ch[i].y==ch[i+1].y)

            if(!unionn(ch[i].x,ch[i+1].x,ch[i+1].w-ch[i].w))

                fl=false;

        

        for(register int i=1;i<=r;++i)

        min1[i]=min2[i]=2e16;

        

        for(register int i=1;i<=n;++i){

            int rt=getfa(ch[i].x);

            min1[rt]=min(min1[rt],ch[i].w+w[ch[i].x]);

        }

        for(register int i=1;i<=r;++i){

            int rt=getfa(i);

            min2[rt]=min(min2[rt],-w[i]);

        }

        for(register int i=1;i<=r;++i)

        if(fa[i]==i&&min2[i]+min1[i]<0){

            fl=false;break;

        }

        if(fl)printf("Yes\n");

        else printf("No\n");

    return 0;

}