/*
 * @Description: 链表中环的入口结点, 双指针
 * @Author: YuanJiang
 * @Date: 2024-07-21 15:35:29
 */

#include <iostream>
using namespace std;

//定义链表节点
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr){}
};

class Solution{
public:
    ListNode* EntryNodeOfLoop(ListNode* head){
        ListNode* low = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            low = low->next;
            fast = fast->next->next;
            if(low == fast){
                break;
            }
        }
        if(fast == nullptr || fast->next == nullptr) return nullptr;
        low = head;
        while(low != fast){
            low = low->next;
            fast = fast->next;
        }
        return low;
    }
};

int main(int argc, char* argv[]){
    // 初始化头节点
    ListNode* head = new ListNode(-1);
    ListNode* pre = head;
    ListNode* cur = nullptr;
    // 创建链表, -1终止
    int num;
    while(cin >> num){
        if(num == -1) break;
        cur = new ListNode(num);
        pre->next = cur;
        pre = pre->next;
    }
    head = head->next;
    cout << "input the start of cycle list, -1 represents no cycle." << endl;
    int start;
    cin >> start;
    ListNode* res = head;
    if(start != -1){
        for(int i = 0; i < start; i++){
            res = res->next;
        }
        pre->next = res;
    }
    Solution s;
    res = s.EntryNodeOfLoop(head);
    if(res) cout << res->val << endl;
    else cout << "nullptr" << endl;
    system("pause");
    return 0;
}