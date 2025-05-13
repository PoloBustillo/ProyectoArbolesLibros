//
// Created by Mario Bustillo on 13/01/25.
//

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
private:
    T data;
    Node *next;
    Node *back;

public:
    explicit Node(T data) : data{data}, next{nullptr}, back{nullptr} {
    }

    // Getters
    T get_data() const { return data; }
    Node *get_next() const { return next; }
    Node *get_back() const { return back; }

    // Setters
    void set_data(T new_data) { data = new_data; }
    void set_next(Node *new_next) { next = new_next; }
    void set_back(Node *new_back) { back = new_back; }
};

#endif //NODE_H
