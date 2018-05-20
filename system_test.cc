/* Collin Clark, Colby Banbury
 * test file
 */

#include <iostream>
#include <assert.h>
#include "system.h"

void test(System *system);

int main(){
  System *system = new System(0,100,12,4);
  test(system);
  return 0;
}

void test(System *system){
  system->jump_to_time(3);
  system->submit(new Job(3, 1, 120, 5, 10, 1));
  system->jump_to_time(4);
  system->submit(new Job(4, 2, 70, 2, 12, 2));
  system->jump_to_time(5);
  system->submit(new Job(5, 3, 100, 8, 4, 1));
  system->jump_to_time(7);
  system->submit(new Job(7, 4, 1000, 5, 12, 2));
  system->jump_to_time(8);
  system->submit(new Job(8, 5, 10, 8, 4, 1));
  system->jump_to_time(26);
}

