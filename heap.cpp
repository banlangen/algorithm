#include <functional>
#include <queue>
#include <iostream>
class cmp;

class Node {
    public : 
        int val;
    public :
        Node(int i) : val(i) {};
        friend class cmp;
        friend bool operator<(const Node &, const Node &);
        friend bool operator>(const Node &, const Node &);
        friend std::ostream &operator<<(std::ostream &os, const Node &rhs);
};

class cmp {
    public :
        bool operator() (Node *lhs, Node *rhs) {
            return lhs->val > rhs->val;
        }
}; 


bool operator<(const Node &lhs, const Node &rhs) {
    return lhs.val < rhs.val;
}

bool operator>(const Node &lhs, const Node &rhs) {
    return lhs.val > rhs.val;
}

std::ostream &operator<<(std::ostream &os, const Node &object) {
   os << object.val ;
   return os; 
}


int main(void) {
    //std::priority_queue<Node, std::vector<Node>, std::greater<Node> > heap;
    std::priority_queue<Node *, std::vector<Node *>, cmp > heap; 
    //std::priority_quyeue<Node *, std::vector<Node *>, greater<Node *> > heap;
    Node *n1 = new Node(109);
    Node *n2 = new Node(9);
    Node *n3 = new Node(10);
    Node *n4 = new Node(15);
    heap.push(n1);
    heap.push(n2);
    heap.push(n3);
    heap.push(n4);

    while (!heap.empty()) {
        std::cout << heap.top()->val << ", ";
        heap.pop();
    }
    std::cout << std::endl;
}

