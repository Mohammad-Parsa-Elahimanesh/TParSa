#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

inline bool C() {return rnd.next(2);}
inline bool Coin() {return C();}
inline bool coin() {return Coin();}
constexpr int TOTAL = 100;
inline bool C(int x) {return rnd.next(TOTAL) < x;}
inline bool Coin(int x) {return C(x);}
inline bool coin(int x) {return Coin(x);}
inline string RBigNum(int digits){return rnd.next("[1-9][0-9]{"+to_string(digits)+"}");}
inline string Rword(int length){return rnd.next("[a-z]{"+to_string(length)+"}");}
inline string RWord(int length){return rnd.next("[a-zA-Z]{"+to_string(length)+"}");}

int main(int argc, char *argv[]) 
{
	registerGen(argc, argv, 1);


	return 0;
}
