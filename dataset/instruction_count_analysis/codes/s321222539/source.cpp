#include<cstdio>



int main(){

  int N;

  scanf("%d", &N);

  int in;

  int m_in = 200000;

  int cn = 0;

  for(;N-->0;){

    scanf("%d", &in);

    if(m_in >= in){

      cn++;

      m_in = in;

    }

  }

  

  printf("%d\n", cn);

  

  return 0;

}