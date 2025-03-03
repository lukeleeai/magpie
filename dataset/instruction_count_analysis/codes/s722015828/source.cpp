#include"stdc++.h"

using namespace std;

void meal(int x,int a,int b){

       if(abs(x-a)<abs(x-b)){

        cout<<"A"<<endl;

       }

       if(abs(x-b)<abs(x-a)){

        cout<<"B"<<endl;

       }

}

int main(){

   int x,a,b;

   cin>>x>>a>>b;

   meal(x,a,b);

   return 0;

}
