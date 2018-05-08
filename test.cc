/* Collin Clark, Colby Banbury
 * test file
 */

#include <iostream>
#include <assert.h>
#include "system.h"

void system_status_test();
void system_getter_test();

int main(){
  system_status_test();
  system_getter_test();
  return 0;
}

void system_status_test(){
  System *system = new System(0,15,15,2);
  system->submit(new Job(1,1,4,3,77,1));
  system->submit(new Job(2,2,16,1,1,2));
  system->submit(new Job(3,3,1,1,1,2));
  system->status();
}

void system_getter_test(){
  int time = 0;
  int mem = 15;
  int dev = 13;
  int qnt = 2;
  System *system = new System(time,mem,dev,qnt);
  assert(system->get_time()==time);
  assert(system->get_tot_mem()==mem);
  assert(system->get_tot_dev()==dev);
  assert(system->get_avail_mem()==mem);
  assert(system->get_avail_dev()==dev);
  assert(system->get_quantum()==qnt);
  time++;
  mem--;
  dev--;
  system->set_time(time);
  system->set_avail_mem(mem);
  system->set_avail_dev(dev);
  assert(system->get_avail_dev()==dev);
  assert(system->get_time()==time);
  assert(system->get_avail_mem()==mem);
  
}

