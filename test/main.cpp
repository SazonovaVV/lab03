
#include "histogram.h"
#include "SVG.h"
#include <cassert>

	void test_positive()
	{
	    double min = 0;
	    double max = 0;
	    find_minmax({1, 2, 3}, min, max);
	    assert(min == 1);
	    assert(max == 3);
	}


	void
	test_negative()
	{
	    double min = 0;
	    double max = 0;
	    find_minmax({-1, -2, -3}, min, max);
	    assert(min == -3);
	    assert(max == -1);
	}
	void
	test_same()
	{
	    double min = 0;
	    double max = 0;
	    find_minmax({3, 3, 3}, min, max);
	    assert(min == 3);
	    assert(max == 3);
	}
	void
	test_onenumber()
	{
	    double min = 0;
	    double max = 0;
	    find_minmax({2}, min, max);
	    assert(min == 2);
	    assert(max == 2);
	}
	void
	test_empty()
	{
	    double min = 0;
	    double max = 0;
	    find_minmax({}, min, max);

	}
    void
    test_indiv1()
    {
        string text_decoration="underline";
        decor(text_decoration);
        assert(text_decoration == "underline");
    }
    void
    test_indiv2()
    {
        string text_decoration="underlin";
        decor(text_decoration);
        assert(text_decoration == "none");
    }
    void
    test_indiv3()
    {
        string text_decoration="none";
        decor(text_decoration);
        assert(text_decoration == "none");
    }
int main()
{
    test_positive();
    test_negative();
    test_same();
    test_onenumber();
    test_empty();
    test_indiv1();
    test_indiv2();
    test_indiv3();
}


