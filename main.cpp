#include "Graph/dfs.cpp"
// #include "Graph/dfs.hpp"
// #include <filesystem>
#include <fstream>
#include <stdexcept>

#define print(x) std::cout << x << std::endl;
int main(int argc, char *argv[]) {
  // Decorator<string> v;
  //
  // v.set("number", new Integer<string>("alpha"));
  //
  // std::cout << v.get("number")->intValue() << std::endl;

  /*----------------------------------------------------------------*/
  graph::Graph<int> G;
  // G.make_graph("~/Documents/GitHub/DSA/Graph/data.txt");

  // HACK: opening file and building graph from txt file
  std::string filename = "~/Documents/GitHub/DSA/Graph/data.txt";

  try {
    print("Trying to open file");
    std::ifstream inputFile(filename, std::ios::in);
    if (!inputFile) {
      throw std::runtime_error("File does not exists" + filename);
    }
    if (inputFile.is_open()) {

      print("File opened");
    } else {
      print("ERROR !")
    }
    std::cout << "Graph building done" << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Exception occured <===> " << e.what() << std::endl;
  }

  return 0;
}
