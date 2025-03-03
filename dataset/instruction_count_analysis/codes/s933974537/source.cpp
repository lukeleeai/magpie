#include "stdc++.h"



using namespace std;



int main() {



   string color1,color2;

   int no1,no2;

   string color;

   cin>>color1>>color2>>no1>>no2>>color;

   if(color==color1){

       cout<<--no1<<" "<<no2<<endl;

   }

   else cout<<no1<<" "<<--no2<<endl;

    return 0;

}
