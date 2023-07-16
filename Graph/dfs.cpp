#include "dfs.hpp"
#include <fstream>
#include <sstream>
#include <stack>

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

template<typename T>
void graph::Graph<T>::setVisit(T data, bool state) {
    for(size_t i=0; i<adj_list.size(); i++){
        std::vector<Decorator<T>> v = adj_list[i];
        if(v[0].get("node_data")->intValue() == data){
            v[0].get("visited")->setValue(state);
            break;
        }
    }
    return;
}

template<typename T>
bool graph::Graph<T>::getVisit(T data) {
    bool visitState=false;
    for(size_t i=0; i<adj_list.size(); i++){
        std::vector<Decorator<T>> v = adj_list[i];
        if(v[0].get("node_data")->intValue() == data){
            visitState = v[0].get("visited")->intValue();
            break;
        }
    }
    return visitState;
}

template<typename T>
void graph::Graph<T>::initialize() {
    std::cout << "Making visited state in every node and setting it to false" << std::endl;
    for(size_t i=0; i<adj_list.size(); i++){
        std::vector<Decorator<T>> v = adj_list[i];
        v[0].set("visited", new Integer<bool>(false));
    }
    return;

}

template<typename T>
std::vector<Decorator<T>> graph::Graph<T>::neighbor(T data) {
    std::vector<Decorator<T>> v;
    for(size_t i=0; i<adj_list.size(); i++){
        v = adj_list[i];
        if (v[0].get("node_data")->intValue == data){
            break;
        }
    }
    return v;
}

template<typename T>
void graph::Graph<T>::RunDFS(T start_val) {

    std::cout << "Node : " << start_val << std::endl;
    this->setVisit(start_val, true);
    auto neighbor = this->neighbor(start_val);
    neighbor.erase(neighbor.begin()); // remove the first element as it is the node
    for(auto nei: neighbor){
        T nei_val = nei.get("node_data")->intValue();
        if(!this->getVisit(nei_val)){
            DFS(nei);
        }
    }
    return;
}

template<typename T>
void graph::Graph<T>::DFS(T start) {
    // initialize visited states
    this->initialize();
    // call run dfs
    this->RunDFS(start);
    return;
}
