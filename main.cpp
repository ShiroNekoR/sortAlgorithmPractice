#include "mergeSort.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "quickSort.h"
#include "insertSort.h"
#include "shellSort.h"
#include "random"
#include "sortC.h"


int main() {
	/*srand(20175);
	generateRandomVec( a );
	quick2( a );
	printIntVec( a );*/
	bubblesortC *qs = new bubblesortC;
	qs->generateVec( 500 );
	qs->printVerify();
	qs->Sort();
	qs->printIntVec();
	qs->printVerify();
	system( "pause" );
	return 1;
}

