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

	while (getline(stream, line)) {
		try {
		auto val = std::stoull(line);
		primes.push_back(val);
		} catch (const std::invalid_argument& _e) {}
	}

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

	INT i = primes[primes.size() - 1];
	INT last_prime = i;
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
			last_prime = i;
			primes.push_back(i);
			stream << i << "\n";
		}
		i += 2;
		iter++;
		if (iter == 1000) { std::cout << "Reached " << last_prime << "\n"; }
		if (iter == 5000) {
			stream.flush();
			iter = 0;
		}
	}

	return 0;
}