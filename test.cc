/* Collin Clark, Colby Banbury
 * test file
 */

#include <iostream>
#include "system.h"

int main(void){
  System *system = new System(0,15,15,2);
  system->submit(new Job(1,1,4,3,77,1));
  system->submit(new Job(2,2,16,1,1,2));
  system->submit(new Job(3,3,1,1,1,2));
  system->status();
}
