/*
 * @Description: 判断链表中是否有环，双指针
 * @Author: YuanJiang
 * @Date: 2024-07-21 15:03:04
 */

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr){}
};

class Solution{
public:
    bool hasCycle(ListNode* head){
        // 快慢指针
        ListNode* fast = head;
        ListNode* low = head;
        while(fast != nullptr && fast->next != nullptr){
            low = low->next;
            fast = fast->next->next;
            if(low == fast){
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]){
    //定义链表头节点
    ListNode* head = new ListNode(-1);
    ListNode* pre = head;
    ListNode* cur = nullptr;
    // 创建链表
    int num;
    while(cin >> num){
        if(num == -1) break;
        cur = new ListNode(num);
        pre->next = cur;
        pre = pre->next;
    }
    head = head->next;
    cout << "inuput the start of the cycle list, -1 represent no cycle." << endl;
    int start;
    cin >> start;
    if(start != -1){
        ListNode* cur = head;
        for(int i = 0; i < start; i++){
            cur = cur->next;
        }
        pre->next = cur;
    }
    Solution s;
    bool hasCycle = s.hasCycle(head);
    if(hasCycle) cout << "True" << endl;
    else cout << "False" << endl;
    system("pause");
    return 0;
}