//
//  5839.移除石子使总数最小.cpp
//  Cpp
//
//  Created by warden on 2021/8/8.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = accumulate(piles.begin(), piles.end(), 0);
        
        priority_queue<int> q(piles.begin(), piles.end());
        
        while ((k--) > 0) {
            int num = q.top();
            if (num & 0x1) num = (num >> 1) + 1;
            else num >>= 1;
            sum -= q.top() - num;
            q.pop();
            q.push(num);
        }
                
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> piles;
    Solution solution;
    
    piles = {5,4,9};
    // 12
    cout << solution.minStoneSum(piles, 2) << endl;
    
    piles = {4,3,6,7};
    // 12
    cout << solution.minStoneSum(piles, 3) << endl;
    
    return 0;
}
