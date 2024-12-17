#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
typedef long long ll;

constexpr int TOTAL = 100;
inline bool C() {return rnd.next(2);}
inline bool Coin() {return C();}
inline bool coin() {return Coin();}
inline bool C(int x) {return rnd.next(TOTAL) < x;}
inline bool Coin(int x) {return C(x);}
inline bool coin(int x) {return Coin(x);}

inline string RBigNum(int digits){return rnd.next("[1-9][0-9]{"+to_string(digits)+"}");}
inline string Rword(int length){return rnd.next("[a-z]{"+to_string(length)+"}");}
inline string RWord(int length){return rnd.next("[a-zA-Z]{"+to_string(length)+"}");}

template<typename _RandomAccessIterator>
inline void RateShuffle(_RandomAccessIterator __first, _RandomAccessIterator __last, int percent = TOTAL) {
    while (__first != __last) {
        if(coin(percent))
            swap(*__first, *(__first+rnd.next(__last-__first)));
        __first++;
    }
}

template<typename _RandomAccessIterator>
inline void RangeShuffle(_RandomAccessIterator __first, _RandomAccessIterator __last, int percent = TOTAL) {
    while (__first != __last) {
        swap(*__first, *(__first+(1LL*rnd.next(__last-__first)*percent+TOTAL-1)/TOTAL));
        __first++;
    }
}


int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);


    return 0;
}
