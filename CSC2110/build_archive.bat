@echo off
cls

g++ -c CD.cpp
g++ -c Keyboard.cpp
g++ -c Matrix.cpp
g++ -c Poly.cpp
g++ -c Random.cpp
g++ -c ReadFile.cpp
g++ -c Song.cpp
g++ -c String.cpp
g++ -c Tokens.cpp
g++ -c WriteFile.cpp

ar -r libCSC2110.a *.o
