#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int index;
    int num;

    bool operator<(const Node n) const {
        return num > n.num;
    }
};

int main() {
    int p;
    scanf("%d", &p);
    if (p <= 0) {
        printf("must greater than 0");
        return 0;
    }
    priority_queue<Node> q;
    for (int i = 0; i < p; ++i) {
        int n;
        scanf("%d", &n);
        if (n <= 0) {
            printf("must greater than 0");
            return 0;
        }
        q.push(Node{i, n});
    }
    int ans = 0;
    int p0 = p;
    vector<int> v;
    while (q.size() > 1) {
        Node a1 = q.top();
        q.pop();
        Node a2 = q.top();
        q.pop();
        q.push(Node{++p, a1.num + a2.num});
        ans += a1.num + a2.num - 1;
        if (a1.index < p0)
            v.push_back(a1.index);
        if (a2.index < p0)
            v.push_back(a2.index);
    }
    printf("%d\n", ans);
    for (auto &i: v) {
        printf("%d ", i);
    }
    return 0;
}
