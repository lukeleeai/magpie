#define NDEBUG

#define _CRT_SECURE_NO_WARNINGS

#include <cassert>

#include <functional>

#include <utility>

#include <vector>



template <typename ValueMonoid, typename OperatorMonoid> class LazySegmentTree {

public:

	using value_type = ValueMonoid;

	using reference = value_type &;

	using const_reference = const value_type &;

	using operator_type = OperatorMonoid;



private:

	using operator_constref = const operator_type &;

	using container_type = std::vector<std::pair<value_type, operator_type>>;



public:

	using size_type = typename container_type::size_type;



private:

	using F = std::function<value_type(const_reference, const_reference)>;

	using G = std::function<operator_type(operator_constref, operator_constref)>;

	using H = std::function<value_type(const_reference, operator_constref)>;

	const F f;

	const G g;

	const H h;

	const value_type v_neutral;

	const operator_type o_neutral;

	size_type height, size_;

	container_type tree;

	static size_type getheight(const size_type size) {

		size_type ret = 0;

		while ((size_type)1 << ret < size)

			++ret;

		return ret;

	}

	value_type reflect(const size_type index) {

		return h(tree[index].first, tree[index].second);

	}

	void recalc(const size_type index) {

		tree[index].first = f(reflect(index << 1), reflect(index << 1 | 1));

	}

	void assign(const size_type index, operator_constref data) {

		tree[index].second = g(tree[index].second, data);

	}

	void push(const size_type index) {

		assign(index << 1, tree[index].second);

		assign(index << 1 | 1, tree[index].second);

		tree[index].second = o_neutral;

	}

	void propagate(const size_type index) {

		for (size_type i = height; i; --i)

			push(index >> i);

	}

	void thrust(const size_type index) {

		tree[index].first = reflect(index);

		push(index);

	}

	void evaluate(const size_type index) {

		for (size_type i = height; i; --i)

			thrust(index >> i);

	}

	void build(size_type index) {

		while (index >>= 1)

			recalc(index);

	}



public:

	LazySegmentTree(

		const size_type size, const F &value_addition = std::plus<value_type>(),

		const_reference value_neutral = value_type(),

		const G &operator_multiplication = std::multiplies<operator_type>(),

		operator_constref operator_neutral = operator_type(),

		const H &mutual_multiplication =

		[](const_reference l, operator_constref r) { return l * r; })

		: f(value_addition), v_neutral(value_neutral), g(operator_multiplication),

		o_neutral(operator_neutral), h(mutual_multiplication),

		height(getheight(size)), size_((size_type)1 << height),

		tree(size_ << 1, std::make_pair(v_neutral, o_neutral)) {}

	void update(size_type begin, size_type end, operator_constref data) {

		assert(begin <= end);

		assert(begin <= size_);

		assert(end <= size_);

		begin += size_;

		end += size_;

		propagate(begin);

		propagate(end - 1);

		for (size_type left = begin, right = end; left < right;

			left >>= 1, right >>= 1) {

			if (left & 1)

				assign(left++, data);

			if (right & 1)

				assign(right - 1, data);

		}

		build(begin);

		build(end - 1);

	}

	void update(size_type index,

		const std::function<value_type(const_reference)> &e) {

		assert(index < size_);

		index += size_;

		propagate(index);

		tree[index].first = e(reflect(index));

		tree[index].second = o_neutral;

		build(index);

	}

	void update(const size_type index, const_reference data) {

		assert(index < size_);

		update(index, [&data](const_reference d) { return data; });

	}

	value_type range(size_type begin, size_type end) {

		assert(begin <= end);

		assert(begin <= size_);

		assert(end <= size_);

		begin += size_;

		end += size_;

		evaluate(begin);

		evaluate(end - 1);

		value_type retL = v_neutral, retR = v_neutral;

		for (; begin < end; begin >>= 1, end >>= 1) {

			if (begin & 1)

				retL = f(retL, reflect(begin++));

			if (end & 1)

				retR = f(reflect(end - 1), retR);

		}

		return f(retL, retR);

	}

	size_type search(const std::function<bool(const_reference)> &b) {

		if (!b(reflect(1)))

			return size_;

		value_type acc = v_neutral;

		size_type i = 1;

		while (i < size) {

			thrust(i);

			if (!b(f(acc, reflect(i <<= 1))))

				acc = f(acc, reflect(i++));

		}

		return i - size_;

	}

	size_type size() const { return size_; }

};

//#define NDEBUG

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>

#include <array>

#include <cassert>

#include <climits>

#include <cmath>

#include <cstdint>

#include <cstdio>

#include <cstdlib>

#include <ctime>

#include <functional>

#include <limits>

#include <map>

#include <memory>

#include <numeric>

#include <queue>

#include <set>

#include <stack>

#include <string>

#include <type_traits>

#include <utility>

#include <vector>

constexpr double PI = 3.1415926535897932;



using int32 = std::int_fast32_t;

using int64 = std::int_fast64_t;

using uint32 = std::uint_fast32_t;

using uint64 = std::uint_fast64_t;

using intl32 = std::int_least32_t;

using intl64 = std::int_least64_t;

using uintl32 = std::uint_least32_t;

using uintl64 = std::uint_least64_t;



const char *yes(bool c) { return c ? "yes" : "no"; }

const char *Yes(bool c) { return c ? "Yes" : "No"; }

const char *YES(bool c) { return c ? "YES" : "NO"; }

const char *pos(bool c) { return c ? "possible" : "impossible"; }

const char *Pos(bool c) { return c ? "Possible" : "Impossible"; }

const char *POS(bool c) { return c ? "POSSIBLE" : "IMPOSSIBLE"; }

template<class T>bool bmaxi(T&a, const T&b) { if (b<a)return 0;a = b;return 1; }

template<class T>bool bmini(T&a, const T&b) { if (a<b)return 0;a = b;return 1; }

template<class T>bool nmaxi(T&a, const T&b) { if (a<b) { a = b;return 1; }return 0; }

template<class T>bool nmini(T&a, const T&b) { if (b<a) { a = b;return 1; }return 0; }

template<typename T>auto scan(T&d)->typename std::enable_if<std::is_signed<T>::value>::type

{

	d = 0;int c = fgetc(stdin);bool f = 0;while (c<'0' || '9'<c) { if (c == '-')f = 1;c = fgetc(stdin); }

	while (c != ' '&&c != '\n') { d = d * 10 + c - '0';c = fgetc(stdin); }if (f)d = -d;

}

template<typename T>auto scan(T&d)->typename std::enable_if<!std::is_signed<T>::value>::type

{

	d = 0;int c = fgetc(stdin);while (c == ' ' || c == '\n')c = fgetc(stdin);

	while (c != ' '&&c != '\n') { d = d * 10 + c - '0';c = fgetc(stdin); }

}

void scan(char&d) { d = fgetc(stdin);while (d == ' ' || d == '\n')d = fgetc(stdin); }

void scan(double&d) { scanf("%lf", &d); }void scan(std::string&d) {

	d.clear();int c = fgetc(stdin);

	while (c == ' ' || c == '\n')c = fgetc(stdin);while (c != ' '&&c != '\n') { d.push_back(c);c = fgetc(stdin); }

}

template<typename F, typename...R>void scan(F&f, R&...r) { scan(f);scan(r...); }

template<typename T>T input() { T d;scan(d);return d; }

template <typename T>auto print(T d)->typename std::enable_if<std::is_signed<T>::value>::type

{

	static int c[20];int i = 0;bool f = 0;if (d<0) { f = 1;d = -d; }while (d) { c[i++] = d % 10;d /= 10; }

	if (!i)c[i++] = 0;if (f)fputc('-', stdout);while (i--)fputc(c[i] + '0', stdout);

}

template<typename T>auto print(T d)->typename std::enable_if<!std::is_signed<T>::value>::type

{

	static int c[20];int i = 0;while (d) { c[i++] = d % 10;d /= 10; }

	if (!i)c[i++] = 0;while (i--)fputc(c[i] + '0', stdout);

}

template<>void print<char>(char d) { fputc(d, stdout); }

template<>void print<double>(double d) { printf("%f", d); }

void print(const char *c) { while (*c != '\0')fputc(*(c++), stdout); }void print() {}

template<typename F, typename...R>void print(F f, R...r) { print(f);print(r...); }

template<typename...R>void println(R...r) { print(r...);fputc('\n', stdout); }

template<typename...R>int END(R...r) { println(r...);return 0; }



template<typename T>

struct Assign {

	T a;

	bool f;

	Assign():f(1){}

	Assign(const T &x):a(x),f(0){}

	Assign operator*(const Assign &o)const {

		return o.f ? *this : o;

	}

};

template<typename T>

struct Mini {

	T a;

	Mini(const T &x=std::numeric_limits<T>::max()):a(x){}

	Mini operator+(const Mini &o)const {

		return Mini(std::min(a, o.a));

	}

	Mini operator*(const Assign<T> &o)const {

		return o.f ? *this : Mini(o.a);

	}

};





int main(void) {

	using M = Mini<uint32>;

	using A = Assign<uint32>;

	uint32 n, q;

	scan(n, q);

	LazySegmentTree<M, A> T(n, std::plus<M>(), M(2147483647));

	while (q--) {

		uint32 c, s, t, x;

		scan(c, s, t);

		if (c) {

			println(T.range(s, t + 1).a);

		}

		else {

			scan(x);

			T.update(s, t + 1, A(x));

		}

	}

	return 0;

}
