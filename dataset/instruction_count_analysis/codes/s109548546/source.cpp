#include "stdc++.h"

//using namespace std;

//#define INF 1145141919810893364

//#define REP(i,n) for(int i=0;i<(n);++i)



signed main(void){

    int N,M;

    int a,b;

    std::vector<std::vector<int>> edge;

    

    

    std::cin >> N >> M;

    edge.resize(N);

    for(int i=0;i<M;i++){

        std::cin >> a >> b;

        a--;b--;

        edge[a].push_back(b);

        edge[b].push_back(a);

    }

    

    std::vector<int> Ans(N,-1);

    std::vector<bool> visited(N,false);

    

    std::queue<int> Queue;

    Queue.push(0);

    visited[0]=true;

    

    while(!Queue.empty()){

        int t = Queue.front();

        Queue.pop();

        for(int v:edge[t]){

            if(visited[v])continue;

            Queue.push(v);

            Ans[v]=t;

            visited[v]=true;

        }

    }

    

    for(int i=1;i<N;i++){

        if(Ans[i]==-1){

            std::cout << "No" << std::endl;

            return 0;

        }

    }

    

    std::cout << "Yes" << std::endl;

    for(int i=1;i<N;i++){

        std::cout << Ans[i]+1 << std::endl;

    }

    

    return 0;

}
