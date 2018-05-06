CC = g++

default:

%.o: %.cc %.h
	$(CC) -c $<

