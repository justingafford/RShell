#!/bin/sh
test -e test/file/path && echo “path exists”
test -e test/Ampersand.cpp/src
test test/Ampersand.hpp/header
test -e test/RShell.hpp/headerr
test -f test/Ampersand.hpp/header
test -d test/Ampersand.hpp/header
