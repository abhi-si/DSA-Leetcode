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
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; 
        }

        ListNode* newHead = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true; 
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the midpoint of the list
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* secondHalfStart = reverseLinkedList(slow->next);

        // Compare the first and second halves
        ListNode* firstHalfStart = head;
        ListNode* secondHalfIter = secondHalfStart;
        bool result = true;
        while (secondHalfIter != nullptr) {
            if (firstHalfStart->val != secondHalfIter->val) {
                result = false;
                break;
            }
            firstHalfStart = firstHalfStart->next;
            secondHalfIter = secondHalfIter->next;
        }

        // Restore the original list structure by reversing the second half back
        slow->next = reverseLinkedList(secondHalfStart);

        return result;
    }
};
