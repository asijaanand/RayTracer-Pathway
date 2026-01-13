#include <cstdio>
#include <cstdlib>
#include <iostream>
// #include <random>
using namespace std;

int main() {
    int isize = 0;
    int jsize = 0;
    int blue = 0;
    cin >> isize >> jsize >> blue;

    FILE *fptr = fopen("output.ppm", "w");

    if (fptr == nullptr) {
        return -1;
    }

    fprintf(fptr, "P3\n %d %d\n255\n", isize, jsize);

    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<> distr(1, 100);

    for (int i = 0; i < jsize; i++) {
        for (int j = 0; j < isize; j++) {
            // int r_red = (int)((distr(gen) / 100) * 255);
            // int r_green = (int)((distr(gen) / 100) * 255);
            // int r_blue = (int)((distr(gen) / 100) * 255);
            int red = int((float(i) / float(jsize)) * 255);
            int green = int((float(j) / float(isize)) * 255);
            fprintf(fptr, "%d %d %d\n", red, green, blue);
        }
    }
    fclose(fptr);

    const char *script = "ffmpeg -i output.ppm output.png && rm output.ppm";
    system(script);
    return 0;
}
