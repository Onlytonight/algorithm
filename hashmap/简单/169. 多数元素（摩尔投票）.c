// https://leetcode.cn/problems/majority-element/
// 找出在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
// 摩尔投票法，众数票+1，非众数票-1，若某论票为0，则取该数作为众数，自该轮起众数不变。
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int vote = 0, num = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (vote == 0)
                num = nums[i];
            if (nums[i] == num)
                vote++;
            else
                vote--;
        }
        return num;
    }
};
// 哈希法
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size(), max = 0, res = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]] += 1;
            int t = m[nums[i]];
            if (t > max)
            {
                max = t;
                res = nums[i];
            }
        }
        return res;
    }
};
// 先排序后取中值
// 时间24 ms     击败 20.28%
// 内存19.5 MB  击败56.67%
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n / 2];
    }
};