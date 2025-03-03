#include "stdc++.h"

using namespace std;



typedef long long ll;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)

#define all(x) (x).begin(),(x).end()

#define mp make_pair

#define pb push_back

#define fi first

#define se second



string C(string x);

string D(string x);

string S(string x);

string L(string x);



int main()

{

    string s;

    while(cin >>s,(s!="."))

    {

        int ct=0;

        rep(i,s.size()) ct+=(s[i]=='?');



        int lim=1;

        rep(i,ct) lim*=26;



        string ans(100,'z');



        rep(mask,lim)

        {

            int t=mask;

            string im(ct,' ');

            rep(i,ct)

            {

                im[i]='A'+t%26;

                t/=26;

            }



            int c=0;

            string ss=s;

            rep(i,ss.size())

            {

                if(ss[i]=='?') ss[i]=im[c++];

            }



            ans=min(ans,C(ss));

        }



        cout << ans <<endl;

    }

    return 0;

}



string C(string x)

{

    if(x[0]=='[')

    {

        int br=0;

        int idx=0;

        while(idx<x.size())

        {

            if(x[idx]=='[') ++br;

            else if(x[idx]==']') --br;



            if(br==0) break;

            ++idx;

        }



        string a=S(x.substr(0,idx+1));



        string b="";

        if(idx+1!=x.size()) b=D(x.substr(idx+1));



        return a+b;

    }

    else

    {

        //Letter



        int idx=0;

        while(idx<x.size())

        {

            if('A'<=x[idx] && x[idx]<='Z') break;

            ++idx;

        }



        string a=S(x.substr(0,idx+1));

        string b=D(x.substr(idx+1));



        return a+b;

    }

}



string D(string x)

{

    if(x=="") return x;

    return C(x);

}



string S(string x)

{

    if(x[0]=='[')

    {

        //reverse

        string r=C(x.substr(1,x.size()-2));

        reverse(all(r));



        return r;

    }

    else return L(x);

}



string L(string x)

{

    if(x[0]=='+')

    {

        string r=L(x.substr(1));



        if(r[0]=='Z') r[0]='A';

        else ++r[0];



        return r;

    }

    else if(x[0]=='-')

    {

        string r=L(x.substr(1));



        if(r[0]=='A') r[0]='Z';

        else --r[0];



        return r;



    }

    else return x;

}