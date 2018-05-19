/* Collin Clark, Colby Banbury
 * Banker's algorithm test
 * 
 */

#include "system.h"
#include <iostream>

int main(int argc, const char* argv[]){
  System* system = new System(1, 200, 12, 4); //the initial values of the test

  std::cout << "first test" << std::endl;

  system->is_safe(); //test safe with no jobs

  system->jump_to_time(3);
  system->submit(new Job(3, 1, 20, 5, 10, 1));

  system->jump_to_time(4);
  system->submit(new Job(4, 2, 30, 2, 12, 2));

  system->jump_to_time(9);
  system->submit(new Job(9, 3, 10, 8, 4, 1));

  std::cout << "second test" << std::endl;

  system->is_safe();

  system->jump_to_time(10);
  system->submit(new Job(10, 4, 20, 5, 10, 1));

  system->jump_to_time(11);
  system->submit(new Job(11, 5, 30, 2, 12, 2));

  system->jump_to_time(12);
  system->submit(new Job(12, 6, 10, 8, 4, 1));

  system->is_safe();

  system->jump_to_time(13);
  system->submit(new Job(13, 7, 40, 8, 4, 1));

  system->jump_to_time(14);
  system->submit(new Job(14, 8, 40, 8, 4, 1));

  system->is_safe();

  system->status();

}