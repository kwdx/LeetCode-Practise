/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

// @lc code=start
#define mutate(x, pos, n) ((x & ~(3<<pos*2) | n<<pos*2) & 0xffff)

class Solution {
private:
    inline int gencode(string& gen){  // 将字符串编码成int
        int code = 0;
        for (int i = 0; i < 8; ++i){
            code <<= 2;
            switch(gen[i]){
                case 'A': break;
                case 'C': code |= 1; break;
                case 'G': code |= 2; break;
                case 'T': code |= 3; break;
            }
        }
        return code;
    }
    
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int scode = gencode(start), ecode = gencode(end);
        // 基因库编码后保存在set中
        unordered_set<int> sets;
        for (string& s : bank) {
            sets.insert(gencode(s));
        }
        
        if (!sets.count(ecode)) {
            return -1;
        }
        // 移除开始的基因
        sets.erase(scode);
              
        // bfs
        queue<int> q;
        q.emplace(scode);
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int cnt = (int)q.size();
            for (int i = 0; i < cnt; ++i) {
                int cur = q.front();
                q.pop();
                for (int j = 0; j < 8; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        int code = mutate(cur, j, k);
                        if (sets.count(code)) {
                            if (code == ecode) {
                                return ans;
                            }
                            q.push(code);
                            sets.erase(code);
                        }
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

    string start;
    string end;
    vector<string> bank;
    int res;
    
    /**
     输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
     输出：1
     */
    start = "AACCGGTT";
    end = "AACCGGTA";
    bank = {"AACCGGTA"};
    res = 1;
    assert(res == Solution().minMutation(start, end, bank));
    
    /**
     输入：start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
     输出：2
     */
    start = "AACCGGTT";
    end = "AAACGGTA";
    bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    res = 2;
    assert(res == Solution().minMutation(start, end, bank));
    
    /**
     输入：start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
     输出：3
     */
    start = "AAAAACCC";
    end = "AACCCCCC";
    bank = {"AAAACCCC","AAACCCCC","AACCCCCC"};
    res = 3;
    assert(res == Solution().minMutation(start, end, bank));
    
    cout << "OK~" << endl;
    
    return 0;
}
