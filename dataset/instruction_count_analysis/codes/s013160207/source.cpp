#include<cstdio>

#include<iostream>

#include<string>

#include<algorithm>

#include<vector>

#include<queue>



#define reps(i,f,n) for(int i=f;i<int(n);i++)

#define rep(i,n) reps(i,0,n)



class L{

    public:

    int to,coop,dist;

    L(int to,int coop,int dist):to(to),coop(coop),dist(dist){}

};



class T{

    public:

    int now;

    int coop;

    int val;

    T(int now,int val,int coop):now(now),val(val),coop(coop){}

    bool operator<(const T& a)const{

        return val>a.val;

    }

};



using namespace std;

const int DMAX = 22222;



int cost[22][DMAX];

vector<L> load[111];

vector<L> load2[111];



void init(){

    rep(i,22)rep(j,DMAX)cost[i][j]=0;

    rep(i,111)load[i].clear();

    rep(i,111)load2[i].clear();

}

/*

20 38 2 6 13

6 9 14 1

19 4 18 1

14 20 20 1

3 16 6 2

17 5 13 2

18 12 16 1

1 13 18 2

3 15 15 2

11 19 7 1

18 15 6 1

16 3 4 1

20 16 7 2

3 15 13 1

14 2 19 1

4 19 3 2

1 5 4 1

8 10 11 1

7 10 12 1

1 13 2 1

14 20 5 2

8 9 10 1

10 7 14 2

20 16 17 1

18 12 13 2

10 8 20 2

15 18 5 2

5 1 9 2

19 11 13 2

7 11 3 1

9 8 7 2

7 11 15 2

17 2 10 2

2 14 8 2

4 12 3 1

17 5 8 1

2 17 7 1

4 12 9 2

9 6 20 2

1 1



1



1

*/



int main(){

    int ldcont=0;

    while(1){

        init();



        int n,m,c,s,g;

        cin>>n>>m>>c>>s>>g;

        ldcont++;



        if(n==0)break;



        rep(i,m){

            int st,en,dist,coop;

            cin>>st>>en>>dist>>coop;

            ldcont++;



            load[st].push_back(L(en,coop,dist));

            load[en].push_back(L(st,coop,dist));

        }



        int p[22]={0};

        reps(i,1,c+1){cin>>p[i]; ldcont++;}





        int q[22][55]={0};

        int r[22][55]={0};

        reps(i,1,c+1){

            rep(j,p[i]-1)cin>>q[i][j];

            rep(j,p[i])cin>>r[i][j];

            ldcont++;ldcont++;



            cost[i][0]=0;

            int cont = 0;

            reps(j,1,DMAX){

                cost[i][j] = cost[i][j-1]+r[i][cont];

                if(q[i][cont]==j)cont++;

            }



            /*

            rep(j,23){

                printf("%d-%d ",j,cost[i][j]);

                j++;

            }puts("");*/

        }



        priority_queue<T> que;

        reps(pst,1,n+1){

            reps(cst,1,c+1){

                int visit[111][22]={0};

                priority_queue<T> que;

                que.push(T(pst,0,cst));



                while(1){

                    if(que.empty())break;



                    T u = que.top();

                    que.pop();



                    if(visit[u.now][u.coop]==1)continue;

                    visit[u.now][u.coop]=1;



                    rep(i,load[u.now].size()){

                        L ld = load[u.now][i];

                        if(u.coop != ld.coop)continue;

                        if(visit[ld.to][ld.coop]==1)continue;



                        que.push(T(ld.to, u.val+ld.dist, ld.coop));

                    }



                    if(u.val!=0){

                        load2[pst].push_back(L(u.now, u.coop, u.val));

                    }

                }

            }

        }





        priority_queue<T> que2;

        que2.push(T(s,0,-1));



        int ans = -1;

        int visit2[111][22]={0};



        while(1){

            if(que2.empty())break;



            T u = que2.top();

            que2.pop();



            if(visit2[u.now][u.coop]==1)continue;

            visit2[u.now][u.coop]=1;



            if(u.now==g){

                ans = u.val;

                break;

            }

            //printf("now=%d val=%d coop=%d\n",u.now,u.val,u.coop);



            rep(i,load2[u.now].size()){

                L ld = load2[u.now][i];

                que2.push(T(ld.to, u.val+cost[ld.coop][ld.dist], u.coop));

            }

        }

        printf("%d\n",ans);



        /*

        rep(i,n){

            rep(j,load2[i].size()){

                L ld = load2[i][j];

                printf("%d-%d-%d-%d  ",i,ld.to,ld.coop,ld.dist);

            }puts("");

        }*/

    }

}