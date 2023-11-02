#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int dice = 0;
    for(int i = 0; i < 2; i++)
    {
        dice += rand() % 6 + 1;
    }
    cout << dice;
}