#include <iostream>
#include <vector>

std::vector<int> tribonacci(std::vector<int> &numbers, const int amount);

int main() {
    std::vector<int> signature;
    signature.push_back(1);
    signature.push_back(1);
    signature.push_back(1);
    tribonacci(signature, 10);
    for(int index = 0; index < signature.size(); index++){
        std::cout << signature[index] << " ";
    }
    return 0;
}

std::vector<int> tribonacci(std::vector<int>& numbers, const int amount){
    if(numbers.size() == amount){
        return numbers;
    } else {
        numbers.push_back( numbers[numbers.size() - 3] + numbers[numbers.size() - 2] + numbers[numbers.size() - 1]);
        tribonacci(numbers, amount);
    }
}
