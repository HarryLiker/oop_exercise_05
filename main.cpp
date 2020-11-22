#include <iostream>
#include <memory>
#include "triangle.hpp"
#include "queue.hpp"
#include "menu.hpp"
#include <utility>
#include <algorithm>


using namespace std;


int main() {
    menu();
    /*
    auto PrintQueue = [](const Node<Triangle<int>> &object) {
        std::cout << object << "\n";
    };


    Queue<Triangle<int>> queue;
    int n;
    cout << "Input count of recrangles: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, y;
        int side;
        cin >> x >> y;
        cin >> side;
        queue.Push(Triangle<int>(std::pair<int,int> {x, y}, side));
    }

    int x, y;
    int side;
    queue.Pop();
    queue.Pop();

    //queue.Insert();
    std::for_each(queue.begin(), queue.end(), PrintQueue); // Выводит все элементы

    int idx;
    std::cout << "Enter index: ";
    std::cin >> idx;
    cin >> x >> y;
    cin >> side;
    try {
        if (queue.FindSize() + 1 < idx) {
            throw std::invalid_argument("Entered wrong index!\n");
        }
        else {
            auto iterator = queue.begin();
            while (--idx) {
                ++iterator;
            }
            queue.Insert(iterator, Triangle<int>(pair<int,int> {x, y}, side));
        }
    }

    catch (std::invalid_argument &arg) {
        std::terminate();
    }
    
    std::for_each(queue.begin(), queue.end(), PrintQueue);

    cin >> idx;
    try {
        auto iterator = queue.begin();
        while(--idx) {
            ++iterator;
        }
        queue.Erase(iterator);
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n\n";

    std::for_each(queue.begin(), queue.end(), PrintQueue);

    */
    //for (int i = 0; )

    /*
    Triangle<double> treangle;
    Queue<Triangle<double>> queue;
    Node <int> *new_node = new Node<int>(25);
    std::shared_ptr<Node<int>> ptr_new {new_node};
    std::cout << "HELLO";
    */
}