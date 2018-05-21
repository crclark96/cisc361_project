#!/usr/bin/python

import json
import sys

results = [
    ["D10.json","D26.json",
     "D11.json","D20.json",
     "D9999.json"],
    ["test1_D10.json","test1_D26.json",
     "test2_D11.json","test2_D20.json",
     "sample_input.json"]
]

def validate(output, expected):
    calc = json.load(open(output))
    given = json.load(open(expected))

    print
    print "checking " + output + " against " + expected
    print
    
    for key in given.keys():
        # check all fields are present
        if key not in calc.keys():
            print key + " not in D10.json"
        # check all system constants
        if type(given[key]) is int:
            if calc[key] != given[key]:
                print "output value for " + key + " is " + str(calc[key]) \
                    + " but should be " + str(given[key])
        # check all queues have all jobs (does not check order)
        if given[key] in ["readyq", "submitq", "holdq2", "holdq1",
                                "completeq", "waitq"]:
            for i in range(len(calc[key])):
                if calc[key][i] not in given[key]:
                    print "job # " + str(calc[key][i]) + " not expected in " \
                    + str(given[key])
    # check all jobs have same attributes
    # for every job in given
    for job in given['job']:
        # check against every job in calc
        for calc_job in calc['job']:
            # if they have the same ids
            if job['id'] == calc_job['id']:
                for attr in job.keys():
                    # check if attribute is missing
                    if attr not in calc_job:
                        print attr + " missing from job num " + str(calc_job['id'])
                        continue
                    # check if attribute is correct
                    if job[attr] != calc_job[attr]:
                        print attr + " in job " + str(calc_job['id']) + " is " \
                            + str(calc_job[attr]) + " and should be " \
                            + str(job[attr])
        
        
                    
if __name__ == "__main__":
    for i in range(len(results[0])):
        validate(results[0][i],results[1][i])

        

        
