#include<cmath>

#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

using namespace std;

int n,x,t=1;

int main(){

    cin>>n>>x;

    if(x==1||x==2*n-1){

        cout<<"No"<<endl;

        return 0;

    }

    cout<<"Yes"<<endl;

    for(int i=1;i<n-1;i++){

        while(t==x||t==x-1||t==x+1) t++;

        cout<<t++<<endl;

    }

    cout<<x-1<<endl<<x<<endl<<x+1<<endl;

    for(int i=1;i<n-1;i++){

        while(t==x||t==x-1||t==x+1) t++;

        cout<<t++<<endl;

    }

    return 0;

}
