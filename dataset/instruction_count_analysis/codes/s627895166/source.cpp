#include <cstdio>

#include <algorithm>

#include <vector>

#include <utility>



using namespace std;



int N,M,H,K;



typedef pair<int,int> cor_t;//height, vertStcik index



struct knot_t{

    int col;

    int score;

    bool turned;//対応する横棒で曲がる得点　ここで曲がったことありますか

    knot_t* parallel;

    knot_t* next;

};



int scores[1005];

cor_t horizontalSticks[100007];

vector<knot_t> vertSticks[1005];



void init(){

    for(int i=1;i<=N;i++) scanf("%d",scores+i);

    for(int i=1;i<=M;i++){

        scanf("%d",&horizontalSticks[i].second);

        scanf("%d",&horizontalSticks[i].first);

        horizontalSticks[i].first=H-horizontalSticks[i].first;

    }

    for(int i=1;i<=N;i++) vertSticks[i].clear(),vertSticks[i].reserve(1005);

}



void search(knot_t& a){

    a.turned=true;

    auto nextptr=a.parallel->next;

    if (nextptr&&!nextptr->turned) search(*nextptr);

}



int main(){



    while(scanf("%d%d%d%d",&N,&M,&H,&K)

        &&

        N&&M&&H&&K){

        init();

        sort(horizontalSticks+1,horizontalSticks+M+1);

        for(int i=1;i<=M;i++){

            auto &cur=horizontalSticks[i];

            int leftIndex=cur.second,rightIndex=leftIndex+1;

            auto &left=vertSticks[leftIndex],&right=vertSticks[rightIndex];

            auto leftTop=left.empty()?nullptr:&left.back(),

                 rightTop=right.empty()?nullptr:&right.back();

            int leftScore=left.empty()?scores[leftIndex]:left.back().score,

                rightScore=right.empty()?scores[rightIndex]:right.back().score;

            //左/右の縦棒から直行する時の得点

            left.push_back(

                {cur.second,rightScore,false,nullptr,leftTop}

                );

            right.push_back(

                {cur.second+1,leftScore,false,nullptr,rightTop}

                );

            left.back().parallel=&right.back();

            right.back().parallel=&left.back();

        }



        for(int i=1;i<=K;i++) if (!vertSticks[i].empty()) search(vertSticks[i].back());



        int sum=0;

        for(int i=1;i<=K;i++) sum+=vertSticks[i].empty()?scores[i]:vertSticks[i].back().score;



        int diff=0;

        for(int i=1;i<=N;i++){

            auto &curCol=vertSticks[i];

            for(auto &a:curCol){

                auto &fst=a,&snd=*a.parallel;

                auto fstCandidate=fst.next?fst.next->score:scores[fst.col];

                auto sndCandidate=snd.next?snd.next->score:scores[snd.col];

                diff=min(diff,fst.turned*(fstCandidate-fst.score)+snd.turned*(sndCandidate-snd.score));

            }

        }

        printf("%d\n",sum+diff);

    }





    return 0;

}
