#include "dependency_analyzer.h"

#include <cstdlib>
#include <iostream>

using namespace std;

void analyzeDependencies()
{
    cout << "\n========== DEPENDENCY ANALYZER ==========\n";

    cout << "Showing Linux service dependencies:\n\n";

    int result = system(
        "systemctl list-dependencies --plain --no-pager | head -20"
    );

    if (result != 0)
    {
        cout << "Unable to read service dependencies.\n";
    }

    cout << "==========================================\n";
}

