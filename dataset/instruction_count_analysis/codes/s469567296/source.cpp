#include<iostream>

#include<algorithm>

#include<cstring>

#include<string>

#include<cstdio>

using namespace std;

string a[100000];

int main(){

    long long n;

    cin>>n;

    long long ans=0;

    for(long long i=0;i<n;i++){

        cin>>a[i];

        std::sort(a[i].begin(),a[i].end());

    }

    sort(a,a+n);

    long long z[100000]={0},cnt=0;

    for(long long  i=0;i<n;i++){

        if(i==0){

            z[cnt]=1;

            continue;

        }

        if(a[i]==a[i-1]){

            z[cnt]++;

        }

        else{

            cnt++;

            z[cnt]++;

        }

    }



    for(long long  i=0;i<=cnt;i++){

        ans+=((z[i]*(z[i]-1))/2);

    }

    cout<<ans;

}
