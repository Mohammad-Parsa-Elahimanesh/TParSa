#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// Generate random boolean
inline bool C() {return rnd.next(2);}
inline bool Coin() {return C();}
inline bool coin() {return Coin();}
constexpr int TOTAL = 100;
inline bool C(int x) {return rnd.next(TOTAL) < x;}
inline bool Coin(int x) {return C(x);}
inline bool coin(int x) {return Coin(x);}

int main(int argc, char *argv[]) 
{
	registerGen(argc, argv, 1);

	return 0;
}
