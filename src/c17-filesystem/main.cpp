#include <filesystem>

int main()
{
    const auto myfile {"myfile"};
    if (std::filesystem::exists(myfile)) {
        const auto bigFileSize {std::filesystem::file_size(myfile)};
        std::filesystem::path tmpPath {"/tmp"};
        if (std::filesystem::space(tmpPath).available > bigFileSize) {
            std::filesystem::create_directory(tmpPath.append("example"));
            std::filesystem::copy_file(myfile, tmpPath.append("newFile"));
        }
    }

    return 0;
}
