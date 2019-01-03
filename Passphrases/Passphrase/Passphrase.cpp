//
// Created by Dan Orel on 1/3/19.
//
#include "Passphrase.h"

std::string PlayPass::playPass(std::string *code, int shift){
    moveLetters(code, shift);
    replaceDigits(code);
    downcaseOddLetters(code);
    reverseResult(code);
    return *code;
}

void PlayPass::moveLetters(std::string *code, int shift){
    size_t size = code->size();
    char *code_chars = new char[size];
    strcpy(code_chars, code->c_str());
    for(int index = 0; index < size; index++){
        if((code_chars[index] <= 'Z' && code_chars[index] >= 'A') || ((code_chars[index] <= 'z') && code_chars[index] >= 'a')){
            code_chars[index] = static_cast<char>(code_chars[index] + shift);
        }
    }
    *code = "";
    for(int index = 0; index < size; index++){
        *code += code_chars[index];
    }
}

void PlayPass::replaceDigits(std::string *code){
    size_t size = code->size();
    char *code_chars = new char[size];
    strcpy(code_chars, code->c_str());
    for(int index = 0; index < size; index++){
        if((code_chars[index] <= '9' && code_chars[index] >= '1')){
            int digit = 9 - (code_chars[index] - '0');
            char c_digit = static_cast<char>(digit + 48);
            code_chars[index] = c_digit;
        }
    }
    *code = "";
    for(int index = 0; index < size; index++){
        *code += code_chars[index];
    }
}

void PlayPass::downcaseOddLetters(std::string *code){
    size_t size = code->size();
    char *code_chars = new char[size];
    strcpy(code_chars, code->c_str());
    for(int index = 0; index < size; index++){
        if(index % 2 == 1 && (code_chars[index] >= 'A' && code_chars[index] <= 'Z')){
            code_chars[index] = static_cast<char>(code_chars[index] + (97 - 65));
        }
    }
    *code = "";
    for(int index = 0; index < size; index++){
        *code += code_chars[index];
    }
}

void PlayPass::reverseResult(std::string *code){
    size_t size = code->size();
    char *code_chars = new char[size];
    char *temp_chars = new char[size];
    strcpy(code_chars, code->c_str());
    for(int index = 0, down = size - 1; index < size; index++, down--){
        temp_chars[index] = code_chars[down];
    }
    *code = "";
    for(int index = 0; index < size; index++){
        *code += temp_chars[index];
    }
}