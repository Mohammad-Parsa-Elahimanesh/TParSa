#!/bin/bash
name="${1%.cpp}"
g++ ${name}.cpp -Wall -Wextra -o $name -Ofast -mcmodel=medium -llapack -lblas
