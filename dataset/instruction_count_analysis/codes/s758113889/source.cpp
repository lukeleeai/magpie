#include <cstdio>

bool b[26];

int main(){

    register char ch;

    while((ch=std::getchar())!='\n') b[ch-'a']=true;

    for(int i=0;i<26;++i) if(!b[i]){std::putchar(i+'a');std::putchar(10);return 0;}

    std::puts("None");

}