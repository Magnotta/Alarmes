#include <string>
#include <vector>

extern std::string cin_buff;    // For type conversion

class device {
    public:

    std::string name;
    std::string serial_no;
    std::string type;
    time_t date_of_birth;

    device(){
        name = "";
        serial_no = "";
        type = "";
        date_of_birth = time(nullptr);
    }

    device(std::string nam, std::string num, std::string typ){
        name = nam;
        serial_no = num;
        type = typ;
        date_of_birth = time(nullptr);
    }

    void create();
    void display();
    void update();
    void del();
};

void read_devices(const char*, std::vector<device>&);
void write_devices(const char*, std::vector<device>);
void display_devices(std::vector<device>);
std::vector<device> find_devices(std::vector<device>, std::string);
int select_device(std::vector<device>&);

class alarm {
    public:

    std::string description;
    std::string level;
    std::string device_no;
    time_t date_of_birth;
    unsigned int activated_count;
    int active;

    alarm(){
        description = "";
        level = "";
        device_no = "";
        date_of_birth = 0;
        activated_count = 0;
        active = 0;
    }

    void create();
    void display();
    void update();
    void del();
};

void read_alarms(const char*, std::vector<alarm>&);
void write_alarms(const char*, std::vector<alarm>);
void display_alarms(std::vector<alarm>);
std::vector<alarm> find_alarms(std::vector<alarm>, std::string);
int select_alarm(std::vector<alarm>&);
std::vector<alarm> get_active_alarms(std::vector<alarm>);