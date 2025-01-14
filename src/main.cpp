#include "lib/Canvas/Canvas.h"

// Window
// 800x450 = 16:9
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 450;
constexpr int N_COL = 800;
constexpr int N_ROW = 450;

int main() {
    const Canvas canvas(WINDOW_WIDTH, WINDOW_HEIGHT, N_ROW, N_COL);
    canvas.Draw();
    return 0;
}