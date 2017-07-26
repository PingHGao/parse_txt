# parse_txt
C++ code to read text to get input and C++ code to list all the files in a directory

# Run
```shell
cd <parse_txt_root>
mkdir build
cd build
cmake ..
make
./parse_input
```

# Use
### Read text to get input
You can get variable from input.txt easily using class input_from_txt.h in your function like below:
```cpp
#include <iostream>
#include "input_from_txt.h"                // include .h

using namespace std;

int main() {

    parse_input_txt input("input.txt");    // define a class
    string path = input.get_value("path"); // get value
    string type = input.get_value("type"); // get value
    cout << "path:" << path << endl
         << "type:" << type << endl;
    return 0;
}
```
### List all the files in a directory
You can get all the files easily using class path.h like below:
```cpp
#include <iostream>
#include <vector>

#include "path.h"

int main() {

    vector<string> files;
    string path = "./";
    string type = ".txt";
    PATH file_path(path, type); // step 1 initial
    file_path.list_files();     // step 2 list files
    files = file_path.files;    // this is the result
    string file;

    for (int i = 0; i < files.size(); ++i)
    {
        file = path + '/' + files[i];
        cout << file << endl;
    }

    return 0;
}
```
