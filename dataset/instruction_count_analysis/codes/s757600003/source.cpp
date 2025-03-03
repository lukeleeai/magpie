#include"stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

#define Khela ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ll long long int

#define llu long long unsigned int

#define pf printf

#define sf scanf

#define f first

#define s second

#define pb push_back

#define mk make_pair

#define pii pair<int ,int>

#define PII pair<ll ,ll>

 

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};

int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

int dx4[] = {0, 0, 1, -1};

int dy4[] = {1, -1, 0, 0};

 

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int Set(int N,int pos){return N=N | (1<<pos);}

int reset(int N,int pos){return N= N & ~(1<<pos);}

bool check(int N,int pos){return (bool)(N & (1<<pos));}

const int Max=1e9+100;

const ll  MAX=1e18+500;

const int sz=1e3+100;

 

int main()

{

    Khela

    int a,b,c,i,j,k,q,p,x,y,ct,ct1,m,l,r,x1,y1,mn,h,sum1,in,z,mid,n,mx;

    char ch;

    double d;

    //string str1,str2,str;

    bool bl,bl1;

    int t,cs=1;

    while(cin>>n>>m)

    {

        string str[n];

        for(i=0;i<n;i++)  cin>>str[i];

        int sum[5][n][m];

        memset(sum,0,sizeof sum);

        for(i=0;i<n;i++){

            for(j=0;j<m;j++){

               if(j==0) {

                   if(str[i][j]=='.') sum[1][i][j]=1;

                   if(i>0 && str[i][j]=='.') sum[2][i][j]=sum[2][i-1][j]+1;

                   else if(i==0 && str[i][j]=='.') sum[2][i][j]=1;

                }

                else if(i==0) {

                    if(str[i][j]=='.') sum[2][i][j]=1;

                    if(str[i][j]=='.') sum[1][i][j]=sum[1][i][j-1]+1;

                }

                else{

                    if(str[i][j]=='.') sum[1][i][j]=sum[1][i][j-1]+1,sum[2][i][j]=sum[2][i-1][j]+1;

                }

            }

        }



        for(i=n-1;i>=0;i--){

            for(j=m-1;j>=0;j--){

                    if(j==m-1) {

                        if(str[i][j]=='.') sum[3][i][j]=1;

                        if(i<n-1 && str[i][j]=='.') sum[4][i][j]=sum[4][i+1][j]+1;

                        else if(i==n-1 && str[i][j]=='.') sum[4][i][j]=1;

                    }

                    else if(i==n-1) {

                        if(str[i][j]=='.')  sum[4][i][j]=1;

                        if(str[i][j]=='.') sum[3][i][j]=sum[3][i][j+1]+1;

                    }

                else{

                    if(str[i][j]=='.') sum[3][i][j]=sum[3][i][j+1]+1,sum[4][i][j]=sum[4][i+1][j]+1;

                }

            }

        }





        mx=0;

        for(i=0;i<n;i++){

            for(j=0;j<m;j++){

                if(str[i][j]=='.') p=sum[1][i][j]+sum[2][i][j]+sum[3][i][j]+sum[4][i][j];

                mx=max(mx,p-3);

            }

        }



        cout<<mx<<endl;

    }











}