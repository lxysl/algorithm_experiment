#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

struct position {
    int height;
    int x;
    int y;
    bool operator> (position p) const {
        return height > p.height;
    }
};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m <= 2 || n <= 2) {
            return 0;
        }
        priority_queue<position, vector<position>, greater<position>> q;
        bool visit[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == m - 1) {
                    q.push(position{heightMap[i][j], i, j});
                    visit[i][j] = true;
                }
            }
        }
        int ans = 0;
        int dicx[4] = {-1, 1, 0, 0};    // 上下左右
        int dicy[4] = {0, 0, -1, 1};
        while (!q.empty()) {
            position cur = q.top();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = cur.x + dicx[i];
                int y = cur.y + dicy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && !visit[x][y]) {
                    ans += max(0, cur.height - heightMap[x][y]);
                    q.push(position{max(cur.height, heightMap[x][y]), x, y});
                    visit[x][y] = true;
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> heightMap = {{1,4,3,1,3,2}, {3,2,1,3,2,4}, {2,3,3,2,3,1}};
    Solution s;
    int ans = s.trapRainWater(heightMap);
    printf("%d", ans);
}