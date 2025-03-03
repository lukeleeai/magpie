//

//  main.cpp

//  vjudge

//

//  Created by Sudipto Mondal on 7/9/20.

//  Copyright © 2020 Sudipto Mondal. All rights reserved.

//



#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    long long int a,b,c;

    cin>>a>>b>>c;

    

    if((a+b+c)>=22){

        cout<<"bust"<<endl;

    }else{

        cout<<"win"<<endl;

    }

    return 0;

}
