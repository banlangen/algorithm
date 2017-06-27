#include <iostream>
#include "LinkedList.h"
#include <queue>
#include <stack>
#include <functional>

class comparator {
    public:
        bool operator() (ListNode<int> *lhs, ListNode<int> *rhs) {
            return  lhs->data > rhs->data;
        }
};

ListNode<int> *merge_k_sorted_lists(std::vector<ListNode<int> *> &vec) {
    std::priority_queue<ListNode<int> *, std::vector<ListNode<int> *>, comparator> heap;
    for (std::vector<ListNode<int> *>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
        if (*itr != NULL) {
            heap.push(*itr); 
        }
    }

    ListNode<int> *result = new ListNode<int>(0);
    ListNode<int> *tail = result;

    while (!heap.empty()) {
       tail->next = heap.top();
       tail = tail->next;
       heap.pop();
       if (tail->next != NULL) {
            heap.push(tail->next);
       }
    }

    return result;

}


int main(void) {
    std::vector<ListNode<int> *> vec;
    std::cout << "numbers of lists: ";
    int count = 0;
    std::cin >> count;
    LinkedList<int> l, j;
    vec.push_back(l.getListHead());
    vec.push_back(j.getListHead());
    
    ListNode<int> *tmp = merge_k_sorted_lists(vec); 
    LinkedList<int> result(tmp);
    result.printList();

}
