# Chapter 2 Two Pointers
## 基础
* 指针定义
```c++
int x;
int * p1 = &x; // 指针可以被修改，值也可以被修改
const int * p2 = &x; // 指针可以被修改，值不可以被修改（const int）
int * const p3 = &x; // 指针不可以被修改（* const），值可以被修改
const int * const p4 = &x; // 指针不可以被修改，值也不可以被修改
```
* 指针函数
```c++
// addition是指针函数，一个返回类型是指针的函数
int* addition(int a, int b) {
    int* sum = new int(a + b);
    return sum;
}
int subtraction(int a, int b) 
    return a - b; 
int operation(int x, int y, int (*func)(int, int)) 
    return (*func)(x,y);

// minus是函数指针，指向函数的指针
int (*minus)(int, int) = subtraction;
int* m = addition(1, 2);
int n = operation(3, *m, minus);
```

## 167. Two Sum II - Input array is sorted
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1, sum;
        while(1){
            sum = numbers[l] + numbers[r];
            if(sum == target) return vector<int>{l + 1, r + 1};
            else if(sum > target) --r;
            else ++l;
        }
    }
};
```
> 题意：在一个升序数组中找到两个数和与target相同  
> 基本思路：两个指针分别从两头向中间移动，大于target,右指针左移, 小于target,左指针右移   

❗ 时间复杂度为O(n),优于二分查找O(nlogn)

## 633. Sum of Square Numbers
```c++
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = sqrt(c);
        while(r >= l){
            long long t = l * l + r * r;
            if(t == c)
                return true;
            if(t < c) ++l;
            else --r;
        }
        return false;
    }
};
```
> 题意：判断给定数是否是两个数的平方和  
> 基本思路：两个指针分别从1和sqrt(target)向中间移动，大于target,右指针左移, 小于target,左指针右移

## 680. Valid Palindrome II
```c++
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1, cnt1 = 0, cnt2 = 0;
        while(l <= r){
            if(s[l] == s[r])
                ++l, --r;
            else if(s[l + 1] == s[r])
                ++cnt1, ++l;
            else {
                cnt1 = 2;
                break;
            }
        }
        l = 0, r = s.size() - 1;
        while(l <= r){
            if(s[l] == s[r])
                ++l, --r;
            else if(s[r - 1] == s[l])
                ++cnt2, --r;
            else {
                cnt2 = 2;
                break;
            }
        }
        if(cnt1 > 1 && cnt2 > 1) return false;
        else return true;
    }
};
```
> 题意：给定字符串，判断最多删除一个字符能否回文  
> 基本思路：两个指针分别从头尾向中间移动找不同，走两遍循环，一次删除左指针元素，一次右指针，判断能否遍历完

## 88. Merge Sorted Array
```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = m + n - 1;
        --m, --n;
        while(m >= 0 && n >= 0)
            nums1[m] > nums2[n] ? nums1[end--] = nums1[m--] :nums1[end--] = nums2[n--];
        while(n >= 0)
            nums1[n--] = nums2[n];
    }
};
```
> 题意：合并两个有序数组，不占用额外空间，将2合并入1  
> 基本思路：三个指针一个指向1空间结尾(end)，两外两个指向1和2的结尾(m和n)，判断mn大小赋给end

## 524. Longest Word in Dictionary through Deleting
```c++
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int n = s.size();
        sort(d.begin(), d.end(), [](string& a, string& b){
            return a.size() == b.size() ? a < b : a.size() > b.size();
        });
        for(int i = 0; i < d.size(); ++i){
            int is = 0, id = 0;
            while(is != n){
                if(s[is] == d[i][id]) 
                    ++is, ++id;
                else ++is;
                if(id == d[i].size()) 
                    return d[i];
            }
        }
        return "";
    }
};
```
> 题意：给定一个字符串s和一个字符串字典，找到字典里面最长的字符串,要求可以通过s删除部分字符得到，并且按字典序  
> 基本思路：先给字典排序，之后用两个指针对比字符串是否相同  
* 排序方法：
```c++
sort(d.begin(), d.end(), [](string& a, string& b){
    return a.size() == b.size() ? a < b : a.size() > b.size();
});
```
❗ 注意：这种先排序的方法写起来简单，思路清晰，但时间复杂度为O(nxlogn + nx),(n为个数，x为长度),不如比较时判断

## 142. Linked List Cycle II
```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *slow = head->next, *fast = head->next->next;
        while(fast != slow){
            if(!fast || !fast->next) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = head;
        while(fast != slow)
            fast = fast->next, slow = slow->next;
        return fast;
    }
};
```
> 题意：判环，有则返回环入口  
> 基本思路：快慢指针，相遇则有环，相遇后快指针返回起点每次走一格，再次相遇为环入口  
> 唯一解法-Flod判环

## 76. Minimum Window Substring
```c++
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> times(128, 0);//词频
        vector<bool> flag(128, false);
        int n = t.size(), m = s.size();
        for(int i = 0; i < n; ++i)
            ++times[t[i]], flag[t[i]] = true;
        int l = 0, r = 0, min_l = 0, min_size = m + 1, cnt = 0;
        for(; r < m; r++)
            if(flag[s[r]]){
                if(--times[s[r]] >= 0)
                    ++cnt;                
                while(cnt == n){
                    if(r - l + 1 < min_size)
                        min_l = l, min_size = r - l + 1;
                    if(flag[s[l]] && ++times[s[l]] > 0)
                        --cnt;
                    ++l;
                }
            }
        return min_size > m ? "" : s.substr(min_l, min_size);
    }
};
```
> 题意：在字符串S中找出包含字符串T所有字符的最小子串，同一字母的个数也要满足要求  
> 基本思路：两个指针同向移动，判断滑动窗口内是否满足要求

**滑动窗口模板**
```c++
for(; r < m; r++) //移动右指针
    if(flag[s[r]]){//遇到满足条件的点更新结果
        if(--times[s[r]] >= 0)  ++cnt;
        while(cnt == n){ //满足条件时，移动左指针，判断是否仍然满足条件
            if(r - l + 1 < min_size) //与min_size对比，更新最优解
                min_l = l, min_size = r - l + 1;
            if(flag[s[l]] && ++times[s[l]] > 0) --cnt, ++l;
        }
    }
```
