//
//  冒泡排序.cpp
//  Cpp
//
//  Created by warden on 2021/8/22.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 冒泡排序
 */
void bubbleSort(vector<int>& nums) {
    int len = (int)nums.size();
    
    for (int i = 0; i < len; i++) {
        bool flag = false;
        for (int j = 0; j < len - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<int> nums, res;
    
    nums = {1,5,9,8,7,2,4,3,0,6};
    res = {0,1,2,3,4,5,6,7,8,9};
    bubbleSort(nums);

    assert(res == nums);
    
    cout << "OK!" << endl;
    
    return 0;
}
