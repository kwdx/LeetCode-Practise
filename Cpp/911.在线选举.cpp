/*
 * @lc app=leetcode.cn id=911 lang=cpp
 *
 * [911] 在线选举
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class TopVotedCandidate {
private:
    // 时间对应的候选人 <<time, person>>
    vector<pair<int, int>> list;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = (int)times.size();
        unordered_map<int, int> votes;
        // 每个候选人的选票
        // 当前得票数最高最近的候选人
        int curPerson = -1;
        for (int i = 0; i < n; ++i) {
            int person = persons[i];
            votes[person] += 1;
            if (curPerson == -1 || votes[persons[i]] >= votes[curPerson]) {
                curPerson = persons[i];
            }
            list.push_back({times[i], curPerson});
        }
    }
    
    int q(int t) {
        int l = 0, r = (int)list.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (list[mid].first <= t) l = mid;
            else r = mid - 1;
        }
        return list[r].first <= t ? list[r].second : 0;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入：
     ["TopVotedCandidate", "q", "q", "q", "q", "q", "q"]
     [[[0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]], [3], [12], [25], [15], [24], [8]]
     输出：
     [null, 0, 1, 1, 0, 0, 1]

     解释：
     TopVotedCandidate topVotedCandidate = new TopVotedCandidate([0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]);
     topVotedCandidate.q(3); // 返回 0 ，在时刻 3 ，票数分布为 [0] ，编号为 0 的候选人领先。
     topVotedCandidate.q(12); // 返回 1 ，在时刻 12 ，票数分布为 [0,1,1] ，编号为 1 的候选人领先。
     topVotedCandidate.q(25); // 返回 1 ，在时刻 25 ，票数分布为 [0,1,1,0,0,1] ，编号为 1 的候选人领先。（在平局的情况下，1 是最近获得投票的候选人）。
     topVotedCandidate.q(15); // 返回 0
     topVotedCandidate.q(24); // 返回 0
     topVotedCandidate.q(8); // 返回 1
     */
    vector<int> persons = {0, 1, 1, 0, 0, 1, 0};
    vector<int> times = {0, 5, 10, 15, 20, 25, 30};
    TopVotedCandidate* topVotedCandidate = new TopVotedCandidate(persons, times);
    // 返回 0 ，在时刻 3 ，票数分布为 [0] ，编号为 0 的候选人领先。
    assert(topVotedCandidate->q(3) == 0);
    // 返回 1 ，在时刻 12 ，票数分布为 [0,1,1] ，编号为 1 的候选人领先。
    assert(topVotedCandidate->q(12) == 1);
    // 返回 1 ，在时刻 25 ，票数分布为 [0,1,1,0,0,1] ，编号为 1 的候选人领先。（在平局的情况下，1 是最近获得投票的候选人）。
    assert(topVotedCandidate->q(25) == 1);
    // 返回 0
    assert(topVotedCandidate->q(15) == 0);
    // 返回 0
    assert(topVotedCandidate->q(24) == 0);
    // 返回 1
    assert(topVotedCandidate->q(8) == 1);

    cout << "OK~" << endl;

    return 0;
}
