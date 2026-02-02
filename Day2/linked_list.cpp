#include <iostream>
#include <vector>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
// ListNode(int x) : val(x), next(NULL) {}
// 这句代码是什么意思?
// 这是构造函数的声明:表明初始化列表的开始
// val(x) 表示初始化val为x
// next(NULL)表示初始化next为NULL
// {}是初始化成员变量

// 将数组转为链表
ListNode* createLinkedList(vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < arr.size(); i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}
