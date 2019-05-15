#define CTEST_MAIN
#define CTEST_COLOR_OK

#include <crcl.h>
#include <ctest.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(test, perimetr)
{
    // Given
    Crcl in = {1.1, 1.2, 1.3, 0};

    // When
    const int result = perimetr(&in, 0);

    // Then
    const int expected = 8.168141;
    ASSERT_EQUAL(expected, result);
}

CTEST(test, area)
{
    // Given
    Crcl in = {1.1, 1.2, 1.3, 0};

    // When
    const int result = area(&in, 0);

    // Then
    const int expected = 5.309292;
    ASSERT_EQUAL(expected, result);
}

CTEST(test, check_intersection_true)
{
    // Given
    Crcl in[2];
    in[0].x = 1.1;
    in[0].y = 1.2;
    in[0].r = 1.3;
    in[0].ind = 0;
    in[1].x = 2.1;
    in[1].y = 2.2;
    in[1].r = 2.3;
    in[1].ind = 1;

    // When
    const int result = intersection(in, 0, 1);

    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(test, check_intersection_false)
{
    // Given
    Crcl in[2];
    in[0].x = 1.1;
    in[0].y = 1.2;
    in[0].r = 1.3;
    in[0].ind = 0;
    in[1].x = 2.1;
    in[1].y = 2.2;
    in[1].r = 0.1;
    in[1].ind = 1;

    // When
    const int result = intersection(in, 0, 1);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
