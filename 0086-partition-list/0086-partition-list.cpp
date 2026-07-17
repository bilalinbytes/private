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
    ListNode* partition(ListNode* head, int x) {

        // Create two dummy nodes
        ListNode* smallDummy = new ListNode(0);
        ListNode* bigDummy = new ListNode(0);

        // Tail pointers
        ListNode* smallTail = smallDummy;
        ListNode* bigTail = bigDummy;

        ListNode* curr = head;

        while (curr != nullptr) {

            ListNode* nextNode = curr->next; // Save next node

            if (curr->val < x) {
                smallTail->next = curr;
                smallTail = curr;
            }
            else {
                bigTail->next = curr;
                bigTail = curr;
            }

            curr = nextNode;
        }

        // End the big list
        bigTail->next = nullptr;

        // Join small list with big list
        smallTail->next = bigDummy->next;

        // Return head of new list
        return smallDummy->next;
    }
};