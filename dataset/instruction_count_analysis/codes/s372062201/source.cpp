#include"stdc++.h"

using namespace std;

int dist[105],n,m,a,b,c,d;

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;

vector<pair<int,int> >x[105];

void add_edge(int a1,int a2,int a3){

    x[a1].push_back(make_pair(a2,a3));

    x[a2].push_back(make_pair(a1,a3));

}

int solve(int b1,int b2){

    for(int i=0;i<105;i++)dist[i]=100000000;dist[b1]=0;

    Q.push(make_pair(0,b1));

    while(!Q.empty()){

        int a1=Q.top().first,a2=Q.top().second;Q.pop();

        for(int i=0;i<(int)x[a2].size();i++){

            int to=x[a2][i].first,len=x[a2][i].second;

            if(dist[to]>a1+len){

                dist[to]=a1+len;

                Q.push(make_pair(dist[to],to));

            }

        }

    }

    if(dist[b2]==100000000)return -1;

    return dist[b2];

}

int main(){

    while(true){

        cin>>n>>m;for(int i=0;i<105;i++)x[i].clear();

        if(n==0 && m==0)break;

        for(int i=0;i<m;i++){

            cin>>a;

            if(a==0){cin>>b>>c;cout<<solve(b,c)<<endl;}

            if(a==1){cin>>b>>c>>d;add_edge(b,c,d);}

        }

    }

}