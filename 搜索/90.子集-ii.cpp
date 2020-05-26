/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (59.99%)
 * Likes:    225
 * Dislikes: 0
 * Total Accepted:    33.6K
 * Total Submissions: 56K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vis = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int deep){
        if(deep == nums.size()){
            ans.push_back(path);
            return;
        }
        dfs(nums, deep + 1);
        // 剪枝
        if(deep && nums[deep] == nums[deep -1] && !vis[deep - 1])
            return;        
        //
        vis[deep] = true, path.push_back(nums[deep]);
        dfs(nums, deep + 1);
        vis[deep] = false, path.pop_back();
    }

    /* 非递归写法 由于没有剪枝所以速度会慢
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < 1 << n; i++){
            bool flag = false;
            vector<int> path;
            for(int j = 0; j < n; j++){
                if(i & 1 << j){
                    if(j && nums[j] == nums[j - 1] && !(i & 1 << j - 1)){
                        flag = true;
                    }
                    path.push_back(nums[j]);
                }
            }
            if(!flag) ans.push_back(path);
        }
        return ans;
    } */

};
// @lc code=end

