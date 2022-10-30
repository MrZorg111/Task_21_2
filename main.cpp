#include <iostream>
#include <vector>
#include <string>

struct rooms {
    int name_room = 0;
    int area_room = 0;
};
struct floors {
    int ceiling = 0;
    std::vector<rooms> room;
};
struct buildings {
    int name_build = 0;
    std::string oven = "No";
    std::string oven_bath = "No";
    int area = 0;
    std::vector<floors> floor;

};
struct plots {
    int number = 0;
    int plot_area = 0;
    std::vector<buildings> build;
};
struct village {
    std::vector<plots> plot;
};

enum build_plot {
    HOUSE = 1,
    GARAGE = 2,
    BARN = 4,
    BATHHOUSE = 8
};
enum rooms_build {
    BEDROOM = 16,
    CHILDREN_ROOM = 32,
    LIVING_ROOM = 64,
    BATHROOM = 128,
    KITCHEN = 256
};

int code_switch_build (std::string& bd, int& c_b) {
    if (bd == "House") {
        return c_b = 1;
    }
    if (bd == "Garage") {
        return c_b = 2;
    }
    if (bd == "Barn") {
        return c_b = 3;
    }
    if (bd == "Bathhouse") {
        return c_b = 4;
    }
    else {
        return c_b = 5;
    }
}
int code_switch_room (std::string& rm, int& c_r) {
    if (rm == "Bedroom") {
        return c_r = 1;
    }
    if (rm == "Children") {
        return c_r = 2;
    }
    if (rm == "Living") {
        return c_r = 3;
    }
    if (rm == "Bathroom") {
        return c_r = 4;
    }
    if (rm == "Kitchen") {
        return c_r = 5;
    }
    else {
        return c_r = 6;
    }
}

int area(int& a, int& b_a) {
    return (a * 100) / b_a;
}

int main() {
    int num_plot = 0, num_build = 0, num_floor = 0, num_room = 0, code_build = 0, code_room = 0, build_area = 0;
    std::string name_build, name_room;
    village vil;
    vil.plot.resize(1);

    std::cout << "Enter the number of plots in the village:";
    std::cin >> num_plot;
    vil.plot.resize(num_plot);
    std::cout << "Let's fill in our structures with data about the site:\n";
    for (int p = 0; p < num_plot; p++) {
        vil.plot[p].number = (p + 1);
        std::cout << "Enter the area of the plot:";
        std::cin >> vil.plot[p].plot_area;
        std::cout << "Enter the number of buildings on the site, and enter their names:";
        std::cin >> num_build;
        vil.plot[p].build.resize(num_build);
        for (int b = 0; b < num_build; b++) {
            std::cout << "Name of the building:";
            std::cin >> name_build;
            code_switch_build(name_build, code_build);
            switch (code_build) {
                case 1: {
                    vil.plot[p].build[b].name_build |= HOUSE;
                    std::cout << "Enter the area of the building:";
                    std::cin >> vil.plot[p].build[b].area;
                    std::cout << "Is there a furnace with a pipe (Yes/No):";
                    std::cin >> vil.plot[p].build[b].oven;
                    break;
                }
                case 2: {
                    vil.plot[p].build[b].name_build |= GARAGE;
                    std::cout << "Enter the area of the building:";
                    std::cin >> vil.plot[p].build[b].area;
                    break;
                }
                case 3: {
                    vil.plot[p].build[b].name_build |= BARN;
                    std::cout << "Enter the area of the building:";
                    std::cin >> vil.plot[p].build[b].area;
                    break;
                }
                case 4: {
                    vil.plot[p].build[b].name_build |= BATHHOUSE;
                    std::cout << "Enter the area of the building:";
                    std::cin >> vil.plot[p].build[b].area;
                    std::cout << "Is there a furnace with a pipe (Yes/No):";
                    std::cin >> vil.plot[p].build[b].oven_bath;
                    break;
                }
                default: {
                    std::cout << "invalid code!\n";
                    b--;
                    break;
                }
            }
            if (vil.plot[p].build[b].name_build & HOUSE) {
                std::cout << "Enter the number of floors in the house:";
                std::cin >> num_floor;
                vil.plot[p].build[b].floor.resize(num_floor);
                for (int fl = 0; fl < num_floor; fl++) {
                    std::cout << "Enter the height of the ceilings on the floor:";
                    std::cin >> vil.plot[p].build[b].floor[fl].ceiling;
                    std::cout << "Enter the number of rooms per floor:";
                    std::cin >> num_room;
                    vil.plot[p].build[b].floor[fl].room.resize(num_room);
                    for (int rm = 0; rm < num_room; rm++) {
                        std::cout << "Name of the room:";
                        std::cin >> name_room;
                        code_switch_room(name_room, code_room);
                        switch (code_room) {
                            case 1: {
                                vil.plot[p].build[b].floor[fl].room[rm].name_room |= BEDROOM;
                                std::cout << "Enter the area of the room:";
                                std::cin >> vil.plot[p].build[b].floor[fl].room[rm].area_room;
                             break;
                            }
                            case 2: {
                                vil.plot[p].build[b].floor[fl].room[rm].name_room |= CHILDREN_ROOM;
                                std::cout << "Enter the area of the room:";
                                std::cin >> vil.plot[p].build[b].floor[fl].room[rm].area_room;
                                break;
                            }
                            case 3: {
                                vil.plot[p].build[b].floor[fl].room[rm].name_room |= LIVING_ROOM;
                                std::cout << "Enter the area of the room:";
                                std::cin >> vil.plot[p].build[b].floor[fl].room[rm].area_room;
                                break;
                            }
                            case 4: {
                                vil.plot[p].build[b].floor[fl].room[rm].name_room |= BATHROOM;
                                std::cout << "Enter the area of the room:";
                                std::cin >> vil.plot[p].build[b].floor[fl].room[rm].area_room;
                                break;
                            }
                            case 5: {
                                vil.plot[p].build[b].floor[fl].room[rm].name_room |= KITCHEN;
                                std::cout << "Enter the area of the room:";
                                std::cin >> vil.plot[p].build[b].floor[fl].room[rm].area_room;
                                break;
                            }
                            default: {
                                std::cout << "Invalid code!\n";
                                rm--;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << std::endl;
    int plot_info;
    std::cout << "Information about which site are you interested in?";
    std::cin >> plot_info;
    plot_info -= 1;

    std::cout << "This plot has the number: " << vil.plot[plot_info].number << "\n";
    for (int b_info = 0; b_info < vil.plot[plot_info].build.size(); b_info++) {
        if (vil.plot[plot_info].build[b_info].name_build & HOUSE) {
            build_area += vil.plot[plot_info].build[b_info].area;
            std::cout << "And there are buildings on it: House\n";
            std::cout << "The area of the house is:" << vil.plot[plot_info].build[b_info].area << "\n";
            if (vil.plot[plot_info].build[b_info].oven == "Yes") {
                std::cout << "The house has a stove with a pipe\n";
            }else { std::cout << "There is no stove with a pipe in the house\n";}
            std::cout << "The house also has several floors with rooms.\n";
            for (int fl_info = 0; fl_info < vil.plot[plot_info].build[b_info].floor.size(); fl_info++) {
                std::cout << "Floor number " << fl_info + 1 <<" has a ceiling height equal to: " << vil.plot[plot_info].build[b_info].floor[fl_info].ceiling << "\n";
                for(int rm_info = 0; rm_info < vil.plot[plot_info].build[b_info].floor[fl_info].room.size(); rm_info++) {
                    if (vil.plot[plot_info].build[b_info].floor[fl_info].room[rm_info].name_room & BEDROOM) {
                        std::cout << "And also on this floor there are rooms: Bedroom\n";
                        std::cout << "The area of the room consists of: " << vil.plot[plot_info].build[b_info].floor[fl_info].room[rm_info].area_room << "\n";
                    }
                    if (vil.plot[plot_info].build[b_info].floor[fl_info].room[rm_info].name_room & CHILDREN_ROOM) {
                        std::cout << "And also on this floor there are rooms: Children room\n";
                        std::cout << "The area of the room consists of: " << vil.plot[plot_info].build[b_info].floor[fl_info].room[rm_info].area_room << "\n";
                    }
                    if (vil.plot[plot_info].build[b_info].floor[fl_info].room[rm_info].name_room & LIVING_ROOM) {
                        std::cout << "And also on this floor there are rooms: Living room\n";
                        std::cout << "The area of the room consists of: " << vil.plot[plot_info].build[b_info].floor[fl_info].room[rm_info].area_room << "\n";
                    }
                    if (vil.plot[plot_info].build[b_info].floor[fl_info].room[rm_info].name_room & BATHROOM) {
                        std::cout << "And also on this floor there are rooms: Bathroom\n";
                        std::cout << "The area of the room consists of: " << vil.plot[plot_info].build[b_info].floor[fl_info].room[rm_info].area_room << "\n";
                    }
                    if (vil.plot[plot_info].build[b_info].floor[fl_info].room[rm_info].name_room & KITCHEN) {
                        std::cout << "And also on this floor there are rooms: Kitchen\n";
                        std::cout << "The area of the room consists of: " << vil.plot[plot_info].build[b_info].floor[fl_info].room[rm_info].area_room << "\n";
                    }
                }
            }
        }
        if (vil.plot[plot_info].build[b_info].name_build & GARAGE) {
            build_area += vil.plot[plot_info].build[b_info].area;
            std::cout << "\nAnd there are buildings on it: Garage\n";
            std::cout << "The area of the house is:" << vil.plot[plot_info].build[b_info].area<< "\n";
        }
        if (vil.plot[plot_info].build[b_info].name_build & BARN) {
            build_area += vil.plot[plot_info].build[b_info].area;
            std::cout << "And there are buildings on it: Barn\n";
            std::cout << "The area of the house is: " << vil.plot[plot_info].build[b_info].area<< "\n";
        }
        if (vil.plot[plot_info].build[b_info].name_build & BATHHOUSE) {
            build_area += vil.plot[plot_info].build[b_info].area;
            std::cout << "And there are buildings on it: Bathhouse\n";
            std::cout << "The area of the house is: " << vil.plot[plot_info].build[b_info].area << "\n";
            if (vil.plot[plot_info].build[b_info].oven == "Yes") {
                std::cout << "There is a stove with a pipe in the bath\n";
            }else { std::cout << "There is no furnace with a pipe in the bath\n";}
        }
    }
    std::cout << "The area of the building occupies " << area(build_area, vil.plot[plot_info].plot_area) <<"% of the plot area!";

    return 0;
}