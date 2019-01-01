#include <iostream>
#include <map>

int solution(std::string);

int main() {
    std::cout << solution("IV") << std::endl;
    std::cout << solution("XV") << std::endl;
    std::cout << solution("MMVIII") << std::endl;
    std::cout << solution("MDCLXVI") << std::endl;
    return 0;
}

class Roman {
private:
    std::map<char, int> converter;
public:
    Roman(){
        converter.insert(std::pair<char, int>('I', 1));
        converter.insert(std::pair<char, int>('V', 5));
        converter.insert(std::pair<char, int>('X', 10));
        converter.insert(std::pair<char, int>('L', 50));
        converter.insert(std::pair<char, int>('C', 100));
        converter.insert(std::pair<char, int>('D', 500));
        converter.insert(std::pair<char, int>('M', 1000));
    }

    int getValueAtKey(char roman_key){
        return converter.at(roman_key);
    }

    int getIntegerI(){
        return converter.at('I');
    };

    int getIntegerV(){
        return converter.at('V');
    };

    int getIntegerX(){
        return converter.at('X');
    };

    int getIntegerL(){
        return converter.at('L');
    };

    int getIntegerC(){
        return converter.at('C');
    };

    int getIntegerD(){
        return converter.at('D');
    };

    int getIntegerM(){
        return converter.at('M');
    };
};

int solution(std::string roman) {
    Roman *RomanConverter = new Roman();
    int summary_value = 0;
    if(roman.size() == 0){
        return summary_value;
    } else {
        char *sequence = new char[roman.size()];
        strcpy(sequence, roman.c_str());
        for(int index = 0; index < roman.size(); index++){
            if(index != roman.size() - 1 && RomanConverter->getValueAtKey(sequence[index]) < RomanConverter->getValueAtKey(sequence[index + 1])){
                summary_value += RomanConverter->getValueAtKey(sequence[index + 1]) - RomanConverter->getValueAtKey(sequence[index]);
                index++;
            } else {
                summary_value += RomanConverter->getValueAtKey(sequence[index]);
            }
        }
    }
    return summary_value;
}