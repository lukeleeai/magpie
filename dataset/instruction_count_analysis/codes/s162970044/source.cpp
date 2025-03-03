#include<iostream>

using namespace std;



bool IsSquare(int N)

{

    int i;

    for(i=1; N>0; i+=2)  //变化步长为2， 初值为1，一直减到N大于0

    {

        N-=i;

    }

    if(N==0)

        return true;  //如果N减到最后，恰好等于0，就是平方数

    else

        return false;  //否则，就不是平方数

}



int main()

{

    int n;

    cin>>n;

    

    while(n){

        if(IsSquare(n)){

           cout << n;

            break;

        }

       else n--;

        

    }

    

    return 0;

}
