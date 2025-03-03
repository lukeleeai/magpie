#include<iostream>

using namespace std; // 575



int main() {

	int K, n;

	cin >> K;

	cout << (n = K + 3 >> 2 << 1);

	for (int i = 0, j, k;i < n;++ i) {

		cout << endl;

		for (j = 0;j < n;++ j) cout << ((k = (i & 1) * n + (i + j) % n) >= K ? (k - n) % K: k) + 1 << ' ';

	}

	return 0;

}

/*

31536000のコメント解説欄

ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり

また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー



解説AC、解けなかったの悔しい

*/