#include <cstdio>

#include <algorithm>

#include <functional>

#include <set>



int n;

int S[1<<18];



int main(){

  std::multiset<int, std::greater<int> > S, T;

  scanf("%d",&n);

  for(int i=0;i<(1<<n);i++){

    int x;

    scanf("%d",&x);

    S.insert(x);

  }

  T.insert(*(S.begin()));

  S.erase(S.begin());



  for(int i=0;i<n;i++){

    int tmp[1<<18];

    int t=0;

    auto itr = S.begin();

    for(int x: T){

      while(itr != S.end() && *itr == x) ++itr;

      if(itr == S.end()){

        puts("No");

        return 0;

      }

      tmp[t++] = *itr;

      itr = S.erase(itr);

    }

    if(i != n-1) T.insert(tmp, tmp+t);

  }



  puts("Yes");





  return 0;

}
