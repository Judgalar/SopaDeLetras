#include <iostream>
#include <string>
#include <filesystem>
#include <unistd.h>


using namespace std;

int main()
{
    char tmp[256];
    getcwd(tmp, 256);
    cout << "Current working directory: " << tmp << endl;

    return 0;
}
