@echo off
cls

g++ -I. -I.\CSC2110 -c Widget.cpp InventoryManager.cpp InventoryDriver.cpp
g++ -L.\CSC2110 -o Inventory.exe Widget.o InventoryManager.o InventoryDriver.o -lCSC2110
