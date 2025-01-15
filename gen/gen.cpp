#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
typedef long long ll;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

template<typename _Iterator>
inline void out(_Iterator __first, _Iterator __last) {
	cout << (__first == __last?"\n":"");
	while (__first != __last)
		cout << *__first++ << (__first == __last?'\n':' ');
}

template<typename _List>
inline void out(_List &_list) { 
	out(all(_list));
}

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

vector<int> Tree(int n, string tr) {
    vector<int> par(n-1);
    if(tr == "regular" or tr == "cbt" or tr == "sqrt" or tr == "path") { 
        int deg;
        if(tr == "regular")
            deg = opt<int>("r");
        else if(tr == "path")
            deg = 1;
        else if(tr == "cbt")
            deg = 2;
        else if(tr == "sqrt")
            deg = (int) sqrt(n);
        int boss = 1, p = 2, r = deg;
        while(p <= n) {
            par[p-2] = boss;
            r--;
            p++;
            if(r == 0)
                r = deg, boss++;
        }
    } else if(tr == "star" or tr == "layer") {
        int layers;
        if(tr == "layer")
            layers = opt<int>("l");
        else if(tr == "star")
            layers = 1;
        vector<int> h(n);
        vector<int> a = {1};
        int p = 2;
        while(p <= n) {
            int he = rnd.any(a);
            while (h[he-1] < layers and p <= n) {
                par[p-2] = he;
                h[p-1] = h[he-1]+1;
                if(h[p-1] < layers)
                    a.push_back(p);
                he = p++;
            }
        }
    } else if(tr == "pastar") {
        for(int i = 1; i <= n/3; i++)
            par[i-1] = 1;
        for(int i = n/3+1; i <= 2*n/3; i++)
            par[i-1] = i;
        for(int i = 2*n/3+1; i < n; i++)
            par[i-1] = 2*n/3+1;
    } else {
        for(int i = 1; i < n; i++)
            par[i-1] = rnd.next(1, i);
    }
    return par;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    return 0;
}
