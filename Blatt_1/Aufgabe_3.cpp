#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

// converts string of '0' and '1' into an integer
int strtoint(string s){
    int output = 0;

    int count = 0;
    for (int i=s.length()-1; i>=0; --i){
	if (s.at(i) == '1') output += pow(2, count);
	count++;
    }
    return output;
}


int search(string s, int k){// s is the input string containing only '0' and '1's 
			    // k is the bit length of the numbers in s

    int numOfNums = s.length() / k; // calculates the amount of numbers in "s"
    if (numOfNums == 1){    // break condition if divide and conquer has divided and conquered
			    // only one number in bit form is left in string

	if (s.at(k-1) == '1'){ // looks a smallest bit. If it's 1 -> number is uneven, else number is even
	    return strtoint(s) - 1; // -1, because missing number is one less compared to the remaining one
	}
	else{
	    return strtoint(s) + 1; // +1, because missing number is one more compared to the remaining one
	}
    }

    int middle_bit = (numOfNums / 2 + 1) * k - 1;   // calculates the index of the smallest bit of the number
						    // in the middle of the array. There is always a "middle number"
						    // because the array has 2^k - 1 numbers in it

    if (s.at(middle_bit) == '1'){   // if the number in the middle is uneven
				    // the missing number has to be to the right,
				    // thus the search interval can be split in 
				    // half (divided). The first half of the
				    // string can be discarded
				    
	s.erase(0, (numOfNums/2+1)*k);		    // divide step
	return search(s, k);			    // recursion step
    }    
    if (s.at(middle_bit) == '0'){   // if the number in the middle is even, the
				    // missing number has to be to the left.
				    // Thus, the last half of the string can 
				    // be discarded.

	s.erase(middle_bit-k+1, (numOfNums/2+1)*k); // divide step
	return search(s, k);			    // recursion step
    }   
    // after one iteration the string has 2^(k-1) numbers in it
    // after k-1 iterations, the array is conquered and the break condition
    // is true
}


int main(){
    string s;
    int k = 2;
    cout << "Please input the string" << endl;
    cin >> s;
    cout << "Please input the bitlength k" << endl;
    cin >> k;

    int lostNum = search(s, k);
    
    cout << "The lost Number is: "  << lostNum << endl;

    return 0;
}
