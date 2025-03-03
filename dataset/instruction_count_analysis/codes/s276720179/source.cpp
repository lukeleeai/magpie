#include <iostream>

#include<math.h>



using namespace std;



int IsPrime(int a,int b)

{

    int i,p=0,q=0;

    if(a==1||b==1)

    {

        return 0;

    }

    for(i=2;i<=sqrt(a);i++)

    {



        if(a%i==0)

            {

                p=1;

                break;

            }

    }



    for(i=2;i<=sqrt(b);i++)

    {



        if(b%i==0)

            {

                q=1;

                break;

            }



    }

    if(p!=1&&q!=1)

        return 1;

    else

        return 0;



}

int main()

{

    int a,b,i,c=0;

    while( cin>>a)

    {

        c=0;



    for(i=0;i<a;i++)

    {

        if((b=IsPrime(i+1,a-i))==1)

            c++;



    }

    cout<<c<<endl;



}

}