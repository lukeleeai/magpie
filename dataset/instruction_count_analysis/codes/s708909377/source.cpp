#include <iostream>

using namespace std;



#define INF 2147483647

#define ASTART (1<<17)

int a[1<<18][2];

int ti=1;



int find(int i){

  int nv=INF,t=0;

  i+=ASTART-1;

  nv=a[i][0];

  t=a[i][1];

  while (i>0){

    i=(i-1)/2;

    if (t<a[i][1])nv=a[i][0],t=a[i][1];

    //cout << i << " = " << a[i][0]<< " = " << a[i][1]<< endl;

  }

  return nv;

}

void update(int s,int t,int x,int k,int l,int r){

  if (l>=s&&r<=t){

    a[k][0]=x;

    a[k][1]=ti;

    return;

  }

  if (r<=s||l>=t)return;

  int m=(l+r)/2;

  update(s,t,x,k*2+1,l,m);

  update(s,t,x,k*2+2,m,r);

}

int main(){

  int n,q,com,s,t,x;

  for (int i=0;i<(1<<18);i++)a[i][0]=INF,a[i][1]=0;

  cin >> n>>q;



  for (int i=0;i<q;i++){

    cin >> com;

    if (com==0) {

      cin >> s >> t >> x;

      update(s,t+1,x,0,0,ASTART);

      ti++;

    }else {

      cin >> s;

      cout << find(s)<< endl;

    }

    //for (int i=0;i<5;i++)cout << a[i] << endl;

    //cout << a[ASTART];

  }



  return 0;

}