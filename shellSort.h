#pragma once
#include <vector>

template<typename Comparable>
void shellSort( std::vector<Comparable> &a ) {
	int sz = a.size();
	int gap = sz / 2;
	for (; gap > 0; gap /= 2) {
		for (int p = gap; p < sz; p += gap) {
			int t;
			Comparable temp = std::move( a[p] );
			for (t = p; t > 0 && a[t - gap] > temp; t -= gap)
				a[t] = std::move( a[t - gap] );
			a[t] = std::move( temp );
		}
	}
}