

#include "stdc++.h"

using namespace std;

int c = 0;

vector< vector<int> > v(2500, vector<int>(15,0));

vector<int> buf(15);



void dfs(int i,const int size, const int range_start, const int range_end)

{

    if (i == size) {

        for(int i = 0; i < size; ++i){

            v[c][i] = buf[i];

        }

        c++;

    }

    else{

        for(int j = range_start; j <= range_end; ++j){

            buf[i] = j;

            dfs(i + 1, size, range_start, range_end);

        }

    }

}



int main(){

    int N,M; cin >> N >> M;

    int ans = 0;

    int k[M]; int s[20][M]; int p[M];

    for(int i = 0;i<M;i++){

        cin >>k[i];

        for(int j = 0;j<k[i];j++) {cin >> s[i][j]; s[i][j]--;}

    }

    for(int i = 0;i<M;i++) cin >> p[i]; 





    dfs(0, N, 0, 1);



    for(int i = 0;i<pow(2,N);i++){

        for(int j=0;j<M;j++){

            int div = 0;

            for(int l=0;l<k[j];l++){

                if(v[i][s[j][l]] == 1) div++;

            }

            //cout << div << endl;

            //cout << div%2;

            if (div%2 != p[j])  break;

            if(j == M-1) ans++;

        }

    }

    

    cout << ans << endl;

    

}


