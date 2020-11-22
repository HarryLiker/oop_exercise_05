#include <iostream>
#include <memory>
#include <iterator>
#include <exception>


template <class T>
struct Node;

template <class T>
void operator++(std::shared_ptr<Node<T>> &current_node) {
    if (current_node) {
        current_node = current_node->Next; // ????????????????????????????
    }
    else {
        throw std::out_of_range("Iterator has already nullptr\n");
    }
}

template <class T>
bool operator!=(const Node<T> &left_value, const Node<T> &right_value) {
    return &left_value != &right_value;
}

template <class T>
bool operator==(const Node<T> &left_value, const Node<T> &right_value) {
    return &left_value.Data == &right_value.Data;
}

template <class T>
std::ostream &operator<<(std::ostream &cout, const Node<T> &node) {
    cout << node.Data;
    return cout;
}


template <class T> 
struct Node {
    T Data; 
    std::shared_ptr<Node> Next;

    Node(): Next(nullptr) {}

    Node(const T &data): Data(data), Next(nullptr) {} 

    friend void operator++<>(std::shared_ptr<Node<T>> &node);

    friend bool operator==<>(const Node<T> &left_value, const Node<T> &right_value);

    friend bool operator==<>(const Node<T> &left_value, const Node<T> &right_value);

    friend std::ostream &operator<<<>(std::ostream &cout, const Node<T> &node);
};


template <class T>
class Queue {
private:
    size_t Size = 0;
    std::shared_ptr<Node<T>> First;
    std::shared_ptr<Node<T>> Last;
public:

    class QueueIterator {
    private:
        std::shared_ptr<Node<T>> iterator;
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        QueueIterator(): iterator(nullptr) {}

        explicit QueueIterator(const std::shared_ptr<Node<T>> &another_iter): iterator(another_iter) {}

        bool isNull() {
            return iterator == nullptr;
        } 
        
        friend void operator++(QueueIterator &iter) {
            ++iter.iterator;
        }

        friend bool operator!=(const Queue<T>::QueueIterator &left_value, const Queue<T>::QueueIterator &right_value) {
            return left_value.iterator != right_value.iterator;
        }

        friend std::ostream &operator<<(std::ostream &out, const QueueIterator &iter) {
            out << *iter.iterator;
            return out;
        }

        Node<T> &operator*() {
            return *iterator;
        }
    };

    Queue() noexcept: First(nullptr) {}

    void Push(const T &value) {
        
        if (Size == 0) {
            Node<T> *new_node = new Node<T>(value);
            std::shared_ptr<Node<T>> new_pointer{new_node};
            Last = new_pointer;
            First = Last;
        }
        else if (Size == 1) {
            Node<T> *new_node = new Node<T>(value);
            std::shared_ptr<Node<T>> new_pointer{new_node};
            First->Next = Last;
            Last->Next = new_pointer;
            Last = new_pointer;
        }
        else {
            Node<T> *new_node = new Node<T>(value);
            std::shared_ptr<Node<T>> new_pointer{new_node};
            Last->Next = new_pointer;
            Last = new_pointer;
        }

        //Last = new_pointer;
        
        
        /*
        Node<T> *new_node = new Node<T>(value);
        std::shared_ptr<Node<T>> new_pointer{new_node};
        new_pointer->Previous = Last;
        Last = new_pointer; 

        if (Size == 0) {
            First = Last;
        }
        if (Size == 1) {
            First->Next = Last;
            Last->Previous = First;
        } */
        
        
        /*
        std::shared_ptr<Node<T>> current_node = First;
        while (current_node != nullptr) {
            current_node = current_node->Next;
        }
        std::shared_ptr<Node<T>> new_pointer{new_node};
        current_node = new_pointer;
        */
        ++Size;
    }

    void Pop() {
        if (First) {
            First = First->Next;
            --Size;
        }
        else {
            throw std::runtime_error("Queue is empty");
        }
    }

    T Top () {
        if (First) {
            return First->Data;
        }
        else {
            throw std::runtime_error("First is nullptr!\n");
        }
    }

    void Insert(Queue<T>::QueueIterator &iter, const T &elem) {
        std::unique_ptr<Node<T>> newNode {new Node<T>(elem)};
        std::shared_ptr<Node<T>> newPtr = std::move(newNode);
        std::shared_ptr<Node<T>> nextPtr = First;

        if (nextPtr) {
            if (!iter.isNull()) {
                while(*nextPtr->Next != *iter) {
                    ++nextPtr;
                }
            }
            else {
                while (nextPtr->Next != nullptr) {
                    ++nextPtr;
                }
            }
            newPtr->Next = nextPtr->Next;
            nextPtr->Next = newPtr;
        }
        else {
            First = newPtr;
        }
        ++Size;
    }

    void Erase(QueueIterator &iter) {
        if (iter.isNull()) {
            throw std::runtime_error("Iterator is in nullptr state!\n");
        }
        else {
            if (*iter == *First) {
                First = First->Next;
            }
            else {
                std::shared_ptr<Node<T>> next_ptr = First;
                while (*next_ptr->Next != *iter) {
                    ++next_ptr;
                }
                next_ptr->Next = next_ptr->Next->Next;
            }
            --Size;
        }
    }

    QueueIterator begin() {
        return QueueIterator(First);
    }

    QueueIterator end() {
        return QueueIterator(Last->Next);
    }

    size_t FindSize() {
        return Size;
    }
    ~Queue() {}
};