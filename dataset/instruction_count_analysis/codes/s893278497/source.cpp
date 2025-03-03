//#define NDEBUG

#define _CRT_SECURE_NO_WARNINGS

#include <array>

#include <cstddef>

#include <cstdint>

#include <cstdio>

#include <string>

#include <type_traits>

#include <cstddef>

#include <memory>

#include <utility>



template <class T, class Allocator = std::allocator<T>> class LimitedDeque {

public:

	using value_type = T;

	using allocator_type = Allocator;



	using reference = typename allocator_type::reference;

	using const_reference = typename allocator_type::const_reference;

	using size_type = typename allocator_type::size_type;

	using difference_type = typename allocator_type::difference_type;



	using pointer = typename std::allocator_traits<allocator_type>::pointer;

	using const_pointer =

		typename std::allocator_traits<allocator_type>::const_pointer;

	class iterator {};

	class reverse_iterator {};



private:

	static size_type get_size(const size_type siz) {

		size_type ret = 1;

		while (ret <= siz)

			ret <<= 1;

		return ret;

	}

	using traits = std::allocator_traits<allocator_type>;



	const size_type mask;



	allocator_type alc;

	const pointer p;

	size_type left, right;



public:

	explicit LimitedDeque(const size_type limit,

		const allocator_type &a = allocator_type())

		: mask(get_size(limit) - 1), alc(a), p(traits::allocate(alc, mask + 1)),

		left(0), right(mask) {}

	size_type size() const noexcept { return mask & (right + 1 - left); }

	size_type max_size() const noexcept { return mask; }

	bool empty() const noexcept { return !size(); }



	reference operator[](const size_type i) { return p[(left + i) & mask]; }

	const_reference operator[](const size_type i) const {

		return p[(left + i) & mask];

	}

	reference front() { return p[left]; }

	const_reference front() const { return p[left]; }

	reference back() { return p[right]; }

	const_reference back() const { return p[right]; }



	void push_front(const value_type &v) {

		left = (left - 1) & mask;

		traits::construct(alc, p + left, v);

	}

	void push_front(value_type &&v) {

		left = (left - 1) & mask;

		traits::construct(alc, p + left, std::move(v));

	}

	void push_back(const value_type &v) {

		right = (right + 1) & mask;

		traits::construct(alc, p + right, v);

	}

	void push_back(value_type &&v) {

		right = (right + 1) & mask;

		traits::construct(alc, p + right, std::move(v));

	}

	template <class... Args> void emplace_front(Args &&... args) {

		left = (left - 1) & mask;

		traits::construct(alc, p + left, std::forward<Args>(args)...);

	}

	template <class... Args> void emplace_back(Args &&... args) {

		right = (right + 1) & mask;

		traits::construct(alc, p + right, std::forward<Args>(args)...);

	}

	void pop_front() {

		traits::destroy(alc, p + left);

		left = (left + 1) & mask;

	}

	void pop_back() {

		traits::destroy(alc, p + right);

		right = (right - 1) & mask;

	}

};





struct customIO {

	int c;

	bool f;

	std::array<int, 30> buf;

	void get_c() { c = fgetc(stdin); }

	void put_c(int x) { fputc(x, stdout); }

	bool vacant() { return c == ' ' || c == '\n'; }

	operator int() { return 0; }



	// in



	void cueing() {

		while (get_c(), vacant())

			;

	}

	template <class T>

	auto operator>>(T &d) ->

		typename std::enable_if<std::is_signed<T>::value, customIO &>::type {

		d = 0;

		f = 0;

		cueing();

		if (c == '-')

			f = 1, get_c();

		do

			d = d * 10 + c - '0';

		while (get_c(), !vacant());

		if (f)

			d = -d;

		return *this;

	}

	template <class T>

	auto operator>>(T &d) ->

		typename std::enable_if<!std::is_signed<T>::value, customIO &>::type {

		d = 0;

		cueing();

		do

			d = d * 10 + c - '0';

		while (get_c(), !vacant());

		return *this;

	}

	customIO &operator>>(char &d) {

		cueing();

		d = c;

		return *this;

	}

	customIO &operator>>(double &d) {

		scanf("%lf", &d);

		return *this;

	}

	customIO &operator>>(std::string &d) {

		d.clear();

		cueing();

		do

			d.push_back(c);

		while (get_c(), !vacant());

		return *this;

	}

	template <class T> T input() {

		T d;

		*this >> d;

		return d;

	}



	// out



	template <class T>

	auto operator<<(T d) ->

		typename std::enable_if<std::is_signed<T>::value, customIO &>::type {

		c = 0;

		f = 0;

		if (d < static_cast<T>(0))

			f = 1, d = -d;

		while (d)

			buf[c++] = d % 10 + '0', d /= 10;

		if (!c)

			buf[c++] = '0';

		if (f)

			put_c('-');

		while (c--)

			put_c(buf[c]);

		return *this;

	}

	template <class T>

	auto operator<<(T d) ->

		typename std::enable_if<!std::is_signed<T>::value, customIO &>::type {

		c = 0;

		while (d)

			buf[c++] = d % 10 + '0', d /= 10;

		if (!c)

			buf[c++] = '0';

		while (c--)

			put_c(buf[c]);

		return *this;

	}

	customIO &operator<<(char d) {

		put_c(d);

		return *this;

	}

	customIO &operator<<(double d) {

		printf("%f", d);

		return *this;

	}

	customIO &operator<<(const std::string &d) {

		for (const auto e : d)

			put_c(e);

		return *this;

	}

	customIO &operator<<(const char *d) {

		while (*d != '\0')

			put_c(*(d++));

		return *this;

	}

	void endl() { put_c('\n'); }

	void space() { put_c(' '); }

} IO;



using int32 = std::int_fast32_t;

using int64 = std::int_fast64_t;

using uint32 = std::uint_fast32_t;

using uint64 = std::uint_fast64_t;

using intl32 = std::int_least32_t;

using intl64 = std::int_least64_t;

using uintl32 = std::uint_least32_t;

using uintl64 = std::uint_least64_t;



int main() {

	const auto n = IO.input<uint32>();

	const auto l = IO.input<uint32>();

	LimitedDeque<std::pair<uint32, uint32>> D(l);

	uint32 a;

	for (uint32 i = 0;i < l;++i) {

		IO >> a;

		while (!D.empty() && D.back().first > a)

			D.pop_back();

		D.emplace_back(a, i);

	}

	IO << D.front().first;

	for (uint32 i = l;i < n;++i) {

		IO >> a;

		if (D.front().second == i - l)

			D.pop_front();

		while (!D.empty() && D.back().first > a)

			D.pop_back();

		D.emplace_back(a, i);

		IO << ' ' << D.front().first;

	}

	IO.endl();

	return 0;

}
