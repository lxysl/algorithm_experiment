#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;
const int MAXN = 1001;

// prim
struct Node {
    int to;
    int len;
};

struct Point {
    int index;
    int len;
    int last;

    bool operator<(Point p) const {
        return len > p.len;
    }
};

bool visit[MAXN] = {false};
int dis[MAXN];
vector<Node> graph[MAXN];

// kruskal
struct Edge {
    int from;
    int to;
    int len;

    bool operator<(Edge e) const {
        return len < e.len;
    }
};

int root[MAXN];
int height[MAXN];
Edge edgeSet[MAXN * MAXN];

vector<Edge> treeEdge;  // 存放最小生成树的边节点

int Prim(int s) {
    // O(nlogn+m)
    fill(dis, dis + MAXN, INT_MAX);
    int sum = 0;
    priority_queue<Point> q;
    dis[s] = 0;
    q.push(Point{s, dis[s], s});
    while (!q.empty()) {
        int cur = q.top().index;
        int last = q.top().last;
        q.pop();
        if (!visit[cur]) {
            visit[cur] = true;
            sum += dis[cur];
            if (cur != s)
                treeEdge.push_back(Edge{last, cur, dis[cur]});
            for (auto &i: graph[cur]) {
                // 原来点i到集合的距离 > 点i到点cur的距离
                if (!visit[i.to] && dis[i.to] > i.len) {
                    dis[i.to] = i.len;
                    q.push(Point{i.to, dis[i.to], cur});
                }
            }
        }
    }
    return sum;
}

void init() {
    memset(height, 0, sizeof(root));
    treeEdge.clear();
    for (int i = 0; i < MAXN; ++i) {
        root[i] = i;
    }
}

int findRoot(int i) {
    if (root[i] != i)
        root[i] = findRoot(root[i]);
    return root[i];
}

void merge(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);
    if (x != y) {
        if (height[x] > height[y]) {
            root[y] = x;
        } else if (height[x] < height[y]) {
            root[x] = y;
        } else {
            root[x] = y;
            ++height[y];
        }
    }
}

int Kruskal(int m) {
    // O(mlogm)
    init();
    sort(edgeSet, edgeSet + m);
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        Edge cur = edgeSet[i];
        if (findRoot(cur.from) != findRoot(cur.to)) {
            merge(cur.from, cur.to);
            sum += cur.len;
            treeEdge.push_back(cur);
        }
    }
    return sum;
}

int main() {
    int n, m, method, sum;
    printf("请选择 Prim:1; Kruskal:2\n");
    scanf("%d", &method);
    scanf("%d %d", &n, &m);
    if (method == 1) {
        for (int i = 0; i < m; ++i) {
            int from, to, length;
            scanf("%d %d %d", &from, &to, &length);
            graph[from].push_back(Node{to, length});
            graph[to].push_back(Node{from, length});
        }
        sum = Prim(1);
    }
    if (method == 2) {
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &edgeSet[i].from, &edgeSet[i].to, &edgeSet[i].len);
        }
        sum = Kruskal(m);
    }
    printf("%d\n", sum);
    for (auto i: treeEdge) {
        printf("%d %d %d\n", i.from, i.to, i.len);
    }
    return 0;
}
