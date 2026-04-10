//ДЗ!!! (Смотри видео!)

#include <iostream>
#include <vector>

int* generate_square_idxs(const size_t size) {
    int* array = new int(size);

    for (size_t i = 0; i < size; ++i) {
        array[i] = i * i;
    }

    return array;
}

void print_array(const int* array, const size_t array_size) {
    for (int i = 0; i < array_size; ++i) {
        std::cout << array[i] << std::endl;
    }
}

std::vector<int> generate_square_idxs_vector(const size_t size) {
    std::vector<int> res1(size);
    std::cout << "size: " << res1.size() << "capacity: " << res1.capacity() << std::endl;
    size_t i = 0;
    for (auto iter = res1.begin(); iter < res1.end(); ++iter) {
        *iter = i * i;
        ++i;
    }

    std::vector<int> res2;
    res2.reserve(10);
    std::cout << "size: " << res2.size() << "capacity: " << res2.capacity() << std::endl;
    for (size_t i = 0; i < size; ++i) {
        //res2[i] = i*i;
        res2.emplace_back((i * i));
    }

    for (const auto el : res1) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    for (const auto el : res2) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return res1;
}

void swap(int* x, int* y) {

  
    if (x != nullptr && y != nullptr){         
    int tmp = *x;
    *x = *y;
    *y = tmp;
    }

}

void swapRef(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;

}




int main() {
    //auto array = generate_square_idxs(10);
    //print_array(array, 10);

    auto res = generate_square_idxs_vector(10);

    int p1 = 100;
    int* p2 = &p1;

    std::cout << "adress: " << p2 << std::endl;
    std::cout << "val: " << *p2 << std::endl;

    std::cout << "adress: " << &p1 << std::endl;
    std::cout << "val: " << p1 << std::endl;

    int& ref1 = p1;
    p1 = 200;

    std::cout << "ref1: " << ref1 << std::endl;
    std::cout << "p1: " << p1 << std::endl;

    ref1 = 333;

    std::cout << "ref1: " << ref1 << std::endl;
    std::cout << "p1: " << p1 << std::endl;

    int b = 3;

    ref1 = b;

    std::cout << "ref1: " << ref1 << std::endl;

    int x = 1;
    int y = 2;

    //swap(&x, &y);
    swapRef(x, y);

    const int n = 5;

    int Array[n] = { 1,2,3,4,5 };

    int* arrPtr = Array;
    
    int c = *(Array + 2);

    std::cout << "offset b: " << b << std::endl;

    size_t szarrPtr = sizeof(arrPtr);
    size_t szArray = sizeof(int) * n;

    

    return 0;
}