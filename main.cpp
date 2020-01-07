#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "z_function.hpp"
#include "r_function.hpp"
#include "n_function.hpp"
#include "l_little_function.hpp"
#include "l_big_function.hpp"

int main() {
    std::string pattern, str;
    std::cout << "Input pattern: ";
    std::cin >> pattern;
    std::cout << "Input text: ";
    std::cin >> str;

    std::vector<int> N(pattern.size());
    NFunction(pattern, N);
    std::vector<int> L = LBigFunction(pattern, N);
    std::vector<int> l = LLittleFunction(pattern, N);
    std::vector<std::vector<int>> R(26);
    RFunction(pattern, R);

    int k = pattern.size() - 1;
    while (k < str.size()) {
        int i = pattern.size() - 1;
        int h = k;
        while ((i >= 0) && (pattern[i] == str[h])) {
            i--;
            h--;
        } 
        if (i == -1) {
            std::cout << "Match found!!!\n";
            k = k + pattern.size() - l[2];
        } else {
            int maxSuff;
            if (i == pattern.size() - 1) {
                maxSuff = 1;
            } else {
                if (L[i + 1] > 0) {
                    maxSuff = pattern.size() - L[i + 1] - 1;
                } else {
                    maxSuff = pattern.size() - l[i + 1] - 1;
                }
            }
            int maxSymb = pattern.size();
            for (int j = 0; j < R[str[h] - 97].size(); j++) {
                if (R[str[h] - 97][j] < i) {
                    maxSymb = std::max(1, i - R[str[h] - 97][j]);
                    break;
                }
            }
            k += std::max(maxSuff, maxSymb);
        }
    }
    
    return 0;
}