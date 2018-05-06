/* Collin Clark, Colby Banbury
 * system class declaration
 */

#ifndef _SYSTEM_H
#define _SYSTEM_H

class System {
  int time,
    memory,
    devices,
    quantum;

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

};

#endif
