/*
 * @Description: 删除链表中的重复元素
 * @Author: YuanJiang
 * @Date: 2024-07-22 14:57:50
 */
#include <iostream>
using namespace std;

//定义链表节点
struct ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr){}
};

class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        auto dummpy = new ListNode(-1);
        dummpy->next = head;
        auto pre = dummpy;
        while(pre->next){
            auto cur = pre->next;
            while(cur && pre->next->val == cur->val) cur = cur->next;
            if(pre->next->next == cur) pre = pre->next;
            else pre->next = cur;
        }
        return dummpy->next;
    }
};

int main(int argc, char* argv[]){
    //初始化链表头节点
    auto head = new ListNode(-1);
    auto pre = head;
    ListNode* cur = nullptr;
    // 创建链表, -1表示结束
    int num;
    while(cin >> num){
        if(num == -1) break;
        cur = new ListNode(num);
        pre->next = cur;
        pre = pre->next;
    }
    head = head->next;
    //去重
    Solution s;
    head = s.deleteDuplicates(head);
    //终端打印输出
    cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    system("pause");
    return 0;
}