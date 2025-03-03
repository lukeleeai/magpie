#include"stdc++.h"

#include<string.h>

using namespace std;

int main(){

    char str[150][150]={'\0'};

int i,j,k,l,m,n,arr[10];

    scanf("%d%d",&m,&n);

    //char a=getchar();

    for(i=0;i<m;i++){

       // gets(str[i]);

       scanf("%s",str[i]);

    }

    for(i=0;i<m;i++){k=0;

        for(j=0;j<n;j++){

            if(str[i][j]=='.')

            k++;

        }

        if(k==n)

        for(l=0;l<n;l++) str[i][l]='1';

    }

    for(i=0;i<n;i++){k=0;

        for(j=0;j<m;j++){

            if(str[j][i]=='.'||str[j][i]=='1')

            k++;

        }

        if(k==m)

        for(l=0;l<m;l++) str[l][i]='1';

    }



    for(i=0;i<m;i++){

        for(j=0;j<n;j++){

            if(str[i][j]!='1'&&j!=n-1)

                printf("%c",str[i][j]);

            if(str[i][j]!='1'&&j==n-1)

                printf("%c\n",str[i][j]);

            else if(str[i][j]=='1'&&j==n-1)

             printf("\n");

        }



    }





    return 0;

}
