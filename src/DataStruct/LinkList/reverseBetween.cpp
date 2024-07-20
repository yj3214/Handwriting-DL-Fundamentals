/*
 * @Description: 链表指定区间反转，将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转
 * @Author: YuanJiang
 * @Date: 2024-07-20 14:41:11
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
    ListNode* reverseBetween(ListNode* head, int m, int n){
        if(head == nullptr) return nullptr;
        ListNode* dummpy = new ListNode(-1);
        dummpy->next = head;
        ListNode* pre = dummpy;

        //找到反转区间的前一个节点
        for(int i = 0; i < m - 1; i++){
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        for(int i = 0; i < n - m; i++){
            auto temp = cur->next; //临时存放待反转的节点
            cur->next = cur->next->next; // 当前节点与下下个节点链接
            temp->next = pre->next; // 待反转的节点连到pre的下个节点
            pre->next = temp; 
        }
        return dummpy->next;
    }
};

int main(int argc, char* argv[]){
    // 链表头节点的初始化
    ListNode* head = new ListNode(-1);
    ListNode* pre = head;
    ListNode* cur = nullptr;
    // 创建链表, 为了方便，以-1为结束
    int num;
    while(cin >> num){
        if(num == -1) break;
        cur = new ListNode(num);
        pre->next = cur;
        pre = cur;
    }
    head = head->next;

    Solution s;
    int m, n;
    cin >> m, cin >> n;
    head = s.reverseBetween(head, m, n);
    //打印反转后的节点
    cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    system("pause");
    return 0;
}