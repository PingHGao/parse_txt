#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <algorithm>

using namespace std;

class PATH {
private:
    DIR *dir;
    struct dirent *ptr;
    char base[1000];
public:
    string path;
    string type;
    vector<string> files;
    vector<string> folders;

public:
    PATH(string path, string type);
    void list_files();
};

void PATH::list_files()
{
    while ((ptr=readdir(dir)) != NULL)
    {
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    //current dir OR parrent dir
                continue;
        else if(ptr->d_type == 8)    //file
        {
            if (strstr(ptr->d_name, type.c_str()) == NULL)
                continue;
//            printf("d_name:%s/%s\n",path.c_str(),ptr->d_name);
            files.push_back(ptr->d_name);
        }
        else if(ptr->d_type == 10)    //link file
        {
//            printf("d_name:%s/%s\n",path.c_str(),ptr->d_name);
            continue;
        }
        else if(ptr->d_type == 4)    //dir
        {
//            printf("d_name:%s/%s\n",path.c_str(),ptr->d_name);
            folders.push_back(ptr->d_name);
        }
        else {
            cout << "uncounted situation!\n";
        }
    }
    closedir(dir);
    sort(files.begin(), files.end());
    sort(folders.begin(), folders.end());
}

PATH::PATH(string path, string type)
{
    dir = opendir(path.c_str());
    if (dir == NULL)
    {
        cout << "[ERROR] Failed to open " << path << endl;
        exit(1);
    }
    this->path = path;
    this->type = type;
}
