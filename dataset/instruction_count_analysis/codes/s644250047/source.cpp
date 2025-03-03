#include"stdc++.h"

#define l strlen(s)

using namespace std;

int main(){

	char s[100012]={};

    scanf("%s",&s);

    if(l%2==1){

        printf("No");

        return 0;

    }

    for(int i=0;i<l/2;i++){

        int u=abs(s[i]-s[l-i-1]);

        if(u!=1&&u!=2){

            printf("No");

            return 0;

        }

    }

    printf("Yes");

}