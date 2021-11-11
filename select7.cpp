#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> pos;
const int MAXN = 9;
int graph[MAXN][MAXN] = {0};
set<pos> pos_occupied;
vector<int> subset[MAXN];

void init(int size) {
    // init subset: {0 ~ [0,1,2]}; {1 ~ [0,1,2]}; {2 ~ [0,1,2]}; {3 ~ [3,4,5]}; ...
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i / 3 == j / 3)
                subset[i].push_back(j);
        }
    }
}

void select_option(set<int> &option, int size, int i, int j) {
    for (int k = 1; k <= size; ++k) {
        option.insert(k);
    }
    for (int y = 0; y < size; ++y) {
        if (graph[i][y] != 0)
            option.erase(graph[i][y]);
    }
    for (int x = 0; x < size; ++x) {
        if (graph[x][j] != 0)
            option.erase(graph[x][j]);
    }
    vector<int> sub_x = subset[i];
    vector<int> sub_y = subset[j];
    for (auto &sub_i: sub_x) {
        for (auto &sub_j: sub_y) {
            if (graph[sub_i][sub_j] != 0)
                option.erase(graph[sub_i][sub_j]);
        }
    }
}

void dfs(int size, int num) {
    if (num == size * size) {
        printf("found!\n");
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                printf("%d ", graph[i][j]);
            }
            printf("\n");
        }
        return;
    }
    int i = num / size;
    int j = num % size;
    if (pos_occupied.count(pos{i, j})) {
        dfs(size, num + 1);
        return;
    }
    set<int> option;
    select_option(option, size, i, j);
    for (auto &o: option) {
        graph[i][j] = o;
        dfs(size, num + 1);
        graph[i][j] = 0;
    }
}

int main() {
    int size, num;
    scanf("%d%d", &size, &num);
    while (num--) {
        int x, y, n;
        scanf("%d %d %d", &x, &y, &n);
        graph[x][y] = n;
        pos_occupied.insert(pos{x, y});
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    init(size);
    dfs(size, 0);
    return 0;
}