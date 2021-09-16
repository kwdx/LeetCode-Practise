/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

// @lc code=start
struct TrieNode {
    string word;
    unordered_map<char, TrieNode *> children;
    TrieNode() {
        this->word = "";
    }
};

void insert(TrieNode *root, string &word) {
    TrieNode *node = root;
    for (auto &c : word) {
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word;
}

class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode * root, set<string> & res) {
        char c = board[x][y];
        if (!root->children.count(c)) return false;
        
        root = root->children[c];
        if (root->word.size() > 0) {
            res.insert(root->word);
        }
        
        board[x][y] = '#';
        for (vector<int> & dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if (board[nx][ny] != '#') {
                    dfs(board, nx, ny, root, res);
                }
            }
        }
        board[x][y] = c;
        
        return true;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        set<string> res;
        vector<string> ans;

        for (string &word : words) {
            insert(root, word);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, res);
            }
        }
        
        for (auto & word : res) {
            ans.emplace_back(word);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<vector<char>> board;
    vector<string> words;
    vector<string> res;
    
    /**
     输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
     输出：["eat","oath"]
     */
    board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    words = {"oath","pea","eat","rain"};
    res = {"eat","oath"};
    assert(res == Solution().findWords(board, words));
    
    /**
     输入：board = [["a","b"],["c","d"]], words = ["abcb"]
     输出：[]
     */
    board = {
        {'a','b'},
        {'c','d'}
    };
    words = {"abcd"};
    res = {};
    assert(res == Solution().findWords(board, words));
    
    /**
     输入：board = [["a","b"]], words = ["ab"]
     输出：[]
     */
    board = {
        {'a','b'}
    };
    words = {"ab"};
    res = {"ab"};
    assert(res == Solution().findWords(board, words));
    
    cout << "OK~" << endl;
    
    return 0;
}
