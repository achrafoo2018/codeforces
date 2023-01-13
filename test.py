def topological_sort(graph):
    # Set of vertices that have been visited during the current DFS traversal
    visited = set()
    # List to store the linear ordering of the vertices
    ordering = []

    def dfs(vertex):
        # Mark the vertex as visited
        visited.add(vertex)
        # Recursively visit the neighbors of the vertex
        for neighbor in graph[vertex]:
            if neighbor not in visited:
                dfs(neighbor)
        # Add the vertex to the ordering after all of its neighbors have been visited
        ordering.append(vertex)

    # Start the DFS traversal from each vertex in the graph
    for vertex in graph:
        if vertex not in visited:
            dfs(vertex)

    return ordering

# Example usage

# Define the input graph as a dictionary where the keys are the vertices and the values are the lists of neighbors
graph = {
    'A': ['C', 'D'],
    'B': ['D'],
    'C': ['E'],
    'D': ['E'],
    'E': []
}

# Compute the topological sort of the graph
ordering = topological_sort(graph)

# Print the result
print(ordering)
