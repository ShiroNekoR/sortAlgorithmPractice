#pragma once
#include <vector>

template<typename Comparable>
void mergeSort( std::vector<Comparable> &a ) {
	if (a.size() == 0)
		return;
	std::vector<Comparable> temp( a.size(), 0 );
	mergeSort( a, temp, 0, a.size() - 1 );
	return;
}

template<typename Comparable>
void mergeSort( std::vector<Comparable> &a, std::vector<Comparable> &temp,
				int left, int right ) {
	if (left == right)
		return;
	int center = (left + right) >> 1;
	mergeSort( a, temp, left, center );
	mergeSort( a, temp, center + 1, right );
	merge( a, temp, left, center, right );
	return;
}

template<typename Comparable>
void merge( std::vector<Comparable> &a, std::vector<Comparable> &temp,
			int left, int center, int right ) {
	int firstPos = left, secondPos = center + 1;
	int tempPos = left;
	while (firstPos <= center && secondPos <= right) {
		temp[tempPos++] = std::move( a[firstPos] < a[secondPos] ? a[firstPos++] : a[secondPos++] );
	}
	while (firstPos <= center) {
		temp[tempPos++] = std::move( a[firstPos++] );
	}
	while (secondPos <= right) {
		temp[tempPos++] = std::move( a[secondPos++] );
	}

	for (int _i = left; _i <= right; _i++) {
		a[_i] = std::move( temp[_i] );
	}
} 