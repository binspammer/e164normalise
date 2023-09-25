
#include "gtest/gtest.h"
#include "utils.h"

//
// 1) e.g. normalising a UK mobile number:

TEST( testE164normalise, mobileDomesticStartFromNoZero )
{
    EXPECT_EQ( "+447789977766", Utility::E164::normalise( "7789977766", "UK" ) );
}

TEST( testE164normalise, mobileDomesticStartFromZero )
{
    EXPECT_EQ( "+447789977766", Utility::E164::normalise( "07789977766", "UK" ) );
}

TEST( testE164normalise, mobileInternationalStartFromTwoZero )
{
    EXPECT_EQ( "+447789977766", Utility::E164::normalise( "00447789977766", "UK" ) );
}

TEST( testE164normalise, mobileInternationalStartFromPlusCountryCode )
{
    EXPECT_EQ( "+447789977766", Utility::E164::normalise( "+447789977766", "UK" ) );
}

TEST( testE164normalise, mobileInternationalStartFromPlusCountryCodeInBrackets )
{
    EXPECT_EQ( "+447789977766", Utility::E164::normalise( "(+44)7789977766", "UK" ) );
}

TEST( testE164normalise, mobileInternationalStartFromPlusCountryCodeAndZeroInBrackets )
{
    EXPECT_EQ("+447789977766", Utility::E164::normalise("+44(0)7789977766", "UK"));
}

//
// 2) e.g. normalising a UK PSTN number:

TEST( testE164normalise, landlineDomesticStartFromZero )
{
    EXPECT_EQ( "+442035100500", Utility::E164::normalise( "02035100500", "UK" ) );
}

TEST( testE164normalise, landlineInternationalStartFromTwoZero )
{
    EXPECT_EQ( "+442035100500", Utility::E164::normalise( "020 3510 0500", "UK" ) );
}

TEST( testE164normalise, landlineInternationalStartFromPlusCountryCode )
{
    EXPECT_EQ( "+442035100500", Utility::E164::normalise( "020-3510-0500", "UK" ) );
}

TEST( testE164normalise, landlineDomesticStartFromNonZero )
{
    EXPECT_EQ( "+442035100500", Utility::E164::normalise( "2035100500", "UK" ) );
}

TEST( testE164normalise, landlineInternationalStartFromDoubleZeroCountryCode )
{
    EXPECT_EQ( "+442035100500", Utility::E164::normalise( "00442035100500", "UK" ) );
}

TEST( testE164normalise, landlineDomesticStartFromPlusCountryCodeInBrackets )
{
    EXPECT_EQ( "+442035100500", Utility::E164::normalise( "(+44)2035100500", "UK" ) );
}

TEST( testE164normalise, landlineInternationalStartFromPlusCountryCodeAndZeroInBrackets )
{
    EXPECT_EQ( "+442035100500", Utility::E164::normalise( "+44(0)2035100500", "UK" ) );
}

//
// 3) e.g. not a UK number but already in E164 format:
TEST( testE164normalise, internationalStartFromPlusNonCountryCode )
{
    EXPECT_EQ( "+61262715111", Utility::E164::normalise( "+61262715111", "UK" ) );
}

//
// 4) e.g. normalising a AU PSTN/Mobile number:
TEST( testE164normalise, landlineDomesticStartFromZeroAU )
{
    EXPECT_EQ( "+61262715111", Utility::E164::normalise( "0262715111", "AU" ) );
}

//
// 5) normalising an internal extension:
TEST( testE164normalise, Extention )
{
    EXPECT_EQ( "12001", Utility::E164::normalise( "12001", "UK" ) );
}
