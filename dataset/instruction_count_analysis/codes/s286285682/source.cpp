//In the name of God

#include"stdc++.h"



using namespace std;

typedef long long ll;

typedef pair<int , int> pii;



const int N = 1e5 + 10;



map<pii , bool> block , mark;

ll res[10] , h , w;

int n , a[N] , b[N] , cnt;



void check(int x , int y){

        if(x <= 1 || x >= h || y <= 1 || y >= w || mark[{x,y}])

                return;

        int now = 0; 

        for(int dx = -1 ; dx < 2 ; dx++) 

                for(int dy = -1 ; dy < 2 ; dy++)

                                now += (block[{x+dx , y+dy}] == 1);

        res[now]++;

        mark[{x,y}] = 1;

        cnt++;

}



int main(){

        ios_base::sync_with_stdio(false);

        cin.tie(0);

        cout.tie(0);

        cin >> h >> w >> n; 

        for(int i=0 ; i < n ; i++){

                cin >> a[i] >> b[i];

                block[{a[i],b[i]}] = 1;

        }

        for(int i=0 ; i < n ; i++)

                for(int dx = -1 ; dx < 2 ; dx++)

                        for(int dy = -1 ; dy < 2 ; dy++)

                                check(a[i] + dx , b[i] + dy);

        res[0] = (h-2) * (w-2) - cnt;

        for(int i=0 ; i < 10 ; i++)

                cout << res[i] << "\n";

        return 0;

}