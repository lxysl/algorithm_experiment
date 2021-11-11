#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 100;
int p[MAXN];
int m[MAXN][MAXN];
int s[MAXN][MAXN];

void init(int n) {
    memset(p, 0, sizeof (p));
    memset(m, 0, sizeof (m));
    memset(s, 0, sizeof (s));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            s[i][j] = i;
        }
    }
}

void dfs_print(int start, int end, int split) {
    if (end - start >= 0 && end - start <= 1) {
        while (end - start >= 0 && end - start <= 1) {
            printf("A%d", start++);
        }
        return;
    }
    int split_left = s[start][split];
    int split_right = s[split + 1][end];
    if (split - start >= 1) printf("(");
    dfs_print(start, split, split_left);
    if (split - start >= 1) printf(")");
    if (end - split >= 2) printf("(");
    dfs_print(split + 1, end, split_right);
    if (end - split >= 2) printf(")");
}

int main() {
    int n;
    scanf("%d", &n);
    init(n);
    for (int i = 0; i <= n; ++i) {
        scanf("%d", &p[i]);
    }
    for (int l = 2; l <= n; ++l) {  // 链长
        for (int i = 1; i <= n - l + 1; ++i) {  // 前边界
            int j = i + l - 1;  // 后边界
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            for (int k = i + 1; k <= j - 1; ++k) {  // 新划分点
                int tmp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (tmp < m[i][j]) {
                    m[i][j] = tmp;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("%d\n", m[1][n]);
    for (int i = 1; i <= n; ++i) {
        printf("A%d", i);
    }
    printf("=");
    dfs_print(1, n, s[1][n]);
    printf("\n");
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%6d ", m[i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}