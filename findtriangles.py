import random
import matplotlib.pyplot as plt
import numpy as np
import timeit

def findTriangles(G):
    num = 0
    #convert G to adjacency matrix
    adj = []
    edges = []
    for u in range(len(G)):
        adj.append(set())
        for v in range(len(G)):
            if G[u][v] == 1 and u != v:
                adj[-1].add(v)
                edges.append([u, v])
    
    #find shared nodes
    for u, v in edges:
        for common in adj[u]:
            if common == u or common == v:
                continue
            if u in adj[common] and v in adj[common]:
                #rint(u, adj[u], v, adj[v], adj[common])
                return True
    return False

def main():
    max_i = 10
    x = [i for i in range(2, max_i+1)]
    y = []
    for e in range(2, max_i+1):
        n = int(2**e)
        times = []
        for t in range(5):
            G = [[0 for j in range(n)] for i in range(n)]
            for i in range(int(n/2)):
                for j in range(int(n/2), n):
                    rand = random.randint(0, 1)
                    G[i][j] = rand
                    G[j][i] = rand
            times.append(timeit.timeit(lambda: findTriangles(G), number = 5))

        y.append(np.mean(times))
    plt.plot(x, y)
    plt.xlabel("log base 2 of n (number of vertices)")
    plt.ylabel("Average execution time (s)")
    plt.title("Triangle Finding Algorithm Performance on Randomly Generated Bipartite Graphs")
    plt.show()


main()
