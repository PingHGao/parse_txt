#include <fstream>

using namespace std;

class parse_input_txt {
public:
    string txtfile = "calibration_input.txt";
//    int pic_num = 10;
//    int step = 2;
    string data[100][100];
    int data_nums = 0;

public:
    parse_input_txt(string txtfile);
    ~parse_input_txt();
    string get_value(string key);
    template <class Type>
    Type get_value(string key);
    void read_txt();
};

void parse_input_txt::read_txt()
{
    ifstream infile(this->txtfile.c_str());
    int data_nums = 0;
    while (!infile.eof())
    {
        infile >> this->data[data_nums][0] >> this->data[data_nums][1];
        data_nums++;
    }
    this->data_nums = data_nums;
}

string parse_input_txt::get_value(string key)
{
    for (int i = 0; i < this->data_nums; i++)
    {
        if (this->data[i][0] == key)
        {
            return this->data[i][1];
        }
    }
    return "None";
}

template <class Type>
Type parse_input_txt::get_value(string key)
{
    for (int i = 0; i < this->data_nums; i++)
    {
        if (this->data[i][0] == key)
        {
            Type num;
            istringstream iss(this->data[i][1]);
            iss >> num;
            return num;
        }
    }
    return -1;
}

parse_input_txt::parse_input_txt(string txtfile)
{
    this->txtfile = txtfile;
//    this->pic_num = pic_num;
//    this->step = step;
    this->read_txt();
}

parse_input_txt::~parse_input_txt(void)
{

}
