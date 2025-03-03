#include <iostream>

#include <string.h>

#include <cmath>

using namespace std;



int main(){



    int c[21][21],w,h;

    memset(c,0,sizeof(c));

    char t;

    while(1){

    cin>>w>>h;if(w==0&&h==0)return 0;

    for(int i=0;i<w*h;i++){cin>>t;c[i%w][i/w]=t;}

    for(int i=0;i<w*h;i++){

      for(int j=0;j<w*h;j++)

        if(c[j%w][j/w]==64){

	  if(c[j%w-1][j/w]==46)c[j%w-1][j/w]=64;

          if(c[j%w+1][j/w]==46)c[j%w+1][j/w]=64;

          if(c[j%w][j/w-1]==46)c[j%w][j/w-1]=64;

          if(c[j%w][j/w+1]==46)c[j%w][j/w+1]=64;

        }

    }

    int cou=0;

    for(int i=0;i<w*h;i++)if(c[i%w][i/w]==64)cou++;

    cout<<cou<<endl;

    } 

}