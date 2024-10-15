#include "testlib.h"

using namespace std;
typedef long long ll;

// read n numbers in one line in range [a, b] inclusive.
inline vector<ll> GetIntList(size_t n, ll l, ll r, string name = "arr[i]") {
	vector<ll> arr(n);
	for(size_t i = 0; i < n; i++) {
		arr[i] = inf.readLong(l, r, "arr[i]");
		if(i+1 == n)
			inf.readEoln();
		else
			inf.readSpace();
	}
	return arr;
}

inline vector<ll> GetIntList(size_t n, string name = "arr[i]") {
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

vector<ll> GetIntList(ll ln, ll rn, ll la, ll ra, string arrName = "arr[i]", string lengthName = "n") {
	return GetIntList(ReadInt(ln, rn, lengthName), la, ra, arrName);
}

inline void CheckSorted(const vector<ll> &arr) {
	ensuref(is_sorted(arr.begin(), arr.end()), "Array must be sorted.");
}

inline void CheckUnique(vector<ll> &arr) {
	ensuref(unique(arr.begin(), arr.end()) == arr.end(), "Array must be unique.");
}

inline string word() {
	string s = inf.readToken("[a-z]+");
	inf.readEoln();
	return s;
}

inline string word(size_t l, size_t r) {
	string s = word();
	ensuref(l <= s.size() and s.size() <= r, "String size does not match.");
}

inline string word(size_t n) {
	return word(1, n);
}

inline string Word() {
	string s = inf.readToken("[A-Za-z]+");
	inf.readEoln();
	return s;
}

inline string Word(size_t l, size_t r) {
	string s = Word();
	ensuref(l <= s.size() and s.size() <= r, "String size does not match.");
}

inline string Word(size_t n) {
	return Word(1, n);
}

// TODO: read and validate tree

int main() 
{
	registerValidation();
	


	inf.readEof();
	return 0;
}
