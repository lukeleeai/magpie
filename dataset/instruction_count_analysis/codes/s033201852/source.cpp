#include<cstdio>

#include<cstring>

#include<algorithm>

#include<string>

#include<iostream>

using namespace std;



int main(){

    string s;

    cin >> s;

    for(int i=1;i<(int)s.length();i++){

        if(s[i]==s[i-1]){

            printf("%d %d\n",i,i+1);

            exit(0);

        }

        if(i+1<(int)s.length()&&s[i-1]==s[i+1]){

            printf("%d %d\n",i,i+2);

            exit(0);

        }

    }

    printf("-1 -1");

}
