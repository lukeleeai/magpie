#include<cstdio>

#include<queue>

#include<algorithm>

using namespace std;



int main(){

  int q,lim,query,x;



  while(1){

    deque<int> l;

    scanf("%d %d",&q,&lim);

    if(!q && !lim)break;

    for(int i=0;i<q;i++){

      scanf("%d %d",&query,&x);



      if(query==0){

	l.push_back(x);

	if((int)l.size()>lim)l.pop_front();

      }

      if(query==1)l.erase(l.begin()+x-1);

      if(query==2)printf("%d\n",*(l.begin()+x-1));

      if(query==3)l.erase(find(l.begin(),l.end(),x));

    }

    printf("end\n");

  }

}