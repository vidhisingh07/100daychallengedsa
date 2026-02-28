/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *prev = NULL, *nextNode = NULL;
    while (slow) {
        nextNode = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nextNode;
    }
    struct ListNode *first = head;
    struct ListNode *second = prev;
    while (second) {
        if (first->val != second->val)
            return false;
        first = first->next;
        second = second->next;
    }
    return true;
}