use std::collections::{VecDeque, HashSet};

fn bfs(adj: &Vec<Vec<usize>>, start: usize) {
    let mut visited = HashSet::new();
    let mut queue = VecDeque::new();

    visited.insert(start);
    queue.push_back(start);

    while let Some(node) = queue.pop_front() {
        for &neighbor in &adj[node] {
            if visited.insert(neighbor) {
                queue.push_back(neighbor);
            }
        }
    }
}

fn build_graph(edges: &[(usize, usize)], node_count: usize) -> Vec<Vec<usize>> {
    let mut adj = vec![vec![]; node_count];
    for &(u, v) in edges {
        adj[u].push(v);
        adj[v].push(u); // Undirected
    }
    adj
}

fn main() {
    let graphs: Vec<Vec<(usize, usize)>> = vec![
        vec![(0,1), (0,2), (1,3), (2,4), (4,5)],                            // 5 edges
        vec![(0,1), (0,2), (1,3), (2,4), (4,5), (1,2), (3,5)],              // 7 edges
        vec![(0,1), (0,2), (1,3), (2,4), (4,5), (1,2), (3,5), (3,4), (0,5)] // 9 edges
    ];

    for edges in graphs {
        let adj = build_graph(&edges, 6);
        bfs(&adj, 0);
    }
}
