#include <cstdio>

#include <cstring>

#include <algorithm>



using namespace std;



char st[104014];



int main(){

  while(~scanf("%s", st)){

    int len = strlen(st);

    if(st[0] != st[len-1]){

      if(len & 1) printf("First\n");

      else printf("Second\n");

    }

    else {

      if(len & 1) printf("Second\n");

      else printf("First\n");

    }

  }

  return 0;

}
