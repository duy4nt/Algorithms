use std::io;

fn main() {
    let mut nodes: String = String::new();
    println!("Input the number of nodes");
    io::stdin().read_line(&mut nodes).expect("Unable to read line");

    let nodes: usize = nodes.trim().parse::<usize>().expect("Unable to parse into int");
    println!("{:?}", nodes);

    let mut matrix: Vec<Vec<i32>> = vec![vec![0; nodes]; nodes];
    println!("{:?}", matrix);

}

fn add_edge(u: usize, v:usize, matrix: &mut Vec<Vec<i32>>) {
    if 0<=u && u<matrix.len() && 0<=v && v<matrix.len() {
        matrix[u][v]= 1;
        matrix[v][u]= 1;
    }
}
