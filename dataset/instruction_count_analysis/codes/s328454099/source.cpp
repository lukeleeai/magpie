#include <stdio.h>

#include <iostream>



using ll = long long;

const ll INF = 1ll << 50;



int main(void){

  int N, M;

  std::cin >> N >> M;



  const int NMAX = 1000;

  const int MMAX = 2000;

  int a[MMAX], b[MMAX];

  ll c[MMAX];



  for (int i = 0; i < M; ++ i){

      std::cin >> a[i] >> b[i] >> c[i];

      c[i] = -c[i];

  }



  ll dist[NMAX];

  for (int i = 0; i < N; ++ i) {

      dist[i] = INF;

  }

  dist[0] = 0;



  for (int loop = 0; loop < N - 1; ++ loop) {

      for (int i = 0; i < M; ++ i) {

          if (dist[a[i] - 1] == INF) continue;

          if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {

              dist[b[i] - 1] = dist[a[i] - 1] + c[i];

          }

      }

  }



  ll ans = dist[N - 1];



  bool negative[NMAX];

  for (int i = 0; i < N; ++ i) {

      negative[i] = false;

  }



  for (int loop = 0; loop < N; ++ loop) {

      for (int i = 0; i < M; ++ i) {

        if (dist[a[i] - 1] == INF) continue;

        if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {

            dist[b[i] - 1] = dist[a[i] - 1] + c[i];

            negative[b[i] - 1] = true;

        }



        if (negative[a[i] - 1] == true) {

          negative[b[i] - 1] = true;

        }

      }

  }



  if (negative[N - 1])

      std::cout << "inf" << std::endl;

  else

      std::cout << -ans << std::endl;



  return 0;



}