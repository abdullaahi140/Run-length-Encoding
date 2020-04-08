#include "../include/compress.hpp"

/**
 * Compresses a string using run-length encoding.
 * 
 * @param line String that is to be compressed using run-length encoding.
 * @return compressed string.
 */
string compress(string line)
{
	int counter = 0;
	char compare;
	stringstream compressed;

	compare = line[0];						 // getting the first char in line
	for (int i = 0; i <= line.length(); i++) // iterating over each char in line
	{
		if (compare == line[i])
		{
			counter++; // incrementing the counter
		}
		else
		{
			compressed << counter << compare; // appending counter and char to string
			compare = line[i];				  // seting the char to compare
			counter = 1;					  // counting the char that's set in compare
		}
	}

	return compressed.str(); // returning the string from std::stringstream
}

/**
 * Decompresses a string that was compressed using run-length encoding.
 * 
 * @param line String that is to be decompressed by reversing run-length encoding.
 * @return decompressed string.
 */
string decompress(string line)
{
	int counter;
	stringstream str_counter;
	stringstream uncompressed;

	// for (int i = 0; i <= line.length(); i += 2) // iterating over each char in line
	// {
	// 	counter = line[i] - '0'; // converting char to int
	// 	for (int j = 0; j < counter; j++)
	// 	{
	// 		uncompressed << line[i + 1]; // appending counter amount of char in string
	// 	}
	// }

	int i = 0;
	while (i < line.length())
	{
		if (isdigit(line[i])) // checking if char is an integer
		{
			str_counter << line[i]; // appending integer to string counter
			i++;
		}
		else
		{
			counter = stoi(str_counter.str()); // converting string to integer
			for (int j = 0; j < counter; j++)
			{
				uncompressed << line[i]; // appeding char to string
			}
			i++;
			str_counter = stringstream(); // emptying string counter
		}
	}

	return uncompressed.str(); // returning the string from std::stringstream
}

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
int compress_or_decompress(string filename1, string filename2, bool isCompress)
{
	ifstream file1; // file to read from
	ofstream file2; // file to write to
	string line;

	// opening the files
	file1.open(filename1);
	if (!file1) // checking if file1 exists in file system
	{
		cout << filename1 << " does not exist"
			 << "\n";
		exit(1); // exit the program
	}
	file2.open(filename2);

	while (getline(file1, line)) // iterating over each line in file1
	{
		if (isCompress == true) // checking if file to be compressed
		{
			file2 << compress(line) << "\n"; // writting compressed string to file
		}
		else
		{
			file2 << decompress(line) << "\n"; // writing decompressed string to file
		}
	}

	// closing the files
	file1.close();
	file2.close();

	return 0;
}

/**
 * Counts the amount of characters in a text file.
 * 
 * @param filename The filename of the file to be counted.
 * @return the integer of the amount of characters in the file.
 */
int count_chars(string filename)
{
	ifstream file; // file to read from
	string line;
	int counter = 0;

	file.open(filename);		// opening file
	while (getline(file, line)) // iterating over each line in file
	{
		counter += line.length(); // counting chars in file
	}
	file.close(); // closing the file

	return counter;
}

/**
 * Calculates the compression ratio of the compressed and original files
 * 		by diving the charater count in the original file by the character
 * 		count of the compressed file.
 * 
 * @param original The filename of the file that has not been compressed.
 * @param compressed The filename of the file that has been compressed. 
 * @return compression ratio of the files.
 */
float compression_ratio(float original, float compressed)
{
	return original / compressed; // return compression ratio
}

/**
 * Display the character count and compression ratio of two files.
 * 
 * @param original The filename of the file that has not been compressed.
 * @param compressed The filename of the file that has been compressed. 
 * @return statistics displayed successfully.
 */
int display(string original, string compressed)
{
	int original_count = count_chars(original);		// counting chars in original file
	int compressed_count = count_chars(compressed); // counting chars in compressed file

	cout << "Chacters in " << original << ": " << original_count << "\n";
	cout << "Chacters in " << compressed << ": " << compressed_count << "\n";
	cout << "Compression ratio: " << compression_ratio(original_count, compressed_count) << "\n";

	return 0;
}
