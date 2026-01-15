#include <cstdlib>
#include <format>
#include <fstream>
#include <string>

int main() {
    int nx = 16 * 120;
    int ny = 9 * 120;

    for (int b = 0; b < 255; b++) {
        std::string name = std::format("output{:03}.ppm", b);
        std::ofstream file(name);

        if (file.is_open()) {
            file << "P3" << '\n';
            file << nx << " " << ny << '\n';
            file << 255 << '\n';

            for (int i = 0; i < ny; i++) {
                for (int j = 0; j < nx; j++) {
                    int red = int(float(i) / float(ny) * 255);
                    int green = int(float(j) / float(nx) * 255);

                    file << red << " " << green << " " << b << '\n';
                }
            }
        }
    }
    system("ffmpeg -i output%03d.ppm -r 120 out.mp4 && rm output*");
    return 0;
}
