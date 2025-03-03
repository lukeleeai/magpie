#include "stdc++.h"

using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)



class Kruskal{

    private:

    int V=0,E=0;

    typedef std::pair<std::pair<int,int>,long long> P;

    std::vector<int> UF,rank;

    std::vector<std::pair<std::pair<int,int>,long long>> es;

    

    bool comp(P F,P G){

        return F.second<G.second;

    }

    

    int root(int k){

        if(UF[k]==k){

            return k;

        }else{

            UF[k]=root(UF[k]);

            return UF[k];

        }

    }

    

    bool same(int p,int q){

        return root(p)==root(q);

    }

    

    void unite(int P,int Q){

        int p=root(P);

        int q=root(Q);

        if(p==q)return;

        if(rank[p]<rank[q])std::swap(p,q);

        UF[q]=p;

        if(rank[p]==rank[q])rank[p]++;

    }

    

    public:

    

    

    std::vector<P> solve(std::vector<P> edge){

        //頂点数を決定する

        V=0;

        for(int i=0;i<edge.size();i++){

            V=std::max(V,edge[i].first.first+1);

            V=std::max(V,edge[i].first.second+1);

        }

        //辺数をもとめる　

        E=edge.size();

        //unionfindを初期化する

        UF.clear();

        rank.clear();

        for(int i=0;i<V;i++){

            UF.push_back(i);

            rank.push_back(0);

        }

        //辺をソートして代入しておく

        std::sort(edge.begin(),edge.end(),[&](P x, P y){return comp(x, y);});

        es=edge;

        

        std::vector<P> R;

        for(int i=0;i<E;i++){

            if(!same(es[i].first.first,es[i].first.second)){

                unite(es[i].first.first,es[i].first.second);

                R.push_back(es[i]);

            }

        }

        return R;

    }

    

    //solve:{{int,int},longlong}のvectorを渡すことで最小全域木を返す

};





struct machi{

  int x,y,num;  

};



bool compx(machi F,machi G){

    if(F.x!=G.x){

        return F.x<G.x;

    }else{

        return F.y<G.y;

    }

}

bool compy(machi F,machi G){

    if(F.y!=G.y){

        return F.y<G.y;

    }else{

        return F.x<G.x;

    }

}

 

machi city[114514];



int main(){

    int N,x,y;

    cin >> N;

    

    vector<pair<pair<int,int>,long long>> G;

    

    REP(i,N){

        cin >> x >> y;

        city[i].x = x;

        city[i].y = y;

        city[i].num = i;

    }

    

    sort(city,city+N,compx);

    REP(i,N-1){

        int c=min(abs(city[i].x-city[i+1].x),abs(city[i].y-city[i+1].y));

        G.push_back({{city[i].num,city[i+1].num},c});

    }

    

    sort(city,city+N,compy);

    REP(i,N-1){

        int c=min(abs(city[i].x-city[i+1].x),abs(city[i].y-city[i+1].y));

        G.push_back({{city[i].num,city[i+1].num},c});

    }

    

    Kruskal krus;

    G=krus.solve(G);

    

    int Ans=0;

    REP(i,G.size()){

        Ans+=G[i].second;

    }

    

    cout << Ans << endl;

	return 0;

}