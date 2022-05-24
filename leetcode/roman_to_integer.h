#pragma once

#include <string>

using std::string;

bool is_single_digit_num(char ch1, char ch2);
int  get_single(char ch);
int  get_double(char ch);

//O(N)
int roman_to_integer(const string& s)
{
    int result(0);
    for (int i(0); i < s.length(); )
    {
        if (i + 1 == s.length() || is_single_digit_num(s[i], s[i + 1]))
        {
            result += get_single(s[i]);
            ++i;
        }
        else
        {
            result += get_double(s[i + 1]);
            i += 2;
        }
    }

    return result;
}

bool is_single_digit_num(char ch1, char ch2)
{
    if (ch1 == 'I' && (ch2 == 'V' || ch2 == 'X'))
        return false;

    if (ch1 == 'X' && (ch2 == 'L' || ch2 == 'C'))
        return false;

    if (ch1 == 'C' && (ch2 == 'D' || ch2 == 'M'))
        return false;

    return true;
}

int get_single(char ch)
{
    switch (int(ch))
    {
        case int('I') : return 1;
        case int('V') : return 5;
        case int('X') : return 10;
        case int('L') : return 50;
        case int('C') : return 100;
        case int('D') : return 500;
        case int('M') : return 1000;
    }

    return 0;
}

int get_double(char ch)
{
    switch (int(ch))
    {
        case int('V') : return 4;
        case int('X') : return 9;
        case int('L') : return 40;
        case int('C') : return 90;
        case int('D') : return 400;
        case int('M') : return 900;
    }

    return 0;
}

/*
I  - 1
IV - 4
V  - 5
IX - 9
X  - 10
XL - 40
L  - 50
XC - 90
C  - 100
CD - 400
D  - 500
CM - 900
M  - 1000

I < V && I < X
X < L && X < C
C < D && C < M
*/