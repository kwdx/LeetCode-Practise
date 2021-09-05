//
//  5866.数组的最大公因数排序.cpp
//  Cpp
//
//  Created by warden on 2021/9/5.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class UnionFind {
private:
    // 图的容量
    int capacity;
    // 存储若干棵树
    std::vector<int> parents;
    // 记录树的重量
    std::vector<int> size;
public:
    UnionFind(int n) {
        capacity = n;
        
        parents.resize(n);
        size.resize(n);
        
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            size[i] = 1;
        }
    }

    void unionn(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        
        if (rootP == rootQ) return;
        
        if (size[rootP] > size[rootQ]) {
            parents[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parents[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        capacity--;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int find(int x) {
        while (parents[x] != x) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return x;
    }

    int count() {
        return capacity;
    }
};

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        UnionFind uf(100000);
        unordered_map<int, int> indexToVal;
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            for (int k = 2; k * k <= num; ++k) {
                if (num % k == 0) {
                    uf.unionn(k, num);
                    uf.unionn(num / k, num);
                }
            }
            indexToVal[i] = nums[i];
        }
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (!uf.connected(indexToVal[i], nums[i])) {
                return false;
            }
        }
        
        return true;
    }
    
    int hasGCD(int a, int b) {
        int temp;

        if (a < b) {
            temp = a;
            a = b;
            b = temp;
        }

        while (b != 0) {
            temp = a % b;
            a = b;
            b = temp;
        }
        return a > 1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums;
    bool res;
    
    /**
     输入：nums = [7,21,3]
     输出：true
     解释：可以执行下述操作完成对 [7,21,3] 的排序：
     - 交换 7 和 21 因为 gcd(7,21) = 7 。nums = [21,7,3]
     - 交换 21 和 3 因为 gcd(21,3) = 3 。nums = [3,7,21]
     */
    nums = {7,21,3};
    res = true;
    assert(res == Solution().gcdSort(nums));

    /**
     输入：nums = [5,2,6,2]
     输出：false
     解释：无法完成排序，因为 5 不能与其他元素交换。
     */
    nums = {5,2,6,2};
    res = false;
    assert(res == Solution().gcdSort(nums));

    /**
     输入：nums = [10,5,9,3,15]
     输出：true
     解释：
     可以执行下述操作完成对 [10,5,9,3,15] 的排序：
     - 交换 10 和 15 因为 gcd(10,15) = 5 。nums = [15,5,9,3,10]
     - 交换 15 和 3 因为 gcd(15,3) = 3 。nums = [3,5,9,15,10]
     - 交换 10 和 15 因为 gcd(10,15) = 5 。nums = [3,5,9,10,15]
     */
    nums = {10,5,9,3,15};
    res = true;
    assert(res == Solution().gcdSort(nums));

    /**
     输入：nums = [8,9,4,2,3]
     输出：true
     */
    nums = {8,9,4,2,3};
    res = true;
    assert(res == Solution().gcdSort(nums));
    
    /**
     输入：nums = [6,9,2,4,10]
     输出：true
     */
    nums = {6,9,2,4,10};
    res = true;
    assert(res == Solution().gcdSort(nums));
    
    /**
     输入：nums = [6,9,2,4,10]
     输出：true
     */
    nums = {6,9,2,4,10};
    res = true;
    assert(res == Solution().gcdSort(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
