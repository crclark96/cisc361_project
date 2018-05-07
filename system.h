/* Collin Clark, Colby Banbury
 * system class declaration
 */

#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <queue>
#include "job.h"
#include "process.h"

class System {
  int time,
    memory,
    devices,
    quantum;

  std::queue<Job> sub_q;
  std::queue<Job> hold_q1;
  std::queue<Job> hold_q2;

  std::queue<Process> ready_q;
  std::queue<Process> wait_q;
  std::queue<Process> complete_q;
  
 public:
  System(int time,
         int memory,
         int devices,
         int quantum);
  int get_time();
  int get_memory();
  int get_devices();
  int get_quantum();
  void set_time(int time);
  void set_memory(int memory);
  void set_devices(int devices);
  void set_quantum(int quantum);

  void submit(Job job);
  void update();
  void status();
  void request(int time, int job_num, int dev);
  void release(int time, int job_num, int dev);
  
};

#endif
