#include <iostream>

template <typename T>
void iter(T *addr, int length, void(*f)(T const&)) {
	for (int i = 0; i < length; i++) {
		f(addr[i]);
	}
}
