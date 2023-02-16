#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    for (int i = 3; i >= 0; i -- )
        printf("%d", n >> i & 1);
    return 0;
}