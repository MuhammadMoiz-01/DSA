#include "dfs.hpp"
#include <fstream>
#include <sstream>

template <typename T> void graph::Graph<T>::make_graph(const string &filename) {
  std::ifstream inputFile(filename);
  if (inputFile.is_open()) {
    std::string line;
    if (std::getline(inputFile, line)) {

      std::istringstream iss(line);
      if (iss >> numNodes_) {
        adj_list.resize(numNodes_ +
                        1); // Index 0 will be ignored for simplicity

        while (std::getline(inputFile, line)) {
          std::istringstream iss(line);
          T node;
          // Decorator<T> v;
          // v.set("node",new Integer<T>(node));
          if (iss >> node) {
              T neighbor;
            // Decorator<T> neighbor;
            while (iss >> neighbor) {
                std::cout << "Node : " << node << " Neighbor :: "<< neighbor << std::endl;
              // adj_list[node].push_back(neighbor);
            }
          }
        }
      } else {
        std::cerr << "Invalid number of nodes in the input file." << std::endl;
      }
    } else {
      std::cerr << "Failed to read the number of nodes from the input file."
                << std::endl;
    }
  } else {
    std::cerr << "Failed to open the input file." << std::endl;
  }
  return;
}
