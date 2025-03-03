#include "stdc++.h"

using namespace std;

#define ll long long

const int maxx =  100005;

int a[maxx];

int main()

{

    int n;

    cin>>n;

    int flag = 0;

    for(int i=1;i<=n;i++){

        scanf("%d",&a[i]);

    }

    for(int i=2;i<=n;i++){

        if(a[i] > a[i-1]){

            a[i]-=1;

        }

    }

    for(int i=2;i<=n;i++){

        if(a[i] < a[i-1]){

            flag = 1;

        }

    }

    if(flag){

        cout<<"No"<<endl;

    }else{

        cout<<"Yes"<<endl;

    }

    return 0;

}


