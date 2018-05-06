/* Collin Clark, Colby Banbury
 * intake function
 */

#include <iostream>
#include <fstream>
#include <string>

void process_config(std::string line);
void process_arrival(std::string line);
void process_request(std::string line);
void process_release(std::string line);
void process_display(std::string line);

int main(int argc, const char* argv[]){
  if(argc != 2){
    std::cout << "usage: ./intake <filename>" << std::endl;
    return 1;
  }

  std::ifstream fh(argv[1]);
  std::string line;

  while(getline(fh, line)){
    switch((char)line[0]){
    case 'C' :
      process_config(line);
      break;
    case 'A' :
      process_arrival(line);
      break;
    case 'Q' :
      process_request(line);
      break;
    case 'L' :
      process_release(line);
      break;
    case 'D' :
      process_display(line);
      break;
    default:
      std::cout << "invalid instruction: " << line << std::endl;
      return 1;
    }
  }

  return 0;
}

void process_config(std::string line){
  std::cout << "config " << line << std::endl;
}
void process_arrival(std::string line){
  std::cout << "arrival " << line << std::endl;
}
void process_request(std::string line){
  std::cout << "request " << line << std::endl;
}
void process_release(std::string line){
  std::cout << "release " << line << std::endl;
}
void process_display(std::string line){
  std::cout << "display " << line << std::endl;
}
