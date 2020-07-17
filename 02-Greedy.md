# Chapter 1 Greedy
## 455. Assign Cookies
```c++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = 0, si = 0;
        while(gi < g.size() && si < s.size()){
            if(g[gi] <= s[si]) ++gi;
            ++si;
        }
        return gi;
    }
};
```
>题意：分饼干  
>基本思路：孩子和饼干排个序，优先满足胃口小的孩子就行。

## 135. Candy
```c++
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n < 2) return n;
        vector<int> nums(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1])  
                nums[i] = nums[i - 1] + 1;
        }
        for(int i = n - 1; i > 0; i--){
            if(ratings[i] < ratings[i - 1] && nums[i] >= nums[i - 1])
                nums[i - 1] = nums[i] + 1;
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
```
>题意：分饼干，比旁边人分数高就要给的多  
>基本思路：从左到右、从右到左遍历两次，遇到大的就置为前一个加1。  

🔺技巧：  
>* `accumulate(nums.begin(), nums.end(), 0);`  
>定义在`#include<numeric>`中。  
>三个形参：头两个形参指定要累加的**元素范围**，第三个形参则是累加的**初值**。  
>特殊用法：拼接字符串  
`string sum = accumulate(v.begin() , v.end() , string(" "));  `

## 435. Non-overlapping Intervals
```c++
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n < 2) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int ans = 0, prev = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] < prev)
                ++ans;
            else
                prev = intervals[i][1];
        }
        return ans;
    }
};
```
>题意：计算区间互不重叠所需要移除的最少区间个数。  
>基本思路: 以区间结尾排序，从前往后遍历，比较前一个区间结尾与西区一个区间开头是否重叠。

🔺技巧：
```c++
sort(intervals.begin(), intervals.end(),
    [](vector<int>& a, vector<int>& b){
    return a[1] < b[1];
});
```
>sort()函数Lambda表达式，一定要引用，加`&`！！

## 605. Can Place Flowers
```c++
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int m) {
        int ans = 0, n = flowerbed.size();
        if(n == 1){
            if(flowerbed[0] && m == 0) return true;
            if(!flowerbed[0]) return true;
            return false;
        } 
        if(!flowerbed[1] && !flowerbed[0]){
            ++ans;
            flowerbed[0] = 1;
        }
        if(!flowerbed[n - 1] && !flowerbed[n - 2]){
            ++ans;
            flowerbed[n - 1] = 1;
        }
        for(int i = 1; i < n- 1; i++){
            if(!flowerbed[i - 1] && !flowerbed[i + 1] && !flowerbed[i]){
                ++ans;
                flowerbed[i] = 1;
                ++i;
            }
        }
        return ans >= m;
    }
};
```
>题意：种花(1)，两边需要是0;  
>基本思路：直接遍历即可。
## 452. Minimum Number of Arrows to Burst Balloons
```c++
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 2) return n;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        }) ;
        int tot = 0, prev = points[0][1];
        for(int i = 1; i < n; i++){
            if(points[i][0] <= prev)
                ++tot;
            else
                prev = points[i][1];
        }
        return n - tot;
    }
};
```
>题意：用最少的箭(区间内的点)射所有的气球(区间)；  
>基本思路：435计算出重叠区间个数，用总区间数减。

## 763. Partition Labels
```c++
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        int flag = 1, now = 0, end = 0;
        char nowc = S[0];
        vector<int> ans;
        while(now != n){
            int start = now;
            end = now;
            do{
                nowc = S[now];
                for(int i = now; i < n; i++){
                    if(S[i] == nowc && end < i)
                        end = i;
                }
                ++now;
            }while(now != end + 1);
            ans.push_back(end - start + 1);
        }
        return ans;
    }
};
```
>题意：划分字符串，使每个部分中的字母不会出现在其他部分中，求最多分几个部分。  
>基本思路：从前往后遍历记录当前字母最后出现的位置，直至片段结束。

🔺优化思路：
建立哈希表，记录每个字母的最后位置。
## 122. Best Time to Buy and Sell Stock II
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)  return 0;
        int ans = 0, start = 0;
        if(prices[1] < prices[0]) start = 1;
        for(int i = start; i < n; i++){
            if(i == n - 1 || prices[i + 1] < prices[i]){
                ans += prices[i] - prices[start];
                start = i + 1;
            }
        }
        return ans;
    }
};
```
>题意：股票交易，已知一段时间内股价，求最大收益。  
>基本思路：统计每个上升区间始末价差。

## 406. Queue Reconstruction by Height ⭐
```c++
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        list<vector<int>> ans;
        sort(people.begin(), people.end(),[](vector<int>& a, vector<int> &b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        for(int i = 0; i < n; i++){
            auto pos = ans.begin();
            advance(pos, people[i][1]);
            ans.insert(pos, people[i]);
        }
        vector<vector<int>> ansv(ans.begin(), ans.end());
        return ansv;
    }
};
```
>题意：恢复队形，已知每个人(身高h，在他前面的比他高的人数k)。  
>基本思路：按先h后k排序，从身高高的开始排，在k的位置插入队伍即可。

🔺技巧：
1 .**分优先级排序**
```c++
sort(people.begin(), people.end(),[](vector<int>& a, vector<int> &b){
    return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
});
```
2 .list容器-链表 ⭐
```c++
list<vector<int>> ans;//定义
auto pos = ans.begin();//指针指向头节点
advance(pos, people[i][1]);//向后找k个元素
ans.insert(pos, people[i]);//插入元素
vector<vector<int>> ansv(ans.begin(), ans.end());//list转vector(vector初始化)
```

## 665. Non-decreasing Array
```c++
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return true;
        int  m = 0;
        if(nums[0] > nums[1]){
            ++m;
            nums[0] = nums[1];
        }
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i - 1]){
                ++m;
                if(i != n - 1 && nums[i + 1] <= nums[i - 2]) return false;
                if(nums[i] < nums[i - 2])
                    nums[i] = nums[i - 1];
            }
        }
        if(m > 1) return false;
        else return true;
    }
};
```
>题意：判断在最多改变1个元素的情况下，能否变成非递减数列  
>基本思路：从前往后遍历，遇到递减情况，分析删除前后哪个元素