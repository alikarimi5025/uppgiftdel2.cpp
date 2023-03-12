#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

// This function takes a path to a directory to search for files containing specified strings.
void findtheString(const std::filesystem::path startPath){
	
  // This vector contains a list of strings to search for in files.
  std::vector<std::string> findStrings{ "Koffein", "Kaka", "Vatten","Mjölk"};
  // This vector contains a list of all the files in the directory represented by the startPath.
  std::vector fileList(std::filesystem::directory_iterator(startPath), {});

  // This loop iterates over each file in the fileList and checks if it is a regular file.
  for (const std::filesystem::directory_entry &de : fileList) {

    
    if (std::filesystem::is_regular_file(de.path())){

      // This block opens the file and reads its contents into a string called fileContent.
      if (std::ifstream fileStream{de.path().string()}; fileStream) {

        	
        	std::string fileContent(std::istreambuf_iterator<char>(fileStream), {});

        // This loop checks if any of the strings in findStrings are present in fileContent.
        for (const std::string &l : findStrings)
          if (std::search(fileContent.begin(), fileContent.end(), l.begin(),
           l.end()) != fileContent.end())

           // This prints a message indicating which file and which string were found.
          	std::cout << "File '" << de.path().string() << "' contains '" << l
            << "'\n";
      } else{
        // This block prints an error message to cerr if the file cannot be opened.
        std::cerr << "\n Error: the file could not open '" << de.path().string()
                  << "'\n";
      }
    }
    
    if (std::filesystem::is_directory(de.path())){
    	
     	findString(de.path());
    }
      
    }
}
// This main function calls findString with the path './TestData/' and returns 0 to indicate success.
int main() {

 findtheString("../TestData/"); 
  return 0;
}
