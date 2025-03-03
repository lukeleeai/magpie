#include <cstdio>

#include <vector>

#include <algorithm>

 

 

using namespace std;

 

#define  INF (1<<29)

int matrix[201][201];

void warshall_floyd(int n) { 

    // nは頂点数,matrixにはグラフの距離を格納した2次元配列（隣接行列）

    // d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はINF、ただしd[i][i]=0）

    for (int i = 0; i < n; i++)      // 経由する頂点

      for (int j = 0; j < n; j++)    // 開始頂点

        for (int k = 0; k < n; k++)  // 終端

          matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);

}

 

int main(){

    int N,M,R;

    int r[9];

    scanf("%d %d %d", &N, &M, &R);

    for(int i=0;i<R;i++){

        int in;

        scanf("%d",&in);

        in--;

        r[i] = in;

    }

    for(int i=0;i<N;i++){

        for(int j=0;j<N;j++){

        if(i!=j) matrix[i][j] = INF; 

        else matrix[i][j] = 0;

        }

    }

    for(int i=0; i<M; i++){

        int A,B,C;

        scanf("%d %d %d",&A,&B,&C);

        if(matrix[A-1][B-1]>C) matrix[A-1][B-1] = matrix[B-1][A-1] = C;

    }



    sort(r, r+R);



    warshall_floyd(N);



    /*for(int i=0; i <min(N,8); i++){

        for(int j; j < min(N,8); j++){

            printf("%d\n",matrix[i][j]);

        }

    }*/



    int res = INF;

    do {

        int buf = 0;

        for(int i=0;i<R-1; i++) buf += matrix[r[i]][r[i+1]]; 

        if(res > buf) res = buf;

    } while(next_permutation(r, r+R));   // 次の順列を生成

    printf("%d\n",res);

}