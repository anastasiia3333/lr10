#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    ifstream source_file("source.txt");
    ofstream destination_file("destination.txt");

    if (!source_file || !destination_file) 
    {
        cerr << "Error." << endl;
        return 1;
    }

    char ch;
    int count = 0;

    while (source_file.get(ch)) 
    {
        destination_file.put(ch);
        count++;
    }

    cout << "Quantity of copied characters: " << count << endl;
    source_file.close();
    destination_file.close();

    return 0;
}


// int countWordsInFile(const string& filename) 
// {
//     ifstream file(filename);
//     char ch;
//     int wordCount = 0;

//     if (file.is_open()) 
//     {
//         bool inWord = false;
//         while (file.get(ch)) 
//         {
//             if (isspace(ch)) 
//             {
//                 inWord = false;
//             } else if (!inWord)
//             {
//                 inWord = true;
//                 wordCount++;
//             }
//         }
//         file.close();
//     } else 
//     {
//         cerr << "Error!! " << filename << endl;
//         return -1;
//     }

//     return wordCount;
// }

// int main() 
// {
//     string filename = "file.txt";
//     int wordCount = countWordsInFile(filename);
//     if (wordCount != -1) 
//     {
//         cout << "Quantity of words in file: " << wordCount << endl;
//     }

//     return 0;
// }
