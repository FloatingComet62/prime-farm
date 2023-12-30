#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#define INT unsigned long long int
#define FILE "primes.txt"

std::vector<INT> loadPrimes() {
	std::vector<INT> primes;
	std::ifstream stream(FILE);
	std::string line;

	while (getline(stream, line)) { primes.push_back(std::stoull(line)); }

	if (primes.size() == 0) {
		std::cout << "Primes Database was empty\n";
		return std::vector<INT>({ 2, 3 });
	}

	return primes;
}

int main() {
	std::vector<INT> primes = loadPrimes();
	std::ofstream stream(FILE);

	for (const INT& previousPrimes : primes) { stream << previousPrimes << "\n"; }

	INT i = primes[primes.size()-1];
	unsigned short int iter = 0;
	std::cout << "Loaded primes till " << i << "\n";
	while (true) {
		bool isPrime = true;
		for (const INT& prime : primes) {
			if (i % prime == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			primes.push_back(i);
			stream << i << "\n";
		}
		i += 2;
		if (iter == 65000) {
			stream.flush();
			std::cout << "Reached " << i << "\n";
			iter = 0;
		}
	}

	return 0;
}