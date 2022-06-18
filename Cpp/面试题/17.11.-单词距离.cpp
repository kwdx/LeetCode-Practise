//
//  A.面试题-17.11.-单词距离.cpp
//  cpp
//
//  Created by kingsoft on 2022/5/27.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        vector<int> v1, v2;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                v1.emplace_back(i);
            } else if (words[i] == word2) {
                v2.emplace_back(i);
            }
        }
        int ans = INT_MAX;
        for (int i = 0, j = 0; i < v1.size(); ++i) {
            // 找到v2中大于v1[i]的第一个元素下标
            while (j < v2.size() and v1[i] > v2[j]) {
                ++j;
            }
            if (j > 0) {
                ans = min(ans, abs(v1[i] -  v2[j - 1]));
            }
            if (j < v2.size()) {
                ans = min(ans, abs(v1[i] - v2[j]));
            }
        }
        return ans;
//        int ans = INT_MAX;
//        for(int j = 0, i = 0; j < v2.size(); j++){
//            //找到v1中大于v2[i]的第一个元素下标
//            while(i < v1.size() and v1[i] < v2[j]) i++;
//            //如果i>0， 那么存在比v2[i]起小的元素，那么就维护最小值
//            if(i > 0) ans = min(ans, abs(v1[i-1] - v2[j]));
//            //如果i < v1.size() 那么那么存在比v2[i]大的元素，那么就维护最小值
//            if(i < v1.size()) ans = min(ans, abs(v1[i] - v2[j]));
//        }
//        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> words;
    string word1;
    string word2;
    int res;
    
    /**
     输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
     输出：1

     来源：力扣（LeetCode）
     链接：https://leetcode.cn/problems/find-closest-lcci
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    words = {"I","am","a","student","from","a","university","in","a","city"};
    word1 = "a";
    word2 = "student";
    res = 1;
    assert(res == Solution().findClosest(words, word1, word2));

    cout << "OK~" << endl;
    
    return 0;
}
