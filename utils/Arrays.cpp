#include <iostream>

using namespace std;

template <typename T>
class Array {
private:
    T *data;
    int size;
public:

    Array(int size){
        assert(size > 0);
        data = new T[size]{};
        size = size;
    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    ~Array(){
        delete[] data;
    }

    void erase(){
        delete[] data;
        data = nullptr;
        size = 0;
    }

    T& operator[](int index){
        assert(index >= 0 && index < size);
        return data[index];
    }

    int getSize() const {
        return size;
    }
};

int main(){
    return 0;
}