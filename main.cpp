#include <iostream>
#include <locale.h>

#include"headers.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Polish");

    menu();
}
