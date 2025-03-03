#include <iostream>

#include "stdc++.h"



using namespace std;

char s[500005],t[500005];

char st[2000000];

int pre[2000000];

bool ab[500005];

int cnt[500005],sy[500005];



int main()

{

    scanf("%s",t);scanf("%s",s);

    int slen = strlen(s);int tlen = strlen(t);

    int alen = slen+1;

    memcpy(st,s,sizeof(char)*slen);

    st[slen] = '#';



    while(alen-slen-1<max(2*slen,2*tlen)){

        memcpy(st+alen,t,sizeof(char)*tlen);

        alen+=tlen;

    }



    for (int i = 1; i < alen; i++) {

    int j = pre[i - 1];

    while (j > 0 && st[i] != st[j]) j = pre[j - 1];

    if (st[i] == st[j]) j++;

    pre[i] = j;

  }

    int tlen2 = 2*tlen;

    for(int i=1;i<=tlen;++i){

        if(pre[alen-i]==slen) {

            ab[(tlen2-i-slen%tlen+1)%tlen] = true;

        }

    }



    bool minf = false;

    for(int i=0;i<tlen&&!minf;++i){

        int ncnt = 1,j=i;

        while(ab[j]&&cnt[j]<ncnt){

            if(sy[j]==i+1){

                minf = true;break;

            }

            cnt[j]=ncnt++;

            sy[j] = i+1;

            j=(j+slen)%tlen;

        }

    }



    int ans = 0;

    for(int i=0;i<tlen;++i) ans = max(ans,cnt[i]);

    if(minf) ans = -1;

    printf("%d\n",ans);

    return 0;

}
