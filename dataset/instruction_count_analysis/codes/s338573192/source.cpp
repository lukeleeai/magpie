#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cstring>

#include<vector>

using namespace std;

#define MAXN 5000

#define Fi first

#define Se second

int h,w;

int a[MAXN+5][MAXN+5];

vector < pair<int,int> > Ans;

vector < pair<int,int> > As2;

int main()

{

    scanf("%d%d",&h,&w);

    for(int i=1;i<=h;i++)

        for(int j=1;j<=w;j++)

        scanf("%d",&a[i][j]);

    for(int i=1;i<=h;i++)

    {

        for(int j=1;j<=w-1;j++)

        if(a[i][j]%2==1)

        {

            a[i][j]-=1,

            a[i][j+1]+=1;

            Ans.push_back(make_pair(i,j));

            As2.push_back(make_pair(i,j+1));

        }

        if(i!=h&&a[i][w]%2==1)

        {

            a[i][w]-=1,a[i+1][w]+=1;

            Ans.push_back(make_pair(i,w));

            As2.push_back(make_pair(i+1,w));

        }

    }

    printf("%d\n",Ans.size());

    for(int i=0;i<Ans.size();i++)

    {

        printf("%d %d %d %d\n",Ans[i].Fi,Ans[i].Se,As2[i].Fi,As2[i].Se);

    }

}
