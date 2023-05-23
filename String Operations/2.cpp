#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while(l1!= NULL || l2 != NULL || carry != 0){
            int x = l1? l1-> val: 0;
            int y = l2? l2-> val: 0;
            int sum = carry + x + y;
            carry = sum/10;
            curr -> next = new ListNode(sum%10);
            curr = curr -> next;
            l1 = l1? l1-> next: nullptr;
            l2 = l2? l2-> next: nullptr; 
        }
        return dummyHead->next;
    }
};
void input(ListNode *n){
    ListNode *cur = n;
    for(int i = 0; i < 2; i++, cur = cur -> next){
        int x; cin >> x;
        cur -> next = new ListNode(x);
        
    }
}
void output(ListNode *n){
    ListNode *cur = n;
    while(cur != nullptr){
        cout << cur ->val << " ";
        cur = cur -> next;
    }
    cout << "\n";
}
int main(){
    ListNode *a = new ListNode(0);
    ListNode *b = new ListNode(0);
    input(a), input(b);
    Solution solutions;
    ListNode *ans = solutions.addTwoNumbers(a, b);
    output(a); output(b);
    output(ans);
    return 0;
}