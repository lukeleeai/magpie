#include <iostream>

using namespace std;

int main() {

    char ch[1];

    char s[1];

    scanf("%s",ch);

    scanf("%s",s);

    if(ch[0]>s[0]){

        cout<<">"<<endl;

    }

    else if(ch[0]<s[0])cout<<"<"<<endl;

    else cout<<"="<<endl;



}