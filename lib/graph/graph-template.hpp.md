---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/warshall-floyd.test.cpp
    title: test/graph/warshall-floyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Graph Template
    links: []
  bundledCode: "#line 2 \"lib/graph/graph-template.hpp\"\nusing length = lint;\nstruct\
    \ edge{\n\tint src, to, id;\n\tedge() = default;\n\tedge(int src, int to, int\
    \ id = 0): src(src), to(to), id(id){}\n};\n\nusing Edges = vector<edge>;\nclass\
    \ Weighted: public vector<Edges>{\npublic:\n\tWeighted(int n){\n\t\tthis->resize(n);\n\
    \t}\n\tvoid add_edge(edge e, bool directed = 0){\n\t\t(*this)[e.src].push_back(e);\n\
    \t\tif(!directed)(*this)[e.to].push_back(edge(e.to, e.src, e.id));\n\t}\n\tvoid\
    \ add_edge(int src, int to, int id = 0, bool directed = 0){\n\t\t(*this)[src].push_back(edge(src,\
    \ to, id));\n\t\tif(!directed)(*this)[to].push_back(edge(to, src, id));\n\t}\n\
    };\nclass Matrix: public vector<vector<length>>{\npublic:\n\tMatrix(int n, length\
    \ inf = 2*linf){\n\t\tthis->resize(n, vector<length>(n, inf));\n\t\tfor(int i\
    \ = 0; i<n; ++i)(*this)[i][i] = 0;\n\t}\n\tvoid add_edge(edge e, length cost,\
    \ bool directed = 0){\n\t\tif((*this)[e.src][e.to]>cost)(*this)[e.src][e.to] =\
    \ cost;\n\t\tif(!directed)if((*this)[e.to][e.src]>cost)(*this)[e.to][e.src] =\
    \ cost;\n\t}\n\tvoid add_edge(int src, int to, length cost, bool directed = 0){\n\
    \t\tif((*this)[src][to]>cost)(*this)[src][to] = cost;\n\t\tif(!directed)if((*this)[to][src]>cost)(*this)[to][src]\
    \ = cost;\n\t}\n};\n\n\n/*\n* @title Graph Template\n*/\n\n\n/*\n* @title Graph\
    \ Template\n*/\n"
  code: "#pragma once\nusing length = lint;\nstruct edge{\n\tint src, to, id;\n\t\
    edge() = default;\n\tedge(int src, int to, int id = 0): src(src), to(to), id(id){}\n\
    };\n\nusing Edges = vector<edge>;\nclass Weighted: public vector<Edges>{\npublic:\n\
    \tWeighted(int n){\n\t\tthis->resize(n);\n\t}\n\tvoid add_edge(edge e, bool directed\
    \ = 0){\n\t\t(*this)[e.src].push_back(e);\n\t\tif(!directed)(*this)[e.to].push_back(edge(e.to,\
    \ e.src, e.id));\n\t}\n\tvoid add_edge(int src, int to, int id = 0, bool directed\
    \ = 0){\n\t\t(*this)[src].push_back(edge(src, to, id));\n\t\tif(!directed)(*this)[to].push_back(edge(to,\
    \ src, id));\n\t}\n};\nclass Matrix: public vector<vector<length>>{\npublic:\n\
    \tMatrix(int n, length inf = 2*linf){\n\t\tthis->resize(n, vector<length>(n, inf));\n\
    \t\tfor(int i = 0; i<n; ++i)(*this)[i][i] = 0;\n\t}\n\tvoid add_edge(edge e, length\
    \ cost, bool directed = 0){\n\t\tif((*this)[e.src][e.to]>cost)(*this)[e.src][e.to]\
    \ = cost;\n\t\tif(!directed)if((*this)[e.to][e.src]>cost)(*this)[e.to][e.src]\
    \ = cost;\n\t}\n\tvoid add_edge(int src, int to, length cost, bool directed =\
    \ 0){\n\t\tif((*this)[src][to]>cost)(*this)[src][to] = cost;\n\t\tif(!directed)if((*this)[to][src]>cost)(*this)[to][src]\
    \ = cost;\n\t}\n};\n\n\n/*\n* @title Graph Template\n*/\n\n\n/*\n* @title Graph\
    \ Template\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/graph-template.hpp
  requiredBy: []
  timestamp: '2021-11-09 16:40:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dijkstra.test.cpp
  - test/graph/bfs.test.cpp
  - test/graph/warshall-floyd.test.cpp
documentation_of: lib/graph/graph-template.hpp
layout: document
redirect_from:
- /library/lib/graph/graph-template.hpp
- /library/lib/graph/graph-template.hpp.html
title: Graph Template
---
