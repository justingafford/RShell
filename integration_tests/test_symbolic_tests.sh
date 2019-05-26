#!/bin/sh
[-e test/file/path && echo “path exists”]
[-e test/Ampersand.cpp/src]
[test/Ampersand.hpp/header]
[-e test/RShell.hpp/headerr]
[-f test/Ampersand.hpp/header]
[-d test/Ampersand.hpp/header]
