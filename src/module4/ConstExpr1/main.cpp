#include <cstdint>

template<typename T>
constexpr int sizeInBytes(int count) {
	return sizeof(T) * count;
}

int main() {
	uint8_t array1[sizeof(int) * 10];
	uint8_t array2[sizeInBytes<int>(10)];
	return 0;
}