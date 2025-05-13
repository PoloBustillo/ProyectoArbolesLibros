#ifndef TCIRCULARQUEUE_H
#define TCIRCULARQUEUE_H

#include "TArray.hpp"
#include <optional>
#include <iostream>

template<typename T>
class TCircularQueue {
private:
    TArray<T> array; // Arreglo dinámico para almacenar los elementos
    int front;       // Índice del frente de la cola
    int rear;        // Índice del final de la cola
    int count;       // Número de elementos en la cola
    int capacity;    // Capacidad máxima de la cola

public:
    explicit TCircularQueue(int size)
        : array(size), front(0), rear(-1), count(0), capacity(size) {}

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void enqueue(T data) {
        if (isFull()) {
            std::cerr << "ERROR: COLA LLENA\n";
            return;
        }
        rear = (rear + 1) % capacity; // Mover el índice circularmente
        array.set_data(rear, data);  // Guardar el dato en el arreglo
        ++count;
    }

    std::optional<T> dequeue() {
        if (isEmpty()) {
            std::cerr << "ERROR: COLA VACIA\n";
            return std::nullopt;
        }
        T data = array.get_data(front); // Obtener el dato del frente
        front = (front + 1) % capacity; // Mover el índice circularmente
        --count;
        return data;
    }

    void show()  {
        if (isEmpty()) {
            std::cout << "Cola vacía\n";
            return;
        }
        std::cout << "Contenido de la cola (de frente a atrás): ";
        for (int i = 0; i < count; ++i) {
            int index = (front + i) % capacity; // Índice circular
            std::cout << array.get_data(index) << " ";
        }
        std::cout << "\n";
    }
};

#endif // TCIRCULARQUEUE_H