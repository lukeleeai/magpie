#include <cstdio>

#include <vector>

using namespace std;



vector<int> l[10000];

int s[10000];

int n;



void unite(int x, int y){

    if(s[x]==s[y])return;



    int i,j,tmp;

    int sx = s[x];

    int sy = s[y];

    for(i=0;i<l[sy].size();i++){

        tmp = l[sy][i];

        s[tmp] = sx;

        l[sx].push_back(tmp);

    }

    l[sy].clear();

    return;

}



bool same(int x, int y){

    return s[x]==s[y];

}



int main(){

    int i,q,com,x,y;

    scanf("%d %d",&n,&q);

    for(i=0;i<n;i++){

        s[i]=i;

        l[i].push_back(i);

    }

    for(i=0;i<q;i++){

        scanf("%d %d %d",&com,&x,&y);

        if(com==0)unite(x,y);

        else{

            if(same(x,y))printf("1\n");

            else printf("0\n");

        }

    }

    return 0;

}


