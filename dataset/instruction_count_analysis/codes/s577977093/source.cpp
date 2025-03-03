



#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<math.h>

#include<stack>

#include<queue>

#include<vector>

#include<algorithm>

#include<string>

#include<iostream>

typedef long long ll;

using namespace std;









int a[100001];

int main(){

    int n;cin>>n;

    int ans=0;

    for(int i=1;i<=n;i++){

        int k;cin>>k;

        if(k<=100000)a[k]++;

        else ans++;

    }

    for(int i=1;i<=100000;i++){

        if(a[i]<i)ans+=a[i];

        if(a[i]>i)ans+=a[i]-i;

    }

    printf("%d",ans);

    

    

    return 0;

}
