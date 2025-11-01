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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        while(head !=NULL && mp.find(head->val)!=mp.end())
        {
            head=head->next;
        }

        ListNode* cur=head;
        while(cur !=NULL && cur->next!=NULL)
        {
            
            if(mp.find(cur->next->val)!=mp.end())
            {
                cur->next=cur->next->next;
            }
            else{
                cur=cur->next;
            }
        }
        return head;

    }
};