 #include<iostream>

 #include<cstdio>

 #include<cmath>

 #include<algorithm>

 //#include<cstring>

 using namespace std;

 struct knife

 {

     int ai;

     bool f;

 }m[2000018];

 inline int read()

 {

   int p=0,f=1;char c=getchar();

   while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}

   while(c>='0'&&c<='9'){p=p*10+c-'0';c=getchar();}

   return f*p;}

 int N,H,ans;

 bool cmp(knife x,knife y)

 {

     return x.ai>y.ai;//返回伤害最大的刀 

 }

 int main()

 {

     N=read(),H=read();

     for(int i=1;i<=N;i++)

         m[i].ai=read(),

      m[i+N].ai=read(),

         m[i+N].f=true;

     //我们把每把刀看作是可以无限扔的和只能扔一次的两把刀，存进去 

     sort(m+1,m+1+N*2,cmp);//排序，便于取 

     int ans=0;           //ans最终答案

     for(int i=1;i<=2*N;i++)//枚举2*N把刀 

        {

          if(m[i].f)//接下来贪心，如果刀可以飞出去就废掉，同时加上伤害 

            {ans++;

             H-=m[i].ai;}

          else

             {

              int u=H%m[i].ai;

              //如果碰到第一把无限次飞而且伤害最高的就无限砍 

              ans+=H/m[i].ai;

              //一直砍到没血，记录ans+ 

              if(u)ans++;

            H=-1;

             }

           if(H<=0)

             {printf("%d",ans);

              return 0;}

             //如果怪物没血了就输出 

        }

 }