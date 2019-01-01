#include <iostream>
using namespace std;

string encrypt(string, int);
string decrypt(string, int);

int main() {
    cout << encrypt("This is a test!", 1) << endl;
    cout << decrypt("hskt svr neetn!Ti aai eyitrsig", 1) << endl;
    return 0;
}

string encrypt(string text, int times){
    if(times <= 0){
        return text;
    }

    string corrected_text, temp_text;
    char *elements = new char[text.size()]
    strcpy(elements, text.c_str());
    for(int index = 0; index < text.size(); index++){
        index % 2 == 1 ? corrected_text += elements[index] : temp_text += elements[index];
    }
    corrected_text += temp_text;

    return encrypt(corrected_text, --times);
}

string decrypt(string encrypted_text, int times){
    if(times <= 0){
        return encrypted_text;
    }

    char *elements = new char[encrypted_text.size()];
    strcpy(elements, encrypted_text.c_str());
    char *last_version = new char[encrypted_text.size()];
    string last_string_version;

    if(encrypted_text.size() % 2 == 0){
        for(int index = 0; index < encrypted_text.size(); index++){
            index < (encrypted_text.size() / 2) ? last_version[2 * index + 1] = elements[index] : last_version[2 * index - encrypted_text.size()] = elements[index];
        }

        for(int index = 0; index < encrypted_text.size(); index++){
            last_string_version += last_version[index];
        }
    } else {
        for(int index = 0; index < encrypted_text.size(); index++){
            index < (encrypted_text.size() / 2) ? last_version[2 * index + 1] = elements[index] : last_version[2 * index - encrypted_text.size() + 1] = elements[index];
        }

        for(int index = 0; index < encrypted_text.size(); index++){
            last_string_version += last_version[index];
        }
    }


    return decrypt(last_string_version, --times);
}
