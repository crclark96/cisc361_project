/* Collin Clark, Colby Banbury
 * intake function
 * takes in the file and parse each line for the relavent information and makes the appropriate system calls
 * also creates the jobs that get sent into the system
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include "system.h"
#include "job.h"

std::vector<std::string> parse(std::string);
System* process_config(std::vector<std::string>);
Job* process_arrival(std::vector<std::string>);


int main(int argc, const char* argv[]){
  if(argc != 2){
    std::cout << "usage: ./intake <filename>" << std::endl;
    return 1;
  }

  std::ifstream fh(argv[1]);
  std::string line;
  System *system;
  Job *job_arrive;

  while(getline(fh, line)){
    std::vector<std::string> split_line = parse(line);

    switch((char)line[0]){
    case 'C' :
      system = process_config(split_line);
      break;
    case 'A' :
      job_arrive = process_arrival(split_line);
      if(job_arrive->get_mem_req() <= system->get_tot_mem()){
        system->submit(job_arrive);
      }
      else{
        std::cout << "job needs more memeory than system total" << std::endl;
      }
      break;
    case 'Q' :
      std::cout << "request " << std::endl;
      system->request(stoi(split_line[1]),
                      stoi(split_line[2].substr(2)),
                      stoi(split_line[3].substr(2)));
      break;
    case 'L' :
      std::cout << "release " << std::endl;
      system->release(stoi(split_line[1]),
                      stoi(split_line[2].substr(2)),
                      stoi(split_line[3].substr(2)));
      break;
    case 'D' :
      std::cout << "display " << std::endl;
      system->status();
      if(split_line[1] == "9999"){
        //Dump the final state. TODO
        std::cout << "end of input file. Dumping final state " << std::endl;
      }
      break;
    default:
      std::cout << "invalid instruction: " << line << std::endl;
      return 1;
    }
  }

  return 0;
}

std::vector<std::string> parse(std::string input){
  std::istringstream iss(input);
  std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());
  return results;
}

System* process_config(std::vector<std::string> split_line){
  std::cout << "config " << std::endl;
  return new System(stoi(split_line[1]), 
                      stoi(split_line[2].substr(2)),
                      stoi(split_line[3].substr(2)),
                      stoi(split_line[4].substr(2)));
}

Job* process_arrival(std::vector<std::string> split_line){
  std::cout << "arrival " << std::endl;
  return new Job(stoi(split_line[1]),
                stoi(split_line[2].substr(2)),
                stoi(split_line[3].substr(2)),
                stoi(split_line[4].substr(2)),
                stoi(split_line[5].substr(2)),
                stoi(split_line[6].substr(2))
                );
}