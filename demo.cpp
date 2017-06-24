#include <iostream>
#include <sstream>
#include "LinkedList.h"
#include <string>
#include <cstdlib>

int main(void) {
    LinkedList<int> list;
    //list.reverse(list.getListHead());
    std::string str;
    while (std::getline(std::cin, str)) {
        std::cout << "m for left, n for right" << std::endl;
        std::stringstream ss(str);
        std::string m, n;
        ss >> m >> n;
        list.reverse(atoi(m.c_str()), atoi(n.c_str()));
        list.printList();
    }
}
