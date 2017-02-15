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

int binary(int key, vector<int> primes) {
	int low = 0;
	int big = primes.size() -1;
	int mid = (low + big)/2;

	while (low <= big) {
		int val = primes[mid];
		if (val < key) low = mid +1;
		else if (val > key) big = mid -1;
		else return mid;

		mid = (low + big)/2;
	}

	return -1;
}

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

void possible(int cur, vector<int> *primes, vector<bool> *p, int ind, vector<int> *posib) {
	if (cur > pow(10, 5)) return;
	else if (ind >= primes->size()) {
		if (p->at(cur +1)) posib->push_back(cur);
	}
	else {
		possible(cur * primes->at(ind),	primes, p, ind +1, posib);
		possible(cur,			primes, p, ind +1, posib);
	}
}

int main() {
	int sum = 0;
	
	// generate prime numbers
	vector<bool> p(pow(10, 5) + 1);

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
	cout << "size: " << (&primes)->size() << endl;
	cout << "size: " << primes.size() << endl;

	vector<int> posib;
	posib.push_back(1);
	cout << "finding possible" << endl;
	possible(2, &primes, &p, 1, &posib);
	sort(posib.begin(), posib.end());
	cout << "got " << posib.size() << " possible" << endl;
//	for (int i : posib) cout << i << endl;

	for (int n : posib) {
		bool ok = true;

		vector<int> divs;
		divisors(0, 0, 1, factors(n, primes), &divs);

		for (int k = 0; k < divs.size() && ok; k++) {
			if (binary(divs[k] + n/divs[k], primes) == -1) ok = false;
		}

		if (ok) sum += n;
		else cout << "\t\t\t\t\t";

		sum += n;
		cout << n << ": ";
		for (vector<int> f : factors(n, primes)) cout << f[0] << ", "; // << "^" << f[1] << ", ";
		cout << endl;
	}

/*
	for (int i = 0; i < primes.size(); i++) {
		int n = primes[i] -1;
		bool ok = true; //(n%10 == 0 || n%10 == 2 || n%10 == 8); 
		
		vector<int> divs;
		divisors(0, 0, 1, factors(n, primes), &divs);

		for (int k = 0; k < divs.size() && ok; k++) {
			if (binary(divs[k] + n/divs[k], primes) == -1) ok = false;
		}

		if (ok) {
			sum += n;
			cout << n << ": ";
			for (vector<int> f : factors(n, primes)) cout << f[0] << ", "; // "^" << f[1] << ", ";
			cout << endl;
		}
	}
*/
	cout << sum << endl;

	return 0;
}
