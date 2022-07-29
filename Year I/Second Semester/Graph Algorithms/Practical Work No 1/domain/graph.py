import copy


class Graph:
    def __init__(self, number_of_vertices, number_of_edges):
        self._number_of_vertices = number_of_vertices
        self._number_of_edges = number_of_edges
        self._dict_in = {}
        self._dict_out = {}
        self._dict_cost = {}
        for index in range(number_of_vertices):
            self._dict_in[index] = []
            self._dict_out[index] = []

    @property
    def dict_cost(self):
        return self._dict_cost

    @property
    def dict_in(self):
        return self._dict_in

    @property
    def dict_out(self):
        return self._dict_out

    @property
    def number_of_vertices(self):
        return self._number_of_vertices

    @property
    def number_of_edges(self):
        return self._number_of_edges

    def parse_vertices(self):
        vertices = list(self._dict_in.keys())
        for v in vertices:
            yield v

    def parse_inbound(self, x):
        for y in self._dict_in[x]:
            yield y

    def parse_outbound(self, x):
        for y in self._dict_out[x]:
            yield y

    def parse_cost(self):
        keys = list(self._dict_cost.keys())
        for key in keys:
            yield key

    def add_vertex(self, x):
        if x in self._dict_in.keys() and x in self._dict_out.keys():
            return False
        self.dict_in[x] = []
        self._dict_out[x] = []
        self._number_of_vertices += 1
        return True

    def remove_vertex(self, x):
        if x not in self._dict_in.keys() and x not in self._dict_out.keys():
            return False
        self._dict_in.pop(x)
        self._dict_out.pop(x)
        for key in self._dict_in.keys():
            if x in self._dict_in[key]:
                self._dict_in[key].remove(x)
            elif x in self._dict_out[key]:
                self._dict_out[key].remove(x)
        keys = list(self._dict_cost.keys())
        for key in keys:
            if key[0] == x or key[1] == x:
                self._dict_cost.pop(key)
                self._number_of_edges -= 1
        self._number_of_vertices -= 1
        return True

    def in_degree(self, x):
        if x not in self._dict_in.keys():
            return -1
        return len(self._dict_in[x])

    def out_degree(self, x):
        if x not in self._dict_out.keys():
            return -1
        return len(self._dict_out[x])

    def add_edge(self, x, y, cost):
        if x in self._dict_in[y]:
            return False
        elif y in self._dict_out[x]:
            return False
        elif (x, y) in self._dict_cost.keys():
            return False
        self._dict_in[y].append(x)
        self._dict_out[x].append(y)
        self._dict_cost[(x, y)] = cost
        self._number_of_edges += 1
        return True

    def remove_edge(self, x, y):
        if x not in self._dict_in.keys() or y not in self._dict_in.keys() or x not in self._dict_out.keys() or y not in self._dict_out.keys():
            return False
        if x not in self._dict_in[y]:
            return False
        elif y not in self._dict_out[x]:
            return False
        elif (x, y) not in self._dict_cost.keys():
            return False
        self._dict_in[y].remove(x)
        self._dict_out[x].remove(y)
        self._dict_cost.pop((x, y))
        self._number_of_edges -= 1
        return True

    def is_edge(self, x, y):
        if x in self._dict_in[y]:
            return self._dict_cost[(x, y)]
        elif y in self._dict_out[x]:
            return self._dict_cost[(x, y)]
        return False

    def is_vertex(self,x):
        if x in self._dict_in.keys():
            return True
        return False

    def change_cost(self, x, y, cost):
        if (x, y) not in self._dict_cost.keys():
            return False
        self._dict_cost[(x, y)] = cost
        return True

    def make_copy(self):
        return copy.deepcopy(self)
