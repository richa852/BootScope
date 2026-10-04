#include "system_info.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void showSystemInfo()
{
    string line;

    cout << "\n========== SYSTEM INFORMATION ==========\n";

    // CPU information
    ifstream cpuFile("/proc/cpuinfo");

    if (cpuFile.is_open())
    {
        while (getline(cpuFile, line))
        {
            if (line.find("model name") == 0)
            {
                cout << "CPU: "
                     << line.substr(line.find(':') + 2)
                     << endl;
                break;
            }
        }

        cpuFile.close();
    }

    // RAM information
    ifstream memoryFile("/proc/meminfo");

    if (memoryFile.is_open())
    {
        while (getline(memoryFile, line))
        {
            if (line.find("MemTotal:") == 0)
            {
                cout << "RAM: "
                     << line.substr(10)
                     << endl;
                break;
            }
        }

        memoryFile.close();
    }

    // Kernel information
    ifstream kernelFile("/proc/version");

    if (kernelFile.is_open())
    {
        getline(kernelFile, line);

        cout << "Kernel: "
             << line
             << endl;

        kernelFile.close();
    }

    cout << "=========================================\n";
}
