#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;
int arr[MAXN];
int visit[MAXN];
int tmp[MAXN];
int sum = 0;

void dfs(int n, int size) {
    if (n == size) {
        ++sum;
        for (int i = 0; i < n; ++i) {
            printf("%d ", tmp[i]);
        }
        printf("\n");
    }
    for (int i = 0; i < size; ++i) {
        if (!visit[i]) {
            if (i > 0 && arr[i] == arr[i - 1] && visit[i - 1] != 0) continue;
            // 如果这个数和之前的数一样，并且之前的数还未使用过，说明已经回溯过
            tmp[n] = arr[i];
            visit[i] = true;
            dfs(n + 1, size);
            visit[i] = false;
            tmp[n] = 0;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    fill(visit, visit + MAXN, false);
    dfs(0, n);
    printf("%d", sum);
    return 0;
}