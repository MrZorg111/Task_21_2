#include <iostream>
#include <vector>
#include <string>

struct suburban_area {
    int buildings = 0;
    int space_garage = 0;
    int space_barn = 0;
    struct house_data {
        int ceiling_height = 0;
        int room;
    }house_dt;
    struct bathhouse_data {
        int space_bathhouse;
        int furn_pipe;
    }bathhouse_data;
};
    enum buildings_on_territory {
        HOUSE = 1,
        GARAGE = 2,
        BARN = 4,
        BATHHOUSE = 8,
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
}
void switch_code_room (std::string r, int& s) {
    if (r == "Bedroom") {
        s = 0;
    }
    else if (r == "Childrenroom") {
        s = 1;
    }
    else if (r == "Bathroom") {
        s = 2;
    }
    else if (r == "Livingroom") {
        s = 3;
    }
    else if (r == "Kitchen") {
        s = 4;
    }
}

int main() {
    int switch_code_number = 0, switch_room_name = 0;
    std::string build, name_r, answer = "yes";
    std::vector<suburban_area> suburban;
    suburban.push_back(suburban_area());
    std::vector<suburban_area::house_data> floor;
    floor.push_back(suburban_area::house_data());
    std::cout << "Enter the name of the building present on the site: (House, garage, bathhouse, barn)\n";
    std::cout << "To stop listing a building on this site, enter 0.";

    for (int b = 0; answer == "yes"; b++) {
        for (int plot = 0; build != "0"; plot++) {
            std::cin >> build;
            switch_code(build, switch_code_number);
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
            }
        }
        std::cout << "Are there any more plots left?(yes/no)";
        std::cin >> answer;

    }
    answer = "yes";
    std::cout << "Enter the names of the rooms on the 1st floor:\n";
    std::cout << "To stop entering room names, enter 0.";

    for (int room = 0; answer == "yes"; room++) {
        for (int rooms; name_r != "0"; rooms++){
            std::cin >> name_r;
            switch_code_room(name_r, switch_room_name);
            switch (switch_room_name) {
                case 0:
                    suburban[room].house_dt.room |= BEDROOM;
                    break;
                case 1:
                    suburban[room].house_dt.room |= CHILDREN_ROOM;
                    break;
                case 2:
                    suburban[room].house_dt.room |= BATHROOM;
                    break;
                case 3:
                    suburban[room].house_dt.room |= LIVING_ROOM;
                    break;
                case 4:
                    suburban[room].house_dt.room |= KITCHEN;
                    break;
            }
        }
    }
    return 0;
}