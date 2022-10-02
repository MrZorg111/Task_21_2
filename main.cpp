#include <iostream>
#include <vector>
#include <string>

struct suburban_area {
    int buildings = 0;
    int space_garage = 0;
    int space_barn = 0;
    struct house_data {
        int ceiling_height = 0;
        int floor;
        std::vector<int> room[0][0];
    };
    struct bathhouse_data {
        int space_bathhouse;
        int furn_pipe;
    };
};
    enum buildings_on_territory {
        HOUSE = 1,
        GARAGE = 2,
        BARN = 4,
        BATHHOUSE = 8,
        NON = 16

    };
    enum house_plan {
        BEDROOM = 3,
        CHILDREN_ROOM = 6,
        BATHROOM = 12,
        LIVING_ROOM = 24,
        KITCHEN = 48,
    };

void switch_code (std::string b, int& s) {
    if (b == "House") {
        s = 0;
    }
    else if (b == "Garage") {
        s = 1;
    }
    else if (b == "Barn") {
        s = 2;
    }
    else if (b == "Bathhouse") {
        s = 3;
    }
    else if (b == "-") {
        s = 4;
    }
    else {
        s = 5;
    }
}

int main() {
    int n, switch_code_number = 0;
    std::string build;
    std::cout << "Enter the number of land plots:";
    std::cin >> n;
    suburban_area suburban[n];
    std::cout << "Enter the name of the building present on the site: (House, garage, bathhouse, barn)";
    std::cin >> build;
    switch_code(build, switch_code_number);
    for (int b = 0; b < n; b++) {
        switch (switch_code_number) {
            case 0:
                suburban[b].buildings |= HOUSE;
                break;
            case 1:
                suburban[b].buildings |= GARAGE;
                break;
            case 2:
                suburban[b].buildings |= BARN;
                break;
            case 3:
                suburban[b].buildings |= BATHHOUSE;
                break;
            case 4:
                suburban[b].buildings |= NON;
                break;
            case 5:
                std::cout << "Invalid code!";
                b--;
                break;
        }
    }

    return 0;
}