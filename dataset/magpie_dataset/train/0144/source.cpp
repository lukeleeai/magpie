#include<cstdio>

#include<cstring>

#include<algorithm>

#include<iostream>

using namespace std;

int chain(int idx,int col);

int model[10002];

int n;

int main(void){

   while(scanf("%d",&n),n){

      int mi = n;

      memset(model,0,sizeof(model));

      for(int i = 0;i < n;i++){

         scanf("%d",&model[i]);

      }



      for(int i = 0;i < n;i++){

         for(int j = 1;j <= 3;j++){

            mi = min(mi,chain(i,j));

         }

      }

      printf("%d\n",mi);

   }

   return 0;

}



int chain(int idx,int col){

   if(model[idx] == col) return n;

   int c[10002];

   int f[10002] = {0};

   for(int i = 0;i < n;i++){

      if(idx == i)

         c[i] = col;

      else c[i] = model[i];

   }

   c[n] = 100;



   while(1){

      int flag = 0;

      int curr = c[0],cnt = 1;

      for(int i = 1;i <= n;i++){

         if(c[i] == 0) continue;

         if(c[i] == curr) cnt++;

         else{

            curr = c[i];

            if(cnt >= 4){

               flag = 1;

               for(int j = 0;j < cnt;j++){

                  if(f[i-1-j] == 1) cnt++;

                  f[i-1-j] = 1;

                  c[i-1-j] = 0;

               }

               break;

            }

            cnt = 1;

         }

      }

      if(flag == 0) break;

   }



   int cnt = 0;

   for(int i = 0;i < n;i++){

      if(f[i] == 0) cnt++;

   }

   return cnt;

}