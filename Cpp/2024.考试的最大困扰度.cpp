/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        this->answer = answerKey;
        this->n = (int)answer.size();
        this->k = k;
        return max(getCnt('T'), getCnt('F'));
    }
private:
    string answer;
    int n, k;
    
    int getCnt(char c) {
        int ans = 0;
        for (int i = 0, j = 0, cnt = 0; i < n; ++i) {
            if (answer[i] == c) ++cnt;
            while (cnt > k) {
                if (answer[j] == c) --cnt;
                ++j;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string answerKey;
    int k;
    int res;
    
    /**
     输入：answerKey = "TTFF", k = 2
     输出：4
     解释：我们可以将两个 'F' 都变为 'T' ，得到 answerKey = "TTTT" 。
     总共有四个连续的 'T' 。
     */
    answerKey = "TTFF";
    k = 2;
    res = 4;
    assert(res == Solution().maxConsecutiveAnswers(answerKey, k));
    
    /**
     输入：answerKey = "TFFT", k = 1
     输出：3
     解释：我们可以将最前面的 'T' 换成 'F' ，得到 answerKey = "FFFT" 。
     或者，我们可以将第二个 'T' 换成 'F' ，得到 answerKey = "TFFF" 。
     两种情况下，都有三个连续的 'F' 。
     */
    answerKey = "TFFT";
    k = 1;
    res = 3;
    assert(res == Solution().maxConsecutiveAnswers(answerKey, k));
    
    /**
     输入：answerKey = "TTFTTFTT", k = 1
     输出：5
     解释：我们可以将第一个 'F' 换成 'T' ，得到 answerKey = "TTTTTFTT" 。
     或者我们可以将第二个 'F' 换成 'T' ，得到 answerKey = "TTFTTTTT" 。
     两种情况下，都有五个连续的 'T' 。
     */
    answerKey = "TTFTTFTT";
    k = 1;
    res = 5;
    assert(res == Solution().maxConsecutiveAnswers(answerKey, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
