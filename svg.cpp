#include "SVG.h"
#include <iostream>
#include <vector>

using namespace std;

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x='"<< x << "' y='" <<y<<"' width='" <<width <<"' height='" <<height <<"' stroke='"<< stroke <<"' fill='"<<fill<<"'/>\n";
}

void svg_text(double left, double baseline, string text,string text_decoration)
{
    cout << "<text x='" << left << "' y='"<< baseline <<"' text-decoration='" <<text_decoration << "'>"<<text<<"</text>\n";
}

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}
void show_histogram_svg(const vector<size_t>& bins,string text_decoration)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const auto MAX_COUNT = (IMAGE_WIDTH-TEXT_WIDTH)/ BLOCK_WIDTH;

    double top = 0;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    size_t count;
    size_t max_count = bins[0];
    for (size_t bin : bins)
    {
        if (bin > max_count)
        {
            max_count = bin;
        }
    }

    if (max_count > MAX_COUNT)
    {

        const double h = (double)MAX_COUNT / max_count;

        for (size_t bin : bins)
        {
            auto height = (size_t)(bin * h);
            const double bin_width = BLOCK_WIDTH * height;
            svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin),text_decoration);
            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black", "red");
            top += BIN_HEIGHT;

        }

        svg_end();
    }
    else
    {
        for (size_t bin : bins)
        {

            const double bin_width = BLOCK_WIDTH * bin;
            svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin),text_decoration);
            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black", "red");
            top += BIN_HEIGHT;

        }
        svg_end();

    }


}
void decor(string &text_decoration)
{
    if (text_decoration!="underline" & text_decoration!="line-through" & text_decoration!="none" & text_decoration!="overline")
    {
        text_decoration="none";
    }
    return ;
}
