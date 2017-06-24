#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>

template<class T>
class ListNode {
    public :
        T data;
        ListNode *next;
        ListNode(T val) : data(val), next(NULL) {};
};

template<class T>
class LinkedList {
    private :
        ListNode<T> *head;
        void reverse(ListNode<T> *, ListNode<T> *);
    public :    
        LinkedList();
        //LinkedList(std::istream &);
        ~LinkedList();

        LinkedList(const LinkedList &);
        void push(T);
        void append(T);
        void printList();
        void reverse();
        void reverse(ListNode<T> *);
        void reverse(int m, int n);
        void setListHead(const ListNode<T> *p) { head = const_cast<ListNode<T> *> (p) ;}
        ListNode<T> * getListHead() { return head; }
};

template<class T> LinkedList<T>::LinkedList() : head(NULL) {
    std::cout << "creating linkedlist ... " << std::endl;
    T i;
    while (std::cin >> i) {
        append(i);
    }
    std::cin.clear(); 
}

template<class T> void LinkedList<T>::reverse() {
    ListNode<T> *prev = NULL;
    ListNode<T> *cur = head;
    while (cur != NULL) {
        ListNode<T> *tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    head = prev;
}

template<class T> void LinkedList<T>::reverse(ListNode<T> *p) {
   if (p->next == NULL) {
       head = p;
       return ;
   } 
   reverse(p->next);
   p->next->next = p;
   p->next = NULL;
}

template<class T> void LinkedList<T>::reverse(ListNode<T> *left, ListNode<T> *right) {
    if (left == right) {
        return;
    }
    reverse(left->next, right);
    left->next->next = left;
    left->next = NULL; 
}

template<class T> void LinkedList<T>::reverse(int m, int n) {
    ListNode<T> *m_prev = NULL;
    ListNode<T> *m_cur = NULL;
    ListNode<T> *n_cur = NULL;
    ListNode<T> *n_next = NULL;
    push(0);
    int count = 1;
    m_prev = head;
    m_cur = head->next;
    while (count != m) {
        m_prev = m_prev->next;
        m_cur = m_cur->next;
        count++; 
    }
    count = 1;
    n_cur = head->next;
    n_next = n_cur->next;
    while (count != n) {
        n_cur = n_cur->next;
        n_next = n_next->next;
        count++;
    }

    reverse(m_cur, n_cur);
    m_prev->next = n_cur;
    m_cur->next = n_next;

    ListNode<T> *tmp = head;
    head = head->next;
    delete tmp;
}


template<class T> LinkedList<T>::LinkedList(const LinkedList<T> &l) {
    if (l.head == NULL) {
        head == NULL;
        return;
    }
    ListNode<T> *lnode = l.head;
    head = new ListNode<T>(lnode->data);
    ListNode<T> *node = head;
    lnode = lnode->next;
    while (lnode != NULL) {
        node->next = new ListNode<T>(lnode->data);
        node = node->next;
        lnode = lnode->next;
    }
}       
            
template<class T> LinkedList<T>::~LinkedList() {
    std::cout << "destroying LinkedList ..." << std::endl;
    while (head != NULL) {
        ListNode<T> *node = head;
        head = head->next;
        delete node;
    }    
    std::cout << "LinkedList destroied !" << std::endl;
}


template<class T> void LinkedList<T>::push(T ival) {
    ListNode<T> *new_node = new ListNode<T>(ival);
    if (head != NULL) {
        new_node->next = head;
        head = new_node;
    } else {
        new_node->next = NULL;
        head = new_node;
    }
}

template<class T> void LinkedList<T>::append(T ival) {
    ListNode<T> *last = head;
    ListNode<T> *new_node = new ListNode<T>(ival);
    if (head == NULL) {
       head = new_node;
       return;
    } 
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

template<class T> void LinkedList<T>::printList() {
    ListNode<T> *node = head;
    std::cout << "printing LinkedList ..." << std::endl;
    while (node != NULL) {
        std::cout << node->data << ", " ;
        node = node->next;
    }
    std::cout << std::endl;
} 


#endif
