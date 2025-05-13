//
// Created by Mario Bustillo on 13/01/25.
//

#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H
#include "Node.hpp"
using std::unique_ptr, std::make_unique, std::ostream;

template<typename T>
class TLinkedList {
private:
    unique_ptr<Node<T>> head;
    unique_ptr<Node<T>> last;
public:
    /**
     * Default Constructor
     */
    TLinkedList() : head(nullptr), last(nullptr) {}

    /**
     * Constructor with a node
     * @param Node<T>* node: node to be added
     */
    explicit TLinkedList(Node<T>* node) : head(node), last(node) {}

    /**
     * Push data to linked list initial position
     * @param T data: data to be pushed
     */
    void push_front(T data);

    /**
     * Push data to linked list final position
     * @param T data: data to be pushed back
     */
    void push_back(T data);

    void insertar_ordenado(T data);
    void eliminar_inicio();
    void eliminar_final();
    void eliminar_dato(T data);
    void eliminar_lista();
    Node<T>* buscar_dato(T data);

    /**
     * Show linked list data
     */
    void show_list();

    /**
     * Create stream to print linked list
     * @param stream
     * @param list
     * @return stream with all the data in the linked list
     */
    friend ostream& operator<< (ostream& stream, const TLinkedList<T>& list) {
        Node<T>* current = list.head.get();
        while (current) {
            stream << current->get_data() << '\n';
            current = current->get_next();
        }
        return stream;
    }
};

template<typename T>
void TLinkedList<T>::push_front(T data) {
    auto temp = make_unique<Node<T>>(data);
    if(head) {
        temp->set_next(head.release());
        head = std::move(temp);
    } else {
        head = std::move(temp);
    }
}

template<typename T>
void TLinkedList<T>::push_back(T data) {
    auto temp = make_unique<Node<T>>(data);
    if(head) {
        last->set_next(temp.release());
        last = std::move(temp);
    } else {
        last = std::move(temp);
    }
}

template<typename T>
void TLinkedList<T>::show_list() {
    Node<T>* current = head.get();
    while (current) {
        print("{0}\t", current->get_data());
        current = current->get_next();
    }
    print("\n");
}

#endif //TLINKEDLIST_H