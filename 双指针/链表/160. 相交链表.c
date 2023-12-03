/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// https://leetcode.cn/problems/intersection-of-two-linked-lists/
// 找到相交链表的交点
// 双指针参考大神版：双指针每次走一步，如果走到尽头则指向另一个链表头，相遇时则为交点
// 若链表a长6，链表b长3，交点在链表a的pos4，链表b的pos1，则pa移至链表b时走了7步（加上null），再走一步到交点，pb移至链表a走了4步，再走四步到交点
// 比较长的链表指针指向较短链表head时，长度差就消除了。
// 这题有点类似于快慢指针找环口，根本思想是两个指针都走了pa到交点+pb到交点的长度
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *pA = headA, *pB = headB;
        while (pA != pB)
        {
            pA = pA == NULL ? headB : pA->next;
            pB = pB == NULL ? headA : pB->next;
        }
        return pA;
    }
};

// 双指针自己实现版
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *ta = headA, *tb = headB;
        bool swa = true, swb = true;
        while (ta != tb && ta != NULL && tb != NULL)
        {
            ta = ta->next;
            if (ta == NULL && swa)
            {
                ta = headB;
                swa = false;
            }
            tb = tb->next;
            if (tb == NULL && swb)
            {
                tb = headA;
                swb = false;
            }
        }
        if (ta == tb && ta != NULL)
            return ta;
        return NULL;
    }
};

// 哈希表记住a走过的节点，看b有没有经过
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, bool> m;
        ListNode *t = headA;
        while (t != NULL)
        {
            m[t] = true;
            ;
            t = t->next;
        }
        t = headB;
        while (t != NULL)
        {
            if (m.count(t))
                return t;
            t = t->next;
        }
        return NULL;
    }
};