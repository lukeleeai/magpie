#include <cstring>

#include <cstdio>

#include <algorithm>

using namespace std;

#define loop(i,a,b) for(int i=a; i<int(b); i++)

#define rep(i,b) loop(i,0,b)



char s[1000100];

int l[1000100];

int main(){

    scanf("%s",s);

    int n = strlen(s);

    l[0] = 1;

    rep(i,n-1){

        if(s[i+1]==s[i]) l[i+1]=l[i]+1;

        else l[i+1] = 1;

    }

    int ans = 0;

    loop(i,1,n-1){

        if(s[i]=='O' && s[i+1]!='O' && i+l[i]<n && i-l[i] >= 0 && l[i+l[i]]>=l[i] && l[i-l[i]]>=l[i] && s[i+l[i]]=='I' && s[i-l[i]]=='J'){

            ans = max(ans,l[i]);

        }

    }

    printf("%d\n",ans);

}