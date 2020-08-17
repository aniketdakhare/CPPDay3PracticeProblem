#include <iostream>
#include <fstream>
using namespace std;

string readfile(string file)
{
    fstream fileStream;
    string line;
    string container;
    fileStream.open(file);
    if (fileStream.is_open())
    {
        while (getline (fileStream, line))
        {
            container.append(line);
            container.append("\n");
        }
        fileStream.close();
    }
    return container;
}

void writeFile(string file, string container)
{
    fstream fileStream (file, ios::out | ios::trunc);
    if (fileStream.is_open())
    {
        fileStream << container;
    }
    fileStream.close();    
}

int main()
{
    string firstContainer, secondContainer;
    string firstFile = "a.txt";
    string secondFile = "b.txt";
    
    firstContainer = readfile(firstFile);
    secondContainer = readfile(secondFile);
    writeFile(firstFile, secondContainer);
    writeFile(secondFile, firstContainer);
}