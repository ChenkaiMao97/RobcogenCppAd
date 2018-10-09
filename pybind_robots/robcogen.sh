#!/bin/bash

CP=`find ../lib/ -name '*.jar' | tr '\n' ':'`
java -Dlog4j.configuration=file:log4j.properties -cp "$CP":../bin/ iit.robcogen.Generator $1

python generate_files.py $2
