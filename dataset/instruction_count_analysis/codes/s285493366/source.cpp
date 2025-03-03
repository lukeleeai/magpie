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



int hoge[30][100001];

int used[30][100001];

int anss[100001];

int main (){

      int N,C;

      cin>>N>>C;

      int s[N],t[N],c[N];

      rep0(i,N){

            cin>>s[i]>>t[i]>>c[i];

            --c[i];

      }

      rep0(ch,C){

            rep0(i,N){

                  if(c[i]==ch){

                        hoge[ch][s[i]-1]++;

                        hoge[ch][t[i]]--;

                  }

            }

      }

      rep0(ch,C){

            rep0(t,100001){

                  if(t==0) used[ch][t]=hoge[ch][t];

                  else used[ch][t]=used[ch][t-1]+hoge[ch][t];

            }

      }

      rep0(ch,C)rep0(t,100001){

            if(used[ch][t]>0) used[ch][t]=1;

      }

      rep0(t,100001)rep0(ch,C){

            anss[t]+=used[ch][t];

      }

      int ans=0;

      rep0(t,100001){

            ans=max(ans,anss[t]);

      }

      cout<<ans<<endl;



      

      return 0;

}
