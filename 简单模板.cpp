#include<iostream>
#include<stdlib.h>
using namespace std;

template <class T>
class Vector {
private:
	T* data;
	int size;
	int max;
public:
	
	explicit Vector(int n = 10) :size(0), max(n) { data = new T[max]; }
	int Size() const{ return size; };
	int Max()const { return max; };

	void Reserve(int newmax) {
		if (newmax < max) return;
		T* old = data;
		data = new T[newmax];
		for (int i = 0; i < size; i++) {
			data[i] = old[i];
		}
		max = newmax;
		delete[]old;
	};

	void PushBack(const T& item) {
		if (size == max) {
			Reserve(2 * max + 1);
		}
		data[size++] = item;
		
	}; 

	int Count(const T& item)const {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (data[i] == item) count++;
		}
		return count;
	};
}; 

int main() {
	int a[10] = { 1,2,3,9,5,6,7,8,9,0 };
	Vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.PushBack(a[i]);
	}

	cout << v.Count(9);
}

