#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_set>

#include "engine.hpp"

class Graph {
private:
    std::string graph;
    int node_count;
    std::unordered_map<std::string, std::tuple<std::string, std::string, std::string, float, float>> nodes;
    std::unordered_map<std::string, std::pair<std::string, std::string>> edges;

public:
    Graph();

    std::string get_label_rpr(std::string node_key);

    std::string get_op_str(std::string op);

    void add_node(std::string id, std::string label, std::string args = "color=black", bool is_op = false); 
    void add_edge(std::string from, std::string to); 

    void trace_nodes_and_edges(Value* v) ;

    void trace_graph(Value v);

    void write_to_file(const std::string& filename);

    void draw(const Value v, const std::string& filename);

    ~Graph(); 
};