from domain.graph import Graph
from domain.validator import GraphException
import random

class GraphUIException(GraphException):
    pass

def write_graph_to_text_file(graph,file_name):
    file = open(file_name, "w")
    first_line = str(graph.number_of_vertices) + ' ' + str(graph.number_of_edges) + '\n'
    file.write(first_line)
    if len(graph.dict_cost) == 0 and len(graph.dict_in) == 0:
        raise GraphUIException("There is nothing that can be written!")
    for edge in graph.dict_cost.keys():
        new_line = str(edge[0]) + " " + str(edge[1]) + " " + str(graph.dict_cost[edge]) + "\n"
        file.write(new_line)
    for vertex in graph.dict_in.keys():
        if len(graph.dict_in[vertex]) == 0 and len(graph.dict_out[vertex]) == 0:
            new_line = str(vertex) + "\n"
            file.write(new_line)
    file.close()

def read_graph_from_text_file(file_name):
    file = open(file_name, "r")
    line = file.readline()
    line = line.strip()
    vertices, edges = line.split(' ')
    graph = Graph(int(vertices), int(edges))
    line = file.readline().strip()
    while len(line) > 0:
        line = line.split(' ')
        if len(line) == 1:
            graph.dictionary_in[int(line[0])] = []
            graph.dictionary_out[int(line[0])] = []
        else:
            graph.dict_in[int(line[1])].append(int(line[0]))
            graph.dict_out[int(line[0])].append(int(line[1]))
            graph.dict_cost[(int(line[0]), int(line[1]))] = int(line[2])
        line = file.readline().strip()
    file.close()
    return graph


class GraphUI:
    def __init__(self):
        self.__graph = None
        self.__graph_collection = []

    def print_menu(self):
        print("0.Exit application\n"
              "1.Read a graph from a text file\n"
              "2.Write a graph to a text file\n"
              "3.Get the number of vertices\n"
              "4.Get the number of edges\n"
              "5.Parse the set of vertices\n"
              "6.Find if edge exists\n"
              "7.Get the in degree and outer degree of a specified vertex\n"
              "8.Parse the set of outbound edges of a specified vertex\n"
              "9.Parse the set of inbound edges of a specified vertex\n"
              "10.Add an edge\n"
              "11.Add a vertex\n"
              "12.Remove an edge\n"
              "13.Remove a vertex\n"
              "14.Create a random graph\n"
              "15.Add an empty graph\n"
              "16.Modify the cost of an edge\n"
              "17.Switch the graph\n"
              "18.Create a copy of the current graph\n"
              "19.Parse all inbound vertices of the graph\n"
              "20.Parse all outbound vertices of the graph\n")

    def read_from_file_ui(self):
        file_name = input("Please insert the name of the file you want to read from:")
        graph = read_graph_from_text_file(file_name)
        self.__graph = graph
        self.__graph_collection.append(graph)

    def write_to_file_ui(self):
        output_file = "output.txt"
        write_graph_to_text_file(self.__graph, output_file)

    def print_nr_of_vertices(self):
        print("The number of verticies of the current graph is : " + str(self.__graph.number_of_vertices))

    def print_nr_of_edges(self):
        print("The number of edges of the current graph is : " + str(self.__graph.number_of_edges))

    def print_all_vertices(self):
        print("The vertices are:")
        for vertex in self.__graph.parse_vertices():
            print(str(vertex))

    def find_edge(self):
        x = int(input("Please insert x:"))
        y = int(input("Please insert y:"))

        cost = self.__graph.is_edge(x, y)

        if cost is not False:
            print("There is an edge from vertex " + str(x) + " to vertex " + str(y) + " of cost " + str(cost))
        else:
            print("There is no edge from vertex " + str(x) + " to vertex " + str(y) + " of cost " + str(cost))

    def get_in_out_degree(self):
        while True:
            vertex = int(input("Please insert the vertex:"))
            if self.__graph.is_vertex(vertex):
                break
            print("No vertex present! Try again.")

        user_option = input("Please choose :\n"
                            "1.In degree of a specified vertex\n"
                            "2.Out degree of a specified vertex\n")
        try:
            user_option = int(user_option)
        except:
            raise GraphUIException("Invalid degree option!(integers only)\n")

        if user_option == 1:
            degree = self.__graph.in_degree(vertex)
            print("The in degree of vertex " + str(vertex) + " is " + str(degree))
        elif user_option == 2:
            degree = self.__graph.out_degree(vertex)
            print("The out degree of vertex " + str(vertex) + " is " + str(degree))
        else:
            raise GraphUIException("Invalid degree option!\n")

    def parse_inbound(self):
        while True:
            vertex = int(input("Please insert the vertex:"))
            if self.__graph.is_vertex(vertex):
                break
            print("No vertex present! Try again.")

        line = str(vertex) + " :"
        for y in self.__graph.parse_inbound(vertex):
            line = line + " " + "({}, {})".format(str(vertex), str(y))
        print(line)

    def parse_outbound(self):
        while True:
            vertex = int(input("Please insert the vertex:"))
            if self.__graph.is_vertex(vertex):
                break
            print("No vertex present! Try again.")

        line = str(vertex) + " :"
        for y in self.__graph.parse_outbound(vertex):
            line = line + " " + "({}, {})".format(str(vertex), str(y))
        print(line)

    def add_edge(self):
        print("Add a new edge")
        x = int(input("Please insert x = "))
        y = int(input("Please insert y = "))
        cost = int(input("Enter the cost of the edge: "))
        status = self.__graph.add_edge(x, y, cost)
        if status:
            print("Edge added successfully!")
        else:
            print("Cannot add this edge, it already exists!")
    def add_vertex(self):
        vertex = int(input("Add the new vertex: "))
        added = self.__graph.add_vertex(vertex)
        if added:
            print("Vertex added successfully!")
        else:
            print("Vertex not added, duplicated!")

    def remove_edge(self):
        print("Remove an edge")
        x = int(input("Please insert x = "))
        y = int(input("Please insert y = "))
        deleted = self.__graph.remove_edge(x, y)
        if deleted:
            print("Edge removed successfully!")
        else:
            print("Edge not removed, it does not exist!")

    def remove_vertex(self):
        vertex = int(input("Enter the vertex to be removed: "))
        deleted = self.__graph.remove_vertex(vertex)
        if deleted:
            print("Vertex removed successfully!")
        else:
            print("Vertex not removed, it does not exist!")

    def generate_random(self, vertices, edges):
        if edges > vertices * vertices:
            raise ValueError("Too many edges!")
        graph = Graph(vertices, 0)
        i = 0
        while i < edges:
            x = random.randint(0, vertices - 1)
            y = random.randint(0, vertices - 1)
            cost = random.randint(0, 500)
            if graph.add_edge(x, y, cost):
                i += 1
        return graph

    def create_random_graph_ui(self):
        vertices = int(input("Enter the number of vertices: "))
        edges = int(input("Enter the number of edges: "))
        graph = self.generate_random(vertices, edges)
        self.__graph_collection.append(graph)
        self.__graph = graph

    def add_empty_graph(self):
        graph = Graph(0, 0)
        self.__graph = graph
        self.__graph_collection.append(graph)

    def modify_edge_cost(self):
        x = int(input("Please insert x = "))
        y = int(input("Please insert y = "))
        cost = int(input("Enter the new cost of the edge: "))
        status = self.__graph.change_cost(x,y,cost)
        if status:
            print("Cost modified successfully!")
        else:
            print("Cost not modified, the edge does not exist!")

    def switch_to_another_graph(self):
        if len(self.__graph_collection) == 0:
            print("No graph to switch to")
        else:
            print("Available graphs: 0 to " + str(len(self.__graph_collection)-1))
            index = int(input("Enter the index of the destination graph : "))
            if  0 < index or index > len(self.__graph_collection)-1:
                raise GraphUIException("Trying to switch to a non existing graph!")
            self.__graph = self.__graph_collection[index]

    def creat_copy_graph(self):
        copy = self.__graph.make_copy()
        self.__graph_collection.append(copy)

    def parse_all_inbound_vertices(self):
        for x in self.__graph.parse_vertices():
            line = str(x) + " :"
            for y in self.__graph.parse_inbound(x):
                line = line + " " + str(y)
            print(line)

    def parse_all_outbound_vertices(self):
        for x in self.__graph.parse_vertices():
            line = str(x) + " :"
            for y in self.__graph.parse_outbound(x):
                line = line + " " + str(y)
            print(line)

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
                    self.write_to_file_ui()
                elif user_option == 3:
                    self.print_nr_of_vertices()
                elif user_option == 4:
                    self.print_nr_of_edges()
                elif user_option == 5:
                    self.print_all_vertices()
                elif user_option == 6:
                    self.find_edge()
                elif user_option == 7:
                    self.get_in_out_degree()
                elif user_option == 8:
                    self.parse_outbound()
                elif user_option == 9:
                    self.parse_inbound()
                elif user_option == 10:
                    self.add_edge()
                elif user_option == 11:
                    self.add_vertex()
                elif user_option == 12:
                    self.remove_edge()
                elif user_option == 13:
                    self.remove_vertex()
                elif user_option == 14:
                    self.create_random_graph_ui()
                elif user_option == 15:
                    self.add_empty_graph()
                elif user_option == 16:
                    self.modify_edge_cost()
                elif user_option == 17:
                    self.switch_to_another_graph()
                elif user_option == 18:
                    self.creat_copy_graph()
                elif user_option == 19:
                    self.parse_all_inbound_vertices()
                elif user_option == 20:
                    self.parse_all_outbound_vertices()
                else:
                    raise GraphUIException("Invalid graph operation!\n")

            except GraphException as exception:
                print("Exception occurred: " + str(exception))
