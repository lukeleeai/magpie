#include"stdc++.h"

using namespace std;

#define IO ios_base::sync_with_stdio(false)

long long a[200000], vs[405][406],vs1[100006],to[500][500],white[500][500];

vector<int>v[200000];

char s[405][405];

void f(int n, int m, int co)

{

    int i, k=0;

    vs[n][m]=1;

    for(i=-1;i<=1; i++)

    for(k=-1; k<=1; k++){

            char ch=s[n+i][m+k];

        if(abs(i+k)==1&&ch!='*'){

            if(vs[n+i][m+k]==0&&((co==1&&ch=='.')||(co==0&&ch=='#'))){

                f(n+i,m+k,1-co);

                to[n][m]+=to[n+i][m+k];

                white[n][m]+=white[n+i][m+k];

            }

        }

    }

    to[n][m]++;

    if(s[n][m]=='.')white[n][m]++;

}

int main()

{

    IO;

    long long i, j, m, k, n, t, l=0, mx,ll,mxx,mx1;

    cin>>n>>m;

    for(i=0; i<=n+1; i++)

        for(j=0; j<=m+1; j++) s[i][j]='*';

    for(i=1; i<=n; i++)

        for(j=1; j<=m; j++) cin>>s[i][j];

    for(i=1; i<=n; i++)

        for(j=1; j<=m; j++){

            if(vs[i][j]==0&&s[i][j]=='#'){

                f(i,j,1);

                l+=(to[i][j]-white[i][j])*white[i][j];

            }

        }

    cout<<l<<endl;

    return 0;



}
