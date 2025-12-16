#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <string>
#include <format>
#include <sstream>
#include <ranges>

#include "entry.h"
#include "utils.h"






int main(int argc, char *argv[]) {
    std::map<std::string, std::vector<int>> index;

    std::ifstream fin = open_stream(argc, argv);

    int line_no = 1;

    while (!fin.eof()) {
        std::string line;
        std::getline(fin, line);

        line = normalize(line);
        std::istringstream iss{line};

        std::for_each(std::istream_iterator<std::string>(iss),
                      std::istream_iterator<std::string>{},
            [&index, line_no](std::string s) {
                index[s].push_back(line_no);
            });

        std::cout << "\nline "<< line_no << ": " << line << std::endl;
        line_no++;
    }

    for (const auto& [s, line_mumbers] : index) {
        std::cout << std::format("{} ({}) ", s, line_mumbers.size());

        std::copy(std::begin(line_mumbers), std::end(line_mumbers),
            std::ostream_iterator<int>(std::cout, ", "));

        std::cout << std::endl;
    }






    std::vector<std::string> words;

    // Auslesen
    std::transform(
        std::istream_iterator<std::string>{fin},
        std::istream_iterator<std::string>{},
        std::back_inserter(words),
        [](std::string s) { // würde auch ohne lambda gehen weil Schnittstelle String erwartet und String zurückgibt
            return normalize(s);
        }
    );

    // Sortieren
    std::sort(std::begin(words), std::end(words));

    // Duplikate entfernen
    auto it = std::unique(std::begin(words), std::end(words)); // schiebt Duplikate nur nach hinten
    words.erase(it, std::end(words));

    std::copy(std::begin(words), std::end(words),
    std::ostream_iterator<std::string>(std::cout, ", "));

    std::cout << words.size() << " words" << std::endl;



    // LESERLICH
    // while (fin.good()) {
    //     std::string word;
    //     fin >> word;
    //
    //     words.push_back(word);
    // }


    return 0;
}
