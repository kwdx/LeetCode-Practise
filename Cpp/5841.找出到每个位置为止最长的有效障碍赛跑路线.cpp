//
//  5841.找出到每个位置为止最长的有效障碍赛跑路线.cpp
//  Cpp
//
//  Created by warden on 2021/8/8.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {        
        vector<int> dp, ans;
        for (auto obstacle : obstacles) {
            auto loc = upper_bound(dp.begin(), dp.end(), obstacle);
            if (loc == dp.end()) {
                dp.push_back(obstacle);
                ans.push_back((int)dp.size());
            } else {
                dp[loc - dp.begin()] = obstacle;
                ans.push_back((int)(loc - dp.begin()) + 1);
            }
        }
        
        return ans;
        
        
//        // 超时
//        vector<int> dp;
//        map<int, int> nums;
//        for (int i = 0; i < obstacles.size(); i++) {
//            int obstacle = obstacles[i];
//            int count = 0;
//            for (auto item = nums.rbegin(); item != nums.rend(); item++) {
//                if (item->first <= obstacle) {
//                    count = max(item->second, count);
//                }
//            }
//            dp.push_back(count + 1);
//            nums[obstacle] = count + 1;
//        }
//
//        return dp;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution solution;
    
    vector<int> obstacles;
    vector<int> ans;
    
//    obstacles = {1, 2, 3, 2};
//    // 1, 2, 3, 3
//    ans = solution.longestObstacleCourseAtEachPosition(obstacles);
//    for (auto an : ans) {
//        cout << an << " ";
//    }
//    cout << endl;
//
//    obstacles = {2, 2, 1};
//    // 1, 2, 1
//    ans = solution.longestObstacleCourseAtEachPosition(obstacles);
//    for (auto an : ans) {
//        cout << an << " ";
//    }
//    cout << endl;
//
//    obstacles = {3, 1, 5, 6, 4, 2};
//    // 1, 1, 2, 3, 2, 2
//    ans = solution.longestObstacleCourseAtEachPosition(obstacles);
//    for (auto an : ans) {
//        cout << an << " ";
//    }
//    cout << endl;

    obstacles = {5,1,5,5,1,3,4,5,1,4};
    // [1,1,2,3,2,3,4,5,3,5]
    ans = solution.longestObstacleCourseAtEachPosition(obstacles);
    for (auto an : ans) {
        cout << an << " ";
    }
    cout << endl;
    return 0;
}
