//
//  5855.找出数组中的第K大整数.cpp
//  Cpp
//
//  Created by warden on 2021/8/29.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// @lc code=start
bool compare(string num1, string num2) {
    if (num1.size() == num2.size()) {
        for (int i = 0; i < num1.size(); ++i) {
            if (num1[i] != num2[i])
                return num1[i] > num2[i];
        }
        return true;
    }
    return num1.size() > num2.size();
}
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), compare);
        
        return nums[k - 1];
    }
};
//struct cmp {
//    bool operator() (string num1, string num2) {
//        if (num1.size() == num2.size()) {
//            for (int i = 0; i < num1.size(); ++i) {
//                if (num1[i] != num2[i])
//                    return num1[i] > num2[i];
//            }
//            return true;
//        }
//        return num1.size() > num2.size();
//    }
//};
//class Solution {
//public:
//    string kthLargestNumber(vector<string>& nums, int k) {
//        priority_queue<string, vector<string>, cmp> pq;
//
//        for (string num : nums) {
//            if (pq.size() < k) {
//                pq.push(num);
//            } else {
//                pq.push(num);
//                pq.pop();
//            }
//        }
//        return pq.top();
//    }
//};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<string> nums;
    int k;
    string res;
    
    /**
     输入：nums = ["3","6","7","10"], k = 4
     输出："3"
     解释：
     nums 中的数字按非递减顺序排列为 ["3","6","7","10"]
     其中第 4 大整数是 "3"
     */
    nums = {"3","6","7","10"};
    k = 4;
    res = "3";
    assert(res == Solution().kthLargestNumber(nums, k));

    /**
     输入：nums = ["2","21","12","1"], k = 3
     输出："2"
     解释：
     nums 中的数字按非递减顺序排列为 ["1","2","12","21"]
     其中第 3 大整数是 "2"
     */
    nums = {"2","21","12","1"};
    k = 3;
    res = "2";
    assert(res == Solution().kthLargestNumber(nums, k));

    /**
     输入：nums = ["0","0"], k = 2
     输出："0"
     解释：
     nums 中的数字按非递减顺序排列为 ["0","0"]
     其中第 2 大整数是 "0"
     */
    nums = {"0","0","0","0"};
    k = 2;
    res = "0";
    assert(res == Solution().kthLargestNumber(nums, k));

    /**
     输入：nums = ["233","97"], k = 1
     输出："233"
     解释：
     nums 中的数字按非递减顺序排列为 ["0","0"]
     其中第 2 大整数是 "0"
     */
    nums = {"233","97"};
    k = 1;
    res = "233";
    assert(res == Solution().kthLargestNumber(nums, k));

    cout << "OK~" << endl;
    
    return 0;
}
