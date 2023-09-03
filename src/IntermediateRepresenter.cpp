#include <fstream>
#include <cstring>

char* ItermediatelyRepresent(char* str){

    std::ofstream outFile;
    outFile.open("log.txt", std::ios_base::app);
    int length = strlen(str);
    int skipAmount = 0;

    for (int i = 0; length - 3 > i; i++){
        char currentChar = str[i];
        if(skipAmount > 0){
            skipAmount -= 1;
            break;
        }

        if(currentChar != '\n' && currentChar != ' '){
            //outFile << str[i];
            return;
        }

        if (currentChar == 'm' && str[i + 1] == 'a' && str[i + 2] == 'i' && str[i + 3] == 'n') {
            outFile << "start\n";
            skipAmount = 3;
        }
        if (currentChar == 'p' && str[i + 1] == 'r' && str[i + 2] == 'i' && str[i + 3] == 'n' && str[i + 4] == 't') {
            outFile << "print ";
            skipAmount = 4;
        }
        if (currentChar == '(') {
            if(str[i + 1] == ')'){
                outFile << '\n';
            }
            if(str[i + 1] == '"'){
                
                while(){

                }
            }
        }


    }
    outFile << "end";
    outFile.close();
    
    return str;
}
