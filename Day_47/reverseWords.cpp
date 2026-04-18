#include <iostream>
using namespace std;

int main()
{

    string str = "The quick brown fox jumps over the lazy dog.";
    string tempStr = "";
    int end = 0;
    for (int i = 0; i <= str.length(); i++)
    {
        if (str[i] == ' ' || i == str.length())
        {
            for (int j = i - 1; j >= end; j--)
            {
                tempStr += str[j];
            }
            tempStr += " ";
            end = i + 1;
        }
    }
    cout << "REVERSED WORDS IN THE STRING:--->   " << tempStr << endl;

    return 0;
}

// now also works for single character inputt
//  string str = "h";
//     string tempStr = "";
//     int start = 0;
//     for (int i = 0; i < str.length(); i++)
//     {
//         if (str[i] == ' ' || i == str.length() - 1)
//         {
//             int temp = i;
//             while ((temp >= 0 && start == 0) || temp > start)
//             {
//                 tempStr += str[temp];
//                 temp--;
//             }
//             if (temp != str.length() - 1)
//             {
//                 tempStr += " ";
//             }
//             start = i;
//         }
//     }
//     cout << "REVERSED WORDS IN THE STRING:-->   " << tempStr << endl;

// only only work for a single chracter
//  string str = "hello world";
//     string tempStr = "";
//     int start = 0;
//     for (int i = 0; i < str.length(); i++)
//     {
//         if (str[i] == ' ' || i == str.length() - 1)
//         {
//             int temp = i;
//             while ((temp > 0 && start == 0) || temp > start)
//             {
//                 if (temp == str.length() - 1)
//                 {
//                     tempStr += str[temp];
//                 }
//                 tempStr += str[temp - 1];
//                 temp--;
//             }
//             if (temp != str.length() - 1)
//             {
//                 tempStr += " ";
//             }
//             start = i;
//         }
//     }
//     cout << "REVERSED WORDS IN THE STRING:-->   " << tempStr << endl;