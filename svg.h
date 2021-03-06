#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");

void svg_text(double left, double baseline,  string text);

void svg_begin(double width, double height);

void svg_end();

void decor(string &text_decoration);

void show_histogram_svg(const vector<size_t>& bins, string text_decoration);

#endif // SVG_H_INCLUDED
