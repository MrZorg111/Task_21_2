#include <iostream>
#include <vector>
#include <string>

struct suburban_area {
    int buildings = 0;
    std::string furn_pipe_house = "No";
    int space_garage = 0;
    int space_barn = 0;
    struct house_data {
        int floor = 0;
        int ceiling_height = 0;
        int room = 0;
        int space_bedroom = 0;
        int space_childrenroom = 0;
        int space_bathroom = 0;
        int space_livingroom = 0;
        int space_kitchen = 0;
    }house_dt;
    struct bathhouse_data {
        int space_bathhouse = 0;
        std::string furn_pipe_bathhouse = "No";
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
void switch_code_room (std::string& r, int& s) {
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
    int switch_code_number = 0, switch_room_name = 0, plots = 0, rooms = 0;
    std::string build, name_r;
    std::vector<suburban_area> suburban;
    suburban.push_back(suburban_area());
    std::vector<suburban_area::house_data> floor;
    floor.push_back(suburban_area::house_data());
    std::cout << "Enter the number of plots: ";
    std::cin >> plots;

    for (int plot = 0; plot < plots; plot++) {
        for (int b = 0; build != "0"; b++) {
            std::cout << "Enter the name of the building present on the site: (House, garage, bathhouse, barn)\n";
            std::cout << "To stop listing a building on this site, enter 0.";
            std::cin >> build;
            switch_code(build, switch_code_number);
            switch (switch_code_number) {
                case 0:
                    suburban[plot].buildings |= HOUSE;
                    break;
                case 1:
                    suburban[plot].buildings |= GARAGE;
                    break;
                case 2:
                    suburban[plot].buildings |= BARN;
                    break;
                case 3:
                    suburban[plot].buildings |= BATHHOUSE;
                    break;
            }
        }
    }
    for (int edifice = 0; edifice < plots; edifice++) {
        std::cout << "Enter the data of the " << edifice + 1 << " section:\n";
        if (suburban[edifice].buildings & HOUSE) {
            std::cout << "Is there a stove with a pipe in the house? (yes/no):";
            std::cin >> suburban[edifice].furn_pipe_house;
            std::cout << "Enter the number of floors: ";
            std::cin >> suburban[edifice].house_dt.floor;

        for (int floor_h = 0; floor_h < suburban[edifice].house_dt.floor; floor_h++) {
            std::cout << "Enter the number of rooms per "<< floor_h + 1 << " floor: ";
            std::cin >> rooms;
            std::cout << "\nAnd also enter the ceiling height on this floor: ";
            std::cin >> floor[floor_h].ceiling_height;
            for (int room = 0; room < rooms; room++) {
                std::cout << "Enter the names of the rooms on the " << floor_h + 1 << "st floor:\n";
                std::cout << "To stop entering room names, enter 0.\n";
                std::cin >> name_r;
                switch_code_room(name_r, switch_room_name);
                switch (switch_room_name) {
                    case 0:
                        floor[floor_h].room |= BEDROOM;
                        std::cout << "Enter the bedroom area:";
                        std::cin >> floor[floor_h].space_bathroom;
                        break;
                    case 1:
                        floor[floor_h].room |= CHILDREN_ROOM;
                        std::cout << "Enter the childrenroom area:";
                        std::cin >> floor[floor_h].space_childrenroom;
                        break;
                    case 2:
                        floor[floor_h].room |= BATHROOM;
                        std::cout << "Enter the bathroom area:";
                        std::cin >> floor[floor_h].space_bathroom;
                        break;
                    case 3:
                        floor[floor_h].room |= LIVING_ROOM;
                        std::cout << "Enter the livingroom area:";
                        std::cin >> floor[floor_h].space_livingroom;
                        break;
                    case 4:
                        floor[floor_h].room |= KITCHEN;
                        std::cout << "Enter the kitchen area:";
                        std::cin >> floor[floor_h].space_kitchen;
                        break;
                }
            }
        }
        }
        if (suburban[edifice].buildings & GARAGE) {
            std::cout << "Enter the garage area: ";
            std::cin >> suburban[edifice].space_garage;
        }
        if (suburban[edifice].buildings & BARN) {
            std::cout << "Enter the barn area: ";
            std::cin >> suburban[edifice].space_barn;
        }
        if (suburban[edifice].buildings & BATHHOUSE) {
            std::cout << "Enter the bathhouse area: ";
            std::cin >> suburban[edifice].bathhouse_data.space_bathhouse;
            std::cout << "Is there a stove with a pipe in the bath? (yes/no): ";
            std::cin >> suburban[edifice].bathhouse_data.furn_pipe_bathhouse;
        }

    }
    std::cout << "YAHHO!";
    return 0;
}