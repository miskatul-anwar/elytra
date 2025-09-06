use ford_fulkerson::Graph;

fn main() {
    /*
        Visualization of the provided graph:

              (A)
             /   \
        1000/     \1000
           /       \
        (B)---1---(C)
         \         /
      1000\      / 1000
           \   /
            (D)

        Node mapping:
            0: A
            1: B
            2: C
            3: D

        Edges and capacities:
            A -> B: 1000
            A -> C: 1000
            B -> C:    1
            B -> D: 1000
            C -> D: 1000

        Matrix representation (graph[u][v]):
            A  B  C  D
        A [[0,1000,1000,0],
        B  [0,0,   1,1000],
        C  [0,0,   0,1000],
        D  [0,0,   0,0]]

        The weights shown in the image are 0/current_flow/total_capacity.
    */

    // Create the graph using the adjacency matrix from the diagram
    let mut graph = Graph::new(4, 4);
    graph.graph = vec![
        vec![0, 1000, 1000, 0], // A
        vec![0, 0, 1, 1000],    // B
        vec![0, 0, 0, 1000],    // C
        vec![0, 0, 0, 0],       // D
    ];

    // Source is A (0), sink is D (3)
    let max_flow = graph.edmonds_karp(0, 3);
    println!("Max flow from A to D: {}", max_flow);
}
