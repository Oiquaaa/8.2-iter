#include <iostream>
#include <string>

std::string findFirstWordStartingWithA(const std::string& s) {
    // Перебирає кожен символ у рядку
    for (int i = 0; i < s.size(); ++i) {
        // Якщо поточний символ не є пробілом, перевірте, чи є він «A»,«a»
        if (s[i] != ' ') {
            if (s[i] == 'a' ||
                s[i] == 'A') {
                // Якщо це «A» або «a», провірше решту слів, щоб знайти кінець
                int end = i + 1;
                while (end < s.size() && s[end] != ' ') {
                    ++end;
                }
                // Повернути слово, що починається з індексу "i" та закінчується індексом "end - 1"
                return s.substr(i, end - i);
            }
            // Якщо поточний символ не є "A,a", пропустіть решту слова
            while (i < s.size() && s[i] != ' ') {
                ++i;
            }
        }
    }
    // Якщо не знайдено жодного слова, що починається на «A», «a», поверніть порожній рядок
    return "";
}

int main() {
    std::string s = "Anna Synko and Victor Grygorovich";
    std::cout << findFirstWordStartingWithA(s) << std::endl;
    return 0;
}
