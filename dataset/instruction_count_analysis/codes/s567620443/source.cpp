//

//  main.cpp

//  瀹

//

//  Created by RMBP on 2019/10/13.

//  Copyright 漏 2019 RMBP. All rights reserved.

//



#include <iostream>

using namespace std;

int main() {

    int n,t,a,i,b;

    double h[100000],c,e;

    e=0;

    c=1000000;

    b=0;

    cin>>n>>t>>a;

    for (i=0;i<n;i++){

        cin>>h[i];

        e=t-h[i]*0.006-a;

        

        if (t-h[i]*0.006<a){

            

            e=a-(t-h[i]*0.006);

            

        }

        

        

        if (e<c){

            c=e;

            b=i;

            

        }

        

    }

    cout<<b+1;

    return 0;

}