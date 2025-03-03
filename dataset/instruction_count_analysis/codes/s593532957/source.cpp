#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;



char s[100017];



void solve(){

    int len=strlen(s);

    if(len<2){

        printf("-1 -1\n");

        return ;

    }

    for(int i=0;i<len;i++){

        if(s[i]==s[i+1]){

            printf("%d %d\n",i+1,i+2);

            return ;

        }else if(s[i]==s[i+2]){

            printf("%d %d\n",i+1,i+3);

            return ;

        }

    }

    printf("-1 -1\n");

        return ;

}



int main(){

    memset(s,0,sizeof(s));

    scanf("%s",s);

    solve();

    return 0;

}
