#include <memory>
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

void work() {
    // do something
}

//int main() {
//    
//    return 0;
//}

void function() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(100);
    //std::shared_ptr<int> ptr2(ptr1.get());   //неправильно
    std::shared_ptr<int> ptr2(ptr1); //правильно
    //Нельзя делать sh ptr из сырых ук-лей
    //Умные укалетели через make shared



    
}


class Child;
class Parent {
public:
    std::shared_ptr<Child> child; //счет есть
    ~Parent() { std::cout << "Parent destroyed\n"; }
};

class Child {
public:
    std::weak_ptr<Parent> parent; //счетчика нет
    ~Child() { std::cout << "Child destroyed\n"; }
};

void createFamily() {
    auto father = std::make_shared<Parent>();
    auto son = std::make_shared<Child>();
    father->child = son; // счетчик 0 
    son->parent = father;  //++ отец
}

//void riskyFunction() {
//    Widget* w = new Widget();
//    std::shared_ptr<Widget> sp(w);  //небезопасное создание объекта
//
//    throw std::runtime_error("Oops!"); //код ниже не отработает
//
//    std::shared_ptr<Widget> sp2(w);      //небезопасное создание объекта
//    sp->process();
//}

//Подумать ДЗДЗДЗ!!!

//нельзя кидать исключения в деструкторе.


int main() {
    
    std::thread t(work);

    //t.join();
    //t.detach(); //свободное плавание

    createFamily();
    std::cout << "Family function finished\n";
    


    //std::unique_ptr<int> p1(new int(5));         //небезопас. инициализ
    std::unique_ptr<int> p1=std::make_unique<int>(5); //
    std::unique_ptr<int> p2=std::move(p1); //через мув семантику
    
    std::vector<int> myVec{ 1,4,6,-10,23,44,12222,2333,88,0 };
    //чет удалить
    //отсорт
    for (size_t i = 0; i < myVec.size(); i++)
    {
        if (myVec[i] % 2 == 0) {
            myVec.erase(myVec.begin() + i);
            i--;
        }
    }
    std::sort(myVec.begin(), myVec.end());
    
    for (size_t i = 0; i < myVec.size(); i++)
    {
        std::cout << myVec[i] << std::endl;
    }

   //
   /* v.erase(
        std::remove_if(v.begin(), v.end(),
            [](int x) { return x % 2 == 0; }),
        v.end()
    );*/

    return 0;
}
