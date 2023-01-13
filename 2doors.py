def find_smallest_array(n, q, statements):
    graph = create_graph(n, statements)
    array = [0] * n

    topological_order = topological_sort(graph)

    for vertex in topological_order:
        min_value = 0
        for neighbor in graph[vertex]:
            neighbor_value = array[neighbor[0]-1] | neighbor[1]
            min_value = max(min_value, neighbor_value)
        array[vertex-1] = min_value

    return array


def create_graph(n, statements):
    graph = {i: [] for i in range(1, n+1)}
    for i, j, x in statements:
        graph[i].append((j, x))
    return graph

def topological_sort(graph):
    visited = set()
    topological_order = []

    def dfs(vertex):
        visited.add(vertex)
        for neighbor in graph[vertex]:
            if neighbor[0] not in visited:
                dfs(neighbor[0])
        topological_order.append(vertex)

    for vertex in graph:
        if vertex not in visited:
            dfs(vertex)

    return topological_order[::-1]

def main():
    # Read the input
    n, q = map(int, input().split())
    statements = [tuple(map(int, input().split())) for _ in range(q)]

    # Find the lexicographically smallest array
    array = find_smallest_array(n, q, statements)

    # Print the array
    print(' '.join(str(a) for a in array))

if __name__ == '__main__':
    main()
