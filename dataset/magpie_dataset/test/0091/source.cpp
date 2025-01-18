#include<iostream>

#include<cmath>

#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

int main(){

    char c,k;

    int ans=0;

    scanf("%c",&c);

    printf("%c",c);

    while(scanf("%c",&c)!=-1){

        //记住cin输入失败返回0，scanf输入失败返回-1

        if(c==' '||c=='\n')break;

        ans++;

        k=c;

    }

    printf("%d%c",ans-1,k);

    return 0;

}