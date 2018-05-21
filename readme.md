[![Build Status](https://travis-ci.org/crclark96/cisc361_project.svg?branch=master)](https://travis-ci.org/crclark96/cisc361_project)

# collin clark, colby banbury
# cisc 361 project

## compilation instructions

our program compiles by makefile -- several options are available

`make` will generate just the system binary, named `intake`

`make test` will run several tests and validate their results against provided
sample output

`make validate` will run `./intake test1.in`, `./intake test2.in`,
and `./intake sample.in` and do a quick validation against the provided
outputs. this is for both the convenience of ourselves and the evaluators

`make clean` will delete all binaries, object files, and `.json` format outputs
other than those included to validate operatoration

## dependencies and other notes

we have taken special care to follow the c++98 standard

debugging symbols are enabled by default, and output of all tests
after every commit can be viewed by clicking the badge above

no additional dependencies should be required to run this program
aside from the standard g++ compiler and python2 to run the validation script