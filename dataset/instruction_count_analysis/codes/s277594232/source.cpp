//#define _USE_MATH_DEFINES

#include <algorithm>

#include <array>

#include <climits>

#include <cmath>

#include <cstdint>

#include <cstdio>

#include <cstdlib>

#include <ctime>

#include <functional>

#include <iostream>

#include <map>

//#include <optional>

#include <queue>

#include <set>

#include <stack>

#include <string>

#include <type_traits>

#include <utility>

#include <vector>



using int32 = std::int_fast32_t;

using int64 = std::int_fast64_t;

using uint32 = std::uint_fast32_t;

using uint64 = std::uint_fast64_t;

using intl32 = std::int_least32_t;

using intl64 = std::int_least64_t;

using uintl32 = std::uint_least32_t;

using uintl64 = std::uint_least64_t;









template<typename T, size_t bitsize>

class wavelet_matrix {

	std::vector<std::uint_least32_t> dic[bitsize];

	std::uint_fast32_t border[bitsize];

	inline std::uint_fast32_t rank(std::uint_fast32_t i, std::uint_fast32_t index) {

		return dic[i][(index >> 5) << 1] + __builtin_popcount(dic[i][index >> 4 | 1] & ((std::uint_least32_t)1 << (index & 0x1f)) - 1);

	}

public:

	wavelet_matrix(std::vector<T> &a) {

		const std::uint_fast32_t len = a.size(), block = ((len >> 5) + 1) << 1;

		for (std::uint_fast32_t i = 0; i < bitsize;++i) {

			dic[i] = std::vector<std::uint_least32_t>(block, 0);

		}

		std::queue<T> Q0, Q1;

		for (std::uint_fast32_t i = 0;i < len;++i) {

			Q0.push(a[i]);

		}

		for (std::uint_fast32_t i = bitsize - 1;~i;--i) {

			const std::uint_fast32_t size = Q0.size();

			std::uint_fast32_t j;

			for (j = 0;j < size;++j) {

				if (Q0.front() >> i & 1) {

					dic[i][j >> 4 | 1] |= (std::uint_least32_t)1 << (j & 0x1f);

					Q1.push(Q0.front());

				}

				else {

					Q0.push(Q0.front());

				}

				Q0.pop();

			}

			for (;j < len;++j) {

				if (Q1.front() >> i & 1) {

					dic[i][j >> 4 | 1] |= (std::uint_least32_t)1 << (j & 0x1f);

					Q1.push(Q1.front());

				}

				else {

					Q0.push(Q1.front());

				}

				Q1.pop();

			}

			border[i] = Q0.size();

			for (j = 2;j < block;j += 2) {

				dic[i][j] = dic[i][j - 2] + __builtin_popcount(dic[i][j - 1]);

			}

		}

		return;

	}

	T access(std::uint_fast32_t index) {

		T ret = 0;

		for (std::uint_fast32_t i = bitsize - 1;~i;--i) {

			ret <<= 1;

			if (dic[i][index >> 4 | 1] >> (index & 0x1f) & 1) {

				++ret;

				index = rank(i, index) + border[i];

			}

			else {

				index -= rank(i, index);

			}

		}

		return ret;

	}

	T rank(std::uint_fast32_t begin, std::uint_fast32_t end, T data) {

		for (std::uint_fast32_t i = bitsize - 1;~i;--i) {

			if (data >> i & 1) {

				begin = rank(i, begin) + border[i];

				end = rank(i, end) + border[i];

			}

			else {

				begin -= rank(i, begin);

				end -= rank(i, end);

			}

		}

		return end - begin;

	}

	T quantile(std::uint_fast32_t begin, std::uint_fast32_t end, std::uint_fast32_t k) {

		T ret = 0;

		for (std::uint_fast32_t i = bitsize - 1;~i;--i) {

			const std::uint_fast32_t l = rank(i, begin), r = rank(i, end);

			ret <<= 1;

			if (r - l > k) {

				begin = l + border[i];

				end = r + border[i];

				++ret;

			}

			else {

				begin -= l;

				end -= r;

				k -= r - l;

			}

		}

		return ret;

	}

	T rquantile(std::uint_fast32_t begin, std::uint_fast32_t end, std::uint_fast32_t k) {

		return quantile(begin, end, end - begin - k - 1);

	}

	std::uint_fast32_t less_than(std::uint_fast32_t begin, std::uint_fast32_t end, T data) {

		std::uint_fast32_t ret = 0;

		for (std::uint_fast32_t i = bitsize - 1;~i;--i) {

			if (data >> i & 1) {

				ret += end - begin + rank(i, begin) - rank(i, end);

				begin = rank(i, begin) + border[i];

				end = rank(i, end) + border[i];

			}

			else {

				begin -= rank(i, begin);

				end -= rank(i, end);

			}

		}

		return ret + end - begin;

	}

	std::uint_fast32_t more_than(std::uint_fast32_t begin, std::uint_fast32_t end, T data) {

		std::uint_fast32_t ret = 0;

		for (std::uint_fast32_t i = bitsize - 1;~i;--i) {

			if (data >> i & 1) {

				begin = rank(i, begin) + border[i];

				end = rank(i, end) + border[i];

			}

			else {

				ret += rank(i, end) - rank(i, begin);

				begin -= rank(i, begin);

				end -= rank(i, end);

			}

		}

		return ret;

	}

	std::uint_fast32_t rangefreq(std::uint_fast32_t begin, std::uint_fast32_t end, T lower, T upper) {

		return end - begin - less_than(begin, end, lower) - more_than(begin, end, upper);

	}

};



int main(void) {

	std::ios::sync_with_stdio(false);

	std::cin.tie(0);

	uint32 n, l;

	std::cin >> n >> l;

	std::vector<uint32> a(n);

	for (uint32 i = 0;i < n;++i) {

		std::cin >> a[i];

	}

	wavelet_matrix<uint32, 30> w(a);

	for (uint32 i = 0;i < n - l + 1;++i) {

		std::cout << (i ? " " : "") << w.rquantile(i, i + l, 0);

	}

	std::cout << "\n";

	return 0;

}
