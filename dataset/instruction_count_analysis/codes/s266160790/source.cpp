#include <iostream>

#include <math.h>



using namespace std;



int main(){



    

    long long a,b,min,max,num=0;



    cin>>a;

    cin>>b;



    if(a<b){

        min = a;

        max = b;

    }else{

        min = b;

        max = a;

    }



    for (int i = min+1; i <= max; i++)

    {   

        if(abs(a-i) == abs(b-i)){

            num = i;

        }

    }



    if(num != 0){

        cout<<num<<endl;

    }else{

        cout<<"IMPOSSIBLE"<<endl;

    }

    

}
