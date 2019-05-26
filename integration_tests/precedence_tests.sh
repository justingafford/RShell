#!/bin/sh
(echo A && echo B) || (echo C && echo D)
(yeet || echo hello) && (mkdir test ; ls)
this || (echo hello || echo friend) 
(ls -a ; git status) || (echo a || echo b) && (mkdir finish && ls)
(echo A) && (echo B) && (echo C)
(echo this should work)
