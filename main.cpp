#include "include/compress.hpp"

/**
 * Displays the menu for the program and takes input from user on
 * 		options and filenames.
 * 
 * @return program ran successfully.
 */ 
int main()
{
	int choice;
	string original, compressed;
	cout << "Choose an option:\n";
	cout << "1: Compress a file using Run-length encoding"
		 << "\n";
	cout << "2: Decompress a file compressed with Run-length encoding"
		 << "\n";
	cin >> choice; // taking user input for choice

	switch (choice)
	{
	case 1:
		cout << "Provide the file to compress followed by a space and the output file"
			 << "\n";
		cin >> original >> compressed; // taking user input for filenames
		compress_or_decompress(original, compressed, true);
		break;
	case 2:
		cout << "Provide the compressed file followed by a space and the output file"
			 << "\n";
		cin >> compressed >> original; // taking user input for filenames
		compress_or_decompress(compressed, original, false);
		break;
	}
	display(original, compressed); // display the characer count and compression ratio

	return 0;
}
