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
        //int length;
    public :    
        LinkedList();
        //LinkedList(std::istream &);
        ~LinkedList();

        LinkedList(const LinkedList &);
        void push(T ival);
        void append(T ival);
        void printList();
        void reverse();
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
