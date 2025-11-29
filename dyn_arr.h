#ifndef DYN_ARR
#define DYN_ARR

#include <stdexcept>

namespace comp {
    template <typename T>
    class dyn_arr {
    private:
        T* arr;
        int sizeArr;
        int capacity;

        void expand() {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T* newArr = new T[newCapacity];
            for (int i = 0; i < sizeArr; ++i)
                newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        }

    public:
        dyn_arr() : arr(nullptr), sizeArr(0), capacity(0) {}

        dyn_arr(int initialCapacity) : arr(new T[initialCapacity]()), sizeArr(initialCapacity), capacity(initialCapacity) {}

        dyn_arr(const dyn_arr& other) : arr(nullptr), sizeArr(0), capacity(0) {
            if (other.sizeArr > 0) {
                arr = new T[other.capacity];
                capacity = other.capacity;
                sizeArr = other.sizeArr;
                for (int i = 0; i < sizeArr; ++i) {
                    arr[i] = other.arr[i];
                }
            }
        }

        dyn_arr& operator=(const dyn_arr& other) {
            if (this != &other) {
                delete[] arr;
                
                arr = nullptr;
                sizeArr = 0;
                capacity = 0;
                
                if (other.sizeArr > 0) {
                    arr = new T[other.capacity];
                    capacity = other.capacity;
                    sizeArr = other.sizeArr;
                    for (int i = 0; i < sizeArr; ++i) {
                        arr[i] = other.arr[i];
                    }
                }
            }
            return *this;
        }

        ~dyn_arr() { delete[] arr; }

        int size() const { return sizeArr; }

        T& operator[](int index) {
            if(index < 0 || index >= sizeArr) throw std::out_of_range("Index out of bounds");
            return arr[index];
        }
        
        const T& operator[](int index) const {
            if(index < 0 || index >= sizeArr) throw std::out_of_range("Index out of bounds");
            return arr[index];
        }

        void push_back(const T& value) {
            if (sizeArr == capacity) expand();
            arr[sizeArr++] = value;
        }
    };
}

#endif