airports = 'PHX BKK OKC JFK LAX MEX EZE HEL LOS LAP LIM'.split(' ');

routes = [
    ['PHX', 'LAX'],
    ['PHX', 'JFK'],
    ['JFK', 'OKC'],
    ['JFK', 'HEL'],
    ['JFK', 'LOS'],
    ['MEX', 'LAX'],
    ['MEX', 'BKK'],
    ['MEX', 'LIM'],
    ['MEX', 'EZE'],
    ['LIM', 'BKK'],
]

adj = {}
def addNode(node):
    adj[node] = []

def addEdge(origin, dest):
    adj[origin].append(dest)
    adj[dest].append(origin)

for airport in airports:
    addNode(airport)
for route in routes:
    addEdge(route[0], route[1])


def dfs(pos, visited=set(), steps=0):
    visited.add(pos)
    print(pos)
    steps += 1
    destinations = adj[pos]
    for destination in destinations:
        # if destination == "BKK":
        #     print(f"Found a route from PHX to {destination} Through {pos} in {steps} steps")
        #     return
        if destination not in visited:
            dfs(destination, visited, steps)

def dfsIterative(pos):
    visited = set()
    visited.add(pos)
    stack = [pos]
    while len(stack):
        x = stack[-1]
        stack.pop()
        print(x)
        for destination in adj[x]:
            if destination not in visited:
                stack.append(destination)
                visited.add(destination)


def bfs(pos, des):
    visited = set()
    queue = [pos]
    visited.add(pos)
    while(queue != []):
        airport = queue.pop(0)
        destinations = adj[airport]
        for destination in destinations:
            if destination == des:
                print(f"Found a route from {pos} to {des}")
                return
            if destination not in visited:
                visited.add(destination)
                queue.append(destination)
                print(destination)


def detectCycle(pos, visited=set(), anc=set()):
    visited.add(pos)
    anc.add(pos)
    destinations = adj[pos]
    for destination in destinations:
        if destination in visited and destination in anc:
            return True # There is a cycle
        elif destination not in visited and detectCycle(destination, visited, anc):
            return True
    anc[pos] = False
    return False


for k, v in adj.items():
    print(f"{k} : {v}")

# dfs("PHX")
# dfsIterative("PHX")
# bfs("PHX", "BKK")
    

# print("There is a cycle" if detectCycle("PHX") else "There is no cycle")