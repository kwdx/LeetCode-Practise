//
//  5864.cpp
//  Cpp
//
//  Created by warden on 2021/9/5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int res = 0;
        
        sort(properties.begin(), properties.end(), [](vector<int>& property1, vector<int>& property2) {
            if (property1[0] == property2[0]) {
                return property1[1] < property2[1];
            } else {
                return property1[0] > property2[0];
            }
        });
        
        int maxDefense = properties[0][1];
        for (int i = 1; i < properties.size(); ++i) {
            if (properties[i][1] >= maxDefense) {
                maxDefense = properties[i][1];
            } else {
                ++res;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> properties;
    int res;
    
//    /**
//     输入：properties = [[5,5],[6,3],[3,6]]
//     输出：0
//     解释：不存在攻击和防御都严格高于其他角色的角色。
//     */
//    properties = {
//        {5,5},
//        {6,3},
//        {3,6},
//    };
//    res = 0;
//    assert(res == Solution().numberOfWeakCharacters(properties));
//
//    /**
//     输入：properties = [[2,2],[3,3]]
//     输出：1
//     解释：第一个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
//     */
//    properties = {
//        {2,2},
//        {3,3},
//    };
//    res = 1;
//    assert(res == Solution().numberOfWeakCharacters(properties));
//
//    /**
//     输入：properties = [[1,5],[10,4],[4,3]]
//     输出：1
//     解释：第三个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
//     */
//    properties = {
//        {1,5},
//        {10,4},
//        {4,3},
//    };
//    res = 1;
//    assert(res == Solution().numberOfWeakCharacters(properties));
    
    properties = {
        {7,7},
        {1,2},
        {9,7},
        {7,3},
        {3,10},
        {9,8},
        {8,10},
        {4,3},
        {1,5},
        {1,5}
    };
    res = 6;
    assert(res == Solution().numberOfWeakCharacters(properties));
    
    cout << "OK~" << endl;
    
    return 0;
}
