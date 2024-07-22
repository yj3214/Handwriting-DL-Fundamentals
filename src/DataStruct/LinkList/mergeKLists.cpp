/*
 * @Description: 合并k个已排序的链表, 优先级队列
 * @Author: YuanJiang
 * @Date: 2024-07-21 14:26:27
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//链表节点定义
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val):val(val), next(nullptr){}
};

class Solution{
public:
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*> lists){
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap; //新建一个小顶堆，并重载比较运算符
        ListNode* dummpy = new ListNode(-1);
        for(auto node: lists){
            if(node != nullptr){
                heap.push(node);
            }
        }
        ListNode* cur = dummpy;
        while(!heap.empty()){
            ListNode* temp = heap.top();
            heap.pop();
            cur->next = temp;
            cur = cur->next;
            if(temp->next != nullptr){
                heap.push(temp->next);
            }
        }
        return dummpy->next;
    }
};

int main(int argc, char* argv[]){
    vector<ListNode*> lists;
    // 创建单链表
    int num_list;
    cout << "please input the num of link lists: "<<endl;
    cin >> num_list;
    int num;
    for(int i = 0; i < num_list; i++){
        //初始化头节点
        ListNode* head = new ListNode(-1);
        ListNode* pre = head;
        ListNode* cur = nullptr;
        while(cin >> num){
            if(num == -1) break;
            cur = new ListNode(num);
            pre->next = cur;
            pre = pre->next;
        }
        head = head->next;
        lists.push_back(head);
    }

    Solution s;
    ListNode* res = s.mergeKLists(lists);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    system("pause");
    return 0;
}