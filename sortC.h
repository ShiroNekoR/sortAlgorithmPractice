#pragma once
//#define NODEBUG
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdio>
#include <cassert>



class sortC {
public:
	sortC() {};
	virtual ~sortC() {};
protected:
	std::vector<int> _v;
public:
	virtual void generateVec( int _size ) {
		srand( time( 0 ) );
		_v.clear();
		for (int i = 0; i<_size; i++) {
			_v.push_back( rand() % (3 * _size) );
		}
		this->printIntVec();
	}

	virtual bool verifyIt() {
		if (!_v.size()) return false;
		auto _x = _v[0];
		for (int i = 0; i < _v.size(); ++i) {
			if (_x > _v[i]) return false;
			_x = _v[i];
		}
		return true;
	}

	virtual void printVerify() {
		if (verifyIt()) std::cout << "True, Sorted!!!\r\n";
		else std::cout << "False, Unsorted...\r\n";
	}
	
	virtual void printIntVec() {
		for (int i = 0; i<_v.size() - 1; ++i) { std::cout << _v[i] << ' '; }
		std::cout << std::endl;
		return;
	}

	virtual void Sort() = 0;
};

class quicksortC:public sortC {
public:
	quicksortC() {};
	~quicksortC() {};
public:
	int findPivot( int lhs, int rhs ) {
		int i = lhs , j = rhs;
		int x = _v[lhs];
		while (1) {
			while (i < j && _v[j] > x) {
				--j;
			}
			while (i < j && _v[i] <= x) {
				++i;
			}
			
			if (i == j)break;
			std::swap( _v[i], _v[j] );
		}
		if (_v[i] < x) std::swap( _v[i], _v[lhs] );
		return i;
	}

	virtual void Sort() {
		quickSort( 0, _v.size() - 1 );
		return;
	}

	void quickSort( int lhs, int rhs ) {
		if (lhs >= rhs) return;
		int inx = findPivot( lhs, rhs );
		quickSort( lhs, inx-1 );
		quickSort( inx + 1, rhs );
		return;
	}

};


class insertsortC :public sortC {
public:
	insertsortC() {};
	~insertsortC() {};
public:
	void insertsort() {
		if (_v.size() < 1) return;
		for (int i = 1; i < _v.size(); ++i) {
			int j = i-1;
			int x = _v[i];
			while (j >= 0 && _v[j]>x) {
				_v[j + 1] = _v[j];
				--j;
			}
			_v[j+1] = x;
		}
		return;
	}
	
	virtual void Sort() {
		this->insertsort();
	}
};

class bubblesortC :public sortC {
public:
	bubblesortC() {};
	virtual ~bubblesortC() {};
public:
	void bubbleSort() {
		if (_v.size() < 1)return;
		bool update = false;
		int lastChange = 0;
		for (int i = 0; i < _v.size();) {
			update = false;
			for (int j = _v.size()-1; j > i; --j) {
				if (_v[j-1] > _v[j]) {
					std::swap( _v[j], _v[j-1] );
					lastChange = j ;
					update = true;
				}
			}
			if (!update) return;
			i = lastChange;
		}
	}
	virtual void Sort() {
		this->bubbleSort();
	}
};