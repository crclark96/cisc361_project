/* Collin Clark, Colby Banbury
 * system class implementation
 */

#include "system.h"

System::System(int time,
               int memory,
               int devices,
               int quantum){
  this->time = time;
  this->memory = memory;
  this->devices = devices;
  this->quantum = quantum;
}

int System::get_time(){return this->time;}
int System::get_memory(){return this->memory;}
int System::get_devices(){return this->devices;}
int System::get_quantum(){return this->quantum;}
void System::set_time(int time){this->time = time;}
void System::set_memory(int memory){this->memory = memory;}
void System::set_devices(int devices){this->devices = devices;}
void System::set_quantum(int quantum){this->quantum = quantum;}

