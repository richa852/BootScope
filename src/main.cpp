#include <iostream>

#include "system_info.h"
#include "boot_profiler.h"
#include "dependency_analyzer.h"
#include "optimizer.h"

using namespace std;

int main()
{
    int choice;

    cout << "\n========================================\n";
    cout << "       BOOTSCOPE - LINUX PROFILER\n";
    cout << "========================================\n";

    while (true)
    {
        cout << "\n1. System Information\n";
        cout << "2. Boot-Time Profiler\n";
        cout << "3. Dependency Analyzer\n";
        cout << "4. Optimization Report\n";
        cout << "5. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                showSystemInfo();
                break;

            case 2:
                showBootTime();
                break;

            case 3:
                analyzeDependencies();
                break;

            case 4:
                generateOptimizationReport();
                break;

            case 5:
                cout << "\nExiting BootScope...\n";
                return 0;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    }

    return 0;
}
