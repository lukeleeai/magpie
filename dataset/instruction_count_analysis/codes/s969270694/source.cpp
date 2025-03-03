#include<cstdio>

#include<string>

using namespace std;

char a[100005];

string s;

int main(){

    

    scanf("%s",&a);

    s=a;

    for (int i=0;i<=s.size()-1;i+=2)

	{

       printf("%c",s[i]);

    }

    return 0;

}