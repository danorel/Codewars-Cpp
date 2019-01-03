//
// Created by Dan Orel on 1/3/19.
//

#include <iostream>

#ifndef PASSPHRASE_PASSPHRASE_H
#define PASSPHRASE_PASSPHRASE_H
class PlayPass
{
public:
    std::string playPass(std::string *, int);
private:
    void moveLetters(std::string *, int);
    void replaceDigits(std::string *);
    void downcaseOddLetters(std::string *);
    void reverseResult(std::string *);
};
#endif //PASSPHRASE_PASSPHRASE_H
