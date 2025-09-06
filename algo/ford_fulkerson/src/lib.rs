use std::collections::VecDeque;

/*
    This struct represents a directed graph using an adjacency matrix.
    Each cell graph[u][v] holds the residual capacity of the edge from node u to node v.
*/
pub struct Graph {
    pub graph: Vec<Vec<usize>>, // The residual capacity graph (adjacency matrix)
}

impl Graph {
    /*
        Constructs a new Graph with a given number of rows and columns.
        All edges initially have zero capacity.
    */
    pub fn new(row: usize, col: usize) -> Self {
        Graph {
            graph: vec![vec![0; col]; row],
        }
    }

    /*
        Performs a BFS search on the residual graph from source `s` to sink `t`.
        Fills the `parent` vector to store the path.
        Returns true if a path exists from `s` to `t` (i.e., if more flow can be pushed).

        This is a classic BFS, but it's used here to find an augmenting path in the residual graph.
        Only edges with positive residual capacity are considered.
    */
    fn bfs(&self, s: usize, t: usize, parent: &mut Vec<isize>) -> bool {
        let mut visited = vec![false; self.graph.len()];
        let mut queue = VecDeque::new();

        queue.push_back(s);
        visited[s] = true;
        parent[s] = -1; // Source has no parent

        while let Some(u) = queue.pop_front() {
            // Explore all adjacent vertices (potential neighbors)
            for (v, &capacity) in self.graph[u].iter().enumerate() {
                // If this edge has positive capacity and v hasn't been visited yet, it is a valid path
                if !visited[v] && capacity > 0 {
                    queue.push_back(v);
                    visited[v] = true;
                    parent[v] = u as isize; // Set parent so we can reconstruct path later
                }
            }
        }

        // If the sink was reached, then there is an augmenting path
        visited[t]
    }

    /*
        Implements the Edmonds-Karp algorithm (an optimized Ford-Fulkerson) to compute the maximum flow from `s` (source) to `t` (sink).

        The algorithm repeatedly finds augmenting paths using BFS, determines the minimum residual capacity
        along that path (the bottleneck), and augments the flow along the path by that amount.
        The process repeats until no more augmenting paths are found.

        The residual graph is updated after each augmentation: forward edges decrease in capacity,
        while reverse edges increase (allowing for "undoing" flow in future iterations).
    */
    pub fn edmonds_karp(&mut self, s: usize, t: usize) -> usize {
        let n = self.graph.len();
        let mut parent = vec![-1isize; n]; // Stores path found by BFS
        let mut max_flow = 0; // There is no flow initially

        // Augment the flow while there is a path from source to sink
        while self.bfs(s, t, &mut parent) {
            /*
                Find minimum residual capacity along the path found by BFS (the bottleneck value)
            */
            let mut path_flow = usize::MAX;
            let mut v = t;
            while v != s {
                let u = parent[v] as usize;
                path_flow = path_flow.min(self.graph[u][v]);
                v = u;
            }

            // Add the bottleneck capacity to the overall flow
            max_flow += path_flow;

            /*
                Update residual capacities along the path:
                - Subtract the flow from forward edges
                - Add the flow to reverse edges
            */
            let mut v = t;
            while v != s {
                let u = parent[v] as usize;
                self.graph[u][v] -= path_flow;
                self.graph[v][u] += path_flow;
                v = u;
            }
        }

        max_flow
    }
}
