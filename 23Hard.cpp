﻿

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int MinimalIndex(const vector<ListNode*>& vec) {
    int ind = -1;
    int min_value = std::numeric_limits<int>::max();

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == nullptr) { continue; }
        if (vec[i]->val < min_value) {
            min_value = vec[i]->val;
            ind = i;
        }
    }
    return ind;
}

ListNode* OrderedList(vector<ListNode*>&& lists) {
    if (lists.empty()) { return nullptr;}
    lists[lists.size() - 1]->next = nullptr;
    if (lists.size() == 1) { return lists[0];}
    for (int i = 0; i + 1 < lists.size(); ++i) {
        lists[i]->next = lists[i + 1];
    }
    return lists[0];
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    
    vector<ListNode*> order_;
    vector<int> positions(lists.size(), 0);    
    while (true) 
    {
        vector<ListNode*> candidates;   
        for (int i = 0; i < lists.size(); ++i) {
            ListNode* tmp = lists[i];
            int mover = 0;
            while (mover != positions[i]) {     
                tmp = tmp->next;
                ++mover;
            }
            candidates.push_back(tmp);
        } 
        int ind = MinimalIndex(candidates);
        if (ind == -1) { break;}
        positions[ind]++;
        order_.push_back(candidates[ind]);
    }
    return OrderedList(move(order_));
}

int main()
{
    ListNode* l2 = new ListNode(5);
    ListNode* l1 = new ListNode(4, l2);
    ListNode* l = new ListNode(1, l1);

    ListNode* q2 = new ListNode(4);
    ListNode* q1 = new ListNode(3, q2);
    ListNode* q = new ListNode(1, q1);

    ListNode* w1 = new ListNode(6);
    ListNode* w = new ListNode(2, w1);
    vector<ListNode*> ln{l, q, w};


  ListNode* ls = mergeKLists(ln);
  ListNode* ptr = ls;

  while (ptr) {
      cout << ptr->val << "->";
      ptr = ptr->next;
  }
      
    delete l2; delete l1; delete l;
    delete q2; delete q1; delete q;
               delete w1; delete w;
    

}

