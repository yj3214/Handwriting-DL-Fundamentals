/*
 * @Description: 反转链表, 双指针
 * @Author: YuanJiang
 * @Date: 2024-07-20 13:59:41
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
    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
            auto temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main(int argc, char* argv[]){
    // 初始化链表头节点
    ListNode* head = new ListNode(-1);
    ListNode* pre = head;
    ListNode* cur = nullptr;
    // 读取输入并构成单链表, 为了方便，-1为结束的标志
    int num;
    while(cin >> num){
        if(num == -1) break;
        cur = new ListNode(num);
        pre->next = cur;
        pre = cur;
    }
    head = head->next;
    
    Solution s;
    auto reverse_head = s.reverseList(head);
    //打印反转后的链表
    ListNode* reverse_cur = reverse_head;
    while(reverse_cur){
        cout << reverse_cur->val << " ";
        reverse_cur = reverse_cur->next;
    }
    cout << endl;
    system("pause");
    return 0;
}