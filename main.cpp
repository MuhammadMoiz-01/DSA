#include "Graph/dfs.cpp"
// #include "Graph/dfs.hpp"
// #include <filesystem>
#include <fstream>
#include <stdexcept>
#include <filesystem>


#define print(x) std::cout << x << std::endl;

int main(int argc, char *argv[]) {
    // Decorator<string> v;
    //
    // v.set("number", new Integer<string>("alpha"));
    //
    // std::cout << v.get("number")->intValue() << std::endl;

    /*----------------------------------------------------------------*/
    graph::Graph<int> G;
    std::string filename = "./Graph/Data/data.txt"; // data1.txt contains string data
    G.make_graph(filename);
    G.print_graph();
    G.DFS(0);
    // std::filesystem::path currentPath = std::filesystem::current_path();
    // std::cout << "Current working directory: " << currentPath << std::endl;
    // NOTE: opening file and building graph from txt file

//    try {
//        print("Trying to open file");
//        std::ifstream inputFile(filename, std::ios::in);
//        if (!inputFile) {
//            throw std::runtime_error("File does not exists" + filename);
//        }
//        if (inputFile.is_open()) {
//
//            print("File opened");
//        } else {
//            print("ERROR !")
//        }
//        std::cout << "Graph building done" << std::endl;
//
//    } catch (const std::exception &e) {
//        std::cerr << "Exception occured <===> " << e.what() << std::endl;
//    }

    return 0;
}
