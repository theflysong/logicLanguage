#ifndef __HEAD__P
#define __HEAD__P

#include <bits/stdc++.h>
#include <hash_map>
#include <memory>
using namespace std;
using namespace __gnu_cxx;

#define interface struct
#define abstract

template<typename T>class Array {
	int size;
	T* array;
	void init() {
		array = new T[size];
	}
	void extend() {
		T* old = array;
		array = new T[size * 2 + size / 10];
		for (int i = 0 ; i < size ; i ++) {
			array[i] = old[i];
		}
		size = size * 2 + size / 10;
		delete old;
	}
public:
	Array() {
		size = 20;
		init();
	}
	~Array() {
		delete[] array;
	}
	T& get(int pos) {
		if (pos > size)	{
			extend();
		}
		return array[pos];
	}
	void set(int pos, T data) {
		array[pos] = data;
	}
	void clear() {
		delete array;
		size = 20;
		init();
	}
	T& operator[](int pos) {
		return get(pos);
	}
	template<typename F>void foreach(F function) {
		for (int i = 0 ; i < size ; i ++) {
			function(get(i));
		}
	}
};

#endif
