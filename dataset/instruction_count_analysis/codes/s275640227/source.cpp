#include<iostream>

#include<cstdio>

#include <stdio.h>

#include<algorithm>

#include<cstring>

#include <string>

#include<cmath>

#include<cstdlib>

#include<queue>

#include<map>

#include<vector>

#include"stdc++.h"

#include <set>

#define ll   long long

#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)

#define inf 0x3f3f3f

#define pi 3.1415926535898

using namespace std;

const int N=3e5+10;

const int mod=1e9+7;

int a[N],b[N];

ll maxs=-9999;

ll sum;

struct A

{

    int x,y;

};

map <pair<int,int >,int >mp;

int main()

{

    int h,w,m;

    int q[N],t[N];//记录最多障碍物的行和列。

    int cnt1,cnt2;//记录有多少条最多的行和列。

    cin>>h>>w>>m;

    int  sum1=0,sum2=0;//求最大的行和列。

    for(int i=0; i<m; i++)

    {

        int x,y;

        cin>>x>>y;

        mp[make_pair(x,y)]++;

        a[x]++;

        b[y]++;

    }

    for(int i=1; i<=h; i++)

    {

        if(sum1<a[i])

        {

            cnt1=0;

            memset(q,0,sizeof(q));

            sum1=max(sum1,a[i]);

            q[cnt1++]=i;

            while(sum1==a[i+1])

            {

                q[cnt1++]=i;

                i++;

            }

        }

        if(sum1==a[i])

        {

            q[cnt1++]=i;

            while(sum1==a[i+1])

            {

                q[cnt1++]=i;

                i++;

            }

        }

    }

    for(int i=1; i<=w; i++)

    {

        if(sum2<b[i])

        {

            cnt2=0;

            memset(t,0,sizeof(t));

            sum2=max(sum2,b[i]);

            t[cnt2++]=i;

            while(sum2==b[i+1])

            {

                t[cnt2++]=i;

                i++;

            }

        }

        if(sum2==b[i])

        {

            t[cnt2++]=i;

            while(sum2==b[i+1])

            {

                t[cnt2++]=i;

                i++;

            }

        }

    }

    sum=sum1+sum2;

    int xx=0;

    for(int i=0; i<cnt1; i++)

    {

        for(int j=0; j<cnt2; j++)

        {

            int x1,y1;

            x1=q[i];

            y1=t[j];

            if(mp[make_pair(x1,y1)]==0)//判断是否交点有障碍物

            {

                xx=1;

                break;

            }



        }

        if(xx==1)

        {

            break;

        }

    }

    if(xx==0)

    {

        sum--;

    }

    cout<<sum<<endl;

    return 0;

}


