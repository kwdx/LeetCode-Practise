/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char &c : letters)
            if (c > target) return c;
        return letters[0];
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<char> letters;
    char target;
    char res;
    
    /**
     输入: letters = ["c", "f", "j"]，target = "a"
     输出: "c"
     */
    letters = {'c','f','j'};
    target = 'a';
    res = 'c';
    assert(res == Solution().nextGreatestLetter(letters, target));
    
    /**
     输入: letters = ["c","f","j"], target = "c"
     输出: "f"
     */
    letters = {'c','f','j'};
    target = 'c';
    res = 'f';
    assert(res == Solution().nextGreatestLetter(letters, target));
    
    /**
     输入: letters = ["c","f","j"], target = "d"
     输出: "f"
     */
    letters = {'c','f','j'};
    target = 'd';
    res = 'f';
    assert(res == Solution().nextGreatestLetter(letters, target));
    
    cout << "OK~" << endl;
    
    return 0;
}
