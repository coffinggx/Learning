#!/bin/bash

set -o xtrace
cc -Wall -Wextra -o main main.c
cc -Wall -Wextra -lm -o gates gates.c
