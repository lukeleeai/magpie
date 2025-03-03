#include <iostream>

#include <algorithm>

#include <vector>

#include <string>

#include <queue>

#include <cstdio>



using namespace std;



int n;

int s,t;

const int INF=1000000000;



inline void setBit(int &s,int pos,int bit){

    if(bit)s|=(1<<pos);

    else s&=~(1<<pos);

}



class Sit{

public:

    int cost;

    int pos;

    int mask;

    Sit(int cost_,int pos_,int mask_){

        cost=cost_;

        pos=pos_;

        mask=mask_;

    }

    bool operator<(const Sit &s)const {

        return s.cost<this->cost;

    }

};



int d[16][1<<16];

priority_queue<Sit> que;

int bfs(){

    for(int j=0;j<n;j++)for(int k=0;k<(1<<n);k++)d[j][k]=INF;

    for(int i=0;i<n;i++){

        d[i][s]=0;

        que.push(Sit(0,i,s));

    }

    while(!que.empty()){

        Sit s=que.top();que.pop();

        if(d[s.pos][s.mask]<s.cost)continue;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                // ·ÅÉèÏÝ

                if((!(((s.mask>>i)&1)^((t>>i)&1)))||(!(((s.mask>>j)&1)^((t>>j)&1)))){

                    continue;

                }

                //  éêÖÚ®µÄA»ÌêÆð·

                int cost=abs(i-s.pos)+abs(j-i);

                int nmask=s.mask;

                int a=(nmask>>i)&1;

                int b=(nmask>>j)&1;

                setBit(nmask,i,b);

                setBit(nmask,j,a);

                if(d[j][nmask]>d[s.pos][s.mask]+cost){

                    d[j][nmask]=d[s.pos][s.mask]+cost;

                    que.push(Sit(d[j][nmask],j,nmask));

                }

            }

        }

    }

    int res=INF;

    for(int i=0;i<n;i++)res=min(res,d[i][t]);

    return res;

}

//int solve(){

//    return bfs();

//    //for(int tern=n;tern>=0;tern--){

//    //    int nxt=tern%2;

//    //    int cur=(tern+1)%2;

//    //    for(int pos=0;pos<n;pos++){

//    //        for(int sit=0;sit<(1<<n);sit++){

//    //            int res=INF;

//    //            if(tern==n){

//    //                if(sit==t)res=0;

//    //            }

//    //            else{

//    //                for(int to=0;to<n;to++){

//    //                    // ®©·¾¯

//    //                    res=min(res,dp[cur][to][sit]+abs(to-pos));

//    //                    // trade

//    //                    int cost=abs(to-pos);

//    //                    int nsit=sit;

//    //                    int a=(sit>>pos)&1;

//    //                    int b=(sit>>to)&1;

//    //                    setBit(nsit,pos,b);

//    //                    setBit(nsit,to,a);

//    //                    res=min(res,dp[cur][to][nsit]+cost);

//    //                }

//    //            }

//    //            dp[nxt][pos][sit]=res;

//    //        }

//    //    }

//    //}

//    //int res=INF;

//    //for(int i=0;i<n;i++)res=min(res,dp[0][i][s]);

//    //return res;

//}

int main(){



    string ss,tt;

    while(cin>>n&&n){

        s=t=0;

        cin>>ss>>tt;

        for(int i=0;i<n;i++)if(ss[i]=='B')s|=(1<<i);

        for(int i=0;i<n;i++)if(tt[i]=='B')t|=(1<<i);

        printf("%d\n",bfs());

    }



    return 0;

}