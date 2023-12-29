#include <iostream>
using namespace std;

string Scrambling(const string& code)
{
    string res;

    for(auto i = 0; i < code.length(); i++)
    {
        bool temp;
        if(i < 5)
            temp = code[i] - '0';

        else if(i < 9)
            temp = code[i] - '0' ^ res[i-5] - '0';

        else if(i < 11)
            temp = code[i] - '0' ^ res[i-5] - '0' ^ res[i-9] - '0' ;

        else
            temp = code[i] - '0' ^ res[i-5] - '0' ^ res[i-9] - '0' ^ res[i-11] - '0';

        res += std::to_string(temp);
    }
    return res;
}

string deScrambling(const string& code)
{
    string res;

    for(auto i = 0; i < code.length(); i++)
    {
        bool temp;
        if(i < 5)
            temp = code[i] - '0';

        else if(i < 9)
            temp = code[i] - '0' ^ code[i-5] - '0';

        else if(i < 11)
            temp = code[i] - '0' ^ code[i-5] - '0' ^ code[i-9] - '0' ;

        else
            temp = code[i] - '0' ^ code[i-5] - '0' ^ code[i-9] - '0' ^ code[i-11] - '0';

        res += to_string(temp);
    }
    return res;
}

void check(const string& A)
{
    if(A == deScrambling(Scrambling(A)))
        cout << "OK";
    else
        cout << "v(0_0)v   No((((";
}

int main()
{
    string test = "1100101000000000110000001111111111001110";
    cout << "Code:\t\t" << test << "\n";
    cout << "Scrambling:\t" << Scrambling(test) << "\n";
    printf("16bit res:\t%llX\n", strtoull(Scrambling(test).c_str(), NULL, 2) );
    cout << "deScrambling:\t" << deScrambling(Scrambling(test)) << "\n";
    cout << "Check:\t\t";
    check(test);
    return 0;
}