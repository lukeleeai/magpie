#include <iostream>

#include <algorithm>

#include <cstring>

#include <cstdio>

#include <vector>

#include <queue>

#include <stack>

#include <cstdlib>

#include <iomanip>

#include <cmath>

#include <cassert>

#include <ctime>

#include <cstdlib>

#include <map>

#include <set>

using namespace std;

#pragma comment(linker, "/stck:1024000000,1024000000")

#define lowbit(x) (x&(-x))

#define max(x,y) (x>=y?x:y)

#define min(x,y) (x<=y?x:y)

//#define MAX 100000000000000000

#define MOD 1000000007

#define pi acos(-1.0)

#define ei exp(1)

#define PI 3.1415926535897932384626433832

#define ios() ios::sync_with_stdio(true)

#define INF (1<<31)-1;

#define mem(a) (memset(a,0,sizeof(a)))

struct P{

    int x,y;

}H[200000];

vector<int>G[200000];

int POS(int k,int value){

    int mid;

    int left = 0;

    int len = G[k].size();

    int right = len - 1;

    //cout<<" "<<k<<"A"<<value<<endl;

    while(left <= right){

 

        // 确保中点靠近区间的起点

        mid = left + (right-left)/2;

        //cout<<mid<<endl;

        //cout<<"mid= "<<mid<<" "<<left<<" "<<right<<endl;

        // 如果找到则返回

        if(G[k][mid] == value) return mid;

        // 将中点赋给终点

        else if(G[k][mid] > value) right = mid;

        // 将中点加一赋给起点

        else left = mid + 1;

    }

    return -1;

}

set<int>::iterator it;

int main()

{

    set<int>s;

    int N,M;

    int x,y;

    cin>>N>>M;

    for(int i=1;i<=M;i++){

        cin>>x>>y;

        H[i].x = x;

        H[i].y = y;

        G[x].push_back(y);

        s.insert(x);

    }

    for(int i=1;i<=N;i++){

        sort(G[i].begin(),G[i].end());

    }

 

 

    for(int i=1;i<=M;i++){

        cout<<setw(6)<<setfill('0')<<H[i].x;

        cout<<setw(6)<<setfill('0')<<POS(H[i].x,H[i].y)+1<<endl;

    }

    return 0;

}