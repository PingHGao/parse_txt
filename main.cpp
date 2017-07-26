#include <iostream>
#include <vector>

#include "input_from_txt.h"
#include "path.h"

using namespace std;

int main(int argc, char** argv) {

    parse_input_txt input("input.txt");
    string path = input.get_value("path");
    string type = input.get_value("type");
    cout << "path:" << path << endl
         << "type:" << type << endl;
    vector<string> files;
    PATH file_path(path, type);
    file_path.list_files();
    files = file_path.files;
    string file;

    for (int i = 0; i < files.size(); ++i)
    {
        file = path + '/' + files[i];
        cout << file << endl;
    }

    return 0;
}
