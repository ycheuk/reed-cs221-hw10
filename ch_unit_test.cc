#include<iostream>
#include<cassert>
#include<string>
#include<random>

#include"cities.hh"
#include"chromosome.hh"


// Generates random 5-city Cities objects for testing
Cities* gen_random_cities() {
	std::vector<std::pair<int, int>> city_list;
	Cities::coord_t city;
	for(int i = 0; i < 20; i++){
		city.first = std::rand() % 100;
		city.second = std::rand() % 100;
		city_list.push_back(city);
	}
	Cities* rtn_ptr = new Cities(city_list);
	return(rtn_ptr);
}

void print_chromosome_ordering(Chromosome& chromosome) {
	auto ordering = chromosome.get_ordering();

	std::cout << "CITY ORDERING: ";

	for(auto city : ordering) {
		std::cout << city << " ";
	}
	std::cout << std::endl;
}






int main() {

	Cities* test_cities = gen_random_cities();

	// Print out cities order

	std::cout << "CITIES\n" << *test_cities << std::endl;


	// Create a new chromosome w/ test_cities
	Chromosome* test_chromosome1 = new Chromosome(test_cities);
	
	// Look at current chromosome1 ordering
	print_chromosome_ordering(*test_chromosome1);



	// Create a second chromosome w/ test_cities
	Chromosome* test_chromosome2 = new Chromosome(test_cities);

	// Look at current chromosome2 ordering
	print_chromosome_ordering(*test_chromosome2);


/////////////////////////////////////////////////////////////////////////////////
	// Test total distance
	std::cout << test_chromosome1 -> calculate_total_distance() << std::endl;

	// Test mutation
	test_chromosome1 -> mutate();
	print_chromosome_ordering(*test_chromosome1);
	std::cout << "FITNESS RATING: " << test_chromosome1 -> get_fitness() << std::endl;

	// Perform crossover test
	std::pair test_children = test_chromosome1 -> recombine(test_chromosome2);
	print_chromosome_ordering(*test_children.first);
	print_chromosome_ordering(*test_children.second);
	std::cout << "FITNESS RATING: " << test_children.first -> get_fitness() << std::endl;
	std::cout << "FITNESS RATING: " << test_children.second -> get_fitness() << std::endl;



	return 0;
}