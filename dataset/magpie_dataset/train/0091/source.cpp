#include<cstdio>

#include<algorithm>

#include<vector>

#include<string>

#include<set>

using namespace std;



#define INF ( 1 << 30 )

typedef multiset<int,int>::iterator itr;



int main()

{

  int N, Q;

  int stmp[1000000], comp[1000000], a;

  char buff[1024];

  scanf( "%d %d", &N, &Q);

  for(int i = 0 ; i < N ; i++ ){

    scanf( "%d", &stmp[i]);

    comp[i] = stmp[i];

  }

  sort( comp, comp + N);



  multiset< int > sym;

  while(Q--){

    scanf("%s %d", buff, &a);

    if(*buff == 'A'){ //ADD



      sym.insert(stmp[a - 1]);



    } else if(*buff == 'R'){ //REMOVE

      try{

        sym.erase( sym.lower_bound(stmp[a - 1]));

      }catch( ... ){}

    } else { //CHECK



      int left = 0, right = INF;

      while(left != right){

        int center = ( left + right ) / 2;

        int pre = 0, BAN = 0;

        for(itr it = sym.begin() ; it != sym.end() ; it++ ){

          int p = distance( comp,lower_bound( comp, comp + N, *it - center));

          BAN += max( p - pre, 0);

          pre = distance( comp, upper_bound( comp, comp + N, *it));

        }

        BAN += max( N - pre, 0);

        if(BAN <= a) right = center;

        else left = center + 1;

      }

      if( left != INF) printf("%d\n", left);

      else puts("NA");



    }

  }

  return false;

}