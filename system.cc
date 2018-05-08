/* Collin Clark, Colby Banbury
 * system class implementation
 */

#include <iostream>
#include <iomanip>
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

  this->sub_q = new std::list<Job*>();
  this->hold_q1 = new std::list<Job*>();
  this->hold_q2 = new std::list<Job*>();
  this->ready_q = new std::list<Process*>();
  this->wait_q = new std::list<Process*>();
  this->complete_q = new std::list<Process*>();
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

bool sort_hold_q1(Job *job1, Job *job2){
  if(job1->get_run_time() == job2->get_run_time()){
    return job1->get_arr_time() < job2->get_arr_time();  // SJF
  } else {
    return job1->get_run_time() < job2->get_run_time();  // FIFO
  }
}

bool sort_hold_q2(Job *job1, Job *job2){
  return job1->get_arr_time() < job2->get_arr_time();  // FIFO
}

void System::submit(Job *job){
  if(job->get_mem_req() > this->get_tot_mem() ||
     job->get_max_dev() > this->get_tot_dev()){
    std::cout << "job rejected: insufficient system resources" << std::endl;
  } else if(job->get_mem_req() > this->get_avail_mem()) {
    switch(job->get_priority()){
    case 1:
      this->hold_q1->push_back(job);
      this->hold_q1->sort(sort_hold_q1);
      break;
    case 2:
      this->hold_q2->push_back(job);
      this->hold_q2->sort(sort_hold_q2);
      break;
    }
  } else {
    this->ready_q->push_back(new Process(job));
  }
}

void System::request(int time, int job_num, int dev){
  std::cout << "request at " << time << " by " << job_num << " for " << dev << " devices" << std::endl;
}

void System::release(int time, int job_num, int dev){
  std::cout << "release at " << time << " by " << job_num << " of " << dev << " devices" << std::endl;
}


//GO NO FURTHER
void System::status(){

  std::cout << "---------- System Information ----------"
            << std::endl;
  std::cout << "time: " << this->get_time() << std::endl;
  std::cout << "mem : " << this->get_avail_mem() << std::endl;
  std::cout << "dev : " << this->get_avail_dev() << std::endl;
  std::cout << std::endl;


  std::cout << "------------- Hold Queue 1 -------------"
            << std::endl;
  std::cout << "Job # | Arr | Mem | Dev | Run | Pri "
            << std::endl;
  std::cout << "------------------------------------"
            << std::endl;
  std::list<Job*>::iterator it1;
  for(it1=hold_q1->begin();it1!=hold_q1->end();it1++){
    std::cout << std::setw(6)
              << (*it1)->get_job_num()
              << "|";
    std::cout << std::setw(5)
              << (*it1)->get_arr_time()
              << "|";
    std::cout << std::setw(5)
              << (*it1)->get_mem_req()
              << "|";
    std::cout << std::setw(5)
              << (*it1)->get_max_dev()
              << "|";
    std::cout << std::setw(5)
              << (*it1)->get_run_time()
              << "|";
    std::cout << std::setw(5)
              << (*it1)->get_priority()
              << std::endl;
  }


  std::cout << "------------- Hold Queue 2 -------------"
            << std::endl;
  std::cout << "Job # | Arr | Mem | Dev | Run | Pri "
            << std::endl;
  std::cout << "------------------------------------"
            << std::endl;
  for(it1=hold_q2->begin();it1!=hold_q2->end();it1++){
    std::cout << std::setw(6)
              << (*it1)->get_job_num()
              << "|";
    std::cout << std::setw(5)
              << (*it1)->get_arr_time()
              << "|";
    std::cout << std::setw(5)
              << (*it1)->get_mem_req()
              << "|";
    std::cout << std::setw(5)
              << (*it1)->get_max_dev()
              << "|";
    std::cout << std::setw(5)
              << (*it1)->get_run_time()
              << "|";
    std::cout << std::setw(5)
              << (*it1)->get_priority()
              << std::endl;
  }


  std::cout << "------------- Ready Queue --------------"
            << std::endl;
  std::cout << "Job # | Arr | Mem | MDev | Run | Pri | ADev "
            << std::endl;
  std::cout << "------------------------------------------- "
            << std::endl;
  std::list<Process*>::iterator it2;
  for(it2=ready_q->begin();it2!=ready_q->end();it2++){
    std::cout << std::setw(6)
              << (*it2)->get_job_num()
              << "|";
    std::cout << std::setw(5)
              << (*it2)->get_arr_time()
              << "|";
    std::cout << std::setw(5)
              << (*it2)->get_mem_req()
              << "|";
    std::cout << std::setw(6)
              << (*it2)->get_max_dev()
              << "|";
    std::cout << std::setw(5)
              << (*it2)->get_run_time()
              << "|";
    std::cout << std::setw(5)
              << (*it2)->get_priority()
              << "|";
    std::cout << std::setw(6)
              << (*it2)->get_alloc_dev()
              << std::endl;
  }


    std::cout << "------------- Wait Queue ---------------"
            << std::endl;
  std::cout << "Job # | Arr | Mem | MDev | Run | Pri | ADev "
            << std::endl;
  std::cout << "------------------------------------------- "
            << std::endl;
  for(it2=wait_q->begin();it2!=wait_q->end();it2++){
    std::cout << std::setw(6)
              << (*it2)->get_job_num()
              << "|";
    std::cout << std::setw(5)
              << (*it2)->get_arr_time()
              << "|";
    std::cout << std::setw(5)
              << (*it2)->get_mem_req()
              << "|";
    std::cout << std::setw(6)
              << (*it2)->get_max_dev()
              << "|";
    std::cout << std::setw(5)
              << (*it2)->get_run_time()
              << "|";
    std::cout << std::setw(5)
              << (*it2)->get_priority()
              << "|";
    std::cout << std::setw(6)
              << (*it2)->get_alloc_dev()
              << std::endl;
  }


    std::cout << "------------- Complete Queue -----------"
            << std::endl;
  std::cout << "Job # | Arr | Mem | MDev | Run | Pri | ADev "
            << std::endl;
  std::cout << "------------------------------------------- "
            << std::endl;
  for(it2=complete_q->begin();it2!=complete_q->end();it2++){
    std::cout << std::setw(6)
              << (*it2)->get_job_num()
              << "|";
    std::cout << std::setw(5)
              << (*it2)->get_arr_time()
              << "|";
    std::cout << std::setw(5)
              << (*it2)->get_mem_req()
              << "|";
    std::cout << std::setw(6)
              << (*it2)->get_max_dev()
              << "|";
    std::cout << std::setw(5)
              << (*it2)->get_run_time()
              << "|";
    std::cout << std::setw(5)
              << (*it2)->get_priority()
              << "|";
    std::cout << std::setw(6)
              << (*it2)->get_alloc_dev()
              << std::endl;
  }
  
}
