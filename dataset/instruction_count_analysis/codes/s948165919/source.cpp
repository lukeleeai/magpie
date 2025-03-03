//Is input file is the same as the below link?

//http://acm-icpc.aitea.net/index.php?plugin=attach&refer=2006%2FPractice%2F%CC%CF%B5%BC%B9%F1%C6%E2%CD%BD%C1%AA%2F%CC%E4%C2%EA%CA%B8%A4%C8%A5%C7%A1%BC%A5%BF%A5%BB%A5%C3%A5%C8&openfile=judge-data.zip

#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <string>

#include <vector>

#include <queue>

#include <map>

#include <set>

#include <algorithm>

 

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)

#define REP(i,n) FOR(i,0,n)

#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

#define sz size()

#define pb push_back

#define mp make_pair

#define ALL(X) (X).begin(),(X).end()

 

using namespace std;

 

const int INF = 1000000000;

const double eps = 1e-8;

 

int main(void) {

    int n;

    cin>>n;

    REP(i,n)

    {

        int h,w;

        cin>>h>>w;

        vector<string> table(h);

        set<char> s;

        REP(j,h)

        {

            cin>>table[j];

            REP(k,w)

            {

                s.insert(table[j][k]);

            }

        }

        s.erase('.');

        vector<char> mats;

        FORIT(j,s)

            mats.push_back(*j);

        if(mats.size())

        {

            bool flg = true;

            do

            {

                flg = true;

                vector<string> cp(h);

                REP(k,h)cp[k]=string(table[k]);

                REP(j,mats.size())

                {

                    int top=h,bottom=0,left=w,right=0;

                    REP(k,h)REP(l,w)

                    {

                        if(cp[k][l] == mats[j])

                        {

                            top=min(top,k);

                            bottom=max(bottom,k);

                            left=min(left,l);

                            right=max(right,l);

                        }

                    }

                    FOR(k,top,bottom+1)

                    {

                        FOR(l,left,right+1)

                        {

                            if(cp[k][l]=='.')

                            {

                                flg = false;

                                break;

                            }

                            else if(cp[k][l]==mats[j])

                            {

                                cp[k][l] = '.';

                            }

                        }

                        if(!flg)break;

                    }

                    if(!flg)break;

                }

                if(flg)break;

            }while(next_permutation(ALL(mats)));

            if(flg)

                cout << "SAFE" << endl;

            else

                cout << "SUSPICIOUS" << endl;

        }

        else

            cout << "SAFE"<<endl;

  }

  return 0;

}