#include <iostream>
#include <vector>
#include "histogram.h"
#pragma hdrstop
#include "svg.h"
#include "func.h"
using namespace std;



int main()
{
    foo(2);
    size_t number_count;
    cerr << "Enter number count:";
    cin>>number_count;
    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cerr << "Enter bin count: ";
    cin >> bin_count;
    const auto bins = make_histogram(numbers, bin_count,number_count);


    string text_decoration;
    cerr << "Enter text-decoration: ";
    cin >> text_decoration;
    decor(text_decoration);

    show_histogram_svg(bins, text_decoration);
    return 0;
}
