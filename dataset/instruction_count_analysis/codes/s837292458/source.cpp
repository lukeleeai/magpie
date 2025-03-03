#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

int main(){

    string s;

    cin>>s;

    for(int i=0;i<s.size();i++){

        if(s[i]=='C'){

            for(int j=i+1;j<s.size();j++){

                if(s[j]=='F'){

                    cout<<"Yes"<<endl;

                    return 0;

                }

            }

        }

    }

    cout<<"No"<<endl;

    return 0;

    

}