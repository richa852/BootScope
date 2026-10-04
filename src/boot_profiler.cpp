#include "boot_profiler.h"

#include <cstdlib>
#include <iostream>

using namespace std;

void showBootTime()
{
    cout << "\n========== BOOT-TIME PROFILE ==========\n";

    int result = system("systemd-analyze");

    if (result != 0)
    {
        cout << "Unable to read boot-time information.\n";
    }

    cout << "=======================================\n";
}

