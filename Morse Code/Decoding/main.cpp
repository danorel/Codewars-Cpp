#include <iostream>
#include <map>
#include <fstream>
#include <cstring>

class Morse_library {
private:
    std::map<std::string, char> vocabulary;
public:
    Morse_library(){
        vocabulary.insert(std::pair<std::string, char>(".-", 'A'));
        vocabulary.insert(std::pair<std::string, char>("-...", 'B'));
        vocabulary.insert(std::pair<std::string, char>(".. .", 'C'));
        vocabulary.insert(std::pair<std::string, char>("-..", 'D'));
        vocabulary.insert(std::pair<std::string, char>(".", 'E'));
        vocabulary.insert(std::pair<std::string, char>(".-.", 'F'));
        vocabulary.insert(std::pair<std::string, char>("--.", 'G'));
        vocabulary.insert(std::pair<std::string, char>("....", 'H'));
        vocabulary.insert(std::pair<std::string, char>("..", 'I'));
        vocabulary.insert(std::pair<std::string, char>("-.-.", 'J'));
        vocabulary.insert(std::pair<std::string, char>("-.-", 'K'));
        vocabulary.insert(std::pair<std::string, char>("---", 'L'));
        vocabulary.insert(std::pair<std::string, char>("--", 'M'));
        vocabulary.insert(std::pair<std::string, char>("-.", 'N'));
        vocabulary.insert(std::pair<std::string, char>("- -", 'O'));
        vocabulary.insert(std::pair<std::string, char>(".....", 'P'));
        vocabulary.insert(std::pair<std::string, char>("..-.", 'Q'));
        vocabulary.insert(std::pair<std::string, char>(". ..", 'R'));
        vocabulary.insert(std::pair<std::string, char>("...", 'S'));
        vocabulary.insert(std::pair<std::string, char>("-", 'T'));
        vocabulary.insert(std::pair<std::string, char>("..-", 'U'));
        vocabulary.insert(std::pair<std::string, char>("...-", 'V'));
        vocabulary.insert(std::pair<std::string, char>(".--", 'W'));
        vocabulary.insert(std::pair<std::string, char>(".-..", 'X'));
        vocabulary.insert(std::pair<std::string, char>(".. ..", 'Y'));
        vocabulary.insert(std::pair<std::string, char>("... .", 'Z'));
    }

    char lookForElementByKey(std::string key){
        return vocabulary.at(key);
    }

    void encode(std::string filename){
        std::string data = getDataFromFile(filename);
        char *data_in_chars;
        strcpy(data_in_chars, data.c_str());
        for(int index = 0; index < data.size(); index++){

        }
    }

    void decode(std::string filename){
        std::string data = getDataFromFile(filename);
        char *data_in_chars = new char[data.size()];
        std::string current_signal;
        strcpy(data_in_chars, data.c_str());
        auto iter = vocabulary.begin();
        for(int index = 0; index < data.size(); index++){
            while(data_in_chars[index] != ' ' && data_in_chars[index] != '\n'){
                current_signal += data_in_chars[index];
                index++;
            }
            while(iter != vocabulary.end()){
                if(iter->first == current_signal){
                    std::cout << iter->second << "";
                    break;
                }
                iter++;
            }
            if(data_in_chars[index] == ' '){
                std::cout << " ";
            }
        }
    }

    void createFile(std::string filename){
        std::ofstream file;
        file.open(filename);
        file.close();
    }

    std::string getDataFromFile(std::string filename){
        std::ifstream file(filename);
        std::string line;
        std::string data;
        if(file.is_open()){
            while(getline(file, line)){
                data += line + "\n";
            }
            file.close();
        } else {
            std::cerr << "Unable to open the given file!" << std::endl;
        }
        return data;
    }


};

int main() {
    Morse_library *library = new Morse_library();
    std::cout << library->getDataFromFile("Morse.txt") << std::endl;
    library->createFile("EncryptedMorse.txt");
    library->decode("EncryptedMorse.txt");
    return 0;
}