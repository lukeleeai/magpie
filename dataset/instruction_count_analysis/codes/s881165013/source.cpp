#include<cstdio>

#include<iostream>

#include<cmath>

#include<string.h>

using namespace std;



#define maxn 101



int flag[101][101];

char c[101][101];

int main(){



   int h, w;

   while(cin >> h >> w ){

        memset(flag, 0, sizeof(flag));

        for(int i = 0; i < h; ++i){

            scanf("%s", &c[i]);

        }



        for(int i = 0; i < h; ++i){

             int p = 1;

             for(int j = 0; j < w; ++j){

                 if(c[i][j] != '.') p = 0;

             }

             if(p){

                 for(int j = 0; j < w; ++j) flag[i][j] = 1;

             }

        }

        for(int j = 0; j < w; ++j){

              int p = 1;

              for(int i = 0; i < h; ++i){

                  if(c[i][j] != '.') p = 0;

              }

              if(p){

                 for(int i = 0; i < h; ++i) flag[i][j] = 1;

              }

        }

        for(int i = 0; i < h; ++i){

            int p = 0;

            for(int j = 0; j < w; ++j){

                if(!flag[i][j]) {cout << c[i][j]; p = 1;}

            }

            if(p == 1)

               cout <<endl;

        }



   }

  return 0;

}
