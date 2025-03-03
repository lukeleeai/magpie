/*why so serious?*/

#include"stdc++.h"

using namespace std;

#define   int      long long

#define   fast()   ios_base::sync_with_stdio(0);cin.tie(0)

#define   all(x)   x.begin(),x.end()

#define   pb       push_back

#define   F        first

#define   S        second



const int N=1e5+5;



string s;



struct seg

{int pre,suf,tot;

 seg()

 {pre=suf=tot=0;

 }

};



seg tree[4*N];



seg combine(seg a,seg b)

{seg c;

 c.pre=a.pre;

 c.suf=b.suf;

 c.tot=a.tot+b.tot+(int)(a.suf && b.pre);

 return c;

}



void build(int node,int beg,int en)

{if(beg==en)

 {if(s[beg-1]=='A')

  tree[node].suf=1;

  else if(s[beg-1]=='C')

  tree[node].pre=1;

  return;

 }

 int mid=(beg+en)/2;

 build(2*node,beg,mid);

 build(2*node+1,mid+1,en);

 tree[node]=combine(tree[2*node],tree[2*node+1]);

}



seg qu(int node,int beg,int en,int l,int r)

{if(beg>en || l>en ||r<beg)

 {seg null;

  return null;

 }

 if(l<=beg && en<=r)

 return tree[node];

 int mid=(beg+en)/2;

 return (combine(qu(2*node,beg,mid,l,r),qu(2*node+1,mid+1,en,l,r)));

}



int32_t main()

{int n,q,l,r;



 fast();



 cin>>n>>q>>s;

 build(1,1,n);



 for(;q;--q)

 {cin>>l>>r;

  cout<<qu(1,1,n,l,r).tot<<"\n";

 }

 return 0;

}


