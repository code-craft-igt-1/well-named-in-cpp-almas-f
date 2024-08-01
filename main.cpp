#include <iostream>
#include <assert.h>
#include "TC_ColorCoder.h"

void testNumberToPair(int pairNumber,
    TC_ColorCoder::MajorColor expectedMajor,
    TC_ColorCoder::MinorColor expectedMinor)
{
    TC_ColorCoder::ColorPair colorPair =
        TC_ColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TC_ColorCoder::MajorColor major,
    TC_ColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TC_ColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

int main() {

    testNumberToPair(4, TC_ColorCoder::WHITE, TC_ColorCoder::BROWN);
    testNumberToPair(5, TC_ColorCoder::WHITE, TC_ColorCoder::SLATE);

    testPairToNumber(TC_ColorCoder::BLACK, TC_ColorCoder::ORANGE, 12);
    testPairToNumber(TC_ColorCoder::VIOLET, TC_ColorCoder::SLATE, 25);

    std::cout << "\nReference Manual:\n";
    TC_ColorCoder::PrintReferenceManual();

    return 0;
}
