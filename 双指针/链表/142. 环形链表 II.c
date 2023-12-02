// https://leetcode.cn/problems/linked-list-cycle-ii/
// 找到链表环的入口
// 首先使用快慢指针找到相遇点，然后同速指针分别从起点和相遇点出发，相遇点为环扣
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *quick = head, *slow = head;
        while (quick != NULL)
        { // 快慢指针找到相遇点
            slow = slow->next;
            if (quick != NULL)
                quick = quick->next;
            if (quick != NULL)
                quick = quick->next;
            if (slow == quick)
                break;
        }
        if (quick == NULL)
            return NULL;
        ListNode *t = head;
        while (t != slow)
        {
            slow = slow->next;
            t = t->next;
        }
        return t;
    }
};