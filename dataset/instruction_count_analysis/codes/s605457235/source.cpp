// È¥°É£¡Æ¤¿¨Çð! °ÑAC´ø»ØÀ´£¡

//      ¤Ø¡¡¡¡¡¡¡¡¡¡£¯|

// ¡¡¡¡/£Ü7¡¡¡¡¡¡ ¡Ï£ß/

// ¡¡ /¡¡©¦¡¡¡¡ £¯¡¡£¯								AC		AC		AC		AC

//    ©¦¡¡Z £ß,£¼¡¡£¯¡¡¡¡ /`©c						AC		AC		AC		AC

//    ©¦¡¡¡¡¡¡¡¡¡¡©c¡¡¡¡ /¡¡¡¡¡µ					AC		AC		AC		AC

// ¡¡Y¡¡¡¡¡¡¡¡¡¡`¡¡ /¡¡¡¡/  /						AC		AC		AC		AC

// ¡¡Øé¡ñ¡¡.¡¡¡ñ¡¡¡¡¡´¡¡/¡¡/						AC		AC		AC		AC

// ¡¡()¡¡ ¤Ø¡¡¡¡¡¡¡¡|¡¡£Ü¡´							AC		AC		AC		AC

// ¡¡¡¡>- ._¡¡ ¥£¡¡ ©¦ £¯£¯							AC		AC		AC		AC

// ¡¡ / ¤Ø¡¡¡¡ /¡¡/£¼| £Ü£Ü							AC		AC		AC		AC

// ¡¡ ©c_/¡¡¡¡(_£¯¡¡ ©¦£¯£¯							AC		AC		AC		AC

// ¡¡¡¡ 7¡¡¡¡¡¡¡¡¡¡¡¡¡¡|£¯							AC		AC		AC		AC

// ¡¡¡¡ £¾¨Dr£þ£þ`-¨D£ß/							AC		AC		AC		AC

//**************************************Accepted*****************************************//



#include"stdc++.h"



#define all(x) x.begin(),x.end()

#define pb push_back

#define mp make_pair

#define Unique(x) x.erase(unique(all(x)),x.end());



#define CIN_FILE "input.txt"

#define COUT_FILE "output.txt"



#define Pig (OO)



using namespace std;



const int dx[]={-1,0,1,0};

const int dy[]={0,-1,0,1};



inline int read()

{

	#define gc getchar

	int ans=0;

	bool f=1;

	char ch=gc();

	

	while(!isdigit(ch))f^=ch=='-',ch=gc();

	

	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();

	

	return f?ans:-ans;

	

	#undef gc

}



typedef long long ll;



/*



template <typename T>

struct modular {

    constexpr modular() : val(0){}

    constexpr modular(const modular<T>& _m) : val(_m.val) {}

    template <typename U> constexpr modular(const U& _r = U()) {

        val = -MOD <= _r && _r < MOD ? _r: _r % MOD;

        if (val < 0) { val += MOD; } }

    const T operator()() { return val; }

    template <typename U> explicit operator U() const { return static_cast<U>(val); }

    modular<T>& operator+=(const modular<T>& _m) { if ((val += _m.val) >= MOD) { val -= MOD; } return *this; }

    modular<T>& operator-=(const modular<T>& _m) { if ((val -= _m.val) < 0) { val += MOD; } return *this; }

    modular<T>& operator*=(const modular<T>& _m) { val = modular<T>(static_cast<int64_t>(val) * static_cast<int64_t>(_m.val)).val; return *this; }

    modular<T>& operator/=(const modular<T>& _m) {

        T a = _m.val, b = MOD, u = 0, v = 1;

        while (a != 0) {

            T q = b / a;

            b -= q * a; swap(a, b);

            u -= q * v; swap(u, v);

        } return *this *= u; }

    modular<T>& operator =(const modular<T>& _m) { val = _m.val; return *this; }

    template <typename U> modular<T>& operator+=(const U& _r) { return *this += modular<T>(_r); }

    template <typename U> modular<T>& operator-=(const U& _r) { return *this -= modular<T>(_r); }

    template <typename U> modular<T>& operator*=(const U& _r) { return *this *= modular<T>(_r); }

    template <typename U> modular<T>& operator/=(const U& _r) { return *this /= modular<T>(_r); }

    template <typename U> modular<T>& operator =(const U& _r) { val = modular<T>(_r).val; return *this; }

    modular<T> operator-() { return modular<T>(-val); }

    template <typename U> friend bool operator==(const modular<U>&, const modular<U>&);

    friend std::istream& operator>>(std::istream& os, modular<T>& _m) { os >> _m.val; _m *= 1; return os; }

    friend std::ostream& operator<<(std::ostream& os, const modular<T>& _m) { return os << _m.val; }

    template <typename U>

    modular<T> exp(U e) {

        modular<T> res = 1;

        modular<T> b = val;

        if (e < 0) { b = 1/b; e *= -1; }

        for (; e; e >>= 1) {

            if (e & 1) { res *= b; }

            b *= b;

        } return res; }

private:

    T val;

};

template <typename T> inline modular<T> operator+(const modular<T>& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) += _rhs; }

template <typename T, typename U> inline modular<T> operator+(const modular<T>& _lhs, const U& _rhs) { return modular<T>(_lhs) += _rhs; }

template <typename T, typename U> inline modular<T> operator+(const U& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) += _rhs; }

template <typename T> inline modular<T> operator-(const modular<T>& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) -= _rhs; }

template <typename T, typename U> inline modular<T> operator-(const modular<T>& _lhs, const U& _rhs) { return modular<T>(_lhs) -= _rhs; }

template <typename T, typename U> inline modular<T> operator-(const U& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) -= _rhs; }

template <typename T> inline modular<T> operator*(const modular<T>& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) *= _rhs; }

template <typename T, typename U> inline modular<T> operator*(const modular<T>& _lhs, const U& _rhs) { return modular<T>(_lhs) *= _rhs; }

template <typename T, typename U> inline modular<T> operator*(const U& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) *= _rhs; }

template <typename T> inline modular<T> operator/(const modular<T>& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) /= _rhs; }

template <typename T, typename U> inline modular<T> operator/(const modular<T>& _lhs, const U& _rhs) { return modular<T>(_lhs) /= _rhs; }

template <typename T, typename U> inline modular<T> operator/(const U& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) /= _rhs; }

template <typename T> inline bool operator==(const modular<T>& _lhs, const modular<T>& _rhs) { return _lhs.val == _rhs.val; }

template <typename T, typename U> inline bool operator==(const modular<T>& _lhs, const U& _rhs) { return _lhs == modular<T>(_rhs); }

template <typename T, typename U> inline bool operator==(const U& _lhs, const modular<T>& _rhs) { return modular<T>(_lhs) == _rhs; }

template <typename T> inline bool operator!=(const modular<T>& _lhs, const modular<T>& _rhs) { return !(_lhs == _rhs); }

template <typename T, typename U> inline bool operator!=(const modular<T>& _lhs, const U& _rhs) { return !(_lhs == _rhs); }

template <typename T, typename U> inline bool operator!=(const U& _lhs, const modular<T>& _rhs) { return !(_lhs == _rhs); }

typedef modular<int> mint;



*/



int n;



int ghead[100010];

int gnext[200010];

int gto[200010];



int path[100010];

int npath;



int col[100010];



bool DFS(int x,int pre)

{

	if(x==n-1)

	{

		npath=0;

		path[npath++]=x;

		

		return 1;

	}

	

	for(int v=ghead[x];v!=-1;v=gnext[v])

	{

		int to=gto[v];

		

		if(to==pre)continue;

		else

		{

			if(DFS(to,x))

			{

				path[npath++]=x;

				

				return 1;

			}

			else continue;

		}

	}

	

	return 0;

}



void DFScol(int x,int pre)

{

	for(int v=ghead[x];v!=-1;v=gnext[v])

	{

		int to=gto[v];

		

		if(to==pre||col[to]!=-1)continue;

		else

		{

			col[to]=col[x];

			

			DFScol(to,x);

		}

	}

}



void Add(int x,int y,int flag,int i)

{

	gnext[2*i+flag]=ghead[x];

	ghead[x]=2*i+flag;

	gto[2*i+flag]=y;

}



int cnt1,cnt2;



int main(int argc, char const *argv[])

{

	ios::sync_with_stdio(false);

	

	scanf("%d",&n);

	

	for(int i=0;i<n;i++)ghead[i]=-1;

	

	for(int i=0;i<n-1;i++)

	{

		int x,y;

		scanf("%d%d",&x,&y);

		

		x--,y--;

		

		Add(x,y,0,i);

		Add(y,x,1,i);

	}

	

	assert(DFS(0,-2));

	

	reverse(path,path+npath);

	

	for(int i=0;i<n;i++)col[i]=-1;

	

	for(int i=0;i<npath;i++)col[path[i]]=((i<(npath+1)/2) ? 0 : 1);

	

	for(int i=0;i<npath;i++)DFScol(path[i],-1);

	

	for(int i=0;i<n;i++)

	{

		if(col[i]==0)cnt1++;

		else cnt2++;

	}

	

	printf("%s",(cnt1>cnt2 ? "Fennec" : "Snuke"));

	

	//printf("Time used = %.12f",(double)(clock())/CLOCKS_PER_SEC);

	return 0;

}