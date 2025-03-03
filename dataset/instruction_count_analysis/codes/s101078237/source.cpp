#include<cstdio>

#include<cstdlib>

#include<iostream>

#include<algorithm>

#include<cmath>

#include<map>

#include<queue>

#include<stack>

#include<list>

#include<set>

#include<cstring>

#include<string>

using namespace std;

int main(){

    int a,b,c,d;

    scanf("%1d%1d%1d%1d",&a,&b,&c,&d);

    for(int i=43;i<=45;i+=2){

        for(int j=43;j<=45;j+=2){

            for(int k=43;k<=45;k+=2){

                int ans=a;

                if(i==43)ans+=b;

                	else ans-=b;

                if(j==43)ans+=c;

                	else ans-=c;

                if(k==43)ans+=d;

               	 	else ans-=d;

                if(ans==7){

                    printf("%d%c%d%c%d%c%d=7\n",a,i,b,j,c,k,d);

                    return 0;

                }

            }

        }

    }

    return 0;

}