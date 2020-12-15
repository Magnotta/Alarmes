#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#include "../include/header.hpp"

int main(){
    std::vector<device> devices;
    read_devices("data_devices.txt", devices);
    std::vector<device>::iterator it_dev; // For the erase member function
    device curr_device;

    std::vector<alarm> alarms, actives;
    read_alarms("data_alarms.txt", alarms);
    std::vector<alarm>::iterator it_al; // For the erase member function
    alarm curr_alarm;

    int opt, idx;
    bool quit = false;

    while(!quit){
        actives = get_active_alarms(alarms);

        std::system("clear");
        std::cout << "Welcome to the Mariano alarm system" << std::endl;
        std::cout << "You can select an option from the list below by typing its number and pressing enter" << std::endl;
        std::cout << "------------------------------------------------------------------------------------" << std::endl;
        std::cout << "1 - Alarms" << std::endl << "2 - Devices" << std::endl << "3 - Quit" << std::endl;

        std::getline(std::cin, cin_buff);
        opt = stoi(cin_buff);

        switch(opt){
            case 1:
                std::system("clear");
                std::cout << "Alarms menu" << std::endl;
                std::cout << "1 - Create new alarm" << std::endl << "2 - View alarms" << std::endl;
                std::cout << "3 - Update alarm" << std::endl << "4 - Delete alarm" << std::endl;
                std::cout << "5 - Go back" << std::endl;

                std::getline(std::cin, cin_buff);
                opt = stoi(cin_buff);

                switch(opt){
                    case 1:
                        std::system("clear");
                        curr_alarm.create();
                        alarms.push_back(curr_alarm);
                        break;
                    case 2:
                        std::system("clear");
                        std::cout << "How do you wish to go about this?" << std::endl;
                        std::cout << "1 - Search for an alarm" << std::endl << "2 - View all alarms" << std::endl;
                        std::cout << "3 - View active alarms" << std::endl << "4 - Go back" << std::endl;

                        std::getline(std::cin, cin_buff);
                        opt = stoi(cin_buff);

                        switch(opt){
                            case 1:
                                std::system("clear");
                                std::cout << "Enter a part of the description or level of the alarm you're looking for: " << std::endl;
                                std::getline(std::cin, cin_buff);

                                display_alarms(find_alarms(alarms, cin_buff));
                                break;

                            case 2:
                                display_alarms(alarms);
                                break;

                            case 3:
                                display_alarms(actives);
                                break;
                                
                            default:
                                std::cout << "Oops! I don't understand that. Please choose an option from the list" << std::endl;
                                std::cout << "Press enter to continue";
                                std::cin.ignore();
                                break;
                        }
                        break;
                    case 3:
                        std::cout << "I'm going to show you all the alarms. Please select the one you wish to update" << std::endl;
                        std::cout << "Press enter to continue";
                        std::cin.ignore();

                        idx = select_alarm(alarms);

                        if(idx >= 0)
                            alarms[idx].update();
                        break;
                    case 4:
                        std::cout << "I'm going to show you all the alarms. Please select the one you wish to delete" << std::endl;
                        std::cout << "Press enter to continue";
                        std::cin.ignore();

                        idx = select_alarm(alarms);

                        if(idx >= 0){
                            it_al = alarms.begin() + idx;
                            alarms.erase(it_al);
                        }
                        break;
                    default:
                        std::cout << "Oops! I don't understand that. Please choose an option from the list" << std::endl;
                        std::cout << "Press enter to continue";
                        std::cin.ignore();
                        break;
                }
                break;
            case 2:
                std::system("clear");
                std::cout << "Devices menu" << std::endl;
                std::cout << "1 - Create new device" << std::endl << "2 - View devices" << std::endl;
                std::cout << "3 - Update device" << std::endl << "4 - Delete device" << std::endl;
                std::cout << "5 - Go back" << std::endl;

                std::getline(std::cin, cin_buff);
                opt = stoi(cin_buff);

                switch(opt){
                    case 1:
                        std::system("clear");
                        curr_device.create();
                        devices.push_back(curr_device);
                        break;

                    case 2:
                        std::system("clear");
                        std::cout << "How do you wish to go about this?" << std::endl;
                        std::cout << "1 - Search for a device" << std::endl << "2 - View all devices" << std::endl;
                        std::cout << "3 - Go back" << std::endl;

                        std::getline(std::cin, cin_buff);
                        opt = stoi(cin_buff);

                        switch(opt){
                            case 1:
                                std::system("clear");
                                std::cout << "Enter a part of the name or serial number of the device you're looking for: " << std::endl;
                                std::getline(std::cin, cin_buff);

                                display_devices(find_devices(devices, cin_buff));
                                break;

                            case 2:
                                display_devices(devices);
                                break;

                            case 3:
                                break;

                            default:
                                std::cout << "Oops! I don't understand that. Please choose an option from the list" << std::endl;
                                std::cout << "Press enter to continue";
                                std::cin.ignore();
                                break;
                        }
                        break;
                    case 3:
                        std::cout << "I'm going to show you all the devices. Please select the one you wish to update" << std::endl;
                        std::cout << "Press enter to continue";
                        std::cin.ignore();

                        idx = select_device(devices);

                        if(idx >= 0)
                            devices[idx].update();
                        break;

                    case 4:
                        std::cout << "I'm going to show you all the devices. Please select the one you wish to delete" << std::endl;
                        std::cout << "Press enter to continue";
                        std::cin.ignore();

                        idx = select_device(devices);

                        if(idx >= 0){
                            it_dev = devices.begin() + idx;
                            devices.erase(it_dev);
                        }
                        break;

                    default:
                        std::cout << "Oops! I don't understand that. Please choose an option from the list" << std::endl;
                        std::cout << "Press enter to continue";
                        std::cin.ignore();
                        break;
                }
                break;
            case 3:
                quit = true;
                break;
            default:
                std::cout << "Oops! I don't understand that. Please choose an option from the list" << std::endl;
                std::cout << "Press enter to continue";
                std::cin.ignore();
                break;
        }
        write_alarms("data_alarms.txt", alarms);
        write_devices("data_devices.txt", devices);
    }
    return 0;
}