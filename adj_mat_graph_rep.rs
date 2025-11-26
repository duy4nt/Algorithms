use std::io;

fn main() {
    let mut nodes: String = String::new();
    println!("Input the number of nodes");
    io::stdin().read_line(&mut nodes).expect("Unable to read line");

    let nodes: usize = nodes.trim().parse::<usize>().expect("Unable to parse into int");
    println!("{:?}", nodes);

    let mut matrix: Vec<Vec<u32>> = vec![vec![0; nodes]; nodes];
    println!("{:?}", matrix);

    let mut vertex: Vec<char> = vec![' '; nodes];

}

fn add_edge(u: usize, v:usize, matrix: &mut Vec<Vec<u32>>) {
    if 0<=u && u<matrix.len() && 0<=v && v<matrix.len() {
        matrix[u][v]= 1;
        matrix[v][u]= 1;
    }
}

fn add_vertex_data(vertex_data: &mut Vec<char>,vertex: u32, data: char ) {
    if 0<=vertex && vertex<vertex_data.len() {
        vertex_data[vertex] = data;
    }
}

fn print_graph(vertex_data: &Vec<char>, matrix: &Vec<Vec<u32>>) {
    println!("Adjacency Matrix");
    for row in matrix {
        println!(" {row}");
    }
    println!("\nVertex Data");
    for vertex, data in vertex_data.iter().enumerate() {
        println!("Vertex {}, {}", vertex, data);
    }
}
