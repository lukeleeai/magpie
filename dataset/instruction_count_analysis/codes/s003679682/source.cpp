#include"stdc++.h"

using namespace std;

typedef long long ll;

const int MOD=1000000007;

#define INF 1LL<<30

#define rep(i,n) for (int i = 0; i < (n); ++i)

#define all(x) (x).begin(),(x).end()



vector<vector<int>> sum(100000);



int main(){

    int h,w,d;

    cin>>h>>w>>d;

    int a[h][w];

    pair<int,int> p[h*w+1];

    rep(i,h){ 

        rep(j,w){

            cin>>a[i][j];

            p[a[i][j]]={i,j};

        }

    }



    //for(int i=1;i<=h*w;i++) cout<<p[i].first<<" "<<p[i].second<<endl; 

    

    for(int i=1;i<=d;i++){

        for(int j=i;j<=h*w;j+=d){

            if(j==i){

                if(i==d) sum[0].push_back(0);

                else sum[i].push_back(0);

            }

            else{

                int c=abs(p[j].first-p[j-d].first)+abs(p[j].second-p[j-d].second);

                if(i==d) sum[0].push_back(c+sum[0][(j-1)/d-1]);

                else sum[i].push_back(c+sum[i][j/d-1]);

            }

        }

    }



    

    int q;

    cin>>q;

    while(q--){

        int l,r;

        cin>>l>>r;

        int x=l%d;

        int ans;

        if(x==0){

            if(l==d) ans=sum[x][(r-1)/d];

            else ans=sum[x][(r-1)/d]-sum[x][(l-1)/d];



        }

        else{

            if(l==x) ans=sum[x][r/d];

            else ans=sum[x][r/d]-sum[x][l/d];

        }

        



        cout<<ans<<endl;

    }    

}




