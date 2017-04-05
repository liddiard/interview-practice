#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

// http://stackoverflow.com/a/38675700/2487925
enum class byte : std::uint8_t {};

void drawHorizontalLine(vector<byte> screen, int width, int x, int x2, int y) {
  int height = screen.size() / width;
  // TODO
}