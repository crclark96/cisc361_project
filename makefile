CC = g++
OBJS = system.o job.o process.o

default: intake.o

test: test.o $(OBJS)
	$(CC) $^ -o test

%.o: %.cc %.h
	$(CC) -c $<

clean:
	rm *.o
