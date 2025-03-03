#include<iostream>

#include<algorithm>

#include<stdio.h>

#include<string.h>

using namespace std;

const int maxn=30000+10;

struct node

{

   double x,y;

}no[maxn];

struct line

{

   node l,r;

   bool operator<(line b)const

   {

      return l.y<b.l.y||(l.y==b.l.y&&r.y<b.r.y);

   }

}a[maxn];

int sum[maxn];

double area[maxn];

int n,m,w,h,s;

inline double xmulti(node a,line b)//å°äºé¶ç¹å¨ç´çº¿ä¸ 

{

       return (b.l.x-a.x)*(b.r.y-a.y)-(b.l.y-a.y)*(b.r.x-a.x);

}

int main()

{

    int ans=0;

    while(scanf("%d%d%d%d%d",&n,&m,&w,&h,&s)&&(n+m+w+h+s))

    {

        a[0].l.y=a[0].r.y=0;

        a[0].l.x=0;a[0].r.x=w;

        for(int i=1;i<=m;i++)

        {

           scanf("%lf%lf",&a[i].l.y,&a[i].r.y);

           a[i].l.x=0;a[i].r.x=w;

        }

        m++;

        a[m].l.y=a[m].r.y=h;

        a[m].l.x=0;a[m].r.x=w;

        for(int i=0;i<n;i++)

        {

           scanf("%lf%lf",&no[i].x,&no[i].y);

        }

        sort(a,a+m);

        for(int i=0;i<m;i++)

        {

           area[i]=((a[i+1].l.y-a[i].l.y)+(a[i+1].r.y-a[i].r.y))*w/2;

        }

        memset(sum,0,sizeof(sum));

        for(int i=0;i<n;i++)

        {

           int l=0,r=m;

           int mid;

           while(l<=r)

           {

             mid=(l+r)/2;

             if(xmulti(no[i],a[mid])>0)

             {

               if(xmulti(no[i],a[mid+1])<0)

                 break;

               else

                 l=mid+1;

             }

             else

                r=mid-1;

           }

           sum[mid]++;

           //cout<<mid<<endl;

        }

        ans=-1;

        int tot=0;

        double totarea=0;

        int i=0,j=0;

        /*while(j<m&&totarea+area[j]<=w*h-s)

        {

          totarea+=area[j];

          tot+=sum[j];

          j++;

        }

        if(j>0)

        {

          ans=max(tot,ans);

        }

        for(i=1;i<m;i++)

        {

          totarea-=area[i-1];

          tot-=sum[i-1];

          while(j<m&&totarea+area[j]<=w*h-s)

          {

            totarea+=area[j];

            tot+=sum[i-1];

          }

          ans=max(tot,ans);

        }       */

        /*while(j<m)

        {

          if(totarea>0)

          {

             totarea-=area[i-1];

             tot-=sum[i-1];

          }

          while(j<m&&totarea+area[j]<=w*h-s)

          {

            totarea+=area[j];

            tot+=sum[j];

            j++;

          }

          i++;

          if(totarea==0)

            j++;

          ans=max(tot,ans);

          //cout<<totarea<<' '<<tot<<endl; 

        }*/

        for(i=0;i<m;i++)

        {

           j=max(i,j);

           if(totarea>0)

           {

             totarea-=area[i-1];

             tot-=sum[i-1];

           }

           while(j<m&&area[j]+totarea<=w*h-s)

           {

             totarea+=area[j];

             tot+=sum[j];

             j++;

           }

           //cout<<totarea<<' '<<tot<<endl; 

           ans=max(ans,tot);

        } 

            

        printf("%d\n",n-ans);     

    }

    return 0;

}   