#include <iostream>
#include <sstream>
#include "LinkedList.h"
#include <string>
#include <cstdlib>
#include <ctime>



int main(void) {
    LinkedList<int> list;
    clock_t begin, end;
    //list.reverse(list.getListHead());
    /*std::string str;
    while (std::getline(std::cin, str)) {
        std::cout << "m for left, n for right" << std::endl;
        std::stringstream ss(str);
        std::string m, n;
        ss >> m >> n;
        list.reverse(atoi(m.c_str()), atoi(n.c_str()));
        list.printList();
    }*/
    begin = clock();
    //list.bubbleSort(true);
    list.quickSort();
    end = clock();
    std::cout <<"ElapseTime is " << (double) (end - begin) / CLOCKS_PER_SEC << std::endl;
    list.printList();
}
