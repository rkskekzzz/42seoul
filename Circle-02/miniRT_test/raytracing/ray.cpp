#include <stdio.h>

int main() {

    // Image

    const int image_width = 256;
    const int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            auto g = double(i) / (image_width-1);
            auto r = double(j) / (image_height-1);
            auto b = 1;

            // std::cout << r << ' ' << g << ' ' << b << '\n';
            int ir = (int)(255.999 * r);
            int ig = (int)(255.999 * g);
            int ib = (int)(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}
