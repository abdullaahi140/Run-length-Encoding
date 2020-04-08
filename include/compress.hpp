#ifndef COMPRESS_H
#define COMPRESS_H

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/**
 * Compresses a string using run-length encoding.
 * 
 * @param line String that is to be compressed using run-length encoding.
 * @return compressed string.
 */ 
string compress(string line);

/**
 * Decompresses a string that was compressed using run-length encoding.
 * 
 * @param line String that is to be decompressed by reversing run-length encoding.
 * @return decompressed string.
 */ 
string decompress(string line);

/**
 * Checks whether a file needs to compressed or decompressed using run-length
 * encoding.
 * 
 * @param filename1 The filename of the file that will be read.
 * @param filename2 The filename of the file that will be written to.
 * @param isCompress Boolean for determing whether the file needs to be
 * 		compressed or decompressed. 
 * @return file operation completed successfully.
 */ 
int compress_or_decompress(string filename1, string filename2, bool isCompress);

/**
 * Counts the amount of characters in a text file.
 * 
 * @param filename The filename of the file to be counted.
 * @return the integer of the amount of characters in the file.
 */ 
int count_chars(string filename);

/**
 * Calculates the compression ratio of the compressed and original files.
 * 
 * @param original The filename of the file that has not been compressed.
 * @param compressed The filename of the file that has been compressed. 
 * @return compression ratio of the files.
 */ 
float compression_ratio(float original, float compressed);

/**
 * Display the character count and compression ratio of two files.
 * 
 * @param original The filename of the file that has not been compressed.
 * @param compressed The filename of the file that has been compressed. 
 * @return statistics displayed successfully.
 */ 
int display(string original, string compressed);

#endif
