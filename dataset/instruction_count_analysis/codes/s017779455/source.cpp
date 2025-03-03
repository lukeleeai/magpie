	#include "stdc++.h"



using namespace std;



typedef long long ll;



int r,c,tujuan,x;

ll temp;



int main(){

		cin>>r>>c;

		int dist[10];

		int w[10][10];

        memset(w,-1,sizeof(w));

		for (int i = 0; i <= 9; ++i)

		{

			dist[i] = INT_MAX;

		}

		for (int i = 0; i <= 9; ++i)

		{

			for (int j = 0; j<=9; j++ ){

				cin>>w[i][j];

			}

		}

		priority_queue<pair<ll,ll>> pq;

		dist[1] = 0;

		pq.push(make_pair(-dist[1],1));

		while(!pq.empty()){

			x = pq.top().second;

			pq.pop();

            for (int i = 0; i<=9; i++){

                if (dist[i]>w[i][x] + dist[x]){

                    dist[i] = w[i][x]+dist[x];

                    pq.push(make_pair(-dist[i],i));

                }

            }

		}

		ll res = 0;

		for (int i = 0; i < r; ++i)

		{

			for (int j=0; j<c; j++){

				cin>>tujuan;

				if (tujuan!=-1){

					if (tujuan != 1) res+=dist[tujuan];

				}

			}

		}

		cout<<res<<endl;







	return 0;



}
