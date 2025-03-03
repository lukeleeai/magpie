#include"stdc++.h"

using namespace std;

#define IO ios_base::sync_with_stdio(false)

long long a[200000], vs[405][406],vs1[100006],d[500][500],white[500][500];

vector<int>v[200000];

char s[405][405];

void f(int n, int m)

{

    int i, k=0,j=0;

    vs[n][m]=1;

    for(i=0;i<=1; i++)

    for(k=0; k<=1; k++){

            char ch=s[n+i][m+k]; j=0;

        if(abs(i+k)==1&&ch!='*'){

            if(ch=='#'&&s[n][m]=='.') j=1;

            if(vs[n+i][m+k]==0||d[n][m]+j<d[n+i][m+k]){

                d[n+i][m+k]=d[n][m]+j;

                f(n+i,m+k);

            }

        }

    }

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



    if(s[1][1]=='#')d[1][1]++;

    f(1,1);

    cout<<d[n][m]<<endl;

    return 0;



}
