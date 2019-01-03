#include "Passphrase.h"

int main() {
    PlayPass *pass = new PlayPass();
    std::string passcode = "I LOVE YOU!!!";
    std::string *str_passcode = &passcode;
    std::string result = pass->playPass(str_passcode, 1);
    std::cout << result << std::endl;
    return 0;
}