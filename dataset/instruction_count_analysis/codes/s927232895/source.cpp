//**PEACE BE UPON YOU**

// AZMAYEN FAYEK SABIL

// IUT CSE SWE-19



#include <iostream>

#include "stdc++.h"



#include <cmath>

#include <string>

#include <algorithm>

using namespace std;





int main()



{

    int n;

    cin>>n;



    int a[200005];

    int c[200005]={0};



    int i;



    for(i=1;i<n;i++)

    {

        cin>>a[i];

    }



    for(i=0;i<n;i++)

    {

       c[a[i]-1]++;

    }



    for(i=0;i<n;i++)

    {

        cout<<c[i]<<endl;

    }





    return 0;

}
