#include"stdc++.h"

using namespace std;

using ll=long long;

#define fr(i,n) for(int i=0;i<(n);++i)

#define Fr(i,n) for(int i=1;i<=(n);++i)

#define ifr(i,n) for(int i=(n)-1;i>=0;--i)

#define iFr(i,n) for(int i=(n);i>0;--i)



int main(){

    cin.tie(nullptr);

    ios::sync_with_stdio(false);

    istream& in(cin);

    ostream& out(cout);

    int n;

    scanf("%d",&n);

    if(n==2) return cout<<-1<<endl,0;

    if(n==3) return puts("aa.\n..a\n..a"),0;

    vector<string> q={"aabc","ddbc","bcaa","bcdd"},

            p={"aabbc","cdd.c","c..ba","a..ba","accdd"},

            h={".llkkj","iihh.j","ggfe..","..fedd","c...ba","c...ba"},

            s={".nnmmll","kkjji..","hhggi..","f....ed","f....ed","....cba","....cba"};

    vector<string> ans(n,string(n,'.'));

    fr(i,n/4){

        fr(I,4) fr(J,4){

            ans[4*i+I][4*i+J]=q[I][J];

        }

    }

    if(n%4==1) fr(i,5) fr(j,5) ans[n-5+i][n-5+j]=p[i][j];

    if(n%4==2) fr(i,6) fr(j,6) ans[n-6+i][n-6+j]=h[i][j];

    if(n%4==3) fr(i,7) fr(j,7) ans[n-7+i][n-7+j]=s[i][j];

    fr(i,n) printf("%s\n",ans[i].c_str());

}