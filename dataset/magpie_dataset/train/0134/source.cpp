#include<iostream>

#include<vector>



using namespace std;

#define MAX 100000000

#define Is 110

int n, k,req, a, b, c, d, e, i ,j, map[Is][Is], ans;





int dik(int s, int g){

  vector<int> cost(Is, MAX), f(Is, 0);

  cost[s] = 0;

  for(i = 0; i < Is; i++){

    f[s] = 1;

    for(j = 0; j < Is; j++) if(!f[j] && map[s][j] != MAX && cost[j] > cost[s] + map[s][j]) cost[j] = cost[s] + map[s][j];

    int min = MAX + 1;

    for(j = 0; j < Is; j++) if(!f[j] && min > cost[j]) min = cost[s = j];

  }

  return cost[g];

}



int main(){

  

  while(cin >> n >> k, n != 0 || k != 0) { 

    for(i = 0; i < Is; i++) {

      for(j = 0; j < Is; j++) {

	map[i][j] = MAX;

      }

    }

    

    while(k--){

      cin >> req;

      

      if(req){

	cin >> c >> d >> e;

	if(e < map[c][d]) map[c][d] = map[d][c] = e;

      }

      

      else{

	cin >> a >> b;

	if((ans = dik(a, b)) != MAX) cout << ans << endl;

	else cout << "-1" << endl;

      }

    }

    

  }

  return 0;

}

  

  