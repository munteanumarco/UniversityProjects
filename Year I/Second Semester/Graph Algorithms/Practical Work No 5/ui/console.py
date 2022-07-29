from domain.graph import Graph
from domain.validator import GraphException
from domain.undirected_graph import UndirectedGraph

import random

class GraphUIException(GraphException):
    pass


def read_undirected_graph_from_text_file(file_name):
    with open(file_name, "r") as file:
        firstLine = file.readline()
        firstLine = firstLine.strip().split()
        vertices, edges = int(firstLine[0]), int(firstLine[1])
        undirected_graph = UndirectedGraph(vertices)
        for times in range(edges):
            line = file.readline()
            line = line.strip().split()
            start, end, cost = int(line[0]), int(line[1]), int(line[2])
            try:
                undirected_graph.addEdge(start, end)
            except Exception as me:
                continue
    return undirected_graph

class GraphUI:
    def __init__(self):
        self.__graph = None

    def print_menu(self):
        print("0.Exit application\n"
              "1.Read a graph from a text file\n"
              "2.Add an edge\n"
              "3.Add a vertex\n"
              "4.Remove an edge\n"
              "5.Remove a vertex\n"
              "6.Find vertex cover\n"
              "7.Find minimum vertex cover\n")

    def read_from_file_ui(self):
        file_name = input("Please insert the name of the file you want to read from:")
        graph = read_undirected_graph_from_text_file(file_name)
        self.__graph = graph

    def add_edge(self):
        pass
    def add_vertex(self):
        pass
    def remove_edge(self):
        pass
    def remove_vertex(self):
        pass
    def vertex_cover(self):
        print("Vertex Cover of the graph : ")
        print(self.__graph.approximateVertexCover())
    def minimum_vertex_cover(self):
        print("Minimum vertex cover of the graph : ")
        print(self.__graph.greedyVertexCover())
    def console(self):
        while True:
            try:
                print("Graph options : \n")
                self.print_menu()
                user_option = input("Please select an option from above:")
                try:
                    user_option =  int(user_option)
                except:
                    raise GraphUIException("Invalid graph operation!(must be an integer)\n")

                if user_option == 0:
                    return
                elif  user_option == 1:
                    self.read_from_file_ui()
                elif user_option == 2:
                    self.add_edge()
                elif user_option == 3:
                    self.add_vertex()
                elif user_option == 4:
                    self.remove_edge()
                elif user_option == 5:
                    self.remove_vertex()
                elif user_option == 6:
                    self.vertex_cover()
                elif user_option == 7:
                    self.minimum_vertex_cover()
                else:
                    raise GraphUIException("Invalid graph operation!\n")

            except GraphException as exception:
                print("Exception occurred: " + str(exception))
