#include<iostream>

#include<algorithm>

#include<vector>

#include<queue>

#include<map>

#include<set>

#include<string>

#include<stack>

#include<cstdio>

#include<cmath>

using namespace std;

  

typedef long long LL;

typedef long double LD;

typedef pair<int,int> P;

typedef pair<int,P> P1;

  

#define fr first

#define sc second

#define mp make_pair

#define pb push_back

#define rep(i,x) for(int i=0;i<x;i++)

#define rep1(i,x) for(int i=1;i<=x;i++)

#define rrep(i,x) for(int i=x-1;i>=0;i--)

#define rrep1(i,x) for(int i=x;i>0;i--)

#define sor(v) sort(v.begin(),v.end())

#define rev(s) reverse(s.begin(),s.end())

#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)

#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)

#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())

#define min_3(a,b,c) min(a,min(b,c))

#define max_3(a,b,c) max(a,max(b,c))

#define mp1(a,b,c) P1(a,P(b,c))

#define pque(a) priority_queue<a>

#define rpque(a) priority_queue<a,vector<a>,greater<a>>

  

const LL INF=100000000000000000;

const int dre_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

const int dre_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

  

int main(){

    while(1){

        int n,m;

        static LL ld[202][202]; rep(i,202)rep(j,202){ if(i==j)ld[i][j]=0; else ld[i][j]=INF; }

        static LL sd[202][202]; rep(i,202)rep(j,202){ if(i==j)sd[i][j]=0; else sd[i][j]=INF; }

          

        scanf("%d%d",&n,&m); if(n==0&&m==0)return 0;

        rep(i,m){

            int x,y,t; char sl;

            scanf("%d%d%d %c",&x,&y,&t,&sl);

            if(sl=='L'){

                ld[x][y]=t;

                ld[y][x]=t;

            }

            else {

                sd[x][y]=t;

                sd[y][x]=t;

            }

        }

          

        rep1(k,n)rep1(i,n)rep1(j,n)ld[i][j]=min(ld[i][j],ld[i][k]+ld[k][j]);

        rep1(k,n)rep1(i,n)rep1(j,n)sd[i][j]=min(sd[i][j],sd[i][k]+sd[k][j]);

          

        /*rep1(i,n){

            rep1(j,n){

                cout<<sd[i][j]<<" ";

            }

            cout<<endl;

        }*/

          

        int r,z[1002];

        static LL dp[1002][202]; rep(i,1002)rep(j,202)dp[i][j]=INF;

          

        scanf("%d",&r);

    	rep(i,r)scanf("%d",&z[i]);

        dp[0][z[0]]=0;

          

        rep1(i,r-1){

            rep1(j,n){

            	dp[i][j]=min(dp[i][j],dp[i-1][j]+ld[z[i-1]][z[i]]);

                if(ld[j][z[i]]!=INF){

                    rep1(k,n){

                        dp[i][j]=min(dp[i][j],dp[i-1][k]+ld[z[i-1]][k]+sd[k][j]+ld[j][z[i]]);

                    }

                }

            }

        }

    	

    	int ret=1000000000;

    	rep1(i,n){

    		ret=min(ret,(int)dp[r-1][i]);

    	}

          

        printf("%d\n",ret);

    }

}