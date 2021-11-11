/*
 * @lc app=leetcode.cn id=488 lang=cpp
 *
 * [488] 祖玛游戏
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
private:
    class Node {
        // 当前棋盘情况
    public:
        string board;
        // cur 代表当前 hand 的使用情况（若 cur 二进制表示中的第 k 位为 1，代表 hand 的第 k 个彩球已被使用）
        // val 代表「当前棋盘为 a」和「hand 使用情况为 cur」的情况下，至少还需要多少步才能将 a 全部消掉（启发式估算值）
        // step 代表当前局面是经过多少步而来
        int cur, val, step;
        Node (string b, int c, int v, int s) : board(b), cur(c), val(v), step(s) {}
    };
    
    int INF = 0x3f3f3f3f;
    string _hand;
    int m;
    unordered_map<string, int> map;
    
    /// 计算预估值
    /// @param board 棋盘情况
    /// @param k 当前使用情况
    int estimate(string board, int k) {
        unordered_map<char, int> m1, m2;
        for (char c : board) {
            ++m1[c];
        }
        for (int i = 0; i < m; ++i) {
            if (((k >> i) & 1) == 0) {
                ++m2[_hand[i]];
            }
        }
        int ans = 0;
        for (auto kv : m1) {
            int c1 = kv.second, c2 = m2[kv.first];
            if (c1 + c2 < 3) return INF;
            if (c1 < 3) ans += (3 - c1);
        }
        return ans;
    }
public:
    int findMinStep(string board, string hand) {
        _hand = hand;
        m = (int)hand.length();
        auto cmp = [](Node* a, Node* b) {
            return (a->val + a->step) > (b->val + b->step);
        };
        priority_queue<Node*, vector<Node*>, decltype(cmp)> q(cmp);
        q.push(new Node(board, 1 << m, estimate(board, 1 << m), 0));
        map[board] = 0;
        while (!q.empty()) {
            Node *node = q.top();
            q.pop();
            string a = node->board;
            int cur = node->cur;
            int step = node->step;
            int n = (int)a.length();
            for (int i = 0; i < m; ++i) {
                if (((cur >> i) & 1) == 1) continue;
                int next = (1 << i) | cur;
                for (int j = 0; j <= n; ++j) {
                    bool ok = false;
                    if (j > 0 && j < n && a[j] == a[j - 1] && a[j - 1] != hand[i]) ok = true;
                    if (j < n && a[j] == hand[i]) ok = true;
                    if (!ok) continue;;
                    string sb = a.substr(0, j) + hand.substr(i, 1);
                    if (j != n) sb += a.substr(j);
                    int k = j;
                    while (0 <= k && k < sb.length()) {
                        char c = sb[k];
                        int l = k, r = k;
                        while (l >= 0 && sb[l] == c) --l;
                        while (r < sb.length() && sb[r] == c) ++r;
                        if (r - l - 1 >= 3) {
                            sb.erase(l + 1, r - l - 1);
                            k = l >= 0 ? l : r;
                        } else {
                            break;
                        }
                    }
                    if (sb.length() == 0)
                        return step + 1;
                    int nextV = estimate(sb, next);
                    if (nextV == INF) continue;
                    if (!map.count(sb) || map[sb] > step + 1) {
                        map[sb] = step + 1;
                        q.push(new Node(sb, next, nextV, step + 1));
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string board, hand;
    int res;
    
    /**
     输入：board = "WRRBBW", hand = "RB"
     输出：-1
     解释：无法移除桌面上的所有球。可以得到的最好局面是：
     - 插入一个 'R' ，使桌面变为 WRRRBBW 。WRRRBBW -> WBBW
     - 插入一个 'B' ，使桌面变为 WBBBW 。WBBBW -> WW
     桌面上还剩着球，没有其他球可以插入。
     */
    board = "WRRBBW";
    hand = "RB";
    res = -1;
    assert(res == Solution().findMinStep(board, hand));
    
    /**
     输入：board = "WWRRBBWW", hand = "WRBRW"
     输出：2
     解释：要想清空桌面上的球，可以按下述步骤：
     - 插入一个 'R' ，使桌面变为 WWRRRBBWW 。WWRRRBBWW -> WWBBWW
     - 插入一个 'B' ，使桌面变为 WWBBBWW 。WWBBBWW -> WWWW -> empty
     只需从手中出 2 个球就可以清空桌面。
     */
    board = "WWRRBBWW";
    hand = "WRBRW";
    res = 2;
    assert(res == Solution().findMinStep(board, hand));
    
    /**
     输入：board = "G", hand = "GGGGG"
     输出：2
     解释：要想清空桌面上的球，可以按下述步骤：
     - 插入一个 'G' ，使桌面变为 GG 。
     - 插入一个 'G' ，使桌面变为 GGG 。GGG -> empty
     只需从手中出 2 个球就可以清空桌面。
     */
    board = "G";
    hand = "GGGGG";
    res = 2;
    assert(res == Solution().findMinStep(board, hand));
    
    /**
     输入：board = "RBYYBBRRB", hand = "YRBGB"
     输出：3
     解释：要想清空桌面上的球，可以按下述步骤：
     - 插入一个 'Y' ，使桌面变为 RBYYYBBRRB 。RBYYYBBRRB -> RBBBRRB -> RRRB -> B
     - 插入一个 'B' ，使桌面变为 BB 。
     - 插入一个 'B' ，使桌面变为 BBB 。BBB -> empty
     只需从手中出 3 个球就可以清空桌面。
     */
    board = "RBYYBBRRB";
    hand = "YRBGB";
    res = 3;
    assert(res == Solution().findMinStep(board, hand));

    cout << "OK~" << endl;

    return 0;
}
