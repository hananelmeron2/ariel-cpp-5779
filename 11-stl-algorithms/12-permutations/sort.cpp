/**
 * Demonstrates STL sort algorithms.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <array>
#include "output_containers.hpp"
using namespace std;



int main() {
	vector<int> v{19,18,16,17,14,15,12,10,13,11};       // OK
	// deque<int> v{9,8,6,7,4,5,2,0,3,1};      // OK
	// array<int,10> v{9,8,6,7,4,5,2,0,3,1};   // OK
	// int v[10] {9,8,6,7,4,5,2,0,3,1};       // OK
	// list<int> v{9,8,6,7,4,5,2,0,3,1};       // ERROR - invalid operands to binary expression ('std::_List_iterator<int>' and 'std::_List_iterator<int>')
	cout << "unsorted: " << v << endl;

	sort(begin(v), end(v));
	cout << "sorted: " << v << endl;

	sort(begin(v), end(v), [](int a, int b){return a>b;});
	sort(begin(v), end(v), greater<int>{});
	cout << "\nsorted with comparator: " << v << endl;

	nth_element(begin(v), begin(v)+5, end(v));
	cout << "\nnth_element (5): " << v << endl;  // v[5] is in its correct place;
	                                             // v[0..5] are the smallest 6 elements.

	partial_sort(begin(v), begin(v)+3, end(v));
	cout << "partial_sort (3): " << v << endl;  // v[0..2] are in their correct place


	array<int,10> a{11,13,15,17,19, 12,14,16,18,20};
	cout << "\nTwo sorted halves: " << a << endl;
	inplace_merge(begin(a), begin(a)+5, end(a));
	cout << "inplace_merge: " << a << endl;
}

