/*
	357.cpp
	Andrew Hess
	Project Euler problem 357
	2/21/2017
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<bool> p(pow(10, 6) +1);
vector<int> primes;

void divisors(vector<int> *factors, int ind, long cur, vector<int> *divs, long num) {
	if (ind >= factors->size() || pow(cur * factors->at(ind), 2) > num) {
		divs->push_back(cur);
		return;
	}
	else {
		divisors(factors, ind +1, cur, divs, num);
		divisors(factors, ind +1, cur * factors->at(ind), divs, num);
	}
}

int solve(long cur, int ind, vector<int> *factors) {
	int sum = 0;

	if (ind >= primes.size() || cur * primes[ind] >= p.size() || cur * primes[ind] < 0) {
		if (cur * primes[ind] >= p.size() || cur * primes[ind] < 0) cout << "overflow" << endl;
		if (cur * primes[ind] >= p.size() || cur * primes[ind] < 0 || !p[cur +1]) return 0;

		bool ok = true;
		vector<int> divs;
		divisors(factors, 0, 1, &divs, cur);

		for (int i : divs) {
			if (i + cur/i >= p.size()) {
				cout << "error" << endl;
				ok = false;
			}
			if (!p[i + cur/i]) {
				ok = false;
				break;
			}
		}

		if (ok) {
			sum += cur;
			cout << "ok: " << cur << endl;
		}
		else cout << "\t\tbad: " << cur << endl;
	}
	else {
		vector<int> copy(factors->size() +1);
		for (int i = 0; i < factors->size(); i++) copy[i] = factors->at(i);
		copy[factors->size()] = primes[ind];

		sum += solve(cur, ind +1, factors);
		sum += solve(cur * primes[ind], ind +1, &copy);
	}

	return sum;
}

int main() {
	p[0] = false;
	p[1] = false;
	for (int i = 2; i < p.size(); i++) p[i] = true;

	for (int i = 2; i < p.size(); i++) if (p[i]) 
		for (int k = i*i; k < p.size(); k += i) p[k] = false;

	for (int i = 0; i < p.size(); i++) if (p[i]) primes.push_back(i);

	cout << "found " << primes.size() << " primes under " << p.size() << endl;

	vector<int> factors;
	factors.push_back(2);

	int sum = solve(2, 1, &factors) +1;

	cout << "Answer: " << sum << endl;

	return 0;
}
