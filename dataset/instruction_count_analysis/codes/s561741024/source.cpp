#include <iostream>

#include "stdc++.h"



using namespace std;

char s[100005],t[100005];

vector<int> pos[26];

int slen,tlen;

bool have[26];



int main()

{

    scanf("%s%s",s,t);

    slen = strlen(s);

    tlen = strlen(t);

    for(int i=0;i<tlen;++i){

        have[t[i]-'a']=true;

    }



    for(int i=0;i<slen;++i){

        pos[s[i]-'a'].push_back(i);

        have[s[i]-'a']=false;

    }



    for(int i=0;i<26;++i){

        if(have[i]){

            printf("-1\n");return 0;

        }

    }



    long long ans = 1,now=0;

    for(int i=0;i<tlen;){

        auto np = lower_bound(pos[t[i]-'a'].begin(),

                              pos[t[i]-'a'].end(),now%slen);

        if(np==pos[t[i]-'a'].end()){

            now = (now/slen+1)*slen;continue;

        }

        now = now/slen*slen+*np;

        if(now>=ans){

            ans=now+1;++i;++now;continue;

        }

        ++i;++now;

    }

    printf("%lld\n",ans);

    return 0;

}
