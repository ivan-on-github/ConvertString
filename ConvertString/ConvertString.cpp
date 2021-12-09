#include <iostream>
#include <string>
#include <windows.h>
#include <map>
using namespace std;

int wmain()
{
    locale::global(locale(""));
    wcin.imbue(locale("." + std::to_string(GetConsoleCP())));
    
    wcout << "Please enter a string to convert:\n";
    wstring string_to_convert;
    getline(wcin, string_to_convert);

    wstring converted_string = string_to_convert;

    auto& facet = use_facet<ctype<wchar_t>>(locale());
    facet.tolower(&converted_string[0], &converted_string[0] + converted_string.size());

    map<wchar_t, int> numbers;
    for (wchar_t& c : converted_string) {
        numbers[c]++;
    }

    for (wchar_t& c : converted_string) {
        if (numbers[c] > 1)
            c = ')';
        else
            c = '(';
    }

    wcout << "\nResult:\n";
    wcout << converted_string << endl;

    cin.get();
    return 0;
}