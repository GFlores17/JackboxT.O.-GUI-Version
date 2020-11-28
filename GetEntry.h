#ifndef GETENTRY_H
#define GETENTRY_H

#include "Player.h"

#include <vector>
#include <memory>
#include <string>

    int binarySearch(std::vector<int> numVec, int l, int r, int x);
    //Search for a number in a vector using binarSearch.

    int binaryStringSearch(std::vector<std::shared_ptr<Player>> pVec, std::string x, int n);
    //Search for a Player by name from a vector of Players using binarySearch.

    void nameSort(std::vector<std::shared_ptr<Player>>& vec);
    //Sorts Players in a vector by name in ascending order using bubbleSort.

    void scoreSort(std::vector<std::shared_ptr<Player>> vec);
    //Sorts Players in a vector by their score in descending order using bubbleSort.

    void checkIfInt(int &num);

    //This is a test commit. Just adding this comment in the getEntry.h file.

#endif
