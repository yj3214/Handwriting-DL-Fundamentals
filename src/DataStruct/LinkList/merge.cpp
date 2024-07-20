/*
 * @Description: 合并两个排序的链表，输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。
 * @Author: YuanJiang
 * @Date: 2024-07-20 15:07:27
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
    ListNode* merge(ListNode* pHead1, ListNode* pHead2){
        ListNode* dummpy = new ListNode(-1);
        ListNode* cur = dummpy;
        while(pHead1 && pHead2){
            if(pHead1->val < pHead2->val){
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }else{
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        if(pHead1) cur->next = pHead1;
        if(pHead2) cur->next = pHead2;
        return dummpy->next;
    }
};

int main(int argc, char* argv[]){
    //初始化链表1
    ListNode* pHead1 = new ListNode(-1);
    ListNode* pre = pHead1;
    ListNode* cur = nullptr;
    //创建链表, -1结束
    int num;
    while(cin >> num){
        if(num == -1) break;
        cur = new ListNode(num);
        pre->next = cur;
        pre = cur;
    }
    pHead1 = pHead1->next;
    // 创建链表2
    ListNode* pHead2 = new ListNode(-1);
    pre = pHead2;
    cur = nullptr;
    while(cin >> num){
        if(num == -1) break;
        cur = new ListNode(num);
        pre->next = cur;
        pre = cur;
    }
    pHead2 = pHead2->next;

    Solution s;
    ListNode* head = s.merge(pHead1, pHead2);

    //打印合并后的链表
    cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    system("pause");
    return 0;
}