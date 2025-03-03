#include"stdc++.h"

using namespace std;

const int N = 1e3 + 7;

int mp[N][N];//,cntr[N],cntc[N];

int main()

{

    int r,c,a,b;

    while(~scanf("%d%d%d%d",&r,&c,&a,&b)){

        int tmp;

        memset(mp, 0, sizeof mp);

        for(int i=1;i<=r;i++){

            if(i&1){

                for(int j=1;j<=a;j++){

                    mp[i][j] = 1;

                }

            }

            else{

                for(int j=a+1;j<=c;j++){

                    mp[i][j] = 1;

                }

            }

        }

        /*for(int i=1;i<=r;i++){

            for(int j=1;j<=c;j++){

                printf("%d",mp[i][j]);

            }puts("");

        }puts("");*/

        if(b < r/2){

            for(int i=1;i<=r/2-b;i++){

                for(int j=1;j<=a;j++){

                    mp[i*2][j] = 1;

                }

                for(int j=a+1;j<=c;j++){

                    mp[i*2][j] = 0;

                }

            }

        }

        for(int i=1;i<=r;i++){

            for(int j=1;j<=c;j++){

                printf("%d",mp[i][j]);

            }puts("");

        }

    }

}
