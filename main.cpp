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
    int oven_house = 0;
    int bathhouse = 0;
    };

    enum build{
         HOUSE = 1,
         BARN = 2,
         BATHHOUSE = 4,
         GARAGE = 8,
         OVEN = 16
 };
    void code_for_switch (std::string b, int& c) {
        if (b == "House") {
            c = 0;
        }
        else if (b == "Garage") {
            c = 1;
        }
        else if (b == "Barn") {
            c = 2;
        }
        else if (b == "Bathhouse") {
            c = 3;
        }
        else if (b != "-") {
            c = 4;
        }
    }

int main() {
    std::string build, answer;
    int switch_code = 0, n = 0;
    std::cout << "Enter the number of plots:";
    std::cin >> n;
    village territory[n];
    //territory.push_back(village());
    std::cout << "Enter the names of the buildings on this site:\n(House, Bathhouse, Barn, Garage\nIf there is no structure, put - .)\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Plot number " << i + 1 << ":\n";
        for (int b = 0; b < 4; b++) {
            std::cin >> build;
            code_for_switch(build, switch_code);
            switch (switch_code) {
                case 0:
                    territory[i].buildings |= HOUSE;
                    break;
                case 1:
                    territory[i].buildings |= GARAGE;
                    break;
                case 2:
                    territory[i].buildings |= BARN;
                    break;
                case 3:
                    territory[i].buildings |= BATHHOUSE;
                    break;
                case 4:
                    std::cout << "The name of the building is incorrect.";
                    b--;
            }
        }
    }
    for (int s = 0; s < n; s++) {
        switch (territory[s].buildings) {
            case HOUSE:
                std::cout << ""
        }
    }

    return 0;
}
