/*
 * @lc app=leetcode.cn id=1604 lang=cpp
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> timeMap;
        int n = (int)keyName.size();
        for (int i = 0; i < n; ++i) {
            string name = keyName[i];
            string time = keyTime[i];
            int hour = (time[0] - '0') * 10 + (time[1] - '0');
            int minute = (time[3] - '0') * 10 + (time[4] - '0');
            timeMap[name].emplace_back(hour * 60 + minute);
        }
        vector<string> ans;
        for (auto &[name, list] : timeMap) {
            sort(list.begin(), list.end());
            int m = (int)list.size();
            for (int i = 2; i < m; ++i) {
                int time1 = list[i - 2], time2 = list[i];
                int difference = time2 - time1;
                if (difference <= 60) {
                    ans.emplace_back(name);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> keyName;
    vector<string> keyTime;
    vector<string> res;

    /**
     输入：keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
     输出：["daniel"]
     解释："daniel" 在一小时内使用了 3 次员工卡（"10:00"，"10:40"，"11:00"）。
     */
    keyName = {"daniel","daniel","daniel","luis","luis","luis","luis"};
    keyTime = {"10:00","10:40","11:00","09:00","11:00","13:00","15:00"};
    res  = {"daniel"};
    assert(res == Solution().alertNames(keyName, keyTime));

    /**
     输入：keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
     输出：["bob"]
     解释："bob" 在一小时内使用了 3 次员工卡（"21:00"，"21:20"，"21:30"）。
     */
    keyName = {"alice","alice","alice","bob","bob","bob","bob"};
    keyTime = {"12:01","12:00","18:00","21:00","21:20","21:30","23:00"};
    res  = {"bob"};
    assert(res == Solution().alertNames(keyName, keyTime));

    /**
     输入：keyName = ["john","john","john"], keyTime = ["23:58","23:59","00:01"]
     输出：[]
     */
    keyName = {"john","john","john"};
    keyTime = {"23:58","23:59","00:01"};
    res  = {};
    assert(res == Solution().alertNames(keyName, keyTime));

    /**
     输入：keyName = ["leslie","leslie","leslie","clare","clare","clare","clare"], keyTime = ["13:00","13:20","14:00","18:00","18:51","19:30","19:49"]
     输出：["clare","leslie"]
     */
    keyName = {"leslie","leslie","leslie","clare","clare","clare","clare"};
    keyTime = {"13:00","13:20","14:00","18:00","18:51","19:30","19:49"};
    res  = {"clare","leslie"};
    assert(res == Solution().alertNames(keyName, keyTime));

    cout << "OK~" << endl;
    
    return 0;
}
