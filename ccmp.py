def connected_components_count(graph):
  cmp = 0
  visited = set()
  for vertex, _ in graph.items():
    if vertex in visited:
      continue
    cmp += 1
    visited.add(vertex)
    queue = [vertex]
    while len(queue):
      x = queue.pop(0)
      for edge in graph[x]:
        if edge not in visited:
          queue.append(edge)
          visited.add(edge)
    return cmp
  
          
print(connected_components_count({
  3: [],
  4: [6],
  6: [4, 5, 7, 8],
  8: [6],
  7: [6],
  5: [6],
  1: [2],
  2: [1]
})) # -> 3    
