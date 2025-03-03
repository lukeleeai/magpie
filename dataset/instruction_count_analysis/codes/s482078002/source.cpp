#include<iostream>

#include<vector>

#include<string>

#include<set>

#include<map>

#include<algorithm>

#include<queue>

#include<list>

#include<stack>

#include<cstdio>

#include<fstream>

#include<numeric>

#include<functional>

#include<utility>

#include<memory>

#include <cstring>

using namespace std;

const int M = 1e3;

char mmp[M][M] , s[M][M];

int h , w , k , step[M][M] , dr[4][2] = {1 , 0 , -1 , 0 , 0 , 1 , 0 , -1};

struct TnT {

    int x , y , step , flag;

};

bool visit[M][M];

void bfs(TnT sta) {

    memset(step , 0 , sizeof(step));

    step[sta.x][sta.y] = 1;

    memset(visit, false , sizeof(visit));

    visit[sta.x][sta.y] = true;

    queue<TnT>q;

    q.push(sta);

    while(!q.empty()) {

        TnT gg = q.front();

        q.pop();

        for(int i = 0 ; i < 4 ; i++) {

            TnT gl = gg;

            gl.x += dr[i][0];

            gl.y += dr[i][1];

            if(gl.x >= 0 && gl.x < h && gl.y >= 0 && gl.y < w && mmp[gl.x][gl.y] != '#' && !visit[gl.x][gl.y]) {

                gl.step++;

                step[gl.x][gl.y] = gl.step;

                visit[gl.x][gl.y] = true;

                q.push(gl);

            }

        }

    }

}

int main() {

    cin>>h>>w>>k;

    for(int i = 0 ; i < h ; i++) {

        cin>>mmp[i];

    }

    TnT sta;

    for(int i = 0 ; i < h ; i++) {

        for(int j = 0 ; j < w ; j++) {

            if(mmp[i][j] == 'S') {

                sta.x = i , sta.y = j;

                break;

            }

        }

    }

    sta.step=0 , sta.flag=k;

    bfs(sta);

    int ans=1000000000;

    for(int i=0;i<h;i++) {

        for(int j=0;j<w;j++) {

            if(step[i][j] != 0) {

                if(i == 0 || i == h - 1 || j == 0 || j == w - 1) {

                    int gg = step[i][j];

                    if(gg % k == 0) {

                        ans = min(ans , gg / k);

                    }

                    else {

                        ans = min(ans , gg / k + 1);

                    }

                }

                else {

                    int gg = step[i][j] , gl = 0;

                    if(gg % k == 0) {

                        gl = gg / k;

                    }

                    else {

                        gl = gg / k + 1;

                    }

                    gg = i;

                    if(gg % k == 0) {

                        ans = min(ans , gl + gg / k);

                    }

                    else {

                        ans = min(ans , gl + gg / k + 1);

                    }

                    gg = j;

                    if(gg % k == 0) {

                        ans = min(ans , gl + gg / k);

                    }

                    else {

                        ans = min(ans , gl + gg / k + 1);

                    }

                    gg = h - 1 - i;

                    if(gg % k == 0) {

                        ans = min(ans , gl + gg / k);

                    }

                    else {

                        ans = min(ans , gl + gg / k + 1);

                    }

                    gg = w - 1 - j;

                    if(gg % k == 0) {

                        ans = min(ans , gl + gg / k);

                    }

                    else {

                        ans = min(ans , gl + gg / k + 1);

                    }

                }

            }

        }

    }

    cout<<ans;

    return 0;

}