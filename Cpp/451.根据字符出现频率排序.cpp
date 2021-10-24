/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        string res;
        map<char, int> m;
        for(auto val:s)
            m[val]++;

        priority_queue<pair<int, char>> pq;
        for(auto val:m)
            pq.push(make_pair(val.second, val.first));
        
        while (!pq.empty()) {
            auto top = pq.top();
            int num = top.first;
            while(num--)
                res+=top.second;
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s, res;
    
    /**
     输入:
     "tree"

     输出:
     "eert"

     解释:
     'e'出现两次，'r'和't'都只出现一次。
     因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
     */
    s = "tree";
    res = "eetr";
    assert(res == Solution().frequencySort(s));
    
    /**
     输入:
     "cccaaa"

     输出:
     "cccaaa"

     解释:
     'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
     注意"cacaca"是不正确的，因为相同的字母必须放在一起。
     */
    s = "cccaaa";
    res = "cccaaa";
    assert(res == Solution().frequencySort(s));
    
    /**
     输入:
     "Aabb"

     输出:
     "bbAa"

     解释:
     此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
     注意'A'和'a'被认为是两种不同的字符。
     */
    s = "Aabb";
    res = "bbaA";
    assert(res == Solution().frequencySort(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
