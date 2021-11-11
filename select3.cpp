#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 100;
int arr[MAXN];
struct result {
    int num_sum;    // 子序列的和
    int sum_sum_max;    // 子序列和的和 最大值
    int sum_sum_min;    // 子序列和的和 最小值
    vector<int> split_max;  // 子序列和的和最大合并方案的分割点，中左右 先序遍历
    vector<int> split_min;  // 子序列和的和最小合并方案的分割点，中左右 先序遍历
    bool to_add;    // 是否需要将该结果加入和的和
};

struct node {
    int sum_state;
    result result_left;
    result result_right;
    int split_index;
};

result dfs(int start, int end) {
    if (end - start == 0) {
        return result{arr[start], arr[start], arr[start], vector<int>(), vector<int>(), false};
    }
    if (end - start == 1) {
        int sum = arr[start] + arr[end];
        return result{sum, sum, sum, vector<int>(), vector<int>(), true};
    }
    int sum;
    vector<node> state_max, state_min;
    for (int i = start; i < end; ++i) {
        result rl = dfs(start, i);
        result rr = dfs(i + 1, end);
        sum = rl.num_sum + rr.num_sum;
        int sum_sum_max_sum = sum, sum_sum_min_sum = sum;
        if (rl.to_add) {
            sum_sum_max_sum += rl.sum_sum_max;
            sum_sum_min_sum += rl.sum_sum_min;
        }
        if (rr.to_add) {
            sum_sum_max_sum += rr.sum_sum_max;
            sum_sum_min_sum += rr.sum_sum_min;
        }
        state_max.push_back({sum_sum_max_sum, rl, rr, i});
        state_min.push_back({sum_sum_min_sum, rl, rr, i});
    }
    node node_max = state_max[0], node_min = state_min[0];
    for (const auto &i: state_max)
        if (i.sum_state > node_max.sum_state)
            node_max = i;
    for (const auto &i: state_min)
        if (i.sum_state < node_min.sum_state)
            node_min = i;
    vector<int> split_max_vector, split_min_vector; // {分割点，左子序列分割点vector，右子序列分割点vector}
    split_max_vector.push_back(node_max.split_index);
    split_max_vector.insert(split_max_vector.end(), node_max.result_left.split_max.begin(), node_max.result_left.split_max.end());
    split_max_vector.insert(split_max_vector.end(), node_max.result_right.split_max.begin(), node_max.result_right.split_max.end());
    split_min_vector.push_back(node_min.split_index);
    split_min_vector.insert(split_min_vector.end(), node_min.result_left.split_min.begin(), node_min.result_left.split_min.end());
    split_min_vector.insert(split_min_vector.end(), node_min.result_right.split_min.begin(), node_min.result_right.split_min.end());
    return result{sum, node_max.sum_state, node_min.sum_state, split_max_vector, split_min_vector, true};
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    result ans = dfs(0, n - 1);
    printf("max sum:%d min sum:%d\n", ans.sum_sum_max, ans.sum_sum_min);
    printf("max split index:");
    for (const auto &i: ans.split_max)
        printf("%d ", i);
    printf("\n");
    printf("min split index:");
    for (const auto &i: ans.split_min)
        printf("%d ", i);
    printf("\n");
    return 0;
}