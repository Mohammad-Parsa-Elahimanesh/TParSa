#include "testlib.h"

using namespace std;
typedef long long ll;

ll dfs(ll v, ll d, const vector<vector<ll>> &tr) {
    ll s = 1;
    for(auto u: tr[v])
        if(u != d)
            s += dfs(u, v, tr);
    return s;
}

inline vector<vector<ll>> ReadTree(int n, ll ind = 1) {
    vector<vector<ll>> tr(n);
    for(int i = 1; i < n; i++) {
        ll u = inf.readLong(ind, ind+n-1, "u")-ind;
        inf.readSpace();
        ll v = inf.readLong(ind, ind+n-1, "v")-ind;
        inf.readEoln();
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    ensure(dfs(0,0,tr) == n);
    return tr;
}

// read n numbers in one line in range [a, b] inclusive.
inline vector<ll> GetIntList(size_t n, ll l, ll r, string name = "arr") {
    vector<ll> arr = inf.readLongs((int) n, l, r, name);
    inf.readEoln();
    return arr;
}

inline vector<ll> GetIntList(size_t n, string name = "arr") {
    return GetIntList(n, LONG_LONG_MIN, LONG_LONG_MAX, name);
}

inline ll ReadInt(ll l, ll r, string name = "n") {
    ll res = inf.readLong(l, r, name);
    inf.readEoln();
    return res;
}

inline ll ReadInt(string name = "n") {
    return ReadInt(LONG_LONG_MIN, LONG_LONG_MAX, name);
}

vector<ll> GetIntList(ll ln, ll rn, ll la, ll ra, string arrName = "arr", string lengthName = "n") {
    return GetIntList(ReadInt(ln, rn, lengthName), la, ra, arrName);
}

inline void CheckSorted(const vector<ll> &arr) {
    ensuref(is_sorted(arr.begin(), arr.end()), "Array must be sorted.");
}

inline void CheckUnique(vector<ll> &arr) {
    ensuref(unique(arr.begin(), arr.end()) == arr.end(), "Array must be unique.");
}

inline string word(string name = "s") {
    string s = inf.readToken("[a-z]+", name);
    inf.readEoln();
    return s;
}

inline string word(size_t l, size_t r, string name = "s") {
    string s = word(name);
    ensuref(l <= s.size() and s.size() <= r, "String size does not match.");
    return s;
}

inline string word(size_t n, string name = "s") {
    return word(n, n, name);
}

inline string Word(string name = "s") {
    string s = inf.readToken("[A-Za-z]+", name);
    inf.readEoln();
    return s;
}

inline string Word(size_t l, size_t r, string name = "s") {
    string s = Word(name);
    ensuref(l <= s.size() and s.size() <= r, "String size does not match.");
    return s;
}

inline string Word(size_t n, string name = "s") {
    return Word(n, n, name);
}


int main(int argc, char** argv) {
    registerValidation(argc, argv);
    


    inf.readEof();
    return 0;
}
