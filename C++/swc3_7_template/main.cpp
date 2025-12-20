#include <optional>

#include "fs.h"
#include "utils.h"

int main() {
    ls(".");
    ls(R"(C:\)");

    try {
        std::optional<std::filesystem::path> path =
                find("CMakeCache.txt", ".");

        if (path.has_value()) {
            println("Found at {}", path->string());
        } else {
            println("Not found");
        }
    } catch (const std::filesystem::filesystem_error& e) { // mit const reference fangen weil performanter und keine Kopie erstellt wird
        std::cout << e.what() << '\n';
    }

    // ls(".");
    // ls("doesnotexist");
    // ls("/tmp");
    // ls("/bin");
}
