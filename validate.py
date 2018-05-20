#!/usr/bin/python

import json
import sys

results = [
    ["D10.json","D25.json",
     "D11.json","D20.json"],
    ["test1_D10.json","test1_D26.json",
     "test2_D11.json","test2_D20.json"]
]

def validate(output, expected):
    calc = json.load(open(output))
    given = json.load(open(expected))

    print
    print "checking " + output + " against " + expected
    print
    
    for key in given.keys():
        if key not in calc.keys():
            print key + " not in D10.json"
        if type(given[key]) is int:
            if calc[key] != given[key]:
                print "output value for " + key + " is " + str(calc[key]) \
                    + " but should be " + str(given[key])

            
if __name__ == "__main__":
    for i in range(len(results[0])):
        validate(results[0][i],results[1][i])

        

        
