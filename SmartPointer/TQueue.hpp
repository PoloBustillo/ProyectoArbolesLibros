//
// Created by Mario Bustillo on 08/02/25.
//

#ifndef TCOLA_H
#define TCOLA_H
#include "TLinkedList.hpp"

template<typename T>
class TQueue : private TLinkedList<T> {
public:
    TQueue() = default;

    /**
        * Create stream to print linked list
        * @param stream
        * @param queue
        * @param list
        * @return stream with all the data in the linked list
        */
    friend ostream &operator<<(ostream &stream, const TQueue<T> &queue) {
        if (!queue.get_head()) {
            stream << "Cola vacia" << '\n';
            return stream;
        }
        print("HEAD:{0}         LAST:{1}\n", queue.get_head()->get_data(), queue.get_last()->get_data());
        size_t i = 0;
        Node<T> *current = queue.get_head();
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
        return TLinkedList<T>::remove_init();
    }

    void show() {
        TLinkedList<T>::show_list();
    }

    ~TQueue() = default;
};
#endif //TCOLA_H
