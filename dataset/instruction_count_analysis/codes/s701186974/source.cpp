#include <cstdio>

#include <cmath>

#define ll long long

using namespace std;

int main(){

    ll i;

    ll s,t;

    ll root;

    scanf("%lld",&s);

    root=(ll)sqrt(s);

    if(root*root==s){

        printf("0 0 %lld 0 0 %lld\n",root,root);

        return 0;

    }

    t=(root+1)*(root+1)-s;

    for(i=1;;i++){

        if(t%i==0){

            printf("0 0 %lld %lld %lld %lld\n",root+1,i,t/i,root+1);

            return 0;

        }

    }



}
