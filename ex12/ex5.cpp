#include <iostream>
#include <cstdio>
#include <cstring>
#include <cerrno>

int main() {
    // Deliberately open a file that does not exist
    const char *src = "/tmp/this_file_does_not_exist.txt";
    const char *dst = "/tmp/output_copy.txt";

    FILE *in = fopen(src, "rb");
    if (in == NULL) {
        int err = errno;
        std::cerr << "Error: failed to open source file '" << src << "'\n";
        std::cerr << "errno = " << err << "\n";
        std::cerr << "strerror: " << strerror(err) << "\n";
        // perror also prints the system error string
        perror("perror output");
        return 1;
    }

    FILE *out = fopen(dst, "wb");
    if (out == NULL) {
        int err = errno;
        std::cerr << "Error: failed to open destination file '" << dst << "'\n";
        std::cerr << "errno = " << err << "\n";
        std::cerr << "strerror: " << strerror(err) << "\n";
        perror("perror output");
        fclose(in);
        return 1;
    }

    char buf[4096];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), in)) > 0) {
        if (fwrite(buf, 1, n, out) != n) {
            int err = errno;
            std::cerr << "Error: write failed\n";
            std::cerr << "errno = " << err << " : " << strerror(err) << "\n";
            fclose(in);
            fclose(out);
            return 1;
        }
    }

    if (ferror(in)) {
        int err = errno;
        std::cerr << "Error: read error on source file\n";
        std::cerr << "errno = " << err << " : " << strerror(err) << "\n";
    }

    fclose(in);
    fclose(out);
    std::cout << "Copy completed successfully.\n";
    return 0;
}
