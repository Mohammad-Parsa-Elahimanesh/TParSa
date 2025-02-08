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

////////////////////////// Graph //////////////////////////

// tr can be regular (-r) r is number of children, cbt: complete binary tree, sqrt: sqrn(n) regular, path, 
//        star, layer (-l): have specific number of layers, pastar: star-path-star, 
//        boreth: path with leaves for each node, random
inline vector<int> Tree(int n, string tr) {
    vector<int> par(n-1);
    if(tr == "regular" or tr == "cbt" or tr == "sqrt" or tr == "path") { 
        int deg = 0;
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
        int layers = 0;
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
    } else if(tr == "bores") {
        for(int i = 1; i < n; i++) {
            if(i&1)
                par[i-1] = i;
            else
                par[i-1] = i-1;
        }
    } else {
        for(int i = 1; i < n; i++)
            par[i-1] = rnd.next(1, i);
    }
    return par;
}

vector<pair<int, int>> TreeEdges(int n, string tr) {
    vector<int> par = Tree(n, tr);
    vector<pair<int, int>> edges;
    for(int i = 0; i < n-1; i++)
        edges.push_back({i+2, par[i]});
    vector<int> p(n);
    for(int i = 0; i < n; i++)
        p[i] = i;
    shuffle(all(p));
    for(auto &[u, v]: edges) {
        if(coin())
            swap(u, v);
        u = p[u-1]+1;
        v = p[v-1]+1;
    }
    shuffle(all(edges));
    return edges;
}

////////////////////////// Number Theory //////////////////////////

inline bool isPrime(int n) {
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return false;
    return true;
}

inline int Prime(int n, int cnt_maxer = 0) {
    int p = rnd.wnext(1, n, cnt_maxer);
    while(!isPrime(p))
        p = rnd.wnext(1, n, cnt_maxer);
    return p;
}

vector<int> highest_composite = {
    1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 20160, 25200, 27720,
    45360, 50400, 55440, 83160, 110880, 166320, 221760, 277200, 332640, 498960, 554400, 665280, 720720, 1081080, 1441440, 2162160,
    2882880, 3603600, 4324320, 6486480, 7207200, 8648640, 10810800, 14414400, 17297280, 21621600, 32432400, 36756720, 43243200, 
    61261200, 73513440, 110270160, 122522400, 147026880, 183783600, 245044800, 294053760, 367567200, 551350800, 698377680, 735134400
};

vector<int> cohighest_composite = {
    6, 8,   60, 72, 84, 90, 96,    840,    7560, 9240,    83160, 98280,    720720, 831600, 942480, 982800, 997920, 
    8648640,    73513440, 82162080, 86486400, 91891800, 98017920, 99459360,    735134400, 821620800, 931170240, 994593600
};

inline ll HighlyComposite(ll n, double step = 3.13) {
    ll res = 1LL;
    for(double i = 1.0+step; (ll) i*res <= n; i += step)
        res *= rnd.next(1LL, (ll) i);
    res *= n/res;
    return res;
}


int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    

    return 0;
}
