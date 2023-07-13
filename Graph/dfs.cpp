#include "dfs.hpp"
#include <fstream>
#include <sstream>

template<typename T>
void graph::Graph<T>::make_graph(const string &filename) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string line;
        if (std::getline(inputFile, line)) {

            size_t idx = 0;
            std::istringstream iss(line);
            if (iss >> numNodes_) {
//                adj_list.resize(numNodes_ +
//                                1); // Index 0 will be ignored for simplicity
                adj_list.resize(numNodes_); // Index 0 will be ignored for simplicity

                while (std::getline(inputFile, line)) {
                    std::istringstream iss(line);
                    T node;

                    if (iss >> node) {
                        Decorator<T> v;
                        v.set("node_data", new Integer<T>(node));
//                        std::cout << "Node data: " << v.get("node_data")->intValue();
//                        // Push node v to adj_list at idx
//                        std::cout << "Idx : " << idx << std::endl;
                        adj_list[idx].push_back(v);

                        T neighbor;
                        while (iss >> neighbor) {
//                            std::cout << "Node : " << node << " Neighbor :: " << neighbor << std::endl;
                            Decorator<T> nei;
                            nei.set("node_data", new Integer<T>(neighbor));
//                            std::cout << "Neighbor data : " << nei.get("node_data")->intValue();
//                            std::cout << "Idx : " << idx << std::endl;
                            adj_list[idx].push_back(nei);  // NOTE: adding neighbors to the node
                        }
                        idx++;

                    }
                }
//                ++idx;
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

    std::cout << "Graph building done" << std::endl;
    return;
}

template<typename T>
void graph::Graph<T>::print_graph() const {
    std::cout << "Graph is printed as follows: " << std::endl;
    std::cout << "Node data | Neighbor 1 Neighbor 2 ..." << std::endl;
    for (size_t i = 0; i < adj_list.size(); ++i) {
//        std::cout << "i: " << i << std::endl;
        // Traverse adj_list[i] and print the node data
        std::vector<Decorator<T>> v = adj_list[i];
        for (size_t j = 0; j < v.size(); ++j) {
            if (j == 0) {

                std::cout << v[j].get("node_data")->intValue() << " | ";
            } else {
                std::cout << v[j].get("node_data")->intValue() << " ";
            }
        }
        std::cout << std::endl;
    }

}
