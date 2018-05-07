/* Collin Clark, Colby Banbury
 * process class declaration
 */

#ifndef _PROCESS_H
#define _PROCESS_H

#include "job.h"

class Process{
  Job job;
  int alloc_dev,
    elap_time;

 public:
  Process(Job job);
  
};

#endif
