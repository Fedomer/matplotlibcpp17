// example from
// https://matplotlib.org/stable/gallery/subplots_axes_and_figures/gridspec_multicolumn.html

#include <matplotlibcpp17/pyplot.h>

#include <vector>

using namespace std;
using matplotlibcpp17::gridspec::GridSpec;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();

  auto fig = plt.figure(Args(), Kwargs("constrained_layout"_a = true));

  auto gs = GridSpec(3, 3, Kwargs("figure"_a = fig.unwrap()));
  vector<axes::Axes> axs;
  axs.push_back(fig.add_subplot(Args(gs(0, py::slice(0, 3, 1)).unwrap())));
  axs.push_back(fig.add_subplot(Args(gs(1, py::slice(0, 2, 1)).unwrap())));
  axs.push_back(fig.add_subplot(Args(gs(py::slice(1, 3, 1), 2).unwrap())));
  axs.push_back(fig.add_subplot(Args(gs(2, 0).unwrap())));
  axs.push_back(fig.add_subplot(Args(gs(2, 1).unwrap())));
  fig.suptitle(Args("GridSpec"));

  int cnt = 1;
  for (auto &ax : axs) {
    ax.text(Args(0.5, 0.5, string("ax" + to_string(cnt))),
            Kwargs("va"_a = "center", "ha"_a = "center"));
    ax.tick_params(Args(),
                   Kwargs("labelbottom"_a = false, "labelleft"_a = false));
    cnt++;
  }

#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("gridspec_multicolumn.png"));
#endif
}
