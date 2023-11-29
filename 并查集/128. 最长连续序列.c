// https://leetcode.cn/problems/longest-consecutive-sequence/
// 找到数组中数组的最长连续序列（在原数组中可以不连续），通过检查数字的前后一个数字，是否和该数字在一个集合。数字可能出现负数，重复数字，使用map记录数字和索引值。
class Solution
{
public:
    int fa[100010], num[100010], res;
    unordered_map<int, int> m;
    int find(int x)
    {
        if (fa[x] == x)
            return x;
        else
            return fa[x] = find(fa[x]);
    }
    void judge(int i, int t)
    {
        if (m.count(t))
        {
            int pa = find(m[t]), pai = find(i); // 通过索引查找祖先
            if (pa != pai)
            {
                fa[pai] = pa;
                num[pa] += num[pai];
                cout << i << " " << fa[pai] << " " << num[pa] << endl; // 第i个数，i的祖先，合并后集合的数量
                if (num[pa] > res)
                    res = num[pa];
            }
        }
    }
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n > 0)
            res = 1;
        for (int i = 0; i < n; i++)
        {
            int t = nums[i];
            if (!m.count(t))
            {
                m[t] = i;
                fa[i] = i; // 记录索引
                num[i] = 1;
                judge(i, t + 1);
                judge(i, t - 1);
            }
        }
        return res;
    }
};