#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    setName("Interactor A+B");
    registerInteraction(argc, argv);
    int a = inf.readInt();
    int b = inf.readInt();
    cout << a << " " << b << endl;
    long long pa = ouf.readLong();
    long long ja = a + b;
    if (ja == pa) quitp(0.5,"Your output is the same as the standard answer.");
    else if(pa<=2147483647&&0<=pa)quitf(_ok, "You really have no brain.");
    else quitf(_wa, "Your answer is wrong.");
}
