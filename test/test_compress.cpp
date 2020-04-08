#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/compress.hpp"

TEST_CASE("Strings can be compressed with run-length encoding")
{
	REQUIRE(compress("bbbbaaaaaccchhhhh") == "4b5a3c5h");
	REQUIRE(compress("nnnnnnnnnnnnnbbbbbbbbbbbbbbbzzz") == "13n15b3z");
	REQUIRE(compress("nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn") == "100n");
}

TEST_CASE("Strings can be decompressed with run-length encoding")
{
	REQUIRE(decompress("4b5a3c5h") == "bbbbaaaaaccchhhhh");
	REQUIRE(decompress("13n15b3z") == "nnnnnnnnnnnnnbbbbbbbbbbbbbbbzzz");
	REQUIRE(decompress("100n") == "nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
}

TEST_CASE("Characters can be counted in a file")
{
	REQUIRE(count_chars("test/text files/compress_1.txt") == 98);
	REQUIRE(count_chars("test/text files/compress_2.txt") == 75);
	REQUIRE(count_chars("test/text files/compress_3.txt") == 17);
	REQUIRE(count_chars("test/text files/decompress_1.txt") == 112);
	REQUIRE(count_chars("test/text files/decompress_2.txt") == 70);
	REQUIRE(count_chars("test/text files/decompress_3.txt") == 8);
}

TEST_CASE("Compression ration can be calculated")
{
	const float testFloat = 0.765306122;
	REQUIRE(compression_ratio(98, 112) == 0.875);
	REQUIRE(compression_ratio(75, 98) == testFloat);
	REQUIRE(compression_ratio(17, 8) == 2.125);
}
