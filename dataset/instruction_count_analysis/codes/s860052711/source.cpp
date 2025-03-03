#include "stdc++.h"

#include<iostream>

using namespace std;

typedef long long ll;

const int N=1e5+5;

ll u[N],m[N],b[N];

vector<vector<int> > adj;

bool visited[N][10]={};

int nodesNum;

int s,t;





int main(){

   ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);



int x1,y1,x2,y2,x3,y3,x4,y4;

cin>>x1>>y1>>x2>>y2;

int x=x2-x1;

int y=y2-y1;

x3=x2-y;

y3=y2+x;

x4=x1-y;

y4=y1+x;

cout<<x3<<' '<<y3<<' '<<x4<<' '<<y4;



    return 0;

}
