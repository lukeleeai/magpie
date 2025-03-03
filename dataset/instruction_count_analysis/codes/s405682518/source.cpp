#include<cstdio>

#include<vector>

using namespace std;



#define MAXN 500

#define PII pair<int,int>

int A[MAXN+5][MAXN+5];

vector<PII> S,T;



int main(){

    int H,W;

    scanf("%d%d",&H,&W);

    for(int i=1;i<=H;i++)

        for(int j=1;j<=W;j++)

            scanf("%d",A[i]+j);

    for(int i=1;i<=H;i++)

        for(int j=1;j<W;j++)

            if(A[i][j]&1){

                S.push_back(make_pair(i,j));

                T.push_back(make_pair(i,j+1));

                A[i][j]--,A[i][j+1]++;

            }

    for(int i=1;i<H;i++)

        if(A[i][W]&1){

            S.push_back(make_pair(i,W));

            T.push_back(make_pair(i+1,W));

            A[i][W]--,A[i+1][W]++;

        }

    printf("%d",S.size());

    for(int i=0;i<int(S.size());i++)

        printf("\n%d %d %d %d",S[i].first,S[i].second,T[i].first,T[i].second);

}
