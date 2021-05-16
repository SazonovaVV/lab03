#include <iostream>
#include <vector>
#include <cstdlib>
#include<conio.h>
#include <ctime>
#pragma hdrstop
using namespace std;

vector<double>
input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}
void
find_minmax(vector<double> numbers, double& min, double& max)
{
    min = numbers[0];
    max = numbers[0];
    for (double x : numbers)
    {
        if (x < min)
        {
            min = x;
        }
        else if (x > max)
        {
            max = x;
        }
    }
}
vector <size_t>
make_histogram(vector<double> numbers, double bin_count,double number_count)
{

    double max, min;
    find_minmax(numbers, min, max);
    double bin_size = (max - min) / bin_count;
    vector<size_t> bins(bin_count);
    for(int i = 0; i < number_count; i++)
    {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[bin_count - 1]++;
        }
    }
    return bins;
}
void
show_histogram_text(vector <size_t>bins,double bin_count, double number_count)
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
    size_t  Max = bins[0];
    for (size_t  j=1; j<bin_count; j++)
    {
        if (bins[j]>Max)
            Max = bins[j];
    }
    for (size_t  j=0; j<bin_count; j++)
    {
        if(bins[j]>=100)
            cout<<bins[j];
        if (bins[j]<10)
            cout <<"  "<< bins[j];
        else if (bins[j]<100)
            cout<< " "<< bins[j] ;
        cout << "|";
        if(number_count>MAX_ASTERISK)
        {
            size_t  height = MAX_ASTERISK * (static_cast<double>(bins[j]) / Max);
            for (size_t  a=0; a<height; a++)
            {
                cout << "*";
            }
        }
        else
            for(size_t a=0; a<bins[j]; a++)
                cout << "*";
        cout << endl;
    }
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
void svg_rect(double x, double y, double width, double height)
{
    cout << "<rect x='"<< x << "' y='" <<y<<"' width='" <<width <<"' height='" <<height <<"'/>\n";
}
void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='"<< baseline <<"'>"<<text<<"</text>\n";
}

void show_histogram_svg(const vector<size_t>& bins)
{
    svg_begin(400, 300);
    svg_text(20, 20, to_string(bins[0]));
    svg_rect(50, 0, bins[0] * 10, 30);
    svg_end();
}


int main()
{
    size_t number_count;



    cerr << "Enter number count:";
    cin>>number_count;
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter bin count: ";
    cin >> bin_count;
    const auto bins = make_histogram(numbers, bin_count,number_count);
    show_histogram_text(bins,bin_count,number_count);
    show_histogram_svg(bins);
    return 0;
}
