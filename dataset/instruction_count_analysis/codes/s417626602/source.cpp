#include"stdc++.h"

using namespace std;

int main(){

    int n,x[100005],y[100005],t[100005];

    cin>>n;

    for(int i=0;i<n;i++){

        cin>>t[i]>>x[i]>>y[i];

    }

    for(int i=0;i<n;i++){

    	if(x[i]+y[i]>t[i]||(t[i]-x[i]-y[i])%2!=0){

            cout<<"No";

            return 0;   

        }

	}

        

        cout<<"Yes";

        return 0;

}