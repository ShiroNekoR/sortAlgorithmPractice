#pragma once
#include <vector>

template <typename Comparable>
void insertSort( std::vector<Comparable> &a ) {
	if (a.size() == 0)
		return;
	int sz = a.size();
	for (int p = 1; p<sz; ++p) {
		Comparable temp = a[p];
		int t;
		for (t = p; t > 0 && a[t-1] > temp; t--)
			a[t] = std::move( a[t - 1] );
		a[t] = std::move(temp);
	}
}