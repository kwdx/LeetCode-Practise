//
//  5851.找出不同的二进制字符串.cpp
//  Cpp
//
//  Created by warden on 2021/8/22.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = (int)nums[0].size();
        int len = 1 << n;
        bool flag[len];
        for (int i = 0; i < len; i++) flag[i] = false;
        
        for (string num : nums) {
            int val = 0;
            for (char ch : num) {
                val = (val << 1) + (ch - '0');
            }
            flag[val] = true;
        }
        
        int val = 0;
        for (int i = 0; i < len; i++) {
            if (!flag[i]) {
                val = i;
                break;;
            }
        }
        
        string res;
        while (n--) {
            if (val & 1) {
                res = "1" + res;
            } else {
                res = "0" + res;
            }
            val >>= 1;
        }
        
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<string> nums;
    string res;

    /**
     输入：nums = ["01","10"]
     输出："11"
     解释："11" 没有出现在 nums 中。"00" 也是正确答案。
     */
    nums = {"01","10"};
    res = Solution().findDifferentBinaryString(nums);
    for (string num : nums) {
        if (num == res) assert(false);
    }
    
    /**
     输入：nums = ["00","01"]
     输出："11"
     解释："11" 没有出现在 nums 中。"10" 也是正确答案。
     */
    nums = {"00","01"};
    res = Solution().findDifferentBinaryString(nums);
    for (string num : nums) {
        if (num == res) assert(false);
    }

    /**
     输入：nums = ["111","011","001"]
     输出："101"
     解释："101" 没有出现在 nums 中。"000"、"010"、"100"、"110" 也是正确答案。
     */
    nums = {"111","011","001"};
    res = Solution().findDifferentBinaryString(nums);
    for (string num : nums) {
        if (num == res) assert(false);
    }

    cout << "OK!" << endl;

    return 0;
}
