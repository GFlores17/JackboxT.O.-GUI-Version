#include <iostream>
#include <fstream>
#include "getEntry.h"

/*int getEntry() {
    int choice;
    std::cin >> choice;
    checkIfInt(choice);

    while (choice < 1 || choice > 5) {
        std::cout << "invalid option. retry now." << std::endl;
        int choice;
        std::cin >> choice;
        checkIfInt(choice);

    }
    std::cout << std::endl;
    return choice;
}*/

int binarySearch(std::vector<int> numVec, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (numVec.at(mid) == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (numVec.at(mid) > x)
            return binarySearch(numVec, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray

        return binarySearch(numVec, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

int binaryStringSearch(std::vector<std::shared_ptr<Player>> pVec, std::string x, int n)
{
    int leftBound = 0;
    int rightBound = n - 1;
    while (leftBound <= rightBound)
    {
        int middle = leftBound + (rightBound - leftBound) / 2;

        bool flag = false;
        if (x == (pVec.at(middle)->getName())) {
            flag = true;
        }

        // Check if x is present at mid
        if (flag == true)
        {
            return middle;
        }
        // If x greater, ignore left half
        if (x > (pVec.at(middle)->getName())) {
            leftBound = middle + 1;
            //std::cout << "NEW LEFT : " << leftBound << std::endl;
        }
        // If x is smaller, ignore right half
        else {
            rightBound = middle - 1;
            //std::cout << "NEW RIGHT : " << rightBound << std::endl;
        }
    }

    return -1;
}

void nameSort(std::vector<std::shared_ptr<Player>>& vec) {
    //Sorts "Player" pointers in the vector by name.
    //Self-note. Arrays have to be sorted before the can be properly (algorithmically) searched.
    Player player = Player("temp");
    Player* p = &player;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if ((vec.at(j)->getName()).compare(vec.at(i)->getName()) < 0) {
                p->setName(vec.at(i)->getName());
                p->setScore(vec.at(i)->getScore());

                vec.at(i)->setName(vec.at(j)->getName());
                vec.at(i)->setScore(vec.at(j)->getScore());

                vec.at(j)->setName(p->getName());
                vec.at(j)->setScore(p->getScore());
            }
        }
    }
}//end nameSort()

void scoreSort(std::vector<std::shared_ptr<Player>> vec) {
    //Sorts "Player" pointers in the vector by score.
    //Self-note. Arrays have to be sorted before the can be properly (algorithmically) searched.
    Player player = Player("temp");
    Player* p = &player;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec.at(j)->getScore() > vec.at(i)->getScore()) {
                p->setName(vec.at(i)->getName());
                p->setScore(vec.at(i)->getScore());

                vec.at(i)->setName(vec.at(j)->getName());
                vec.at(i)->setScore(vec.at(j)->getScore());

                vec.at(j)->setName(p->getName());
                vec.at(j)->setScore(p->getScore());
            }
        }
    }
}//end scoreSort

void checkIfInt(int &num) {
    while (!std::cin)
    {
        std::cout << "That was no integer! Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> num;
    }
}

