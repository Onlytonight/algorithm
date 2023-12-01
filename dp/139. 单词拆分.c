// https://leetcode.cn/problems/word-break/
// dp，dp[i]-集合：表示0-i字符串可以被表示，属性：为真
class Solution
{
public:
    int dp[310];
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int len = s.length();
        dp[0] = 1; // 记得初始化
        for (int i = 1; i <= len; i++)
        {
            for (auto word : wordDict)
            { // 遍历每个单词是否可以从该位置放进去
                int wordLen = word.length();
                if (!dp[i])
                    if (i - wordLen >= 0 && s.substr(i - wordLen, wordLen) == word)
                        dp[i] = dp[i - wordLen];
            }
        }
        return dp[len];
    }
};
// 记忆化搜索，根据当前问题指向的字母，选出单词放入，若该单词放入成功，但后续不成功，则标记跳过该位置，以此优化冗余子问题
class Solution
{
public:
    unordered_map<char, vector<int>> m;
    int len, memo[310];
    bool judge(string s, vector<string> &wordDict, int i)
    {
        if (i == len)
            return true;
        int size = m[s[i]].size();
        for (int j = 0; j < size; j++)
        { // 判断每个单词是否能放入
            if (!memo[i])
            {
                int wind = m[s[i]][j], wordSize = wordDict[wind].size(), ti = i, tag = 1;
                for (int k = 0; k < wordSize; k++, ti++)
                { // 逐个字母判断第j个单词是否匹配
                    if (ti >= len || s[ti] != wordDict[wind][k])
                    {
                        tag = 0;
                        break; // 不匹配则判断下一个单词
                    }
                }
                if (tag)
                {
                    if (judge(s, wordDict, ti))
                        return true;
                    else
                        memo[ti] = 1;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int size = wordDict.size();
        len = s.length();
        for (int i = 0; i < size; i++)
            m[wordDict[i][0]].push_back(i);
        return judge(s, wordDict, 0);
    }
};