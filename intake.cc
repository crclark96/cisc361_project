/* Collin Clark, Colby Banbury
 * intake function
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

std::vector<std::string> parse(std::string);
void process_config(std::vector<std::string>);
void process_arrival(std::vector<std::string>);
void process_request(std::vector<std::string>);
void process_release(std::vector<std::string>);
void process_display(std::vector<std::string>);

int main(int argc, const char* argv[]){
  if(argc != 2){
    std::cout << "usage: ./intake <filename>" << std::endl;
    return 1;
  }

  std::ifstream fh(argv[1]);
  std::string line;

  while(getline(fh, line)){
    std::vector<std::string> split_line = parse(line);
    switch((char)line[0]){
    case 'C' :
      process_config(split_line);
      break;
    case 'A' :
      process_arrival(split_line);
      break;
    case 'Q' :
      process_request(split_line);
      break;
    case 'L' :
      process_release(split_line);
      break;
    case 'D' :
      process_display(split_line);
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

void process_config(std::vector<std::string> split_line){

  std::cout << "config " << std::endl;
}
void process_arrival(std::vector<std::string> split_line){
  std::cout << "arrival " << std::endl;
}
void process_request(std::vector<std::string> split_line){
  std::cout << "request " << std::endl;
}
void process_release(std::vector<std::string> split_line){
  std::cout << "release " << std::endl;
}
void process_display(std::vector<std::string> split_line){
  std::cout << "display " << std::endl;
}
