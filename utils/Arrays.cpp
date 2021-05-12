#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class Array {
private:
    T *data;
    int size;
public:

    Array(int s):
        size(s)
    {
        assert(size > 0);
        data = new T[size]{};
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
    Array<int> intArray(12);
    Array<double> doubleArray(12);

    for (int count = 0; count < intArray.getSize(); ++count)
    {
        intArray[count] = count;
        doubleArray[count] = count + 0.5;
    }

    for (int count = intArray.getSize()-1; count >= 0; --count){
        cout << intArray[count] << '\t' << doubleArray[count] << '\n' ;
    }
    cout << endl;

    return 0;
}
