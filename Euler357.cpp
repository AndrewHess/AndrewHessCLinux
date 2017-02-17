/*
	Euler357.cpp
	Andrew Hess
	2/6/2017
	Find the sum of each positive integer n less than 100,000,000 for which 
	n + n/d is prime for each divisor d of n.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<int>> factors(int n, vector<int> primes) {
	vector<vector<int>> f;

	for (int i = 0; i < primes.size(); i++) {
		int p = primes[i];
		if (n % p == 0) {
			vector<int> factor = {p, 0};
			while (n % p == 0) {
				n/= p;
				factor[1]++;
			}

			f.push_back(factor);
		}
	}

	return f;
}

void divisors(int ind, int exp, int cur, vector<vector<int>> factors, vector<int> *divs) {
	if (ind >= factors.size()) divs->push_back(cur);
	else if (exp >= factors[ind][1]) divisors(ind +1, 0, cur, factors, divs);
	else {
		divisors(ind, exp +1, cur * factors[ind][0], factors, divs);
		divisors(ind +1, 0, cur, factors, divs);
	}
}

int solve(long cur, vector<int> primes, vector<bool> p, int ind) {
	long sum = 0;

	if (cur * primes[ind] < 0) return sum;
	if (ind >= primes.size() || cur * primes[ind] > pow(10, 5)) {
		if (cur +1 >= p.size()) {
			cout << "cur: " << cur << endl;
			return sum;
		}
		if (p[cur +1]) {
			bool ok = true;

			vector<int> divs;
			divisors(0, 0, 1, factors(cur, primes), &divs);

			for (int k = 0; k < divs.size() && ok; k++) {
				if (!p[divs[k] + cur/divs[k]]) ok = false; //binary(divs[k] + n/divs[k], primes) == -1) ok = false;
			}

			if (ok) sum += cur;
			else cout << "\t\t\t\t\t";

			cout << cur << ": ";
			for (vector<int> f : factors(cur, primes)) cout << f[0] << ", "; // << "^" << f[1] << ", ";
			cout << endl;
		}
	}
	else {
		sum += solve(cur * primes[ind],	primes, p, ind +1);
		sum += solve(cur,		primes, p, ind +1);
	}

	return sum;
}

int main() {
	int sum = 0;
	
	// generate prime numbers
	vector<bool> p(pow(10, 5) + 2);

	for (int i = 0; i < p.size(); i++) p[i] = true;
	p[0] = false;
	p[1] = false;

	for (int i = 2; i <= sqrt(p.size()); i++) 
		if (p[i]) 
			for (int k = i*i; k < p.size(); k += i) p[k] = false;

	int count = 0;
	for (bool b : p) if (b) count++;

	vector<int> primes(count);
	int ind = 0;
	for (int i = 0; i < p.size(); i++)
		if (p[i]) primes[ind++] = i;

	cout << "found " << count << " primes" << endl;

	sum = solve(1, primes, p, 0);
	cout << "Answer: " << sum << endl;
	cout << sum << endl;

	return 0;
}
