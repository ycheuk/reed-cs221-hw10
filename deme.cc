/*
 * Declarations for Deme class to evolve a genetic algorithm for the
 * travelling-salesperson problem.  A deme is a population of individuals.
 */

#include "chromosome.hh"
#include "deme.hh"

// Generate a Deme of the specified size with all-random chromosomes.
// Also receives a mutation rate in the range [0-1].
Deme::Deme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
{
  // Add your implementation here
}

// Clean up as necessary
Deme::~Deme()
{
  for (auto c : pop_){
    delete c;
  }
}

// Evolve a single generation of new chromosomes, as follows:
// We select pop_size/2 pairs of chromosomes (using the select() method below).
// Each chromosome in the pair can be randomly selected for mutation, with
// probability mut_rate, in which case it calls the chromosome mutate() method.
// Then, the pair is recombined once (using the recombine() method) to generate
// a new pair of chromosomes, which are stored in the Deme.
// After we've generated pop_size new chromosomes, we delete all the old ones.
void Deme::compute_next_generation()
{
  auto newPop = pop_;
  
  for (unsigned 1 = 0; i < pop_.size();){
    auto parent1 = select_parent();
    auto parent2 = select_parent();
    
    static std::uniform_real_distribution<double> dist(0.0, 1.0);
    if (dist(generator_) <= mut_rate_) {
      parent1->mutate();
    }
    if (dist(generator_) <= mut_rate_) {
      parent2->mutate();
    }
    
    auto offspring = parent1->recombin(parent2);
    newPop.push_back(offspring.first);
    newPop.push_back(offspring.second);
    
    i++;
  }
  for (auto c : pop_) {
    delete c;
  }
  std::swap(pop_, newPop);
}

// Return a copy of the chromosome with the highest fitness.
const Chromosome* Deme::get_best() const
{
  assert(pop_.size());
  Chromosome* theBest = pop_[0];
  for (auto cp1 : pop_){
    if (cp1->get_fitness() > best->get_fitness(){
      theBest = cp1;
    }
  }
  return theBest;
}

// Randomly select a chromosome in the population based on fitness and
// return a pointer to that chromosome.
Chromosome* Deme::select_parent()
{
  static std::uniform_real_distribution<double> dist(0.0, 1);
}
