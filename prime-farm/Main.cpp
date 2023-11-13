#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#define INT unsigned long long int

std::vector<INT> loadPrimes() {
	std::vector<INT> primes;
	std::ifstream stream("primes.txt");
	std::string line;

	while (getline(stream, line)) {
		primes.push_back(std::stoull(line));
	}


	if (primes.size() == 0) {
		std::cout << "Primes Database was empty\n";
		return std::vector<INT>({ 2 });
	}

	std::cout << "Loaded primes till " << primes[primes.size()-1] << "\n";
	return primes;
}

int main() {
	std::vector<INT> primes = loadPrimes();
	std::ofstream stream("primes.txt");

	for (const INT& previousPrimes : primes) {
		stream << previousPrimes << "\n";
	}

	INT i = primes[primes.size()-1];
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
		i++;
		if (i % 50000 == 0) {
			stream.flush();
		}
		if (i % 100000 == 0) {
			std::cout << "Reached " << i << "\n";
		}
	}

	return 0;
}