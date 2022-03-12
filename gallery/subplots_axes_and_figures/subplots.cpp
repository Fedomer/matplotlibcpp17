#include <matplotlibcpp17/pyplot.h>

using namespace std;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  {
    auto [fig, axs] = plt.subplots(3, 1);
    std::cout << axs.size() << std::endl;
  }
  {
    auto [fig, axs] = plt.subplots(1, 1);
    std::cout << axs.size() << std::endl;
  }
  {
    auto [fig, axs] = plt.subplots(3, 3);
    std::cout << axs.size() << std::endl;
  }
  return 0;
}
