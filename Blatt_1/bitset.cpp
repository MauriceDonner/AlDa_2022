#include <iostream>
#include <bitset>
#include <string>

using namespace std;


int main() {

////// HARD-CODED BECAUSE BITSETS ARE NOT DYNAMIC //////////////////////////////
    const int k = 18;	// The length of integers in bits
    const int n = 262144; // The number of entries in A
    int missing = 120001;	// The number missing from A
////////////////////////////////////////////////////////////////////////////////

    // We will create the bitset from a string (because ints become too large)
    string A_str;

    // Add all numbers to the bitset, but the missing one
    for (int i=0; i<n; i++) {
	if (i==missing) continue;
	bitset<k> number(i);
	A_str += number.to_string();
    }

    // Create the bitset
    bitset<n*k-k> A(A_str);

    // Print the bitset 
    cout << A << endl;

    return 0;
}

