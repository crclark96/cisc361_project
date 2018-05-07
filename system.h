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
    tot_mem,
    avail_mem,
    tot_dev,
    avail_dev,
    quantum;

  std::queue<Job> sub_q;
  std::queue<Job> hold_q1;
  std::queue<Job> hold_q2;

  std::queue<Process> ready_q;
  std::queue<Process> wait_q;
  std::queue<Process> complete_q;
  
 public:
  System(int time,
         int tot_mem,
         int tot_dev,
         int quantum);
  int get_time();
  int get_tot_mem();
  int get_avail_mem();
  int get_tot_dev();
  int get_avail_dev();
  int get_quantum();
  void set_time(int time);
  void set_avail_dev(int devices);
  void set_avail_mem(int memory);

  void submit(Job *job);
  void update();
  void status();
  void request(int time, int job_num, int dev);
  void release(int time, int job_num, int dev);
  
};

#endif
