# Practical Work No 1

Design and implement an abstract data type directed graph and a function (either a member function or an external one, as your choice) for reading a directed graph from a text file.

The vertices will be specified as integers from 0 to n-1, where n is the number of vertices.

Edges may be specified either by the two endpoints (that is, by the source and target), or by some abstract data type Edge_id (that data type may be a pointer or reference to the edge representation, but without exposing the implementation details of the graph).

Additionally, create a map that associates to an edge an integer value (for instance, a cost).

<b>Required operations:</b>
<ul>
  <li>get the number of vertices;
  </li><li>parse (iterate) the set of vertices;
  </li><li>given two vertices, find out whether there is an edge from the first one to the
second one, and
retrieve the <em>Edge_id</em> if there is an edge (the latter is not required if
an edge is represented simply as a pair of vertex identifiers);
  </li><li>get the in degree and the out degree of a specified vertex;
  </li><li>parse (iterate) the set of outbound edges of a specified vertex (that is, provide
an iterator). For each outbound edge, the iterator shall provide the <em>Edge_id</em>
of the curren edge (or the target vertex, if no <em>Edge_id</em> is used).
  </li><li>parse the set of inbound edges of a specified vertex (as above);
  </li><li>get the endpoints of an edge specified by an <em>Edge_id</em> (if applicable);
  </li><li>retrieve or modify the information (the integer) attached to a specified edge.
  </li><li>The graph shall be modifiable: it shall be possible to add and remove
    an edge, and to add and remove a vertex. Think about what should happen
    with the properties of existing edges and with the identification of
    remaining vertices. You may use an abstract <tt>Vertex_id</tt> instead
    of an <tt>int</tt> in order to identify vertices; in this case, provide
    a way of iterating the vertices of the graph.
  </li><li>The graph shall be copyable, that is, it should be possible to make an
    exact copy of a graph, so that the original can be then modified
    independently of its copy. Think about the desirable behaviour of an
    <tt>Edge_property</tt> attached to the original graph, when a copy is made.
  </li><li>Read the graph from a text file (as an external function); see the format below.
  </li><li>Write the graph from a text file (as an external function); see the format below.
  </li><li>Create a random graph with specified number of vertices and of edges (as an external function).
</li></ul>
The operations must take no more than:

O(deg(x)+deg(y)) for: verifying the existence of an edge and for retrieving the edge between two given vertices.
O(1) for: getting the first or the next edge, inbound or outbound to a given vertex; get the endpoints, get or set the attached integer for an edge (given by an Edge_id or, if no Edge_id is defined, then given by its source and target); get the total number of vertices or edges; get the in-degree or the out-degree of a given vertex.
