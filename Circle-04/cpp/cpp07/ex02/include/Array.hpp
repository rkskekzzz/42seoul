#ifndef Array_HPP
#define Array_HPP

#include <iostream>

template <typename T>

class Array {
	private:
		T *_array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array<T> const&);
		~Array();

		Array<T>& operator=(Array<T> const&);
		T& operator[](unsigned int i);
		T& operator[](unsigned int i) const;
		unsigned int size() const;
};

template <class T>
std::ostream& operator<<(std::ostream& stream, Array<T>const& array);

/** implement **/
template <typename T>
Array<T>::Array() {
	_array = new T[0];
	_size = 0;
};

template <typename T>
Array<T>::Array(unsigned int n) {
	T *temp = new T();

	_size = n;
	_array = new T[_size];
	for (unsigned int i = 0 ; i < _size ; i++) {
		_array[i] = *temp;
	}
	delete temp;
};

template <class T>
Array<T>::Array(Array<T> const& origin) {
	_array = NULL;
	*this = origin;
}

template <class T>
Array<T>::~Array() {
	delete[] _array;
}

template <class T>
Array<T>& Array<T>::operator=(Array<T> const& rvalue)
{
	if (_array != NULL)
		delete[] _array;

	_size = rvalue._size;
	_array = new T[_size];

	for (unsigned int i = 0; i < _size; i++)
		_array[i] = rvalue._array[i];

	return *this;
}

template <class T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= _size)
		throw std::exception();
	return _array[i];
}

template <class T>
T& Array<T>::operator[](unsigned int i) const {
	if (i >= _size)
		throw std::exception();
	return _array[i];
}

template <class T>
unsigned int Array<T>::size() const {
	return _size;
}

template <class T>
std::ostream& operator<<(std::ostream& os, Array<T>const& array) {
	os << "[ ";
	for (unsigned int i = 0 ; i < array.size() ; i++) {
		os << array[i];
		if (i != array.size() - 1)
		 os << ", ";
	}
	os << " ]";
	return os;
}

#endif
