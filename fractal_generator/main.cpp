#include <complex>
#include <fstream>
#include <iostream>

#define SCALE 2

int n = 10000;

struct loc {
    float x;
    float y;
};

class Plain {
  private:
    loc point;

  public:
    Plain(int x, int y) : point{float(x), float(y)} {}

    int blue() {
        float x_co = (point.x - n) / float(n) * SCALE;
        float y_co = (point.y - n) / float(n) * SCALE;

        std::complex<double> z(0, 0);
        std::complex<double> c(x_co, y_co);

        int count = 255;
        for (int i = 0; i < 255; i++) {
            int norm = std::norm(z);
            if (norm > 4) {
                break;
            } else if (norm == 4) {
                return -1;
            } else {
                z = z * z + c;
                count--;
            }
        }
        return count;
    };
};

int main() {
    std::ofstream file("output.ppm");

    if (file.is_open()) {
        file << "P3" << '\n';
        file << n * 2 << " " << n * 2 << '\n';
        file << "255" << '\n';

        for (int i = 0; i < n * 2; i++) {
            for (int j = 0; j < n * 2; j++) {
                Plain obj(j, i);
                int val = obj.blue();
                if (val == -1) {
                    file << 255 << " " << 255 << " " << 255 << '\n';
                } else {
                    file << 0 << " " << 0 << " " << int(0.3 * val) << '\n';
                }
                std::cout << (float(i * n * 2 + j) / float(n * n * 4)) * 100
                          << '\n';
            }
        }
    }

    return 0;
}
