// verified at https://judge.yosupo.jp/submission/3400

#ifndef Union_find_hpp

#define Union_find_hpp



#include <cassert>

#include <cstddef>

#include <vector>



class union_find

{

    std::vector<int> link;



public:

    explicit union_find(const size_t n) : link(n, -1) {}



    size_t find(size_t x)

    {

        assert(x < size());

        return link[x] < 0 ? x : (link[x] = find(link[x]));

    }



    size_t size() const { return link.size(); }



    size_t size(const size_t x)

    {

        assert(x < size());

        return -link[find(x)];

    }



    bool same(const size_t x, const size_t y)

    {

        assert(x < size() && y < size());

        return find(x) == find(y);

    }



    size_t unite(size_t x, size_t y)

    {

        assert(x < size() && y < size());

        if((x = find(x)) != (y = find(y)))

        {

            if(link[x] > link[y]) std::swap(x, y);

            link[x] += link[y];

            link[y] = x;

        }

        return x;

    }

}; // class union_find



#endif // Union_find_hpp



#include <algorithm>

#include <iostream>

#include <tuple>



using namespace std;



int main(int argc, char *argv[])

{

    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);



    int n,h,w; cin>>n>>h>>w;

    vector<tuple<int,int,int>> cards(n);

    for(auto &e : cards)

    {

        int r,c,a; cin>>r>>c>>a;

        --r,--c; c+=h;

        e=tie(a,r,c);

    }

    sort(cards.rbegin(),cards.rend());

    union_find uf(h+w);

    long long ans{};

    bool ext[2<<17]={};

    for(auto &e : cards)

    {

        int a,r,c; tie(a,r,c)=e;

        r=uf.find(r),c=uf.find(c);

        if(r!=c)

        {

            if(ext[r] and ext[c]) continue;

            ext[uf.unite(r,c)]=ext[r]||ext[c];

            ans+=a;

        }

        else if(!ext[r])

        {

            ext[r]=true;

            ans+=a;

        }

    }

    cout << ans << "\n";

}
