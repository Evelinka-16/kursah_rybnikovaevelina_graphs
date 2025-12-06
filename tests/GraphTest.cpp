#include <gtest/gtest.h>
#include "../Graph.h"
#include <fstream>
#include <cstdio>

TEST(GraphTest, AddVertexIncreasesSize) {
    Graph g;
    g.clear();

    g.add_vertex(10);
    g.add_vertex(20);
    g.add_vertex(30);

    EXPECT_NO_THROW(g.connect_vertex(0, 1));
}

TEST(GraphTest, ConnectAndDisconnectVertices) {
    Graph g;
    g.clear();

    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);

    EXPECT_NO_THROW(g.connect_vertex(0, 1));
    EXPECT_NO_THROW(g.connect_vertex(1, 2));
    EXPECT_NO_THROW(g.disconnect_vertex(1, 2));
}

TEST(GraphTest, RemoveVertexReducesMatrix) {
    Graph g;
    g.clear();

    g.add_vertex(5);
    g.add_vertex(6);
    g.add_vertex(7);

    EXPECT_NO_THROW(g.remove_vertex(1));

    EXPECT_NO_THROW(g.connect_vertex(0, 1));
}

TEST(GraphTest, ClearGraphEmptiesEverything) {
    Graph g;

    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.connect_vertex(0, 1);

    g.clear();

    EXPECT_NO_THROW(g.add_vertex(10));
    EXPECT_NO_THROW(g.add_vertex(20));
    EXPECT_NO_THROW(g.connect_vertex(0, 1));
}

TEST(GraphTest, SaveAndLoadGraph) {
    Graph g;
    g.clear();

    g.add_vertex(10);
    g.add_vertex(20);
    g.add_vertex(30);
    g.connect_vertex(0, 1);
    g.connect_vertex(1, 2);

    std::string file = "gtest_graph.txt";

    g.save_to_file(file);

    Graph g2;
    g2.clear();
    g2.load_from_file(file);

    EXPECT_NO_THROW(g2.connect_vertex(0, 1));
    EXPECT_NO_THROW(g2.disconnect_vertex(0, 1));

    std::remove(file.c_str());
}

TEST(GraphTest, OutputOperatorDoesNotThrow) {
    Graph g;
    g.clear();

    g.add_vertex(11);
    g.add_vertex(22);

    std::stringstream ss;
    EXPECT_NO_THROW(ss << g);

    std::string out = ss.str();
    EXPECT_NE(out.find("Вершины"), std::string::npos);
    EXPECT_NE(out.find("Матрица смежности"), std::string::npos);
}
