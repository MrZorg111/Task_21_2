#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

struct village {
    int buildings = 0;
    int space_house = 0;
    int space_barn = 0;
    int space_bathhouse = 0;
    int space_garage = 0;
    };

    enum build{
         HOUSE,
         BARN,
         BATHHOUSE,
         GARAGE,
         OVEN
 };

int main() {
    std::vector<village> territory;
    territory.push_back(village());
    switch (){

    }
    return 0;
}
