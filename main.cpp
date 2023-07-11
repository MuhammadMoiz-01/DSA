#include "Graph/dfs.cpp"

int main(int argc, char *argv[]) {
  Decorator v;

  v.set("number", new Integer(23));

  std::cout << v.get("number")->intValue() << std::endl;

  return 0;
}
