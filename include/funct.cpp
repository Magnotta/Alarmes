#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "header.hpp"

std::string cin_buff; // For type conversion

void read_alarms(const char* filename, std::vector<alarm>& vect){
    alarm x;
    unsigned int alarm_count;

    std::fstream reader;

    reader.open(filename, std::fstream::in);

    if(!reader.is_open()){
        // File doesn't exist, so initialize it
        reader.open(filename, std::fstream::out);
        reader << "alarms 0";
        return;
    }

    std::getline(reader, cin_buff, ' ');
    if(cin_buff == "alarms"){
        // First line stores the amount of alarms listed in file
        std::getline(reader, cin_buff);
        alarm_count = stoi(cin_buff);
    }else{
        std::cout << "Data file is corrupted! First line should be in the format below:" << std::endl;
        std::cout << "alarms X" << std::endl;
        std::cout << "Where X is the number of alarms listed" << std::endl;
        std::exit(-1);
    }

    for(int i = 0; i < alarm_count; i++){
        std::getline(reader, x.description);
        std::getline(reader, x.level);
        std::getline(reader, x.device_no);
        std::getline(reader, cin_buff);
        x.date_of_birth = (time_t)stoi(cin_buff);
        std::getline(reader, cin_buff);
        x.activated_count = stoi(cin_buff);
        std::getline(reader, cin_buff);
        x.active = stoi(cin_buff);

        vect.push_back(x);
    }
}

void write_alarms(const char* filename, std::vector<alarm> vect){
    std::ofstream writer;

    writer.open(filename, std::ofstream::trunc);

    if(!writer.is_open()){
        std::cout << "Failed to open data file!" << std::endl;
        std::exit(-1);
    }

    writer << "alarms " << vect.size() << std::endl;

    for(int i = 0; i < vect.size(); i++){
        writer << vect[i].description << std::endl;
        writer << vect[i].level << std::endl;
        writer << vect[i].device_no << std::endl;
        writer << vect[i].date_of_birth << std::endl;
        writer << vect[i].activated_count << std::endl;
        writer << vect[i].active << std::endl;
    }
}

void display_alarms(std::vector<alarm> alarms){
    if(alarms.size() == 0){
        std::system("clear");
        std::cout << "No alarms found" << std::endl;
        std::cout << "Press enter to continue";
        std::cin.ignore();
    }

    for(int i = 0; i < alarms.size(); i++){
        std::system("clear");
        if(i == alarms.size()-1){std::cout << "This is the last one" << std::endl;}
        std::cout << i+1 << "." << std::endl;
        alarms[i].display();
        std::cout << "Press enter to continue";
        std::cin.ignore();
    }
}

std::vector<alarm> find_alarms(std::vector<alarm> alarms, std::string s){
    std::vector<alarm> matches;

    for(int i = 0; i < alarms.size(); i++){
        if(alarms[i].description.find(s) != std::string::npos ||
            alarms[i].level.find(s) != std::string::npos){
                matches.push_back(alarms[i]);
            }
    }

    return matches;
}

int select_alarm(std::vector<alarm>& alarms){
    if(alarms.size() == 0){
        std::system("clear");
        std::cout << "No alarms found" << std::endl;
        std::cout << "Press enter to continue";
        std::cin.ignore();
        return -1;
    }

    int i;

    for(i = 0; i < alarms.size(); i++){
        std::system("clear");
        if(i == alarms.size()-1){std::cout << "This is the last one" << std::endl;}
        alarms[i].display();
        std::cout << "Press anything to select, just enter to continue" << std::endl;
        std::getline(std::cin, cin_buff);
        if(cin_buff.length()){
            return i;
        }
    }

    return -1;
}

std::vector<alarm> get_active_alarms(std::vector<alarm> alarms){
    std::vector<alarm> actives;

    for(int i = 0; i < alarms.size(); i++){
        if(alarms[i].active){
            actives.push_back(alarms[i]);
        }
    }

    return actives;
}

void read_devices(const char* filename, std::vector<device>& vect){
    device x;
    unsigned int device_count;

    std::fstream reader;

    reader.open(filename, std::fstream::in);

    if(!reader.is_open()){
        // File doesn't exist, so initialize it
        reader.open(filename, std::fstream::out);
        reader << "devices 0";
        return;
    }

    std::getline(reader, cin_buff, ' ');
    if(cin_buff == "devices"){
        // First line stores the amount of alarms listed in file
        std::getline(reader, cin_buff);
        device_count = stoi(cin_buff);
    }else{
        std::cout << "Data file is corrupted! First line should be in the format below:" << std::endl;
        std::cout << "devices X" << std::endl;
        std::cout << "Where X is the number of devices listed" << std::endl;
        std::exit(-1);
    }

    for(int i = 0; i < device_count; i++){
        std::getline(reader, x.name);
        std::getline(reader, x.serial_no);
        std::getline(reader, x.type);
        std::getline(reader, cin_buff);
        x.date_of_birth = (time_t)stoi(cin_buff);

        vect.push_back(x);
    }
}

void write_devices(const char* filename, std::vector<device> vect){
    std::ofstream writer;

    writer.open(filename, std::ofstream::trunc);

    if(!writer.is_open()){
        std::cout << "Failed to open data file!" << std::endl;
        std::exit(-1);
    }

    writer << "devices " << vect.size() << std::endl;

    for(int i = 0; i < vect.size(); i++){
        writer << vect[i].name << std::endl;
        writer << vect[i].serial_no << std::endl;
        writer << vect[i].type << std::endl;
        writer << vect[i].date_of_birth << std::endl;
    }
}

void display_devices(std::vector<device> devices){
    if(devices.size() == 0){
        std::system("clear");
        std::cout << "No devices found" << std::endl;
        std::cout << "Press enter to continue";
        std::cin.ignore();
    }

    for(int i = 0; i < devices.size(); i++){
        std::system("clear");
        if(i == devices.size()-1){std::cout << "This is the last one" << std::endl;}
        std::cout << i+1 << "." << std::endl;
        devices[i].display();
        std::cout << "Press enter to continue";
        std::cin.ignore();
    }
}

std::vector<device> find_devices(std::vector<device> devices, std::string s){
    std::vector<device> matches;

    for(int i = 0; i < devices.size(); i++){
        if(devices[i].name.find(s) != std::string::npos ||
            devices[i].serial_no.find(s) != std::string::npos){
                matches.push_back(devices[i]);
            }
    }

    return matches;
}

int select_device(std::vector<device>& devices){
    if(devices.size() == 0){
        std::system("clear");
        std::cout << "No devices found" << std::endl;
        std::cout << "Press enter to continue";
        std::cin.ignore();
        return -1;
    }

    int i;

    for(i = 0; i < devices.size(); i++){
        std::system("clear");
        if(i == devices.size()-1){std::cout << "This is the last one" << std::endl;}
        devices[i].display();
        std::cout << "Press anything to select, just enter to continue" << std::endl;
        std::getline(std::cin, cin_buff);
        if(cin_buff.length()){
            return i;
        }
    }

    return -1;
}