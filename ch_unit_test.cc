#include<iostream>
#include<cassert>
#include<string>
#include<random>

#include"cities.cc"
#include"cities.hh"
#include"chromosome.cc"
#include"chromosome.hh"


// Generates random 5-city Cities objects for testing
Cities* gen_random_cities() {
	Cities* rtn_cities;
	for(int i; i < 10; i++){
		(std::rand() % 100) >> *rtn_cities;
	}

	return(rtn_cities);
}






int main() {

	std::ifstream input_file;
	input_file.open("five.tsv");
	assert(input_file.is_open());

	Cities* test_cities = new Cities();

	input_file >> *test_cities;

	input_file.close();

	// Create a new chromosome w/ test_cities

	Chromosome* test_chromosome = new Chromosome(test_cities);

	// Test is_valid()
	std::cout << test_chromosome -> calculate_total_distance() << std::endl;


	delete(test_cities);

	return 0;
}