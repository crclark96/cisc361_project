CC = g++
CFLAGS = -std=c++98 -g
OBJS = system.o job.o process.o
TESTS = system_test intake_test banker_test

default: intake.o

test: $(TESTS)

system_test: system_test.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	./$@

intake_test: intake.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	./$@ test.txt

banker_test: banker_test.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	./$@

%.o: %.cc %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o D*.json
