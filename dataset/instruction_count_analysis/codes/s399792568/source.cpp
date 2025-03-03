#include"stdc++.h"

using namespace std;

typedef long long ll;



int main(){

    int n,m,a[10],s,c;

    map<int,int>q;

    cin>>n>>m;

    int flag=1;

    memset(a,-1,sizeof(a));

    while(m--){

        cin>>s>>c;

        if(q.count(s)==0){

            q[s]=c;

            a[s]=c;

        }

        else{

            if(q[s]!=c) flag=0;

        }

    }

    if(a[1]==0 && n>1) flag=0;

    if(flag==0) puts("-1");

    else{

        if(n>1){

            for(int i=1;i<=n;i++){

                if(a[i]==-1 && i==1) cout<<1;

                else if(a[i]==-1 && i>1) cout<<0;

                else cout<<a[i];

            }

        }

        else{

            if(a[1]==-1) cout<<0;

            else cout<<a[1];

        }

    }

    return 0;

}
