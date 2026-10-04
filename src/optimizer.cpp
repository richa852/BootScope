#include "optimizer.h"

#include <cstdlib>
#include <iostream>

using namespace std;

void generateOptimizationReport()
{
    cout << "\n========== OPTIMIZATION REPORT ==========\n";

    cout << "Checking services that take the most time during boot...\n\n";

    int result = system(
        "systemd-analyze blame | head -10"
    );

    if (result != 0)
    {
        cout << "Unable to generate optimization report.\n";
        return;
    }

    cout << "\nRecommendations:\n";
    cout << "1. Check services with high startup time.\n";
    cout << "2. Disable unnecessary services if they are not required.\n";
    cout << "3. Check failed services.\n";
    cout << "4. Re-run BootScope after making changes.\n";

    cout << "==========================================\n";
}
