# draw the function y = x^2 using manima animation

from manimlib.imports import *

class Graph(GraphScene):
    CONFIG = {
        "x_min": -10,
        "x_max": 10,
        "y_min": -1,
        "y_max": 100,
        "graph_origin": ORIGIN,
        "function_color": RED,
        "axes_color": GREEN,
    }

    def construct(self):
        self.setup_axes(animate=True)
        graph = self.get_graph(lambda x: x**2, self.function_color)
        graph_lab = self.get_graph_label(graph, label = "x^2")
        self.play(ShowCreation(graph), ShowCreation(graph_lab))
        self.wait(3)

if __name__ == "__main__":
    module_name = os.path.basename(__file__)
    command_A = "manim -p -ql " + module_name + " Graph"
    os.system(command_A)

# I am using manim 0.1.10 and python 3.7.3

# I am trying to create a graph of a function using manim animation. I am using the following code:
