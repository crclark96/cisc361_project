/* Collin Clark, Colby Banbury
 * process class implementation
 */

#include "process.h"
#include "job.h"

Process::Process(Job *job){
  this->job = job;
  this->alloc_dev = 0;
  this->elap_time = 0;
}

void Process::set_alloc_dev(int dev){this->alloc_dev = dev;}
void Process::set_elap_time(int time){this->elap_time = time;}
int Process::get_alloc_dev(){return this->alloc_dev;}
int Process::get_elap_time(){return this->elap_time;}
int Process::get_arr_time(){return this->job->get_arr_time();}
int Process::get_job_num(){return this->job->get_job_num();}
int Process::get_mem_req(){return this->job->get_mem_req();}
int Process::get_max_dev(){return this->job->get_max_dev();}
int Process::get_run_time(){return this->job->get_run_time();}
int Process::get_priority(){return this->job->get_priority();}

