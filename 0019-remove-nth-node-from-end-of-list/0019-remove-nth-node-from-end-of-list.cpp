/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        // Move fast pointer n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        // If fast is null, it means we need to remove the head
        if (fast == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        
        // Move both fast and slow until fast reaches the end
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Delete the nth node from the end
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        
        return head;
    }
};
