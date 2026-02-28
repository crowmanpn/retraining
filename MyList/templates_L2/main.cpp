//Как определить приоритет вызова реализации шаблона ?
//С помощью фиктивного параметра, но почему-то два раза выполняется одна функция.
#include <iostream>
#include <string>
#include <vector>
#include <array>

template <typename T>
auto GetSizeImpl(const T& oth, int)
-> decltype(oth.size, size_t()) {
	return oth.size();
}

//Более низкий приоритет
template <typename T>
size_t GetSizeImpl(const T& oth,...) {
	std::cout << "Called sizeof" << std::endl;
	return sizeof(oth);
}

template <typename T>
size_t GetSize(const T& oth)
{
	std::cout << "Called .size()" << std::endl;
	return GetSizeImpl(oth,0);
}

//Вот что предлагает нейросеть
// 
//template <typename T>
//size_t GetSize(const T& oth) {
//	if constexpr (requires {oth.size();}) {
//		return oth.size(); // Приоритет для типов с .size()
//	}
//	else {
//		return sizeof(oth); // Резервный вариант
//	}
//}

int main() {

	std::vector<int> myVec = { 1,2,3,4,5,6,6 };
	std::cout << GetSize(myVec) << std::endl;

	int x = 42;
	std::cout << GetSize(x) << std::endl;
	return 0;
}