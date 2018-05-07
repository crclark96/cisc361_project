/* Collin Clark, Colby Banbury
 * system class implementation
 */

#include <iostream>
#include "system.h"

System::System(int time,
               int tot_mem,
               int tot_dev,
               int quantum){
  this->time = time;
  this->tot_mem = tot_mem;
  this->avail_mem = tot_mem;
  this->tot_dev = tot_dev;
  this->avail_dev = tot_dev;
  this->quantum = quantum;
}

int System::get_time(){return this->time;}
int System::get_tot_mem(){return this->tot_mem;}
int System::get_avail_mem(){return this->avail_mem;}
int System::get_tot_dev(){return this->tot_dev;}
int System::get_avail_dev(){return this->avail_dev;}
int System::get_quantum(){return this->quantum;}
void System::set_time(int time){this->time = time;}
void System::set_avail_mem(int memory){this->avail_mem = memory;}
void System::set_avail_dev(int devices){this->avail_dev = devices;}

void System::submit(Job *job){
  if(job->get_mem_req() > this->get_tot_mem()){
    std::cout << "job rejected: insufficient system memory" << std::endl;
  } else if(job->get_mem_req() > this->get_avail_mem()) {
    std::cout << "job queued" << std::endl;
  } else {
    std::cout << "job running" << std::endl;
  }
  
}

