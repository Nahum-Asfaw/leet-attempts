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
#include <string>
#include <sstream>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // while (l1 isn't null) {
        // enter into string, reverse, convert into integer
        // do the same for l2
        string nums1;
        string nums2;

        // can only do this in O(n) right? cause i need to access every node.
        while(l1 != nullptr){
            nums1.insert(0, to_string(l1->val));
            l1 = l1->next;
        }
        
        while(l2 != nullptr){
            nums2.insert(0, to_string(l2->val));
            l2 = l2->next;
        }
        string soln = to_string(stoi(nums1) + stoi(nums2));
        
        ListNode *l3 = new ListNode(atoi(&soln[0]));

        for(int i = 1; i < soln.length(); i++){
            ListNode* node = new ListNode(atoi(&soln[i]), l3);
            // add to the front of the list
            l3->next = node;
        }

        return l3;
    }
};