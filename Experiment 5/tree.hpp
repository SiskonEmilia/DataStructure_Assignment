#ifndef MY_TREE
#define MY_TREE

#include <iostream>
using namespace std;

struct Node {
	int data;
	unsigned left;
	unsigned right;
	Node(const int data = 0, const unsigned left = 0, const unsigned right = 0) : data(data), left(left), right(right) {}
};

class BTree {
public:
	BTree() :_size(0), _presentStorage(10000) {
		_storage = new Node[_presentStorage];
		_is = new bool[_presentStorage];
		for (unsigned i = 0; i < _presentStorage; ++i) {
			_is[i] = false;
		}
	}

	~BTree() {
		delete[] _storage;
		delete[] _is;
	}

	bool empty() const {
		return _size == 0;
	}

	unsigned size() const {
		return _size;
	}

	void append(const int& data) {
		if (_size == _presentStorage)
			extendStorage();
		if (_size == 0) {
			_storage[0].data = data;
			_is[0] = true;
		}
		else
			for (unsigned i = 0; i < _presentStorage; ++i) {
				if (!_is[i]) {
					_storage[i].data = data;
					if (_storage[(i + 1) / 2 - 1].left != 0) {
						_storage[(i + 1) / 2 - 1].right = i + 1;
					}
					else {
						_storage[(i + 1) / 2 - 1].left = i + 1;
					}
					_is[i] = true;
					break;
				}
			}
		++_size;
	}

	int& operator[] (const unsigned& index) {
		if (index > _presentStorage || !_is[index - 1])
			throw "RANGE_ERROR";
		return _storage[index - 1].data;
	}

	void print(unsigned position = 1, unsigned counter = 0) {
		if (position > _presentStorage || !_is[position - 1])
			return;
		for (unsigned i = 0; i < counter; ++i)
			cout << "  ";
		cout << "|--";
		cout << _storage[position - 1].data;

		cout << endl;
		if (_storage[position - 1].left != 0) {
			print(_storage[position - 1].left, counter + 1);
		}
		if (_storage[position - 1].right != 0) {
			print(_storage[position - 1].right, counter + 1);
		}
	}

	void interChange(unsigned position = 1) {
		if (position > _presentStorage || !_is[position - 1])
			return;

		auto temp = _storage[position - 1].left;
		_storage[position - 1].left = _storage[position - 1].right;
		_storage[position - 1].right = temp;

		if (_storage[position - 1].left != 0) {
			interChange(_storage[position - 1].left);
		}
		if (_storage[position - 1].right != 0) {
			interChange(_storage[position - 1].right);
		}
	}

private:
	void extendStorage() {
		_presentStorage *= 2;
		auto temp = new Node[_presentStorage];
		auto istemp = new bool[_presentStorage];
		for (unsigned i = 0; i < _presentStorage / 2; ++i) {
			temp[i] = _storage[i];
			istemp[i] = _is[i];
		}
		delete[] _storage;
		delete[] _is;
		_storage = temp;
		_is = istemp;
	}

	Node *_storage;
	bool *_is;
	unsigned _size;
	unsigned _presentStorage;
};

#endif
