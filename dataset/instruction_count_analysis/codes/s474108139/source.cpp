#include <unistd.h>

#include <algorithm>

#include <functional>



char ibuf[4000000];

char *ibufe = ibuf-1;



void readall(){

  int k, t = 0;

  while((k=read(STDIN_FILENO, ibuf+t, sizeof(ibuf)-t))>0) t += k;

}



int read_uint(){

  int x=0;

  while(*(++ibufe) <'0');

  do {

    x *= 10;

    x += *ibufe-'0';

  } while(*(++ibufe) >='0');



  return x;

}



int n;

int S[1<<18];

int Q[19];



int main(){

  readall();

  n = read_uint();

  for(int i=0;i<(1<<n);i++) S[i] = read_uint();

  std::sort(S, S+(1<<n), std::greater<int>());

  int k = 0;

  for(int i=0;i<(1<<n);){

    int j = i;

    for(i++; S[i] == S[j]; i++) ;

    S[k++] = i-j;

  }

  Q[n] = 1;

  for(int i=0;i<k;i++){

    int l;

    int a=0;

    for(l=n;l>=0 && a < S[i];l--) a += Q[l];

    if(a<S[i]){

      write(STDOUT_FILENO, "No\n", 3);

      return 0;

    }

    l++;

    for(int t=0;t<l;t++) Q[t] += S[i];

    int b = a-Q[l];

    Q[l] = a-S[i]+b;

    for(n=l+1;b;n++){

      b -= Q[n];

      Q[n] = b;

    }

    n--;

  }

  write(STDOUT_FILENO, "Yes\n", 4);

  return 0;

}
