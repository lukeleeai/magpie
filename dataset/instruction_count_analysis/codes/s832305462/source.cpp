#include <cstdio>

#include <cstring>



char str[100010];

bool vis[100010] = {1};

int main() {

	scanf("%s", str);

	for (int i = 0; str[i]; ++i) {

		if (vis[i]) {

			if (strncmp(str + i, "dreamer", 7) == 0)

				vis[i + 7] = 1;

			if (strncmp(str + i, "eraser", 6) == 0)

				vis[i + 6] = 1;

			if (strncmp(str + i, "dream", 5) == 0)

				vis[i + 5] = 1;

			if (strncmp(str + i, "erase", 5) == 0)

				vis[i + 5] = 1;

		}

	}

	puts(vis[strlen(str)] ? "YES" : "NO");

	return 0;

}
