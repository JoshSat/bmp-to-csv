#include <iostream>
#include <fstream> // Include the fstream library for file input/output

// Function to convert a bitmap image to a CSV file
void convertBitmapToCsv(const std::string& inputFile, const std::string& outputFile)
{
  // Open the input and output files
  std::ifstream in(inputFile, std::ios::binary);
  std::ofstream out(outputFile);

  // Read the bitmap header from the input file
  char header[54];
  in.read(header, 54);

  // Check if the input file is a valid bitmap
  if (header[0] != 'B' || header[1] != 'M')
  {
    std::cout << "Error: Invalid bitmap file" << std::endl;
    return;
  }

  // Get the size of the bitmap from the header
  int width = *(int*)&header[18];
  int height = *(int*)&header[22];

  // Read the bitmap data from the input file
  char* data = new char[width * height * 3];
  in.read(data, width * height * 3);

  // Loop through the bitmap data and write it to the output file
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      int index = (i * width + j) * 3;
      out << (int)(unsigned char)(data[index]) << ","; //index 1 or two to get the other data types for RGB if color is used
    }
    out << std::endl;
  } 

  // Close the input and output files
  in.close();
  out.close();
}

// Main function
int main()
{
  // Example usage:
  convertBitmapToCsv("input4.bmp", "output.csv");

  return 0;
} 
