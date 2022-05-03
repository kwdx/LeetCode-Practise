/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
    class Log {
    public:
        int type, idx;
        string ori, sign, content;
        
        Log(string& s, int idx) {
            this->idx = idx;
            this->ori = s;
            int i = 0, n = (int)s.size();
            while (i < n && s[i] != ' ') {
                ++i;
            }
            this->sign = s.substr(0, i);
            this->content = s.substr(i + 1, n - i - 1);
            this->type = isdigit(s[i + 1]) ? 1 : 0;
        }
    };
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = (int)logs.size();
        vector<Log*> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = new Log(logs[i], i);
        }
        sort(arr.begin(), arr.end(), [&](const Log* a, const Log* b) {
            if (a->type != b->type) {
                return a->type < b->type;
            }
            if (a->type == 1) {
                return a->idx < b->idx;
            }
            return a->content != b->content ?
            a->content < b->content :
            a->sign < b->sign;
        });
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = arr[i]->ori;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> logs;
    vector<string> res;
    
    /**'
     输入：logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
     输出：["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
     解释：
     字母日志的内容都不同，所以顺序为 "art can", "art zero", "own kit dig" 。
     数字日志保留原来的相对顺序 "dig1 8 1 5 1", "dig2 3 6" 。
     */
    logs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    res = {"let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"};
    assert(res == Solution().reorderLogFiles(logs));

    /**
     输入：logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
     输出：["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
     */
    logs = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
    res = {"g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"};
    assert(res == Solution().reorderLogFiles(logs));
    
    cout << "OK~" << endl;
    
    return 0;
}
