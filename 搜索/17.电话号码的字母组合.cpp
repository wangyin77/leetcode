/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (53.52%)
 * Likes:    720
 * Dislikes: 0
 * Total Accepted:    114.2K
 * Total Submissions: 213.3K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    char opt[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 

    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return ans;
        string path;
        dfs(digits, 0, path);
        return ans;
    }
    
    void dfs(string digits, int deep, string path){
        if(deep == digits.size()) {
            ans.push_back(path);
            return;
        }
        int u = digits[deep] - '0';
        for(int i = 0; opt[u][i]; i++){
            dfs(digits, deep + 1, path + opt[u][i]);
        }
    }
};
// @lc code=end

