#pragma once
#include <vector>


template<typename Comparable>
void quickSort( std::vector<Comparable> &a ) {
	if (a.size() == 0)
		return;
	int left = 0;
	int right = a.size() - 1;
	quickSort( a, left, right );
}

template<typename Comparable>
void quickSort( std::vector<Comparable> &a, int lhs, int rhs ) {
	if (lhs == rhs)
		return;
	int center = quickDivide( a, lhs, rhs );
	quickSort( a, lhs, center-1 );
	quickSort( a, center, rhs);
}

template<typename Comparable>
int quickDivide( std::vector<Comparable> &a, int lhs, int rhs ) {
	if (lhs == rhs)
		return lhs;
	//mind that i range from lhs+1 not lhs(as the swap operation may fail);
	int i = lhs+1, j = rhs;

	while (1) {
		//first decrease j to a number that a[j]<pivot value; 
		//if increase i firstly, finally the a[i] would be > pivot value, swap may fail;
		while (a[j] > a[lhs] && j >= i)
			j--;
		while (a[i] <= a[lhs] && i < j)
			i++;
		swapForQuickSort( a[i], a[j] );
		if (i >= j)
			break;
	}
	swapForQuickSort( a[lhs], a[i] );
	return i;
}

template <typename Comparable>
void swapForQuickSort( Comparable &f, Comparable &s ) {
	Comparable temp = f;
	f = s;
	s = temp;
}