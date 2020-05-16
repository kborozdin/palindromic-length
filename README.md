# Description
This repository contains supplementary sources and tests for the paper ["Borozdin, K., Kosolobov, D., Rubinchik, M., & Shur, A. M. (2017). Palindromic length in linear time. In 28th Annual Symposium on Combinatorial Pattern Matching (CPM 2017). Schloss Dagstuhl-Leibniz-Zentrum fuer Informatik"](https://scholar.google.com/scholar?cluster=5303945586501676640), published at [CPM 2017](http://cpm2017.mimuw.edu.pl).

# Programming Language
All sources are written in C++, compiled using MS Visual Studio 2015.

# Usage
archive.zip can be directly downloaded to the [Polygon](https://polygon.codeforces.com/).
Polygon is a specialized version control system which helps running different sources on different sets of tests.

The final edition of the code used in paper can be found in solutions/FOR\_PAPER\_finalize\_bit.cpp.
There is a #define STRESS line in the beginning of the program.
When it is commented out, program reads a string from standard input and prints answers to standard output.
When it is not, program runs stress testing on all small and some random strings comparing answers to eertree solution (embedded into code).
