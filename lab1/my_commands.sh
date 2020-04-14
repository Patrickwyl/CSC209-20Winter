#!/usr/bin/env bash 
./echo_arg csc209 > echo_out.txt 
./echo_stdin < echo_stdin.c
./count 210 | wc -m
ls -S | ./echo_stdin