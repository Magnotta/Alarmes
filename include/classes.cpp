#include <iostream>
#include <string>
#include <ctime>

#include "header.hpp"

void alarm::create(){
    std::cout << "Enter a description for the alarm:" << std::endl;
    std::getline(std::cin, description);

    std::cout << "Enter a level [lo/med/hi]:" << std::endl;
    std::getline(std::cin, level);

    std::cout << "Enter the serial number of the device this alarm should track:" << std::endl;
    std::getline(std::cin, device_no);

    std::cout << "Is this alarm active? [0/1]" << std::endl;
    std::getline(std::cin, cin_buff);
    active = stoi(cin_buff);

    activated_count = 0;

    date_of_birth = time(nullptr);
}

void alarm::display(){
    char date[11];
    strftime(date, sizeof(date), "%d-%m-%Y", localtime(&date_of_birth));

    std::cout << "Description: " << description << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Attached device's serial no: " << device_no << std::endl;
    std::cout << "Date of creation: " << date << std::endl;
    std::cout << "Times activated: " << activated_count << std::endl;
    std::cout << "Active: " << active << std::endl;  
}

void alarm::update(){
    std::cout << "Which paramater do you wish to update?" << std::endl;
    std::cout << "1 - Description" << std::endl << "2 - Level " << std::endl;
    std::cout << "3 - Attached device's serial no" << std::endl << "4 - Active status" << std::endl;

    unsigned int opt;

    std::getline(std::cin, cin_buff);
    opt = std::stoi(cin_buff);

    switch(opt){
        case 1:
            std::cout << "Enter new description: " << std::endl;
            std::getline(std::cin, description);
            break;

        case 2:
            std::cout << "Enter new level [lo/med/hi]: " << std::endl;
            std::getline(std::cin, level);
            break;

        case 3:
            std::cout << "Enter new device's serial number to attach: " << std::endl;
            std::getline(std::cin, device_no);
            break;
        
        case 4:
            if(active){std::cout << "This alarm is active. Inactivate it? [y/n]" << std::endl;}
            else{std::cout << "This alarm is inactive. Activate it? [y/n]" << std::endl;}

            std::getline(std::cin, cin_buff);
            if(cin_buff == "y"){
                active = !active;
                if(active)
                    activated_count++;
            }
            break;

        default:
            std::cout << "Oops! I don't understand that" << std::endl;
            std::cout << "Press enter to continue";
            std::cin.ignore();
            break;
    }
}

void alarm::del(){
    date_of_birth = 0;
}

void device::create(){
    std::cout << "Enter a name for the device: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "Enter the serial number: " << std::endl;
    std::getline(std::cin, serial_no);

    std::cout << "Enter its type [volt/amp/oil]: " << std::endl;
    std::getline(std::cin, type);

    date_of_birth = time(nullptr);

    std::cout << "All done!" << std::endl;
}

void device::display(){
    char date[11];
    strftime(date, sizeof(date), "%d-%m-%Y", localtime(&date_of_birth));

    std::cout << "Device name: " << name << std::endl;
    std::cout << "Serial number: " << serial_no << std::endl;
    std::cout << "Type: " << type << std::endl;

    std::cout << "Date of creation: " << date << std::endl;
}

void device::update(){
    std::cout << "Which parameter do you wish to update?" << std::endl;
    std::cout << "1 - Name" << std::endl << "2 - Serial number" << std::endl;
    std::cout << "3 - Type" << std::endl;

    int opt;
    std::getline(std::cin, cin_buff);
    opt = stoi(cin_buff);

    switch (opt){
    case 1:
        std::cout << "Enter a new name for the device: " << std::endl;
        std::getline(std::cin,  name);
        break;
    
    case 2:
        std::cout << "Enter a new serial number for the device: " << std::endl;
        std::getline(std::cin, serial_no);
        break;

    case 3:
        std::cout << "Enter a new type for the device [volt/amp/oil]: " << std::endl;
        std::getline(std::cin, type);
        break;
    default:
        std::cout << "Oops! I don't understand that!" << std::endl;
        std::cout << "Press enter to continue";
        std::cin.ignore();
        break;
    }
    std::cout << "Done!" << std::endl;
}

void device::del(){
    date_of_birth = 0;
}