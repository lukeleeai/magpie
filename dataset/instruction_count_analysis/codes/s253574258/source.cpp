#include<map>

#include<iostream>

#include<deque>

#include<algorithm>

#include<string>

#include<cctype>

#include<iomanip>

#include<vector>

#include<queue>

 

using namespace std;

#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)

#define rep0(i,n) REP(i,0ll,n)

#define rep1(i,n) REP(i,1ll,n+1)

 

#define shosu setprecision(10)

 

typedef long long ll;

typedef pair<int,int> P;

ll longinf=1ll<<60;

int inf=1<<29;

int dx[4]={1,-1,0,0};

int dy[4]={0,0,1,-1};

int main (){

      int N,C;

      cin>>N>>C;

      int s[N],t[N],c[N];

      int maxt=0;

      rep0(i,N){

            cin>>s[i]>>t[i]>>c[i];

            maxt=max(maxt,t[i]);

            --c[i];

      }

      int huu=((maxt+1))*C;

      int hoge[huu];

      int used[huu];

      int anss[maxt+1];

      fill(hoge,hoge+huu,0);

      fill(used,used+huu,0);

      fill(anss,anss+maxt+1,0);



      rep0(ch,C){

            rep0(i,N){

                  if(c[i]==ch){

                        hoge[ch*(maxt+1)+(s[i]-1)]++;

                        hoge[ch*(maxt+1)+(t[i])]--;

                  }

            }

      }

      rep0(ch,C){

            rep0(t,maxt+1){

                  if(t==0) used[ch*(maxt+1)+t]=hoge[ch*(maxt+1)+t];

                  else used[ch*(maxt+1)+t]=used[ch*(maxt+1)+(t-1)]+hoge[ch*(maxt+1)+t];

            }

      }

      rep0(ch,C)rep0(t,(maxt+1)){

            if(used[ch*(maxt+1)+t]>0) used[ch*(maxt+1)+t]=1;

      }

      rep0(t,(maxt+1))rep0(ch,C){

            anss[t]+=used[ch*(maxt+1)+t];

      }

      int ans=0;

      rep0(t,(maxt+1)){

            ans=max(ans,anss[t]);

      }

      cout<<ans<<endl;



      

      return 0;

}
