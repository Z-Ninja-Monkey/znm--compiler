#include <iostream>
#include <fstream>

#include <cstring>
#include <string>

#include <chrono>
#include <thread>

#include <unistd.h>

#include <windows.h>

int main(int argc, char** argv)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD originalAttributes = consoleInfo.wAttributes;


    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        std::cerr << "getcwd() error" << std::endl;
    }

    if (argc <= 2){
        std::cout<<"Missing Arguments"<<std::endl;
    } else {
        char* inputFile = argv[1];
        char* outputFile = argv[2];

        if (inputFile[strlen(inputFile)-3] == 'z' && inputFile[strlen(inputFile)-2] == 'n' && inputFile[strlen(inputFile)-1] == 'm'){
            std::cout<<"Input file is a regular syntax .znm file"<<std::endl;

            std::ifstream inFile;
            inFile.open(inputFile);
            if (inFile.is_open()){
                char* inFileChar = new char[100000];
                std::cout<<"Input file successfully opened"<<std::endl;

                inFile.read(inFileChar, 100000);
                std::cout<<inFileChar<<std::endl;

                delete[] inFileChar;
                inFile.close();

            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                std::cout<<"Error opening input file. \n Please check that the file exists and that you have permission to read it"<<std::endl;
                SetConsoleTextAttribute(hConsole, originalAttributes);
            }

        }
    }
    

    for (int i = 0; i < argc; i++){
        /*
        if(strcmp(argv[i],"bob") == 0){
            
            std::cout<<"You asked for bob, so you get bob! \n";
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            for (int i = 0; i < 300; i++){
                std::cout<<"BOB \n";
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
            }
        }*/
    }
    
    return 0;
}
