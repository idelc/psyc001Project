#ifndef CHOICES_HPP
#define CHOICES_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "manager.hpp"

class choice{
 public:
    string storage [9] = {};
    choice(string arr[]): storage = arr {};
    choice();
};

#endif 