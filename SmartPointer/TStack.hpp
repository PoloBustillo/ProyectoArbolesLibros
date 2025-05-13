//
// Created by Mario Bustillo on 08/02/25.
//

#ifndef TSTACK_H
#define TSTACK_H
#include "TLinkedList.hpp"

template<typename T>
class TStack : private TLinkedList<T> {
public:
    TStack() = default;

    /**
     * Create stream to print linked list
     * @param stream
     * @param stack
     * @param list
     * @return stream with all the data in the linked list
     */
    friend ostream &operator<<(ostream &stream, const TStack<T> &stack) {
        if (!stack.get_head()) {
            stream << "Pila vacia" << '\n';
            return stream;
        }
        print("HEAD:{0}         LAST:{1}\n", stack.get_head()->get_data(), stack.get_last()->get_data());
        size_t i = 0;
        Node<T> *current = stack.get_head();
        while (current) {
            if (current->get_next() == nullptr)
                stream << "Nodo #" << i << ":" << current->get_data();
            else
                stream << "Nodo #" << i << ":" << current->get_data() << "\t-\t";
            current = current->get_next();
            ++i;
        }
        stream << '\n';
        return stream;
    }

    void push(T data) {
        TLinkedList<T>::push_back(data);
    }

    optional<T> pop() {
        return TLinkedList<T>::remove_last();
    }

    void show() {
        TLinkedList<T>::show_list();
    }

    ~TStack() = default;
};


#endif //TSTACK_H
