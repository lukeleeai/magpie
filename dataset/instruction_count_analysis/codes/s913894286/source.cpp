#include"stdc++.h"

using namespace std;

int main(){

    int n,m,d;

    scanf("%d%d%d",&n,&m,&d);

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            int x=(i+j)/d%2;

            int y=(m+i-j)/d%2;

            char c="RGBY"[2*x+y];

            printf("%c",c);

        }

        printf("\n");

    }    

    return 0;

}