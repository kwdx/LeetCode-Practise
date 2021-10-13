/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        
        for (int i = 1; i <= n; ++i) {
            string str;
            if (i % 3 == 0) {
                str = "Fizz";
            }
            if (i % 5 == 0) {
                str += "Buzz";
            }
            if (str.size() == 0) {
                str = to_string(i);
            }
            ans.push_back(str);
        }
        
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    int n;
    vector<string> res;
    
    /**
     输入：n = 3
     输出：["1","2","Fizz"]
     */
    n = 3;
    res = {"1","2","Fizz"};
    assert(res == Solution().fizzBuzz(n));
    
    /**
     输入：n = 5
     输出：["1","2","Fizz","4","Buzz"]
     */
    n = 5;
    res = {"1","2","Fizz","4","Buzz"};
    assert(res == Solution().fizzBuzz(n));
    
    /**
     输入：n = 15
     输出：["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
     */
    n = 15;
    res = {"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"};
    assert(res == Solution().fizzBuzz(n));
    
    cout << "OK~" << endl;
    
    return 0;
}
