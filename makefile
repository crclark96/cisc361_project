CC = g++
OBJS = system.o job.o process.o intake.o

default: intake.o

test: test.o $(OBJS)
	$(CC) $^ -o test

intake_test: intake.o $(OBJS)
	$(CC) $^ -o intake

%.o: %.cc %.h
	$(CC) -c $<

clean:
	rm *.o
