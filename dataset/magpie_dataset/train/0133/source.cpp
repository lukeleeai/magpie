#include<iostream>

#include<cstdio>

#include<algorithm>

using namespace std;

long long int cost[101][101],k,n,a,b,c,d,e,which,go[101];

bool used[101];

void dij(int s){

    fill(go,go+101,10000000);

    fill(used,used+101,false);

    go[s]=0;

    while(true){

        int v=-1;

        for(int i=0;i<100;i++){

            if(!used[i]&&(v==-1||go[i]<go[v]))v=i;

        }

        if(v==-1)break;

        used[v]=true;

        for(int i=0;i<100;i++){

            go[i]=min(go[i],go[v]+cost[v][i]);

        }

    }

}

int main(){

    for(;;){

        cin>>n>>k;

        if(n==0&&k==0)break;

        fill(cost[0],cost[0]+101*101,10000000);

        for(int i=0;i<k;i++){

            cin>>which;

            if(!which){

                cin>>a>>b;

                dij(a-1);

                if(go[b-1]!=10000000)cout<<go[b-1]<<endl;

                else cout<<-1<<endl;

            }

            else {

                cin>>c>>d>>e;

                cost[c-1][d-1]=min(cost[c-1][d-1],e);

                cost[d-1][c-1]=min(cost[d-1][c-1],e);

            }

        }

    }

    return 0;

}