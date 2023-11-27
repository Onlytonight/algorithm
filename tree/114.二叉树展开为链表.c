// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
// 通过 右左中 的遍历，方向链接右孩子，不会有孩子丢失。
class Solution
{
public:
    TreeNode *t = nullptr;
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = t;
        root->left = nullptr;
        t = root;
    }
};