//
// Created by Mario Bustillo on 08/01/25.
//
#ifndef TARREGLO_H
#define TARREGLO_H

#include<print>
#include<memory>
using std::exception, std::out_of_range, std::ostream;
using std::print;

template<typename T>
class TArray {
private:
    size_t size;
    T *ptr_array;

    bool check_out_of_range(int index);

public:
    TArray<T>() : size(0), ptr_array(nullptr) {
    }

    explicit TArray<T>(const size_t size) : size(size), ptr_array(new T[size]) {
    }

    /**
       * Set data in the array
       * @param index: array index to set data
       * @param data: data to set in the array
    */
    void set_data(size_t index, T data);

    /**
     * Get data in the array from a specific index
     * @param index: index inside range where data will be saved
    */
    T get_data(size_t index);

    /**
     * Show array data
     */
    void show_array();

    /**
     * Override the operator ~ to sort the array
     * @return
     */
    void operator~() const;

    /**
     * Create stream to print array
     * @param stream
     * @param array
     * @return stream with all the data in the array
     */
    friend ostream &operator<<(ostream &stream, const TArray<T> &array) {
        for (size_t i = 0; i < array.size; ++i) {
            stream << array.ptr_array[i] << '\n';
        }
        return stream;
    }
};

template<typename T>
bool TArray<T>::check_out_of_range(int index) {
    if (index >= size) {
        throw out_of_range("Index out of range");
    }
    return false;
}

template<typename T>
void TArray<T>::operator~() const {
    print("Ordenando...\n");
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (ptr_array[j] < ptr_array[j + 1]) {
                T temp = ptr_array[j];
                ptr_array[j] = ptr_array[j + 1];
                ptr_array[j + 1] = temp;
            }
        }
    }
}

template<typename T>
void TArray<T>::show_array() {
    for (size_t i = 0; i < size; ++i) {
        print("Index en la posicion {0}: {1}\n", i, ptr_array[i]);
    }
}

template<typename T>
T TArray<T>::get_data(size_t index) {
    check_out_of_range(index);
    return *(ptr_array + index);
}

template<typename T>
void TArray<T>::set_data(size_t index, T data) {
    check_out_of_range(index);
    try {
        print("Guardando dato en la posición {0}\n", index);
        *(ptr_array + index) = data;
    } catch (const exception &e) {
        print("Exception {0}", e.what());
    }
    catch (...) {
        print("Unknown exception");
    }
}

#endif // TARREGLO_H
