// Add the move , set, and display operations to your
// version of Screen . Test your class by executing the following code:

#include "ex7_27.h"
using namespace std;

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";

    return 0;
}