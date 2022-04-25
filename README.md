# HW10: TSP Project Part 2 (GA Search)
By [Vaughn Zaayer](https://github.com/vaughnzaayer) and [Yik Yin Cheuk](https://github.com/ycheuk)
<br />
**Note**: If you see the user "AnastasiyaV" it's me (Yik Yin)!! It's just my laptop / English name that nobody knows about!
## chromosome.hh
- No changes were made thus far...
## chromosome.cc
### is_valid()
- "Hey Eitan, can you look at this for us?" - Vaughn
- *Looks for a mere half a second*
- "Well, your code is about 15 lines too long." - Eitan
- We shortened the code, hopefully, to Eitan's expectations lol. 
- Uses a for loop to check every city in the order vector. 
### get_fitness()
- Used the `calculate_total_distance()` method from the Chromosome class, which uses the `total_path_distance()` method from the Cities class.
### Constructor and Destructor
- No changes were made thus far...
### mutate()
- We firstly define the range, and then run through the `is_valid()` method.
### recombine()
- Firstly, run through the `is_valid()` method.
- We included `size()` since the `create_crossover_child()` method takes index1 and index2.
- Pick 2 random indexs, make the children, and return the children!
## deme.hh
- No changes were made thus far...
## deme.cc
### Constructor and Destructor
- No changes were made thus far...
### get_best()
- First checks if there are elements, if not, returns an error. 
- Uses a for loop to find the chromosome with the highest fitness by using the `get_fitness()` method.
### select_parent()
- Firstly, we calculated the total sum of fitness in pop_ using lambda. 
- We then picked a random fitness sum value. 
- Lastly, we find the first chromosome whose sum exeeds the threshold. 
### compute_next_generation()
- Uses a for loop to do the main calculation. 
- Two chromosomes is randomly selected, with probability `mut_rate`, then mutated using the `mutate()` method. 
- Then, the pair is recombined using the `recombine()` method. 
- The second for loop deletes the old population. 
- Finally, swaps with the `newPop`.
