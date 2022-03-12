#include <matplotlibcpp17/pyplot.h>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  vector<int> data;
  const int N = 10;
  for (int i = 0; i <= N; ++i) {
    plt.xlim(Args(0, 10));
    plt.ylim(Args(0, 10));
    data.push_back(i);
    plt.plot(Args(data));
    plt.pause(Args(1));
    plt.cla();
  }
  return 0;
}
