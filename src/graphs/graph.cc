#include "graphs/graph.hh"

#include <sstream>
using namespace std;

void Graph::export_to(string path) {
    ofstream fs(path);
    if (!fs.is_open()) {
        cerr << "Error: Unable to open file " << path << endl;
        throw runtime_error("File not found");
    }
    fs << "GRAPH\n";
    fs << "NODES " << _num_nodes << "\n";
    fs << "EDGES " << _num_edges << "\n";
    for (int i = 1; i <= _num_nodes; ++i) {
        for (const auto &edge : move[i]) {
            fs << "EDGE " << i << " " << edge.first << " " << edge.second << "\n";
        }
    }
}

Graph::Graph(string path) {
    ifstream fs(path);
    if (!fs.is_open()) {
        cerr << "Error: Unable to open file " << path << endl;
        throw runtime_error("File not found");
    }
    string line;
    while (getline(fs, line)) {
        if (line == "GRAPH")
            continue;
        if (line.find("NODES") != string::npos) {
            _num_nodes = stoi(line.substr(line.find(" ") + 1));
            move.resize(_num_nodes + 1);
        } else if (line.find("EDGES") != string::npos) {
            _num_edges = stoi(line.substr(line.find(" ") + 1));
        } else if (line.find("EDGE") != string::npos) {
            int u, v, w;
            istringstream iss(line);
            string temp;
            iss >> temp >> u >> v >> w;
            move[u].push_back({v, w});
        } else {
            cerr << "Error: Unknown line format in file " << path << endl;
            throw runtime_error("Unknown line format");
        }
    }
}

void Graph::add_edge(int u, int v, int w) {
    move[u].push_back({v, w});
    move[v].push_back({u, w});
}

void Graph::describe(string name) {
    if (name != "")
        cout << "Graph: " << name << endl;
    cout << "Graph with " << _num_nodes << " nodes, " << _num_edges << " edges." << endl;
    for (int i = 1; i <= _num_nodes; ++i) {
        cout << "Node " << i << ": ";
        for (const auto &edge : move[i]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
}