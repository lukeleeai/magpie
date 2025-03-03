#include <iostream>

#include <vector>

#include <array>

#include <list>

#include <string>

#include <stack>

#include <queue>

#include <deque>

#include <unordered_map>

#include <unordered_set>

#include <tuple>

#include <memory>

#include <cmath>

#include <algorithm>

#include <functional>

#include <iomanip>

#include <numeric>

#include <climits>

#include <cfloat>

#include <cassert>

#include <random>

constexpr long long int MOD = 1000000007LL;

long long int power(const long long int base, const int exp) {

	switch (exp) {

	case 0: return 1LL;

	case 1: return base % MOD;

	default: return power(base * base % MOD, exp / 2) * power(base, exp % 2) % MOD;

	}

}

long long int inverse(const long long int base) {

	return power(base, MOD - 2);

}

void move_root(int from, int to, std::vector<int>& size, const std::vector<std::vector<int>>& nodes) {

	int root_size = size[from];

	int child_size = size[to];

	size[from] -= child_size;

	size[to] = root_size;

}

long long int prob(int root, const std::vector<int>& size, const std::vector<std::vector<int>>& nodes) {

	long long int not_hole = inverse(power(2, size.size() - 1));

	for (const auto child : nodes[root]) {

		not_hole += inverse(power(2, size.size() - 1 - size[child])) * (1 - inverse(power(2, size[child])) + MOD) % MOD;

		not_hole %= MOD;

	}

	return (1 - not_hole + MOD) * inverse(2) % MOD;

}

long long int cal_estimate(int root, int prev, std::vector<int>& size, const std::vector<std::vector<int>>& nodes) {

	long long int result = prob(root, size, nodes);

	for (const auto next : nodes[root]) if (next != prev) {

		move_root(root, next, size, nodes);

		result += cal_estimate(next, root, size, nodes);

		result %= MOD;

		move_root(next, root, size, nodes);

	}

	return result;

}

int main() {

	int n; std::cin >> n;

	std::vector<std::vector<int>> nodes(n);

	std::vector<int> size(n, 0), prev(n, -1);

	for (auto i = 1; i < n; ++i) {

		int a, b; std::cin >> a >> b; --a; --b;

		nodes[a].push_back(b); nodes[b].push_back(a);

	}

	std::stack<int> stack; stack.push(0);

	while (!stack.empty()) {

		auto top = stack.top(); stack.pop();

		if (top >= 0) {

			stack.push(-top - 1);

			size[top] = 1;

			for (const auto next : nodes[top]) if (size[next] == 0) {

				prev[next] = top;

				stack.push(next);

			}

		}

		else {

			if (prev[-top - 1] >= 0) {

				size[prev[-top - 1]] += size[-top - 1];

			}

		}

	}

	std::cout << cal_estimate(0, -1, size, nodes) << std::endl;

}