#include <cstdio>
#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 1000;
double cur_min = INT_MAX;
double radius[MAXN] = {0};
bool visit[MAXN] = {false};
double tmp[MAXN][5] = {0};
// 0: rk, 1: dk, 2: xk, 3: lk, 4: Lk

double findMin(int size, int n) {
    double min = tmp[n][0];
    for (int i = 0; i < size; ++i)
        if (!visit[i] && radius[i] < min)
            min = radius[i];
    return min;
}

void dfs(int size, int n) {
    if (n == size) {
        cur_min = tmp[size - 1][4];
        printf("current min = %lf\n", cur_min);
        printf("radius order: ");
        for (int i = 0; i < size; ++i)
            printf("%.1lf ", tmp[i][0]);
        printf("\n");
        printf("         rk    dk    xk    lk    Lk\n");
        for (int i = 0; i < size; ++i)
            printf("%5d %5.1lf %5.1lf %5.1lf %5.1lf %5.1lf\n", i, tmp[i][0], tmp[i][1], tmp[i][2], tmp[i][3], tmp[i][4]);
        return;
    }
    for (int i = 0; i < size; ++i) {
        if (visit[i])
            continue;
        if (i > 0 && radius[i] == radius[i - 1] && visit[i - 1] != 0)
            continue;
        visit[i] = true;
        tmp[n][0] = radius[i];
        if (n == 0)
        tmp[n][1] = tmp[n][2] = 0;
        else {
            tmp[n][1] = 2 * sqrt(tmp[n][0] * tmp[n - 1][0]);
            tmp[n][2] = tmp[n - 1][2] + tmp[n][1];
        }
        tmp[n][3] = tmp[n][2] + tmp[0][0] + tmp[n][0];
        double r_min = findMin(size, n);
        tmp[n][4] = tmp[n][2] + 2 * (size - n - 1) * r_min + r_min + tmp[0][0];
        if (tmp[n][4] <= cur_min)
            dfs(size, n + 1);
        tmp[n][0] = tmp[n][1] = tmp[n][2] = tmp[n][3] = tmp[n][4] = 0;
        visit[i] = false;
    }
}

int main() {
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        scanf("%lf", &radius[i]);
    }
    sort(radius, radius + size);
    dfs(size, 0);
    return 0;
}